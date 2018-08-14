CC = g++
CFLAGS = -I -Wall
OBJ = QuickSort3.o MergeSort.o stressTest.o
INC = stressTest.h

%.o: %.cpp $(INC)
	$(CC) -c $<

stressTest: $(OBJ)
	$(CC) -o $@ $^	
	
clean:
	rm $(OBJ)
