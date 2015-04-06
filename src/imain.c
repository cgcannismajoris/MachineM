/*
 * Main file of MachineM.
 * Copyright (C) 2015  Cristian Costa Mello and Gustavo Freitas de Amorim
 *
 * MachineM is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MachineM is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define ASSEMBLER_CALL		"./AssemblerM/bin/AssemblerM"
#define ASSEMBLER_DIC		"AssemblerM/data/dic_m.dic"
#define ASSEMBLER_EXIT_FILE	"tmp.cpum"

#define CPU_CALL			"./CPUM/bin/CPUM"
#define CPU_INPUT_FILE		ASSEMBLER_EXIT_FILE

int call_assembler(int argc, char **argv);
int call_cpu(char *outputFile);
int call_program(char *program_name, char **argv);

int main(int argc, char **argv)
{
	//Se a quantidade de argumentos for insuficiente...
	if(argc == 1)
	{
		printf("\nMachineM\n");
		printf("Copyright (C) 2015 Cristian Costa Mello and Gustavo \
Freitas de Amorim\n\n");
		printf("Linha de Comando:\n");
		printf("MachineM <NOME_DO_ARQUIVO_DE_ENTRADA> \
<NOME_DO_ARQUIVO_DE_SAIDA> <arg1> <arg2> ... <argn>\n\n");
		printf("Descrição dos Argumentos:\n");
		printf("   <NOME_DO_ARQUIVO_DE_ENTRADA> : é um arquivo de \
texto codificado no padrão ANSI ASCII;\n");
		printf("   <NOME_DO_ARQUIVO_DE_SAIDA>   : é um arquivo de texto \
contendo a função computada;\n");
		printf("   <arg1> <arg2> ... <argn>     : os valores numéricos 	\
naturais inteiros para configurar os valores iniciais\n");
		printf("                                  dos registradores de \
entrada declarados no cabeçalho do arquivo de texto\n");
		printf("                                  de entrada.\n\n");
		return (EXIT_SUCCESS);
	}
	else if(argc < 4)
	{
		printf("Linha de comando inválida. Invoque o programa sem argumentos \
para mais informações.\n");
		return (EXIT_FAILURE);
	}
		
	//Realiza a montagem do código	
	printf("Montando programa...\n");
	if(call_assembler(argc, argv) != EXIT_SUCCESS)
	{
		//Apaga o arquivo binário que foi executado pela CPU
		remove(CPU_INPUT_FILE);
		
		//Exibe o erro	
		printf("MACHINEM: Não é possível continuar.\n");

		return (EXIT_FAILURE);
	}

	//Executa o código
	printf("\nExecutando programa...\n");	
	if(call_cpu(argv[2]) != EXIT_SUCCESS)
	{
		//Apaga o arquivo binário que foi executado pela CPU
		remove(CPU_INPUT_FILE);
	
		//Exibe o erro
		printf("MACHINEM: Erro na execução do programa.\n");

		return (EXIT_FAILURE);
	}

	//Apaga o arquivo binário que foi executado pela CPU
	remove(CPU_INPUT_FILE);

	//Retorna sucesso
    return (EXIT_SUCCESS);
}

int call_assembler(int argc, char **argv)
{
	int i;
	char **argvAssembler;
	int argcAssembler = argc + 2;
	char *dicFile = {ASSEMBLER_DIC};
	char *binaryFile = {ASSEMBLER_EXIT_FILE};

	//Aloca o vetor de argumentos para o montador
	argvAssembler = (char**)malloc(sizeof(char*) * (argcAssembler));
	
	//Referencia a chamada do programa	
	argvAssembler[0] = (char*)malloc(strlen(ASSEMBLER_CALL) + 1);
	strcpy(argvAssembler[0], ASSEMBLER_CALL);

	//Referencia o arquivo de entrada (código fonte)
	argvAssembler[1] = argv[1];
	
	//Referencia o arquivo de saida do montador
	argvAssembler[2] = binaryFile;

	//Referencia o dicionário
	argvAssembler[3] = dicFile;
	
	//Referencia a lista de argumentos de entrada
	//(valores iniciais dos registradores de entrada)
	for(i = 4; i < argcAssembler - 1; i++)
		argvAssembler[i] = argv[i - 1];

	//Necessário para call_program(...)
	argvAssembler[argcAssembler-1] = NULL;
	
	return (call_program(argvAssembler[0], argvAssembler));
}

int call_cpu(char *outputFile)
{
	char *argvCpu[4];

	//Referencia o nome do programa
	argvCpu[0] = (char*)malloc(sizeof(char) * strlen(CPU_CALL));
	strcpy(argvCpu[0], CPU_CALL);

	//Referencia o arquivo de entrada	
	argvCpu[1] = (char*)malloc(sizeof(char) * strlen(ASSEMBLER_EXIT_FILE));
	strcpy(argvCpu[1], CPU_INPUT_FILE);

	//Referencia o arquivo de saída da CPU (função computada)	
	argvCpu[2] = outputFile;

	//Necessário para call_program(...)
	argvCpu[3] = NULL;

	return (call_program(argvCpu[0], argvCpu));
}

int call_program(char *program_name, char **argv)
{
	pid_t 	pid;
	int 	status = 0;

	//Inicia o processo filho
	//Se iniciou com sucesso
	if((pid = fork()) == 0)
	{
		char *_envp[] = { NULL };

		status = execve(program_name, argv, _envp);

		exit(status);
	}
	//Se não iniciou com sucesso
	else if(pid == -1)
	{
		char str[256 + 31];
		snprintf(str, 256 + 31, "Erro ao iniciar %s\nResultado: ", program_name);		
	
		//Exibe o erro	
		perror(str);
		
		//Retorna erro
		return (EXIT_FAILURE);
	}
	
	//Processo pai:
	//Se não obter resposta do filho
	if(waitpid(pid, &status, 0) < 0)
	{
		char str[256 + 31];
		snprintf(str, 256 + 31, "Sem resposta de %s\nResultado: ", program_name);

		//Exibe o erro	
		perror(str);

		//Retorna erro
		return (EXIT_FAILURE);
	}
	
	//Testa a saída do filho
	if(WIFEXITED(status))
	{
		//Retorna o resultado do filho
		return (WEXITSTATUS(status));
	}
	
	return (EXIT_FAILURE);
}
