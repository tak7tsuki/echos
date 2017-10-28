# GNU Makefile
# /src/client

# .PHONY : setup info

TD = $(BD)/src/client
CD = $(DR)/src/client

setup:
	@echo '[ /serc/client ] >> Creating a build mirror folder.'
	mkdir $(BD)/src/client
	@echo

compile : setup $(TD)/client.o

$(TD)/client.o : client.cpp client.hpp
	 @echo '[ /src/client ] >> Compiling client.cpp target_dir: $(TD)'
	$(CC) -c client.cpp -o $(TD)/client.o
	@echo

