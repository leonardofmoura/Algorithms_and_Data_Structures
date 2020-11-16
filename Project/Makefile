CFLAGS = -pedantic -O2 #-Wall -Wextra 
EXEC = faculty

install:
	g++ $(CFLAGS) -std=c++17 -o $(EXEC) src/FacultyMember.cpp src/Subject.cpp src/Course.cpp src/Department.cpp src/Faculty.cpp src/Date.cpp src/main.cpp src/utilities.cpp

debug:
	g++ $(CFLAGS) -std=c++17 -o $(EXEC) src/FacultyMember.cpp src/Subject.cpp src/Course.cpp src/Department.cpp src/Faculty.cpp src/Date.cpp src/main.cpp src/utilities.cpp -g

clean:
	rm $(EXEC) *.o
