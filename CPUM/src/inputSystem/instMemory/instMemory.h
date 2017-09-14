/*
 * Nome do Arquivo:  instMemory.h
 *       Descricao:  TAD para manipulação da memória de instruções da
 *       			 máquina.
 *
 * Exported functions from instMemory.c.
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

#ifndef INSTMEMORY_H
#define INSTMEMORY_H

#include <stdlib.h>
#include <stdint.h>

#include "../../cpuError.h"
#include "../../instruction/instruction.h"

#define INSTMEMORY_EALLOC        NULL
#define INSTMEMORY_EALLOC_MSG    "Falha ao criar memória de instruções."


typedef struct _instMemory
{
    uint8_t *   mem;        /* memória de instruções */
    uint64_t    length;     /* quantidade de instruções, em bytes */
} INSTMEMORY;


/* -> INSTMEMORY *instMemory_new(uint64_t length)
 *
 * - DESCRIÇÃO: Instancia a memória de instruções.
 *
 * - PARÂMETROS:
 *      -> uint64_t length: quantidade de instruções.
 *
 * - RETORNO: estado do processamento
 *   	-> Se NULL    - Erro na operação
 *   	-> Se != NULL - Sucesso na operação.
 */
INSTMEMORY *    instMemory_new(uint64_t length);


/* -> void instMemory_free(INSTMEMORY *instMem)
 *
 * - DESCRIÇÃO: Libera a memória de instruções.
 *
 * - PARÂMETROS:
 *      -> INSTMEMORY *instMem: memória de instruções.
 *
 * - RETORNO: void.
 */
void            instMemory_free(INSTMEMORY *instMem);


/* -> uint32_t instMemory_get(INSTMEMORY *instMem, uint64_t address)
 *
 * - DESCRIÇÃO: Retorna o valor gravado na posição de endereçamento.
 *
 * - PARÂMETROS:
 *      -> INSTMEMORY *instMem: memória de instruções.
 *      -> uint64_t address: endereço da região de memória requisitada.
 *
 * - RETORNO: valor lido da memória.
 *   	-> Se 0    - Erro na operação
 *   	-> Se != 0 - Sucesso na operação.
 */
uint32_t        instMemory_get(INSTMEMORY *instMem, uint64_t address);

#endif /* INSTMEMORY_H */
