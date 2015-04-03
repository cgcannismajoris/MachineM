# MachineM
Projeto de simulação da Máquina de Registradores - uma Máquina Turing-compatível (Universal).

##Objetivo do Projeto
Realiza a simulação da Máquina de Registradores, por meio de duas tarefas principais:

  1. A partir de um arquivo de texto de entrada, escrito em Assembly M, monta-se o binário compatível
     com a CPUM, uma componente executora;
  
  2. Após a execução do binário montado para a CPUM, há a geração da função computada em um arquivo
     de texto.

##Procedimento de compilação do MachineM (via Terminal)
Estando-se na pasta pai do projeto ("/MachineM"), realize o comando abaixo:

	$ make

##Procedimentos de utilização (via Terminal)
Através de um terminal de comando do Linux, observa-se o formato de entrada abaixo:

	$ ./MachineM <NOME_DO_ARQUIVO_DE_ENTRADA> <NOME_DO_ARQUIVO_DE_SAIDA> <arg1> <arg2> ... <argn>
	
	ENTRADA: 
	<NOME_DO_ARQUIVO_DE_ENTRADA> : é um arquivo de texto codificado no padrão ANSI ASCII;
	
	<NOME_DO_ARQUIVO_DE_SAIDA>   : é um arquivo de texto contendo a função computada;
	
	<arg1> <arg2> ... <argn>     : os valores numéricos naturais para configurar os valores iniciais
	                               dos registradores de entrada declarados no cabeçalho do arquivo de texto
	                               de entrada.

Se a execução for bem-sucedida, então será gerado o arquivo de texto contendo a função computada, a rigor de análise.
