#include "../include/Department.hpp"

/**
 * Constructs a Department object.
 * @param name The name of the department.
 * @param courses The courses of the department.
 */
Department::Department(std::string name, std::vector<Course *> courses)
{
  if (name.length() == 0)
  {
    throw InvalidDepartment(1);
  }

  this->name = name;
  this->courses = courses;
}

/**
 * Constructs an empty Department object.
 */
Department::Department() {}

/**
 * Destroys a Department object.
 */
Department::~Department()
{
  for (unsigned int i = 0; i != courses.size(); i++)
  {
    delete courses.at(i);
    i--;
  }
}

/**
 * Gets the name of the department.
 * @return The name of the department.
 */
std::string Department::getName() const
{
  return name;
}

/**
 * Gets the courses of the department.
 * @return The courses of the department.
 */
std::vector<Course *> Department::getCourses() const
{
  return courses;
}

/**
 * Prints the information of the department.
 */
void Department::printInfo() const
{
  string header = "- Department: " + this->getName();
  cout << header << endl;
  for (auto &course : courses)
  {
    course->printInfo();
  }
}

/**
 * Sets the name of the department.
 * @param name The name of the department.
 */
void Department::setName(string name)
{
  this->name = name;
}

/**
 * Sets the courses of the department.
 * @param courses The courses of the department.
 */
void Department::setCourses(std::vector<Course *> courses)
{
  this->courses = courses;
}

/**
 * Adds a course to the departent.
 * @param course A course.
 */
void Department::addCourse(Course *course)
{
  this->courses.push_back(course);
}

/**
 * Erases a course from the vector of courses.
 * @param course A course.
 */
void Department::eraseCourse(Course *course)
{
  for (unsigned int i = 0; i != courses.size(); i++)
  {
    if (courses.at(i) == course)
    {
      courses.erase(courses.begin() + i);
      break;
    }
  }
}

/**
 * Sorts courses by code in ascending order
 */
void Department::sort_courses_code_crescent()
{
  sort(courses.begin(), courses.end(), compare_courses_code_crescent);
}

/**
 * Sorts courses by code in descending order
 */
void Department::sort_courses_code_decrescent()
{
  sort(courses.begin(), courses.end(), compare_courses_code_decrescent);
}

/**
 * Sorts courses by name in ascending order
 */
void Department::sort_courses_name_crescent()
{
  sort(courses.begin(), courses.end(), compare_courses_name_crescent);
}

/**
 * Sorts courses by name in descending order
 */
void Department::sort_courses_name_decrescent()
{
  sort(courses.begin(), courses.end(), compare_courses_name_decrescent);
}

/**
 * Finds a course by code
 * @param code The code of the course to be found
 * @return The course to be found
 */
Course *Department::find_course_by_code(unsigned int code) const
{
  for (size_t i = 0; i < this->courses.size(); i++)
  {
    if (this->courses[i]->getCode() == code)
    {
      return this->courses[i];
    }
  }

  return NULL;
}

/**
 * Finds a course by name
 * @param name The name of the course to be found
 * @return The course to be found
 */
Course *Department::find_course_by_name(std::string name) const
{
  for (size_t i = 0; i < this->courses.size(); i++)
  {
    if (this->courses[i]->getName() == name)
    {
      return this->courses[i];
    }
  }

  return NULL;
}
/**
 * Finds a course by director
 * @param name The name of the director
 * @return
 */
Course *Department::find_course_by_director(std::string name) const
{
  for (size_t i = 0; i < this->courses.size(); i++)
  {
    if (this->courses[i]->getDirector() == name)
    {
      return this->courses[i];
    }
  }

  return NULL;
}

/*COMPARE FUNCTIONS USED TO SORT*/
/**
 * Compare function used to sort
 * courses by name in ascending order
 * @param c1 The first course
 * @param c2 The second course
 * @return The smallest course
 */
bool compare_courses_name_crescent(Course *c1, Course *c2)
{
  return c1->getName() < c2->getName();
}

/**
 * Compare function used to sort
 * courses by name is descending order
 * @param c1 The first course
 * @param c2 The second course
 * @return The biggest course
 */
bool compare_courses_name_decrescent(Course *c1, Course *c2)
{
  return c1->getName() > c2->getName();
}

/**
 * Compare function used to sort
 * courses by code in ascending order
 * @param c1 The first course
 * @param c2 The second course
 * @return The smallest course
 */
bool compare_courses_code_crescent(Course *c1, Course *c2)
{
  return c1->getCode() < c2->getCode();
}

/**
 * Compare function used to sort
 * courses by code in descending
 * @param c1 The first course
 * @param c2 The second course
 * @return The biggest course
 */
bool compare_courses_code_decrescent(Course *c1, Course *c2)
{
  return c1->getCode() > c2->getCode();
}

/**
 * Compacts the information of a department
 */
void Department::compatedInformation(std::ofstream &f)
{
  f << "#Department\n";
  f << name << "\n";

  for (size_t i = 0; i < courses.size(); i++)
  {
    courses.at(i)->compatedInformation(f);
  }

  f << "#Department#\n";
}
