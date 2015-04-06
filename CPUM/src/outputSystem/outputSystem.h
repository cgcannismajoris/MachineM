/*
 * Nome do Arquivo:  outputSystem.h
 *       Descricao:  TAD para escrita de todas as saídas da máquina.
 *
 * Exported functions from outputSystem.c.
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

#ifndef OUTPUTSYSTEM_H
#define OUTPUTSYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../cpuError.h"
#include "../registerBank/registerBank.h"

#define OUTPUTSYSTEM_EALLOC			NULL
#define OUTPUTSYSTEM_EALLOC_MSG		"Falha de alocação de memória para OUTPUTSYSTEM."

#define OUTPUTSYSTEM_EFOPEN			NULL
#define OUTPUTSYSTEM_EFOPEN_MSG 	"Falha ao abrir arquivo de saída da computação."


typedef struct _outputSystem
{
	FILE *file; //Arquivo a ser utilizado na saída
} OUTPUTSYSTEM;


/* -> OUTPUTSYSTEM *output_new(const char *filename)
 * 
 * - DESCRIÇÃO: Instancia uma nova estrutura em memória.
 *
 * - PARÂMETROS: 
 *      -> const char *filename: Nome do arquivo a ser utilizado na escrita.
 *
 * - RETORNO: Estrutura do tipo OUTPUTSYSTEM instanciada.
 *   	-> Se NULL    - Erro na operação.
 *   	-> Se != NULL - Sucesso na operação.
 */
OUTPUTSYSTEM *		output_new(const char *filename);


/* -> void output_free(OUTPUTSYSTEM *output)
 * 
 * - DESCRIÇÃO: Destrói uma estrutura existente em memória.
 *
 * - PARÂMETROS: 
 *      -> OUTPUTSYSTEM *output: Estrutura a ser destruída.
 *
 * - RETORNO: void.
 */
void 				output_free(OUTPUTSYSTEM *output);


/* -> void output_writeTrace(OUTPUTSYSTEM *output, REGISTERBANK *regMem)
 * 
 * - DESCRIÇÃO: Grava o atual estado da CPU.
 *
 * - PARÂMETROS: 
 *      -> OUTPUTSYSTEM *output: Estrutura a ser utilizada na operação.
 *      -> REGISTERBANK *regMem: Memória de registradores a ser gravada.
 *
 * - RETORNO: void.
 */
void 				output_writeTrace(OUTPUTSYSTEM *output, REGISTERBANK *regMem);

#endif
