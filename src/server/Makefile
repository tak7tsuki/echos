# GNU Makefile
# /src/server

# .PHONY : setup info

TD = $(BD)/src/server
CD = $(DR)/src/server

setup:
	@echo '[ /serc/server ] >> Creating a build mirror folder.'
	mkdir $(BD)/src/server

compile : setup $(TD)/server.o $(TD)/client.o

$(TD)/server.o : server.cpp server.hpp
	@echo '[ /src/server ] >> Compiling server.cpp target_dir: $(TD)'
	$(CC) -c server.cpp -o $(TD)/server.o

$(TD)/client.o : client.cpp client.hpp
	 @echo '[ /src/server ] >> Compiling client.cpp target_dir: $(TD)'
	$(CC) -c client.cpp -o $(TD)/client.o

