# GNU Makefile

export PROGRAM_NAME     = echos
export VERSION          = 0.0 
 
export BD = $(CURDIR)/build
export DFLAGS = -g -Wall 
export LFLAGS = -std=c++11 
export CC = clang++ $(DFLAGS) $(LFLAGS)

.PHONY : clean help install compile_subdirectories

help:
	@echo
	@echo  *--------------------------------------------*
	@echo  echos v: $(VERSION)
	@echo The shell in use is $(SHELL).
	@echo Available options are: install, clean and help
	@echo   '> install: installs the mantra facility'
	@echo   '> clean: cleans the builds'
	@echo   '> help: prints out this help'
	@echo *---------------------------------------------*
	@echo

echos: main.o

install:
	@echo ToDo: Make install instructions

compile:
	@echo Run the subdirectories..
	$(MAKE) -C src compile
	$(CC) -lpthread $(BD)/src/main.o $(BD)/src/server/server.o -o $(BD)/echos
	$(CC) $(BD)/src/client_main.o $(BD)/src/client/client.o -o $(BD)/echos_client

clean: 
	@echo Cleaning build directories
	rm -rf build/*
