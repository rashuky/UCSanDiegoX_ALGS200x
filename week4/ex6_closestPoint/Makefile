CC = g++
CFLAGS = -I -Wall
OBJ = QuickSort3.o MergeSort.o closestPoint.o
INC = closestPoint.h

%.o: %.cpp $(INC)
	$(CC) -c $<

closestPoint: $(OBJ)
	$(CC) -o $@ $^	
	
clean:
	rm $(OBJ)