HEADERS=$(wildcard *.h)
SOURCES=$(wildcard *.cpp)
OBJECTS=${SOURCES:.cpp=.o}

CXX=c++

all: stack.bin

stack.bin: clean ${OBJECTS}
	${CXX} $^ -o $@

%.o : %.cpp
	${CXX} -c $^ -o $@

clean:
	rm -f *.o