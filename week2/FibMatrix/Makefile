CC = g++
CFLAGS = -I - Wall
INC = stressTest.h
OBJ = fibNaive.o fibMatrix.o stressTest.o

%.o: %.cpp $(INC)
	$(CC) -c $<

stressTest: $(OBJ)
	$(CC) -o $@ $^	 

clean:
	rm $(OBJ)
