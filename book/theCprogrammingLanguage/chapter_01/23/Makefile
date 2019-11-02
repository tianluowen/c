OBJ=exe

all:$(OBJ)

$(OBJ):main.o
	@gcc $^ -o $@

main.o:main.c
	@gcc -c $^ -o $@ $(debug)

clean:
	@rm -f *.o $(OBJ) write.c
