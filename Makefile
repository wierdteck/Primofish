# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -Wall -g

# Target executable name
TARGET = main

# Source files
SOURCES = main.cpp add.cpp

# Build target
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

# Clean target
clean:
	rm -f $(TARGET)

# Run target
run: all
	./$(TARGET)