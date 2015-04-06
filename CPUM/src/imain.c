/*
 * Nome do Arquivo:  imain.c
 *       Descrição:  Interface da CPUM. Aqui será fornecido recursos
 *                   de linha de comando para entrada feita pelo usuário.
 *
 * Main file of CPUM.
 * Copyright (C) 2015  Cristian Costa Mello and Gustavo Freitas de Amorim
 *
 * This is part of CPUM
 * CPUM is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * AssemblerM is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "cpuError.h"
#include "cpu/cpu.h"
#include "inputSystem/inputSystem.h"
#include "instruction/instruction.h"


int main(int argc, char **argv)
{
	CPU *cpu;
	
	//Se apenas invocou o programa, exibe ajuda
    if(argc == 1)
    {
        fprintf(stdout, "\nCPUM.\n");
        fprintf(stdout, "Copyright (C) 2015  Cristian Costa Mello and \
                Gustavo Freitas de Amorim.\n\n");
        fprintf(stdout, "Linha de comando:\n");
        fprintf(stdout, "    CPUM <NOME_DO_ARQUIVO_DE_ENTRADA> \
                <NOME_DO_ARQUIVO_DE_SAIDA>\n\n");
        fprintf(stdout, "Descrição dos argumentos:\n");
        fprintf(stdout, "   <NOME_DO_ARQUIVO_DE_ENTRADA>\t: é o arquivo \
                binário compatível com a CPUM;\n");
        fprintf(stdout, "   <NOME_DO_ARQUIVO_DE_SAIDA>\t: é o arquivo de texto \
                de saída.\n\n");

        return EXIT_SUCCESS;
    }
	
	//Se a quatidade de argumentos for inválida	
    if (argc < 3 || argc > 3)
    {
        fprintf(stdout, "Linha de comando inválida. Invoque o programa sem \
                argumentos para mais informações.\n");
        return EXIT_FAILURE;
    }
	
	//Instancia o sistema de erros
    if ((cpuError_new(CPUERROR_FAILUREDESCLENGTH)) == NULL)
    {
        fprintf(stderr, "CPU: %s\n", CPUERROR_EALLOC_MSG);
        return EXIT_FAILURE;
    }

	//Instancia uma nova CPU
	if((cpu = cpu_new(1)) == CPU_EALLOC)
	{
		fprintf(stderr, "CPU: %s\n", cpuError_getDesc());
		return EXIT_FAILURE;
	}

	//Executa o programa
	//Se resultar em erro, exibe a mensagem
	if(cpu_start(cpu, argv[1], argv[2]) == CPU_ERROR)
	{
		fprintf(stderr, "CPU: %s\n", cpuError_getDesc());
		return EXIT_FAILURE;
	}
	//Se não, exibe sucesso
	else
	{
		printf("Programa executado com sucesso! =D\n");
	}

	//Desaloca regiões de memória que não serão mais utilizadas
	cpu_free(cpu);
    cpuError_free();
	
	//Retorna sucesso
	return EXIT_SUCCESS;
}
