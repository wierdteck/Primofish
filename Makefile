# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -Wall -g
CFLAGS_CONSTANTS = -Wno-overflow -Wno-unsigned-overflow  # Disable large integer constant warnings for constants.cpp

# Target executable name
TARGET = main

# Source files
SOURCES = main.cpp constants.cpp
OBJECTS = main.o constants.o

# Build target
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Compile main.cpp normally
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

# Compile constants.cpp with warning suppression
constants.o: constants.cpp
	$(CC) $(CFLAGS) $(CFLAGS_CONSTANTS) -c constants.cpp -o constants.o

# Clean target
clean:
	rm -f $(TARGET) $(OBJECTS)

# Run target
run: all
	./$(TARGET)
