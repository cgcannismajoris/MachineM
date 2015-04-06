# Makefile
#
# Makefile of MachineM.
# Copyright (C) 2015  Cristian Costa Mello and Gustavo Freitas de Amorim
#
# MachineM is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# MachineM is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
# ******************************************************************************
#
# ENTRADAS:
#	1. make all ou make: Compila o projeto;
#
#	2. make clean: limpa o projeto.


# DEFINIÇÕES PARA COMPILAÇÃO #################
COMPILER 		= gcc
CFLAG 			= -c
LFLAG 			= -o
LIBFLAG 		=


IMAIN_SRC = src/imain.c
IMAIN_OBJ = obj/imain.o


# BINÁRIO DO MACHINEM ###########################
MACHINEM_OUTPUT_NAME_EXEC		= MachineM
MACHINEM_OUTPUT_FULLPATH_EXEC	= bin/$(MACHINEM_OUTPUT_NAME_EXEC)

ASSEMBLERM_OUTPUT_NAME_EXEC		= AssemblerM
ASSEMBLERM_OUTPUT_FULLPATH_EXEC	= \
	$(ASSEMBLERM_OUTPUT_NAME_EXEC)/bin/$(ASSEMBLERM_OUTPUT_NAME_EXEC)

CPUM_OUTPUT_NAME_EXEC			= CPUM
CPUM_OUTPUT_FULLPATH_EXEC		= \
	$(CPUM_OUTPUT_NAME_EXEC)/bin/$(CPUM_OUTPUT_NAME_EXEC)


BIN = $(MACHINEM_OUTPUT_FULLPATH_EXEC)
OBJ = $(IMAIN_OBJ)


all: mk_dir ASSEMBLERM_MAKE CPUM_MAKE $(BIN) LN_SYMBOL_MACHINEM
	@echo "Sucesso na compilação do MachineM."

mk_dir:
	mkdir -p bin obj

ASSEMBLERM_MAKE:
	cd AssemblerM && make

CPUM_MAKE:
	cd CPUM && make

LN_SYMBOL_MACHINEM:
	rm -f $(MACHINEM_OUTPUT_NAME_EXEC)
	ln -s $(MACHINEM_OUTPUT_FULLPATH_EXEC)

$(IMAIN_OBJ): $(IMAIN_SRC)
	gcc -c $(IMAIN_SRC) -o $(IMAIN_OBJ)

$(BIN): $(OBJ)
	$(COMPILER) $(LFLAG) $(BIN) $(OBJ) $(LIBFLAG)

clean:
	cd AssemblerM && make clean
	cd CPUM && make clean
	rm -f *~ *.swp *.swo $(MACHINEM_OUTPUT_FULLPATH_EXEC) $(MACHINEM_OUTPUT_NAME_EXEC) $(OBJ)
	@echo "MachineM foi limpo."
