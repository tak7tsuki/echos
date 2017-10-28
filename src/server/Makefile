# GNU Makefile
# /src/server

# .PHONY : setup info

TD = $(BD)/src/server
CD = $(DR)/src/server

setup:
	@echo '[ /serc/server ] >> Creating a build mirror folder.'
	mkdir $(BD)/src/server
	@echo

compile : setup $(TD)/server.o

$(TD)/server.o : server.cpp server.hpp
	@echo '[ /src/server ] >> Compiling server.cpp target_dir: $(TD)'
	$(CC) -c server.cpp -o $(TD)/server.o
	@echo

