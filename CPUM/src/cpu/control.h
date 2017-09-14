/*
 * Nome do Arquivo:  control.h
 *       Descricao:  Módulo da unidade de controle.
 *
 * Exported functions from control.c.
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

#ifndef CONTROL_H
#define CONTROL_H

#include "../instruction/instruction.h"
#include "alu.h"

#define CONTROL_EUKNOWINSTRUCTION		-1
#define CONTROL_EUKNOWINSTRUCTION_MSG 	"Instrução não reconhecida."


/* -> int control_process(REGISTERBANK *regsBank, uint8_t *inst)
 *
 * - DESCRIÇÃO: decodifica a instrução e ordena a ALU processar.
 *
 * - PARÂMETROS:
 *      -> REGISTERBANK *regsBank: Banco de registradores.
 *      -> uint8_t *inst: instrução.
 *
 * - RETORNO: estado do processamento
 *   	-> Se 0    - Sucesso na operação
 *   	-> Se != 0 - Erro na operação.
 */
int         control_process(REGISTERBANK *regsBank, uint8_t *inst);

#endif
