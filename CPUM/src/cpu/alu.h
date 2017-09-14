/*
 * Nome do Arquivo:  alu.h
 *       Descricao:  TAD para processamento das instruções da máquina.
 *
 * Exported functions from alu.c.
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

#ifndef ALU_H
#define ALU_H

#include "../instruction/instruction.h"
#include "../registerBank/registerBank.h"


/* -> void alu_processTypeR(REGISTERBANK *regsBank, TYPE_R *inst)
 *
 * - DESCRIÇÃO: Processa a instrução do tipo R.
 *
 * - PARÂMETROS:
 *      -> REGISTERBANK *regsBank: Banco de registradores.
 *      -> TYPE_R *inst: instrução do tipo R.
 *
 * - RETORNO: void
 */
void 		alu_processTypeR(REGISTERBANK *regsBank, TYPE_R *inst);

/* -> void alu_processBeqz(REGISTERBANK *regsBank, TYPE_ESP_BEQZ *inst)
 *
 * - DESCRIÇÃO: Processa a instrução de teste de zero.
 *
 * - PARÂMETROS:
 *      -> REGISTERBANK *regsBank: Banco de registradores.
 *      -> TYPE_ESP_BEQZ *inst: instrução beqz.
 *
 * - RETORNO: void
 */
void 		alu_processBeqz(REGISTERBANK *regsBank, TYPE_ESP_BEQZ *inst);

#endif
