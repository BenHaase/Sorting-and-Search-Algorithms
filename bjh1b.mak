bjh1b:bjh1b.o
	g++ -o bjh1b bjh1b.o
bjh1b.o:bjh1b.cpp
	g++ -c bjh1b.cpp
clean:
	/bin/rm -f bjh1b bjh1b.o
