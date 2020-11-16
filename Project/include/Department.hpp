#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_

#include "../include/Course.hpp"
#include <vector>
#include <algorithm>

class Department
{
private:
  std::string name;
  std::vector<Course *> courses;

public:
  Department();
  Department(std::string name, std::vector<Course *> courses);
  ~Department();
  std::string getName() const;
  std::vector<Course *> getCourses() const;
  void sort_courses_name_crescent();
  void sort_courses_name_decrescent();
  void sort_courses_code_crescent();
  void sort_courses_code_decrescent();
  void printInfo() const;
  void setName(std::string name);
  void setCourses(std::vector<Course *> courses);
  void addCourse(Course *course);
  void eraseCourse(Course *course);
  Course *find_course_by_name(std::string name) const;
  Course *find_course_by_code(unsigned int code) const;
  Course *find_course_by_director(std::string director) const;
  void compatedInformation(std::ofstream &f);
};

class InvalidDepartment : public std::exception
{
private:
  int error_code;

public:
  InvalidDepartment(int error_code)
  {
    this->error_code = error_code;
  }
  virtual const char *what() const throw()
  {
    switch (error_code)
    {
    case 1:
      return "Empty string as department name is not allowed";
    default:
      return "Unknown error";
    }
  }
};

/*COMPARE FUNCTIONS USED TO SORT*/
bool compare_courses_name_crescent(Course *c1, Course *c2);

bool compare_courses_name_decrescent(Course *c1, Course *c2);

bool compare_courses_code_crescent(Course *c1, Course *c2);

bool compare_courses_code_decrescent(Course *c1, Course *c2);

#endif
