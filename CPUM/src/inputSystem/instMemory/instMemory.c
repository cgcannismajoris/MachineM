/*
* Nome do Arquivo:  instMemory.c
*       Descricao:  Implementação do módulo INSTMEMORY.
*
* INSTMEMORY for CPUM.
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

#include "instMemory.h"


INSTMEMORY *instMemory_new(uint64_t length)
{
    INSTMEMORY *novo;

    if ((novo = (INSTMEMORY *)malloc(sizeof(INSTMEMORY))) == NULL)
    {
        cpuError_setDesc(INSTMEMORY_EALLOC_MSG);
        return INSTMEMORY_EALLOC;
    }

    if ((novo->mem = (uint8_t *)malloc(length * INSTRUCTION_INSTLENGTH_BYTES)) == NULL)
    {
        free(novo);
        cpuError_setDesc(INSTMEMORY_EALLOC_MSG);
        return INSTMEMORY_EALLOC;
    }

    novo->length = length;

    return novo;
}

void instMemory_free(INSTMEMORY *instMem)
{
    free(instMem->mem);
    free(instMem);
}

uint32_t instMemory_get(INSTMEMORY *instMem, uint64_t address)
{
    if (address < instMem->length)
        return instMem->mem[address * INSTRUCTION_INSTLENGTH_BYTES];

    return 0;
}

