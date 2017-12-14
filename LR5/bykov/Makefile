TARGET = lr5
PREFIX = /lr5

.PHONY: all clean install uninstall

all: $(TARGET)	
	
clean:
	rm -rf $(TARGET) *.o
main.o: main.cpp
	g++ -std=c++11 -Wall -Wpedantic -Werror -c -o main.o main.cpp
CodeTree.o: CodeTree.cpp
	g++ -std=c++11 -Wall -Wpedantic -Werror -c -o CodeTree.o CodeTree.cpp
fh.o: fh.cpp
	g++ -std=c++11 -Wall -Wpedantic -Werror -c -o fh.o fh.cpp
$(TARGET): main.o CodeTree.o fh.o
	g++ -o $(TARGET) main.o CodeTree.o fh.o -lm -lpthread 
install:
	install $(TARGET) $(PREFIX)
uninstall:
	rm -rf $(PREFIX)/$(TARGET)

