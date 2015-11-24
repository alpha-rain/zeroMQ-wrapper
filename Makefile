#sudo apt-get install g++-4.8
CC=g++-4.8
#clang++
CFLAGS=-c -g -Wall -std=c++0x 
#-Wc++11-extensions
#-I./  
LDFLAGS= -O3 -lzmq 
#-lboost_system
SOURCES= main.cpp  coms.cpp
OBJECTS=$(SOURCES:.cpp=.o)                                                                           
EXECUTABLE=run

all:$(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS)  -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	
clear:
	rm -rf *.o
	


