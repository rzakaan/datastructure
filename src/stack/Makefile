SOURCES=$(wildcard stack.cpp)
STD_SOURCES=$(wildcard std.cpp)
OBJECTS=${SOURCES:.cpp=.o}

CXX=c++

all: clean stack.bin

std.bin: ${STD_SOURCES}
	${CXX} $^ -o $@

stack.bin: ${OBJECTS}
	${CXX} $^ -o $@

%.o : %.cpp
	${CXX} -c $^ -o $@

clean:
	rm -f *.o
	rm -f *.bin

std: std.bin
	./$<

run: stack.bin
	./$<