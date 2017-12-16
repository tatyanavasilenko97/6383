TARGET = cw                                                                
PREFIX = /cw
	
.PHONY: all clean install uninstall  

all: $(TARGET)   

clean:
	rm -rf $(TARGET) *.o
main.o: main.cpp
	g++ -c -o main.o main.cpp
CodeTree.o: CodeTree.cpp
	g++ -c -o CodeTree.o CodeTree.cpp
fh.o: fh.cpp
	g++ -c -o fh.o fh.cpp
huffman.o: huffman.cpp
	g++ -c -o huffman.o huffman.cpp 
$(TARGET): main.o CodeTree.o fh.o huffman.o
	g++ -o $(TARGET) main.o CodeTree.o fh.o huffman.o
install:
	install $(TARGET) $(PREFIX)                                             
uninstall:
	rm -rf $(PREFIX)/$(TARGET)
