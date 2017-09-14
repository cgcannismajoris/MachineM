/*
* Nome do Arquivo:  cpuError.c
*       Descricao:  Implementação do módulo CPUERROR.
*
* CPUERROR for CPUM.
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

#include "cpuError.h"

//Armazena a string do erro gerado.
static char *__failureDescription;


char *cpuError_new(uint32_t desc)
{
    if ((__failureDescription = (char *)malloc(sizeof(char) * desc)) == NULL)
        return NULL;

    return __failureDescription;
}

void cpuError_free()
{
    free(__failureDescription);
}

char *cpuError_getDesc()
{
    return __failureDescription;
}

void cpuError_setDesc(const char *failureDesc)
{
    sprintf(__failureDescription, "%s", failureDesc);
}
