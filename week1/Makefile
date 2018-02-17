CC = g++
CFLAGS = -Wall -I
INC = stressTest.h
OBJ = VecmaxPairWiseNaive.o VecmaxPairWiseFast.o stressTest.o

%.o: %.cpp $(INC)
	$(CC) -c -o $@ $< 

stressTest: $(OBJ)
	$(CC) -o $@ $^

clean: 
	rm $(OBJ)
