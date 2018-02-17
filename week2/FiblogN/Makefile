CC = g++
CFLAGS = -I -Wall
OBJ = fiblogN.o fibNaive.o stressTest.o
OBJM= fiblogNmodulo.o fibNaiveModulo.o stressTestModulo.o
OBJL= fiblogNlast.o fibNaiveLast.o stressTestLast.o
INC = stressTest.h
INCM = stressTestModulo.h
INCL = stressTestLast.h

%.o: %.cpp $(INC)
	$(CC) -c $<

stressTest: $(OBJ)
	$(CC) -o $@ $^	 

stressTestM: $(OBJM)
	INC = INCM
	$(CC) -o $@ $^	

stressTestL: $(OBJL)
	$(CC) -o $@ $^

clean:
	rm $(OBJ)

cleanM:
	rm $(OBJM)
