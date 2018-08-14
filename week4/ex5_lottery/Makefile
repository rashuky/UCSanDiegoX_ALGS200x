CC = g++
CFLAGS = -I -Wall
OBJ = QuickSort3.o MergeSort.o lottery.o
INC = lottery.h

%.o: %.cpp $(INC)
	$(CC) -c $<

lottery: $(OBJ)
	$(CC) -o $@ $^	
	
clean:
	rm $(OBJ)