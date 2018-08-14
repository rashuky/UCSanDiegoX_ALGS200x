CC = g++
CFLAGS = -I -Wall
OBJ = MergeSort.o QuickSort3.o stressTest.o
INC = stressTest.h

%.o: %.cpp $(INC)
	$(CC) -c $<

clean:
	rm $(OBJ)
