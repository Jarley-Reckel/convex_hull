CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o   \
       $(OBJ)/mainFunctions.o   \
       $(OBJ)/sortingAlgorithms.o   \
	   $(OBJ)/structs.o   \
	   $(OBJ)/types.o   \

HDRS = $(INC)/mainFunctions.hpp   \
       $(INC)/sortingAlgorithms.hpp   \
	   $(INC)/structs.hpp   \
	   $(INC)/types.hpp   \

CFLAGS = -Wall -c -I$(INC) -g

EXE = $(BIN)/main

all: $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp  $(LIBS)

$(OBJ)/mainFunctions.o: $(HDRS) $(SRC)/mainFunctions.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/mainFunctions.o $(SRC)/mainFunctions.cpp  $(LIBS)

$(OBJ)/sortingAlgorithms.o: $(HDRS) $(SRC)/sortingAlgorithms.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/sortingAlgorithms.o $(SRC)/sortingAlgorithms.cpp  $(LIBS)

$(OBJ)/structs.o: $(HDRS) $(SRC)/structs.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/structs.o $(SRC)/structs.cpp  $(LIBS)

$(OBJ)/types.o: $(HDRS) $(SRC)/types.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/types.o $(SRC)/types.cpp  $(LIBS)


clean:
	rm -f $(EXE) $(OBJS)