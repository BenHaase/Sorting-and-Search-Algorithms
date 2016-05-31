bjhB1:bjhB1.o
	g++ -o bjhB1 bjhB1.o
bjhB1.o:bjhB1.cpp
	g++ -c bjhB1.cpp
clean:
	/bin/rm -f bjhB1 bjhB1.o
