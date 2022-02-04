SOURCES=$(wildcard main.cpp bst.cpp)
STD_SRC=$(wildcard std.cpp)
OBJECTS=${SOURCES:.cpp=.o}
STD_OBJ=${STD_SRC:.cpp=.o}

CXX=c++
BIN=bst.bin

all: clean ${BIN}

${BIN}: ${OBJECTS}
	${CXX} $^ -o $@

std.bin: ${STD_OBJ}
	${CXX} $^ -o $@

%.o : %.cpp
	${CXX} -c $^ -o $@

clean:
	rm -f *.o
	rm -f *.bin

std: std.bin
	./$^

run: ${BIN}
	./$<