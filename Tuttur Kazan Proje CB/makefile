all: Kisi.o Dosya.o Oyun.o Test.o program run
	@echo "Derleme Tamamlandi"
	
Kisi.o: ./include/Kisi.h ./src/Kisi.c
	gcc -c ./src/Kisi.c -o ./lib/Kisi.o 

Dosya.o:./include/Dosya.h ./src/Dosya.c ./include/Kisi.h 
	gcc -c ./src/Dosya.c -o ./lib/Dosya.o 

Oyun.o: ./include/Oyun.h ./src/Oyun.c ./include/Kisi.h ./include/Dosya.h 
	gcc -c ./src/Oyun.c -o ./lib/Oyun.o 

Test.o: ./include/Test.h ./src/Test.c ./include/Kisi.h ./include/Dosya.h ./include/Oyun.h 
	gcc -c ./src/Test.c -o ./lib/Test.o

program: ./lib/Kisi.o ./lib/Dosya.o ./lib/Oyun.o ./lib/Test.o
	gcc ./lib/Kisi.o ./lib/Dosya.o ./lib/Oyun.o ./lib/Test.o -o ./bin/program

run:
	./bin/program
