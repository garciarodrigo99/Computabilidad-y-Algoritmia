# https://stackoverflow.com/questions/2214575/passing-arguments-to-make-run

MAIN_FILE = $(cliente)cya-P02-Languages.cc
SRC_FILES = $(alfabeto)alfabeto.cc $(cadena)cadena.cc $(lenguaje)lenguaje.cc $(simbolo)simbolo.cc
EXECUTABLE_FILE = $(exe)cya-P02-Languages

# If the first argument is "run"...
ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

default: 
	g++ -std=c++14 -g -Wall -o $(EXECUTABLE_FILE) $(MAIN_FILE) $(SRC_FILES)

run:
	./$(EXECUTABLE_FILE) $(FILE_IN) $(RUN_ARGS)