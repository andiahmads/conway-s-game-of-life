CC = cc
LIBS = $(shell pkg-config --libs --cflags raylib)
SRC = conway-game-of-life.c
OUT = conway-game-of-life


build:
	eval cc $(OUT).c $(LIBS) -o $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)




