OBJ=exe

all:$(OBJ)

$(OBJ):main.o
	@gcc $^ -o $@

main.o:main.c
	@gcc -c $^ -o $@ $(debug) -std=c99

clean:
	@rm -f *.o $(OBJ)
