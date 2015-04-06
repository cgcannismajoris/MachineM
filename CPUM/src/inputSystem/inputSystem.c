/*
* Nome do Arquivo:  inputSystem.c
*       Descricao:  Implementação do TAD IMPUTSYSTEM.
*
* INPUTSYSTEM for CPUM.
* Copyright (C) 2015  Cristian Costa Mello and Gustavo Freitas de Amorim
*
* This is part of CPUM
* CPUM is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* CPUM is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "inputSystem.h"

INPUTSYSTEM *input_new()
{
    INPUTSYSTEM *novo;

    if ((novo = (INPUTSYSTEM *)malloc(sizeof(INPUTSYSTEM))) == NULL)
    {
        cpuError_setDesc(INPUTSYSTEM_EALLOC_MSG);
        return INPUTSYSTEM_EALLOC;
    }

    novo->mem = NULL;

    return novo;
}

void input_free(INPUTSYSTEM *input)
{
    if (input->mem != NULL)
        instMemory_free(input->mem);

    free(input);
}

uint8_t *input_getInst(INPUTSYSTEM *input, uint64_t address)
{
    if (address < input->mem->length)
        return (input->mem->mem + (address * INSTRUCTION_INSTLENGTH_BYTES));

    return NULL;
}

uint8_t *input_load(INPUTSYSTEM *input, const char *filename)
{
    FILE *fbin;      /* ptr. arquivo binário */
    uint64_t length;
	
	uint32_t headerLength; 
	uint8_t  *header;

    if ((fbin = fopen(filename, "rb")) == NULL)
    {
        cpuError_setDesc(INPUTSYSTEM_EFOPEN_MSG);
        return INPUTSYSTEM_EALLOC;
    }

	/* Carrega o cabeçalho */
	//Carrega a quantidade de registradores e calcula o tamanho total
	fread(&headerLength, sizeof(uint32_t), 1, fbin);
	rewind(fbin);

	headerLength = sizeof(uint32_t) + 
						(headerLength * (sizeof(uint8_t) + sizeof(int)));

	//Aloca a memória necessária para carregar o restante do cabeçalho
	if((header = (uint8_t*)malloc(headerLength)) == NULL)
	{
		cpuError_setDesc(INPUTSYSTEM_EALLOC_MSG);
		return INPUTSYSTEM_EALLOC;
	}
	
	//Carrega
	fread(header, headerLength, 1, fbin);

	/* Carrega as instruções */
	rewind(fbin);
    fseek(fbin, 0, SEEK_END);

	//Calcula o tamanho necessário para armazenar as instruções subtraindo o 
	//tamanho do header
    length = (ftell(fbin) - headerLength) / INSTRUCTION_INSTLENGTH_BYTES; 

	//Volta para o final do cabeçalho
	rewind(fbin); /* retorne ao início do arquivo */
	fseek(fbin, headerLength, SEEK_SET);	
	
	//Aloca a memória necessária para o carregamento
    if ((input->mem = instMemory_new(length)) == INSTMEMORY_EALLOC)
    {
		fclose(fbin);
		return INPUTSYSTEM_EALLOC;
    }

	/* Carregar o arquivo integralmente para a memória de instruções */
    fread(input->mem->mem, INSTRUCTION_INSTLENGTH_BYTES, length, fbin);

    fclose(fbin);
    return header;
}

