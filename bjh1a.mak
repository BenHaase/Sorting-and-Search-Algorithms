bjh1a:bjh1a.o
	g++ -o bjh1a bjh1a.o
bjh1a.o:bjh1a.cpp
	g++ -c bjh1a.cpp
clean:
	/bin/rm -f bjh1a bjh1a.o
