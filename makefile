#---------------------------------------
#Students Name: Tarik unal
#Assignment 2
#Lab Section: cmpt-201-x02
#Lab Instructors Name: DR. Mees
#Lecture Instructors Name: Dr. Elmorsy
#--------------------------------------------


CC = gcc
CFLAGS = -Wall -ansi -std=c99

all: pcode htTest

ht.o: ht.c ht_implement.h ht.h
	$(CC) $(CFLAGS) -c ht.c

ht_implement.o: ht_implement.c ht.h
	$(CC) $(CFLAGS) -c ht_implement.c

htTest: htTest.o ht.o ht_implement.o
	$(CC) $(CFLAGS) htTest.o ht.o ht_implement.o -o htTest -lm

htTest.o:
	$(CC) $(CFLAGS) -c htTest.c

pcode: pcode.o ht.o ht_implement.o
	$(CC) $(CFLAGS) pcode.o ht.o ht_implement.o -o pcode -lm

pcode.o: pcode.c ht.h
	$(CC) $(CFLAGS) -c pcode.c

.PHONY: clean
tar:
	tar -czvf ../A2.tar.gz -C .. A2

clean:
	rm -f *.o htTest pcode
