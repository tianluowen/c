CC=clang
OBJ=exe
RM=rm -f

all:$(OBJ) horizon

$(OBJ):main.o
	$(CC) $^ -o $@

main.o:main.c
	$(CC) -c $^ -o $@ $(debug)

horizon:mainhorizon.o
	$(CC) $^ -o $@

mainhorizon.o:mainhorizon.c
	$(CC) -c $^ -o $@ $(debug)

clean:
	$(RM) *.o $(OBJ) horizon
