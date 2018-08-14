CC = g++
CFLAGS = -I -Wall
OBJ = QuickSort3.o lotteryVector.o
INC = lotteryVector.h

%.o: %.cpp $(INC)
	$(CC) -c $<

lottery: $(OBJ)
	$(CC) -o $@ $^	
	
clean:
	rm $(OBJ)