SRC = Students.o List.o main.o
TARGET = lab3
all: $(TARGET)

main.o: main.cpp
	g++ -Wall -g -c -o main.o main.cpp

List.o: List.cpp
	g++ -Wall -g -c -o List.o List.cpp

Students.o: Students.cpp
	g++ -Wall -g -c -o Students.o Students.cpp

$(TARGET): $(SRC)
	g++ -o $(TARGET) $(SRC)

clean:
	rm -rf $(SRC)
