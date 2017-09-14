/*
 * Nome do Arquivo:  outputSystem.c
 *       Descricao:  Implementação do TAD OUTPUTSYSTEM.
 *
 * OUTPUTSYSTEM for CPUM.
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

#include "outputSystem.h"

OUTPUTSYSTEM *output_new(const char *filename)
{
	OUTPUTSYSTEM *novo;

	if((novo = (OUTPUTSYSTEM*)malloc(sizeof(OUTPUTSYSTEM))) == NULL)
	{
		cpuError_setDesc(OUTPUTSYSTEM_EALLOC_MSG);
		return OUTPUTSYSTEM_EALLOC;
	}

	if((novo->file = fopen(filename, "w+")) == NULL)
	{
		cpuError_setDesc(OUTPUTSYSTEM_EFOPEN_MSG);
		return OUTPUTSYSTEM_EFOPEN;
	}

	return (novo);
}

void output_free(OUTPUTSYSTEM *output)
{
	fclose(output->file);
	free(output);
}

void output_writeTrace(OUTPUTSYSTEM *output, REGISTERBANK *regMem)
{
	uint64_t i;
	
	fprintf(output->file, "(%li, (", registerBank_getPc(regMem) + 1);

	for(i = 0; i < registerBank_getLength(regMem) - 1; i++)
		fprintf(output->file, "%i, ", registerBank_getRegister(regMem, i));
	
	fprintf(output->file, "%i", registerBank_getRegister(regMem, i));

	fprintf(output->file, "))\n");
}

