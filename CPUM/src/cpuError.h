/*
 * Nome do Arquivo:  cpuError.h
 *       Descricao:  Módulo de tratamento de erro.
 *
 * Exported functions from cpuError.c.
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


#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define CPUERROR_FAILUREDESCLENGTH      120
#define CPUERROR_EALLOC_MSG             "Falha ao alocar memória para CPUERROR."

 /* -> char *cpuError_new(uint32_t desc)
 * 
 * - DESCRIÇÃO: Instancia uma nova string para armazenamento de erros.
 *
 * - PARÂMETROS: 
 *      -> uint32_t desc: Tamanho da string a ser alocada.
 *
 * - RETORNO: String alocada para armazenar o erro.
 *   	-> Se NULL    - Erro na operação.
 *   	-> Se != NULL - Sucesso na operação.
 */
char *   cpuError_new(uint32_t desc);


/* -> void cpuError_free()
 * 
 * - DESCRIÇÃO: Destrói a string.
 *
 * - PARÂMETROS: void.
 *
 * - RETORNO: void.
 */
void     cpuError_free();


/* -> void cpuError_setDesc(const char *failureDesc)
 * 
 * - DESCRIÇÃO: Seta a mensagem a ser armazenada pela string de erros.
 *
 * - PARÂMETROS: 
 *      -> const char *failureDesc: Mensagem a ser gravada. 
 *
 * - RETORNO: void.
 */
void     cpuError_setDesc(const char *failureDesc);


/* -> char *cpuError_getDesc()
 * 
 * - DESCRIÇÃO: Retorna o ponteiro para a string de erros.
 *
 * - PARÂMETROS: void. 
 *
 * - RETORNO: Ponteiro para a string.
 */
char *   cpuError_getDesc();

