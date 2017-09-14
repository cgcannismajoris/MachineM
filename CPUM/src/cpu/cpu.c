/*
 * Nome do Arquivo:  cpu.c
 *       Descricao:  Implementação do TAD CPU.
 *
 * CPU for CPUM.
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

#include "cpu.h"

CPU *cpu_new(uint32_t ticks)
{
    CPU *nova;

    if ((nova = (CPU *)malloc(sizeof(CPU))) == NULL)
    {
        cpuError_setDesc(CPU_EALLOC_MSG);
        return CPU_EALLOC;
    }

	nova->regsBank = NULL;	
	nova->ticksPerSecond = ticks;

    return nova;
}

void cpu_free(CPU *cpu)
{
	registerBank_free(cpu->regsBank);
	free(cpu);
}

int cpu_start(CPU *cpu, const char *input, const char *output)
{
	
	int status;			
	uint8_t *header;
	uint64_t length;

	//Inicia o sistema de input
	if((cpu->input = input_new()) == INPUTSYSTEM_EALLOC)
		return CPU_ERROR;

	//Inicia o sistema de output
	if((cpu->output = output_new(output)) == OUTPUTSYSTEM_EALLOC)
		return CPU_ERROR;
	
	//Carrega o arquivo de instruções e obtém o header
	if((header = input_load(cpu->input, input)) == NULL)
		return CPU_ERROR;
 
	//Calcula o tamanho da memória de registradores	
	length = (*((uint32_t*)header) * (sizeof(uint8_t) + sizeof(uint32_t)));
	
	//Instancia o banco de registradores utilizando o header
	if((cpu->regsBank = registerBank_new(header + sizeof(uint32_t), length)) == 
					REGISTERBANK_EALLOC)
		return CPU_ERROR;
	
	//Processa o programa
	do{
		output_writeTrace(cpu->output, cpu->regsBank);
	}while((status = cpu_clock(cpu)) == CPU_FINISH);
	
	//Finalisa os subsistemas
	input_free(cpu->input);
	output_free(cpu->output);

	return (status);
}

int cpu_clock(CPU *cpu)
{
	uint8_t *inst;
	
	if((inst = input_getInst(cpu->input, registerBank_getPc(cpu->regsBank))) == 0)
	{
		return (CPU_END);
	}

	if(control_process(cpu->regsBank, inst) == CONTROL_EUKNOWINSTRUCTION)
	{
		return (CPU_ERROR);
	}

	return (CPU_FINISH);
}

