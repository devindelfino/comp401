OBJECTS = driver.o BinomialHeap.o LinkedList.o Node.o

#targets-----------------------------
BinomialHeap:	$(OBJECTS)
				g++ $(OBJECTS) -o BinomialHeap

clean:
	rm *.o

#dependencies
driver.o:	BinomialHeap.h
BinomialHeap.o:	BinomialHeap.h
LinkedList.o:	LinkedList.h Node.h	
Node.o:	LinkedList.h Node.h	
