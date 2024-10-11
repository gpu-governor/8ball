CC = gcc
FILE = main.c
EXE = main
WIN_RAYLIB = -lraylib -lopengl32 -luser32 -lkernel32 -lwinmm -lgdi32
UNIX_RAYLIB = -lraylib -lGL -lpthread -ldl -lrt -lX11
STD = -lm

all: $(EXE)

$(EXE): $(FILE)
	$(CC) $(FILE) -o $(EXE) $(WIN_RAYLIB) $(STD)

clean:
	rm -f $(EXE)
