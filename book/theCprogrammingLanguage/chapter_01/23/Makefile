CC=clang
RM=rm -f
OBJ=exe

all:$(OBJ)

$(OBJ):main.o
	$(CC) $^ -o $@

main.o:main.c
	$(CC) -c $^ -o $@ $(debug)

clean:
	$(RM) *.o $(OBJ)
