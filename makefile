CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=
SOURCES=main.cpp ULLNode.cpp ULL.cpp Trie.cpp TrieNode.cpp BasicTrieNode.cpp MultiSet.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=k

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
	rm $(EXECUTABLE)