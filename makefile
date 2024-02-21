all: StrList

StrList: Main.o StrListLib.a 
	gcc -Wall -o StrList Main.o StrListLib.a
	

Main.o: Main.c StrList.h
	gcc -c -Wall Main.c -o Main.o

StrListLib.a: StrList.o
	ar -rcs StrListLib.a StrList.o
	
StrList.o: StrList.c StrList.h
	gcc -c -Wall StrList.c -o StrList.o
	




.PHONY: clean


clean:
	-rm -f *.o *.a StrList
