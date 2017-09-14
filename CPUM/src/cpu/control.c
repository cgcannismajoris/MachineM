/*
* Nome do Arquivo:  control.c
*       Descricao:  Implementação do módulo Control.
*
* Control for CPUM.
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

#include "control.h"

int control_process(REGISTERBANK  *regsBank, uint8_t *inst)
{
	TYPE_R tmp;

	INSTRUCTION_SETINST(tmp, (*inst));
	
	//Se for uma instrução do tipo R.
	if(tmp.opcode >= 1 && tmp.opcode <= 22)
	{
		alu_processTypeR(regsBank, &tmp);
	}

	//Caso forem acrescentadas novas instruções futuras adicionar trechos de
	//decodificação aqui.

	//Se for uma instrução especial beqz
	else if(tmp.opcode == 56)
	{
		TYPE_ESP_BEQZ beqz;
		
		INSTRUCTION_SETINST(beqz, (*inst));
		
		alu_processBeqz(regsBank, &beqz);
	}
	
	//Tipo não reconhecido.
	else{
		cpuError_setDesc(CONTROL_EUKNOWINSTRUCTION_MSG);
		return CONTROL_EUKNOWINSTRUCTION;
	}

    return 0;
}
