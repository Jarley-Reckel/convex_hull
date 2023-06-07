CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o

HDRS = $(INC)/readExpression.hpp

CFLAGS = -Wall -c -I$(INC) -g

EXE = $(BIN)/main

all: $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp  $(LIBS)


clean:
	rm -f $(EXE) $(OBJS)