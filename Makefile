
all : wirecow

wirecow : wirecow.o
	gcc -o wirecow wirecow.o -lpcap

wirecow.o : wirecow.c
	gcc -c -o wirecow.o wirecow.c -lpcap

clean :
	rm *.o wirecow

