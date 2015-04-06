/*
 * Nome do Arquivo:  cpu.h
 *       Descricao:  TAD principal da máquina.
 *
 * Exported functions from cpu.c.
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

#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <unistd.h>

#include "../inputSystem/inputSystem.h"     /* incluir o TAD INPUTSYSTEM */
#include "../outputSystem/outputSystem.h"	/* incluir o TAD OUTPUTSYSTEM  */
#include "../registerBank/registerBank.h"   /* incluir o TAD REGISTERBANK */
#include "control.h"                        /* incluir o módulo de controle */
#include "alu.h"                            /* incluir o módulo de ALU. */

#define CPU_EALLOC          NULL
#define CPU_EALLOC_MSG      "Falha ao alocar memória para a CPU."

#define CPU_FINISH			0
#define CPU_END				1
#define CPU_ERROR			-1

typedef struct _cpu
{
    uint32_t        ticksPerSecond; // quantidade de ticks por segundo 
    REGISTERBANK *  regsBank;       // banco de registradores
	INPUTSYSTEM *	input;          // sistema de entrada
	OUTPUTSYSTEM *	output;         // sistema de saída
} CPU;


/* -> CPU *cpu_new(uint32_t ticks)
 * 
 * - DESCRIÇÃO: Instancia uma nova estrutura em memória.
 *
 * - PARÂMETROS: 
 *      -> uint32_t ticks: Quantidade de ticks por segundo.
 *
 * - RETORNO: Estrutura do tipo CPU instanciada.
 *   	-> Se NULL    - Erro na operação.
 *   	-> Se != NULL - Sucesso na operação.
 */
CPU *   	cpu_new(uint32_t ticks);


/* -> void cpu_free(CPU *cpu)
 * 
 * - DESCRIÇÃO: Destrói uma estrutura existente em memória.
 *
 * - PARÂMETROS: 
 *      -> CPU *cpu: Estrutura a ser destruída.
 *
 * - RETORNO: void.
 */
void 		cpu_free(CPU *cpu);


/* -> int cpu_start(CPU *cpu, const char *input, const char *output)
 * 
 * - DESCRIÇÃO: Incializa a CPU, fazendo com que o programa seja processado.
 *
 * - PARÂMETROS: 
 *      -> CPU *cpu: CPU a ser utilizada.
 *      -> const char *input: Programa a ser processado.
 *      -> const char *output: Arquivo a receber a função computada.
 *
 * - RETORNO: Estado da execução.
 *      -> Se 0    - Sucesso.
 *      -> Se != 0 - Erro.
 */
int     	cpu_start(CPU *cpu, const char *input, const char *output);


/* -> int cpu_clock(CPU *cpu)
 * 
 * - DESCRIÇÃO: Realiza um clock na CPU (processa uma única instrução).
 *
 * - PARÂMETROS: 
 *      -> CPU *cpu: CPU a ser utilizada.
 *
 * - RETORNO: Estado da operação.
 *      -> Se 0    - Sucesso.
 *      -> Se != 0 - Erro.
 */
int     	cpu_clock(CPU *cpu);

#endif
