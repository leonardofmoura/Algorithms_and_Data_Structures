#ifndef FACULTY_HPP_
#define FACULTY_HPP_

#include <vector>
#include <algorithm>
#include <queue>
#include "../include/BST.h"
#include "../include/Department.hpp"
#include "../include/FacultyMember.hpp"
#include <unordered_set>


struct StaffPtrHash
{
	int operator() (const FacultyMember& student) const
	{
	return	student.getCode() * student.getCellphoneNumber() % 1000;
	}

	bool operator() (const FacultyMember& student1, const FacultyMember& student2) const
	{
	return	student1.getCode() == student2.getCode();
	}
};


typedef std::unordered_set<FacultyMember, StaffPtrHash, StaffPtrHash> HashTabStaff;

class Faculty
{
private:
  std::string name;
  std::vector<Department *> departments;
  std::vector<FacultyMember *> facultyMembers;
  std::vector<Student *> students;
  priority_queue<Student> scholarship_queue;
  BST<StudentPtr> all_students;
  HashTabStaff employeeRegister;

public:
  Faculty();
  Faculty(std::string name, std::vector<Department *> departments,
          std::vector<FacultyMember *> facultyMembers);
  virtual ~Faculty();
  std::vector<Department *> getDepartments() const;
  std::string getName() const;
  std::vector<FacultyMember *> getFacultyMembers() const;
  void sort_departments_name_crescent();
  void sort_departments_name_decrescent();
  void sort_departments_number_of_courses_crescent();
  void sort_departments_number_of_courses_decrescent();
  void sort_member_name_crescent();
  void sort_member_name_decrescent();
  void sort_member_birth_date_crescent();
  void sort_member_birth_date_decrescent();
  void sort_member_code_crescent();
  void sort_member_code_decrescent();
  void addDepartment(Department *d);
  void addFacultyMember(FacultyMember *fm);
  void printInfo() const;
  void setName(std::string name);
  void setDepartments(std::vector<Department *> departments);
  void eraseDepartment(Department *d);
  bool eraseFacultyMember(FacultyMember *fm);
  Department *find_deparment_by_name(std::string name) const;
  FacultyMember *find_member_by_name(std::string name) const;
  FacultyMember *find_member_by_code(int code) const;
  vector<Course *> getCourses();
  Course *findCourse(unsigned int code);
  void addStudentScholarshipQueue(Student s);
  priority_queue<Student> getScholarshipQueue() const;
  void insertStudent(Student *s);
  BST<StudentPtr> getAllStudents() const;
  Student *findStudent(std::string name, int course) const;
  void test();
  void addStudents(vector<Student *> studentsToAdd);
  vector<Student *> getStudents() const;
  bool eraseStudent(Student *s);
  void compatedInformation(std::ofstream &f);
  void setFacultyMembers(std::vector<FacultyMember *>);
  void setStudents(std::vector<Student*> v);
  void printEmployeeRegister();
  HashTabStaff& getEmployeeRegister();
  void popPriorityQueue();
  void EmployeeRegister_delete(FacultyMember f);
};

class InvalidFaculty : public std::exception
{
private:
  int error_code;

public:
  InvalidFaculty(int error_code)
  {
    this->error_code = error_code;
  }
  virtual const char *what() const throw()
  {
    switch (error_code)
    {
    case 1:
      return "Empty string as faculty name is not allowed";
    default:
      return "Unknown error";
    }
  }
};

/*COMPARE FUNCTIONS USED TO SORT*/
bool compare_department_name_crescent(Department *d1, Department *d2);
bool compare_department_name_decrescent(Department *d1, Department *d2);
bool compare_department_number_of_courses_crescent(Department *d1, Department *d2);
bool compare_department_number_of_courses_decrescent(Department *d1, Department *d2);
bool compare_member_name_crescent(FacultyMember *d1, FacultyMember *d2);
bool compare_member_name_decrescent(FacultyMember *d1, FacultyMember *d2);
bool compare_member_birth_date_crescent(FacultyMember *d1, FacultyMember *d2);
bool compare_member_birth_date_decrescent(FacultyMember *d1, FacultyMember *d2);
bool compare_member_code_crescent(FacultyMember *f1, FacultyMember *f2);
bool compare_member_code_decrescent(FacultyMember *f1, FacultyMember *f2);

#endif
