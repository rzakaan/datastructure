SOURCES=$(wildcard list.cpp)
OBJECTS=${SOURCES:.cpp=.o}
STD_OBJ=$(wildcard std.o)

CXX=c++

all: clean list.bin

list.bin: ${OBJECTS}
	${CXX} $^ -o $@

std.bin: ${STD_OBJ}
	${CXX} $^ -o $@

%.o : %.cpp
	${CXX} -c $^ -o $@

clean:
	rm -f *.o
	rm -f *.bin

run: list.bin
	./$<