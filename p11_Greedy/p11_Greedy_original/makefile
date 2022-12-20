# https://stackoverflow.com/questions/2214575/passing-arguments-to-make-run

MAIN_FILE = $(cliente)cya-P11-Greedy.cc
SRC_FILES = $(alfabeto)alfabeto.cc $(amount)amount.cc
EXECUTABLE_FILE = $(exe)p11_Greedy
ERROR_FILE = $(error)error.txt

# If the first argument is "run"...
ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

#./$(EXECUTABLE_FILE) $(FILE_IN) $(RUN_ARGS) &> $(ERROR_FILE)

default: 
	g++ -std=c++14 -g -Wall -o $(EXECUTABLE_FILE) $(MAIN_FILE) $(SRC_FILES)

run:
	./$(EXECUTABLE_FILE) $(FILE_IN) $(RUN_ARGS)

clean:
	rm $(EXECUTABLE_FILE)
	rm $(ERROR_FILE)