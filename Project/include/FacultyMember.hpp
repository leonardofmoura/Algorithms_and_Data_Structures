#ifndef FACULTYMEMBER_HPP_
#define FACULTYMEMBER_HPP_

#include <vector>
#include <string>
#include <map>
#include "../include/Date.hpp"
#include <set>
#include "../include/Subject.hpp"
#include <fstream>

class FacultyMember
{
protected:
  std::string name;
  std::string address;
  Date birthDate;
  int cellphoneNumber;
  int code;

public:
  FacultyMember(){};
  FacultyMember(std::string name, std::string address,
                Date birthDate, int cellphoneNumber, int code);
  virtual ~FacultyMember(){};
  std::string getName() const;
  std::string getAddress() const;
  Date getBirthDate() const;
  int getCellphoneNumber() const;
  int getCode() const;
  virtual void printInfo() const;
  void setName(std::string name);
  void setAddress(std::string address);
  void setDate(Date date);
  void setCellphoneNumber(int cellphoneNumber);
  void setCode(int code);
  void setBirthDate(std::string date);
  virtual void compatedInformation(std::ofstream &f) {}
};

class Student : public FacultyMember
{
private:
  int course;
  float average;
  unsigned int curricularYear;
  std::vector<Subject> subjectsTaken;

public:
  Student() { this->code = 0; } //needed for bst implementation
  Student(std::string name, int course);
  Student(std::string name, std::string address, Date birthDate,
          int cellphoneNumber, int code, int course, float average);
  std::vector<Subject> getSubjectsTaken() const;
  void addSubjectTaken(Subject c);
  float calculateAverage();
  void printInfo() const;
  void setCourse(int course);
  void setSubjectsTaken(std::vector<Subject> subjects);
  int getCourse() const;
  bool operator<(const Student &s) const;
  unsigned int getCurricularYear() const;
  void setCurricularYear(unsigned int curricularYear);
  void setAverage(float average);
  float getAverage();
  bool operator==(const Student &s1) const;
  void compatedInformation(std::ofstream &f);
  friend class StudentPtr;
};

class Teacher : public FacultyMember
{
private:
  int taxpayerNumber;
  int salary;
  string category;
  vector<Subject> subjects;

public:
  Teacher(){};
  Teacher(std::string name, std::string address, Date birthDate,
          int cellphoneNumber, int code, int taxPayerNumber, int salary,
          string category);
  int getTaxpayerNumber() const;
  int getSalary() const;
  void printInfo() const;
  void setTaxpayerNumber(int number);
  void setSalary(int salary);
  void setCategory(std::string category);
  void setSubjects(std::vector<Subject> subjects);
  void compatedInformation(std::ofstream &f);
};

class Staff : public FacultyMember
{
private:
  int taxpayerNumber;
  int salary;
  std::string fieldOfWork;

public:
  Staff(){};
  Staff(std::string name, std::string address, Date birthDate,
        int cellphoneNumber, int code, int taxPayerNumber, int salary,
        std::string fieldOfWork);
  int getTaxpayerNumber() const;
  int getSalary() const;
  std::string getFieldOfWork() const;
  void printInfo() const;
  void setTaxpayerNumber(int number);
  void setSalary(int salary);
  void setFieldOfWork(std::string field);
  void compatedInformation(std::ofstream &f);
};

class StudentPtr
{
private:
  Student *st;

public:
  StudentPtr() { this->st = NULL; }
  StudentPtr(Student *s);
  Student *getPtr() const;
  void print() const;
  bool operator<(const StudentPtr &s1) const;
  bool operator==(const StudentPtr &s1) const;
};

enum InvalidFacultyMemberErrorType
{
  EMPTY_NAME = 1,
  EMPTY_ADDRESS,
  NEGATIVE_CELL,
  NEGATIVE_CODE,
  EMPTY_COURSE,
  EMPTY_CATEGORY,
  NEGATIVE_TAX,
  NEGATIVE_SALARY,
  EMPTY_FIELD
};

class InvalidFacultyMember : public std::exception
{
private:
  int error_code;

public:
  InvalidFacultyMember(int error_code)
  {
    this->error_code = error_code;
  }
  virtual const char *what() const throw()
  {
    switch (error_code)
    {
    case EMPTY_NAME:
      return "Empty string as faculty member name is not allowed";
    case EMPTY_ADDRESS:
      return "Empty string as faculty member address is not allowed";
    case NEGATIVE_CELL:
      return "Negative cellphone number is not allwes";
    case NEGATIVE_CODE:
      return "Negative faculty member code is not allowed";
    case EMPTY_COURSE:
      return "Empty string as student course is not allowed";
    case EMPTY_CATEGORY:
      return "Empty tring as teacher category is not allowed";
    case NEGATIVE_TAX:
      return "Negative taxpayer number is not allowed";
    case NEGATIVE_SALARY:
      return "Negative salary is not allowed";
    default:
      return "Unknown error";
    }
  }
};

#endif
