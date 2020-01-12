CC=clang
RM=rm -f
OBJ=exe exe.origin

all:$(OBJ)

exe:main.o 
	$(CC) $^ -o $@ -lm

exe.origin:main_origin.o
	$(CC) $^ -o $@ -lm

main.o:main.c
	$(CC) -c $^ -o $@ $(debug)

main_origin.o:main_origin.c
	$(CC) -c $^ -o $@ $(debug)


clean:
	$(RM) *.o $(OBJ)
