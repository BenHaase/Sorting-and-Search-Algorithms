bjhB2:bjhB2.o
	g++ -o bjhB2 bjhB2.o
bjhB2.o:bjhB2.cpp
	g++ -c bjhB2.cpp
clean:
	/bin/rm -f bjhB2 bjhB2.o
