bjhA2:bjhA2.o
	g++ -o bjhA2 bjhA2.o
bjhA2.o:bjhA2.cpp
	g++ -c bjhA2.cpp
clean:
	/bin/rm -f bjhA2 bjhA2.o
