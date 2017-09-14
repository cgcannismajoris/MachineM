/*
 * Nome do Arquivo:  registerBank.h
 *       Descricao:  TAD para manipulação dos registradores disponíveis na
 *       			 máquina.
 *
 * Exported functions from registerBank.c.
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

#ifndef REGISTERBANK_H
#define REGISTERBANK_H

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "../cpuError.h"

#define REGISTERBANK_EALLOC         NULL
#define REGISTERBANK_EALLOC_MSG     "Falha ao alocar memória para o banco de registradores."


typedef struct _registerBank
{
	//Registradores de propósito geral
    int8_t *  		registers;	//Memória de registradores
    uint64_t    	length;		//Quantidade de registradores

	//Registradores de propósito específico
	const uint32_t 	zero; 		//Registrador zero (armazena apenas 0)
   	const uint32_t 	um; 		//Registrador um (armazena apenas 1)
   	uint64_t 		pc; 		//Program Counter (Armazena o número da 
								//próxima instrução)
} REGISTERBANK;


/* -> REGISTERBANK *	registerBank_new(uint8_t *mem, uint64_t length)
 * 
 * - DESCRIÇÃO: Instancia uma nova estrutura em memória.
 *
 * - PARÂMETROS: 
 *      -> uint8_t *mem: Registradores a serem armazenados.
 *      -> uint64_t length: Quantidade de registradores recebidos.
 *
 * - RETORNO: Estrutura do tipo REGISTERBANK instanciada.
 *   	-> Se NULL    - Erro na operação.
 *   	-> Se != NULL - Sucesso na operação.
 */
REGISTERBANK *	registerBank_new(uint8_t *mem, uint64_t length);


/* -> void registerBank_free(REGISTERBANK *regsBank)
 * 
 * - DESCRIÇÃO: Destrói uma estrutura existente em memória.
 *
 * - PARÂMETROS: 
 *      -> REGISTERBANK *regsBank: Estrutura a ser destruída.
 *
 * - RETORNO: void.
 */
void            registerBank_free(REGISTERBANK *regsBank);


/* -> int32_t registerBank_getRegister(REGISTERBANK *regsBank, uint64_t address)
 * 
 * - DESCRIÇÃO: Retorna o valor armazenado pelo registrador requisitado.
 *
 * - PARÂMETROS: 
 *      -> REGISTERBANK *regsBank: Banco de registradores a ser lido.
 *      -> uint64_t address: Endereço do registrador desejado.
 *
 * - RETORNO: Valor armazenado pelo registrador.
 */
int32_t         registerBank_getRegister(REGISTERBANK *regsBank, uint64_t address);


/* -> void registerBank_setRegister(REGISTERBANK *regsBank, uint64_t address, 
 *    int32_t value)
 * 
 * - DESCRIÇÃO: Seta o valor armazenado pelo registrador requisitado.
 *
 * - PARÂMETROS: 
 *      -> REGISTERBANK *regsBank: Banco de registradores a ser utilizado.
 *      -> uint64_t address: Endereço do registrador desejado.
 *      -> int32_t value: Valor a ser armazenado.
 *
 * - RETORNO: void.
 */
void            registerBank_setRegister(REGISTERBANK *regsBank, uint64_t address,
	                                         int32_t value);


/* -> void registerBank_pcAdd(REGISTERBANK *regsBank, signed int value)
 * 
 * - DESCRIÇÃO: Adiciona o valor do registrador pc (pc = pc + value).
 *
 * - PARÂMETROS: 
 *      -> REGISTERBANK *regsBank: Banco de registradores a ser utilizado.
 *      -> int32_t value: Valor a ser incrementado.
 *
 * - RETORNO: void.
 */
void 			registerBank_pcAdd(REGISTERBANK *regsBank, signed int value);


/* -> uint64_t registerBank_getPc(REGISTERBANK *regsBank)
 * 
 * - DESCRIÇÃO: Retorna o valor armazenado pelo registrador pc.
 *
 * - PARÂMETROS: 
 *      -> REGISTERBANK *regsBank: Banco de registradores a ser lido.
 *
 * - RETORNO: Valor armazenado pelo registrador pc.
 */
uint64_t		registerBank_getPc(REGISTERBANK *regsBank);


/* -> uint64_t registerBank_getLength(REGISTERBANK *regsBank)
 * 
 * - DESCRIÇÃO: Retorna a quantidade de registradores armazenados.
 *
 * - PARÂMETROS: 
 *      -> REGISTERBANK *regsBank: Banco de registradores a ser lido.
 *
 * - RETORNO: Quantidade de registradores armazenados.
 */
uint64_t		registerBank_getLength(REGISTERBANK *regsBank);

#endif
