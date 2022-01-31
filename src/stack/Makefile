HEADERS=$(wildcard *.h)
SOURCES=$(wildcard *.cpp)
OBJECTS=${SOURCES:.cpp=.o}

CXX=c++

all: clean stack.bin

stack.bin: ${OBJECTS}
	${CXX} $^ -o $@

%.o : %.cpp
	${CXX} -c $^ -o $@

clean:
	rm -f *.o
	rm -f *.bin

run: stack.bin
	./$<