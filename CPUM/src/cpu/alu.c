/*
 * Nome do Arquivo:  alu.c
 *       Descricao:  Implementação do módulo ALU.
 *
 * ALU for CPUM.
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

#include "alu.h"

void alu_processTypeR(REGISTERBANK *regsBank, TYPE_R *inst)
{
	uint32_t tmpResult;

	switch(inst->opcode)
	{	
		//Soma com imediate
		case 1:
			tmpResult = registerBank_getRegister(regsBank, inst->reg);
			tmpResult++;
			registerBank_setRegister(regsBank, inst->reg, tmpResult);
			break;
		
		//Subtração com imediate
		case 2:
			tmpResult = registerBank_getRegister(regsBank, inst->reg);
			tmpResult--;
			registerBank_setRegister(regsBank, inst->reg, tmpResult);
			break;
	}

	registerBank_pcAdd(regsBank, inst->address);
}

void alu_processBeqz(REGISTERBANK *regsBank, TYPE_ESP_BEQZ *inst)
{
	if(registerBank_getRegister(regsBank, inst->reg) == 0)
	{
		registerBank_pcAdd(regsBank, inst->address_t);
	}
	else
	{
		registerBank_pcAdd(regsBank, inst->address_f);
	}
}

