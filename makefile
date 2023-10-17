CXX = g++
CXXFLAGS = -std=c++11

TARGET = rubix

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	rm -f $(TARGET)
