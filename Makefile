toDoList: driver.o
	g++ -o toDoList driver.o

drvier.o: driver.cpp toDo.h
	g++ -c driver.cpp

clean:
	rm *.o toDoList