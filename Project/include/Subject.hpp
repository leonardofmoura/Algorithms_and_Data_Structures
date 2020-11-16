#ifndef COURSE_H_
#define COURSE_H_

#include <vector>
#include <string>
#include <utility>
#include <map> 
#include <iostream>
#include <fstream>

using namespace std;

class Subject {
  protected:
    std::string namePT;
    std::string nameEN;
    int regentCode;
    int code;
    int lectiveYear;
    float ECTS; 
    int workLoad;
    std::vector<int> teachersCode; 
    std::vector<int> studentsCode;
    std::map<int,float> grades;
  public:
    Subject() {};
    Subject(std::string namePT, std::string nameEN, int regentCode, 
            int code, int lectiveYear, 
            float ECTS, int workLoad);
    ~Subject(){};
    bool operator<(const Subject c) const;
    bool operator==(const Subject C) const;
    std::string getNamePT() const;
    std::string getNameEN() const;
    int getRegentCode() const; 
    int getCode() const;
    int getLectiveYear() const;
    float getECTS() const;
    int getWorkLoad() const;
    std::vector<int> getTeachersCode() const;
    std::vector<int> getStudentsCode() const;
    std::map<int,float> getGrades() const;
    float getStudentGrade(int studentCode) const;
    void insertGrade(int studentID, float grade);
    void printInfo() const;
    void setNamePT(std::string name);
    void setNameEN(std::string name);
    void setRegentCode(int code);
    void setCode(int code);
    void setLectiveYear(int lectiveYear);
    void setECTS(float ECTS);
    void setWorkLoad(int workLoad);
    void setGrades(std::map<int,float> map);
    void addTeachersCode(int code);
    void addStudentsCode(int code);
    void compatedInformation(std::ofstream &f);
    void setTeachersCode(vector<int> codes);
    void setStudentsCode(vector<int> codes);
};

enum InvalidSubjectErrorType {EMPTY_SUB_NAME_PT = 1, 
    EMPTY_SUB_NAME_EN, NEGATIVE_SUB_CODE, 
    NEGATIVE_SUB_YEAR, NEGATIVE_SUB_ECTS,
    NEGATIVE_SUB_WORKLOAD};

class InvalidSubject : public std::exception {
  private:
    int error_code;
  public:
    InvalidSubject(int error_code) {
      this->error_code = error_code;
    }
    virtual const char * what() const throw() {
      switch (error_code) {
        case EMPTY_SUB_NAME_PT: 
          return "Empty string as portuguese subject name is not allowed";
        case EMPTY_SUB_NAME_EN: 
          return "Empty string as english subject name is not allowed";
        case NEGATIVE_SUB_CODE: 
          return "Negative subject code is not allowed";
        case NEGATIVE_SUB_YEAR: 
          return "Negative lective year is not allowed";
        case NEGATIVE_SUB_ECTS: 
         return "Negative subject ETCS number is not allowed";
        case NEGATIVE_SUB_WORKLOAD: 
          return "Negative subject workload is not allowed";
        default:
          return "Unknown error";
      }
    }
};

#endif
