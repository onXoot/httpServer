CC = clang++
CPPFLAGS = -Wall -std=c++11
LDFLAGS  = -pthread

main : main.o http.o header.o body.o
	$(CC) $(LDFLAGS) -o $@ $^

main.o : main.cpp http.h
	$(CC) $(CPPFLAGS) -c $^
http.o : http.cpp header.h body.h
	$(CC) $(CPPFLAGS) -c $^
header.o : header.cpp
	$(CC) $(CPPFLAGS) -c $^
body.o : body.cpp
	$(CC) $(CPPFLAGS) -c $^

 
.PHONY : clean
clean :
	-rm main.o http.o header.o body.o main

