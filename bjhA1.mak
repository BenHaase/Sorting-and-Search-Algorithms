bjhA1:bjhA1.o
	g++ -o bjhA1 bjhA1.o
bjhA1.o:bjhA1.cpp
	g++ -c bjhA1.cpp
clean:
	/bin/rm -f bjhA1 bjhA1.o
