CXX = g++
CXXFLAGS = -Wall -std=c++11

LIBS = `pkg-config --libs opencv`

all: cambio

cambio: cambio.cpp tiempo.h
	$(CXX) $(CXXFLAGS) -o cambio cambio.cpp $(LIBS)

clean:
	rm -f cambio
