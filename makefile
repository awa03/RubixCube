CXX = g++
CXXFLAGS = -std=c++11

TARGET = rubix

all: $(TARGET)

$(TARGET): rubix.o main.o
	$(CXX) -o $(TARGET) rubix.o main.o

rubix.o: rubix.cpp
	$(CXX) $(CXXFLAGS) -c rubix.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(TARGET) rubix.o main.o
