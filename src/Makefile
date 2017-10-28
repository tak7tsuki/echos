# GNU Makefile
# /src

TD = $(BD)/src

.PHONY : compile compile_submodules

compile : compile_submodules $(TD)/main.o $(TD)/client_main.o

compile_submodules : 
	@echo /src create build mirror
	mkdir $(BD)/src
	@echo /src running subsdirectories 
	$(MAKE) -C server compile
	$(MAKE) -C client compile

$(TD)/main.o : main.cpp
	$(CC) -c main.cpp -o $(TD)/main.o

$(TD)/client_main.o : client_main.cpp
	$(CC) -c client_main.cpp -o $(TD)/client_main.o
