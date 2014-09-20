EXE    = perceptron

CXX      = g++
#CXX      = g++ -pg
CXXFLAGS  = -std=c++0x -Wall -O3 -Wno-deprecated
LIBS =  

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

SRC    = $(wildcard *.cc)
OBJ    = $(patsubst %.cc, %.o, $(SRC))

	
$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ)  $(LIBS) -o $(EXE) -lz

.PHONY: clean
clean:
	 -rm -f core *.o
