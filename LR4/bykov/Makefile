TARGET = lr4
PREFIX = /lr4

.PHONY: all clean install uninstall

all: $(TARGET)	
	
clean:
	rm -rf $(TARGET) *.o
main.o: main.cpp
	g++ -c -o main.o main.cpp
BTree.o: BTree.cpp
	g++ -c -o BTree.o BTree.cpp
$(TARGET): main.o BTree.o
	g++ -o $(TARGET) main.o BTree.o
install:
	install $(TARGET) $(PREFIX)
uninstall:
	rm -rf $(PREFIX)/$(TARGET)

