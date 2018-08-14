CC = g++
CFLAGS = -I -Wall
OBJ = QuickSort3.o closest.o
INC = closest.h

%.o: %.cpp $(INC)
	$(CC) -c $<

closest: $(OBJ)
	$(CC) -o $@ $^	
	
clean:
	rm $(OBJ)