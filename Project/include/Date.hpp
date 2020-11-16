#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
  unsigned int year;
  unsigned int month;
  unsigned int day;

public:
  Date(){};
  Date(unsigned int day, unsigned int month, unsigned int year);
  unsigned int getMonth();
  unsigned int getYear();
  unsigned int getDay();
  void setDay(unsigned int day);
  void setMonth(unsigned int month);
  void setYear(int year);
  void printDate() const;
  bool operator<(Date d1) const;
  bool operator>(Date d1) const;
  string toString();
};

enum InvalidDateErrorType
{
  INVALID_DAY = 1,
  INVALID_MONTH,
  INVALID_YEAR
};

class InvalidDate : public std::exception
{
private:
  std::string wrongParameter;
  int value;
  int error_code;

public:
  InvalidDate(int value, std::string wrongParameter);
  InvalidDate(int value, std::string wrongParameter, int error_code);
  virtual const char *what() const throw();
  int getValue();
  std::string getParameter();
};

#endif
