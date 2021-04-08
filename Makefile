CC = gcc
MEMWATCH = -DMEMWATCH -DWM_STDIO
CFLAGS = -Wall -g $(MEMWATCH)

all: cardlist 

cardlist: cardmain.o cardlist.o card.o memwatch.o
	$(CC) $(CFLAGS) -o cardlist cardmain.o card.o cardlist.o memwatch.o

cardlist.o: cardlist.c cardlist.h card.h memwatch.h
	$(CC) $(CFLAGS) -c cardlist.c

cardmain.o: cardmain.c cardlist.h card.h
	$(CC) $(CFLAGS) -c cardmain.c

card.o : card.c card.h
	$(CC) $(CFLAGS) -c card.c

memwatch.o: memwatch.c memwatch.h
	$(CC) $(CFLAGS) -c memwatch.c

memwatch.c:
	ln -s /home/class_projects/memwatch-2.71/memwatch.c

memwatch.h:
	ln -s /home/class_projects/memwatch-2.71/memwatch.h


.PHONY: clean
clean:
	@-rm -f *.o cardlist 


solution.o:
	ln -s /home/isaacman/public_html/366/solution.o

nocoalesce.o:
	ln -s /home/isaacman/public_html/366/nocoalesce.o

