TARGET = lr2
PREFIX = /lr2

.PHONY: all clean install uninstall

all: $(TARGET)	
	
clean:
	rm -rf $(TARGET) *.o
main.o: main.cpp
	g++ -c -o main.o main.cpp
list.o: list.cpp
	g++ -c -o list.o list.cpp
$(TARGET): main.o list.o
	g++ -o $(TARGET) main.o list.o
install:
	install $(TARGET) $(PREFIX)
uninstall:
	rm -rf $(PREFIX)/$(TARGET)


