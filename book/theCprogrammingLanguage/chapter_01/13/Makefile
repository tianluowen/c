OBJ=exe

all:$(OBJ) horizon

$(OBJ):main.o
	@gcc $^ -o $@

main.o:main.c
	@gcc -c $^ -o $@ $(debug)

horizon:mainhorizon.o
	@gcc $^ -o $@

mainhorizon.o:mainhorizon.c
	@gcc -c $^ -o $@ $(debug)

clean:
	@rm -f *.o $(OBJ) horizon
