SOURCES=$(wildcard main.cpp array.cpp)
STD_SRC=$(wildcard std.cpp)
OBJECTS=${SOURCES:.cpp=.o}
STD_OBJ=${STD_SRC:.cpp=.o}

CXX=c++

all: clean array.bin

array.bin: ${OBJECTS}
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

run: array.bin
	./$<