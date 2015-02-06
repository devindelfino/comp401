OBJECTS = driver.o binomial_heap.o linked_list.o node.o

#targets-----------------------------
binomial_heap:	$(OBJECTS)
				g++ $(OBJECTS) -o binomial_heap

clean:
	rm *.o

#dependencies
driver.o:	binomial_heap.h
binomial_heap.o:	binomial_heap.h
linked_list.o:	linked_list.h node.h	
node.o:	linked_list.h node.h	
