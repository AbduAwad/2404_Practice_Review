TARGETS	= p2
OBJECTS = main.o Controller.o University.o Student.o List.o View.o

all:	$(TARGETS)

p2:	$(OBJECTS)
	g++ -o p2 $(OBJECTS)

main.o:	main.cc Controller.h
	g++ -c main.cc

Controller.o:	Controller.cc Controller.h
	g++ -c Controller.cc

University.o:	University.cc University.h
	g++ -c University.cc

Student.o:	Student.cc Student.h
	g++ -c Student.cc

List.o:	List.cc List.h Student.h
	g++ -c List.cc

View.o:	View.cc View.h 
	g++ -c View.cc

clean:
	rm -f *.o p1
