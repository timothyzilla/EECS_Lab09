CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = matrix_program
OBJS = main.o

all: $(TARGET)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

$(TARGET): main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o

clean:
	rm -f *.o $(TARGET)
