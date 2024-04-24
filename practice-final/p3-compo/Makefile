p3:	main.o Animal.o Chicken.o Egg.o
	g++ -o p3 main.o Animal.o Chicken.o  Egg.o

main.o:	main.cc Animal.h Chicken.h Egg.h
	g++ -c main.cc

Animal.o:	Animal.cc Animal.h
	g++ -c Animal.cc

Chicken.o:	Chicken.cc Chicken.h Animal.h Egg.h
	g++ -c Chicken.cc

Egg.o:	Egg.cc Egg.h
	g++ -c Egg.cc

clean:
	rm -f *.o p3
