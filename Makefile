create: wordfreak.o glossary.o wordparse.o
	gcc wordfreak.o glossary.o wordparse.o -o wordfreak

wordfreak: wordfreak.c
	gcc -c wordfreak.o

glossary: glossary.c
		gcc -c glossary.o

wordparse: wordparse.c
		gcc -c wordparse.o

clean:
	rm *.o wordfreak
