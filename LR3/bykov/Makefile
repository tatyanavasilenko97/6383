TARGET = lr3
PREFIX = /lr3

.PHONY: all clean install uninstall

all: $(TARGET)	
	
clean:
	rm -rf $(TARGET) *.o
main.o: main.cpp
	g++ -c -o main.o main.cpp
$(TARGET): main.o 
	g++ -o $(TARGET) main.o
install:
	install $(TARGET) $(PREFIX)
uninstall:
	rm -rf $(PREFIX)/$(TARGET)


