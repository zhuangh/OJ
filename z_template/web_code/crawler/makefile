CFLAGS = -Wall -g -lcurl -lhtmlcxx

crawler: crawler.o
	g++ -o $@ crawler.o $(CFLAGS) 

crawler.o: crawler.cpp
	g++ -c crawler.cpp
