
#ifndef FACULTY_MANAGEMENT_UTILITIES_H
#define FACULTY_MANAGEMENT_UTILITIES_H


#include <string>
#include <iostream>
#include <fstream>

#include "../include/Faculty.hpp"


void writeFile(std::string filename,Faculty &faculty);

Faculty * readFile(std::string filename);

#endif //FACULTY_MANAGEMENT_UTILITIES_H