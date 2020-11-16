#ifndef COURSE_HPP_
#define COURSE_HPP_

#include <vector>
#include <string>
#include <map>
#include "../include/Subject.hpp"
#include <fstream>

class Course
{
protected:
  std::string name;
  unsigned int code;
  std::map<int, std::vector<Subject *>> curricularPlan;
  std::string director;

public:
  Course(){};
  Course(unsigned int code, std::string name,
         std::map<int, std::vector<Subject *>> curricularPlan,
         std::string director);
  virtual ~Course();
  unsigned int getCode() const;
  std::string getName() const;
  std::map<int, std::vector<Subject *>> getCurricularPlan() const;
  std::string getDirector() const;
  virtual unsigned int getDuration() const = 0;
  virtual void printInfo() const;
  void setName(std::string name);
  void setCode(unsigned int code);
  void setCurricularPlan(std::map<int, std::vector<Subject *>> cp);
  void setDirector(std::string director);
  virtual void setDuration(unsigned int d) = 0;
  void insertYearSubjects(unsigned int year, vector<Subject *> subjects);
  vector<Subject> getSubjects();
  void eraseSubject(Subject subject);
  virtual void compatedInformation(std::ofstream & f) = 0;
};

class Bachelors : public Course
{
private:
  unsigned int duration;

public:
  Bachelors(){};
  Bachelors(unsigned int code, std::string name,
            std::map<int, std::vector<Subject *>> curricularPlan,
            std::string director);
  ~Bachelors(){};
  unsigned int getDuration() const;
  void printInfo() const;
  void setDuration(unsigned int d);
  void compatedInformation(std::ofstream & f);
};

class Masters : public Course
{
private:
  unsigned int duration;

public:
  Masters(){};
  Masters(unsigned int code, std::string name,
          std::map<int, std::vector<Subject *>> curricularPlan,
          std::string director);
  ~Masters(){};
  unsigned int getDuration() const;
  void printInfo() const;
  void setDuration(unsigned int d);
  void compatedInformation(std::ofstream & f);
};

class IntegratedMasters : public Course
{
private:
  unsigned int duration;

public:
  IntegratedMasters(){};
  IntegratedMasters(unsigned int code, std::string name,
                    std::map<int, std::vector<Subject *>> curricularPlan,
                    std::string director);
  ~IntegratedMasters(){};
  unsigned int getDuration() const;
  void printInfo() const;
  void setDuration(unsigned int d);
  void compatedInformation(std::ofstream & f);
};

enum InvalidCourseErrorType
{
  NEGATIVE_COURSE_CODE = 1,
  EMPTY_COURSE_NAME,
  EMPTY_COURSE_DIRECTOR,
  NEGATIVE_COURSE_DURATION
};

class InvalidCourse : public std::exception
{
private:
  int error_code;

public:
  InvalidCourse(int error_code)
  {
    this->error_code = error_code;
  }
  virtual const char *what() const throw()
  {
    switch (error_code)
    {
    case NEGATIVE_COURSE_CODE:
      return "Negative course code is not allowed";
    case EMPTY_COURSE_NAME:
      return "Empty string as course name is not allowed";
    case EMPTY_COURSE_DIRECTOR:
      return "Empty string as course director is not allowed";
    case NEGATIVE_COURSE_DURATION:
      return "Negative course duration is not allowed";
    default:
      return "Unknown error";
    }
  }
};

#endif
