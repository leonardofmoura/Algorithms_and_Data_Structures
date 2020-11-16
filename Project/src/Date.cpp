#include "../include/Date.hpp"

/**
 * Constructs an InvalidDate object.
 * @param value The value that is wrong on the date.
 * @param wrongParameter The name of the wrong parameter.
 */
InvalidDate::InvalidDate(int value, std::string wrongParameter)
{
  this->value = value;
  this->wrongParameter = wrongParameter;
}

/**
 * Constructs an InvalidDate object.
 * @param value The value that is wrong on the date.
 * @param wrongParameter The name of the wrong parameter.
 * @param error_code The error code.
 */
InvalidDate::InvalidDate(int value, std::string wrongParameter, int error_code)
{
  this->value = value;
  this->error_code = error_code;
  this->wrongParameter = wrongParameter;
}

/**
 * Returns the type of error of the class InvalidDate.
 * @return The type of error.
 */
const char *InvalidDate::what() const throw()
{
  switch (this->error_code)
  {
  case INVALID_DAY:
    return "Invalid day";
  case INVALID_MONTH:
    return "Invalid month";
  case INVALID_YEAR:
    return "Invalid Year";
  default:
    return "Unknown error";
  }
}

/**
 * Gets the value of the InvalidDate object.
 * @return The value of the date.
 */
int InvalidDate::getValue()
{
  return value;
}

/**
 * Gets the name of the wrong parameter.
 * @return The name of the wrong parameter.
 */
string InvalidDate::getParameter()
{
  return wrongParameter;
}

/**
 * Constructs an object of type Date.
 * @param day The day of the date.
 * @param month The month of the date.
 * @param year The year of the date.
 */
Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
  if (1 <= day && day <= 31)
  {
    this->day = day;
  }
  else
  {
    throw InvalidDate(day, "day", INVALID_DAY);
  }
  if (1 <= month && month <= 12)
  {
    this->month = month;
  }
  else
  {
    throw InvalidDate(month, "month", INVALID_MONTH);
  }
  if (year > 0)
  {
    this->year = year;
  }
  else
  {
    throw InvalidDate(year, "year", INVALID_YEAR);
  }
}

/**
 * Gets the year of the date.
 * @return
 */
unsigned int Date::getYear()
{
  return year;
}

/**
 * Gets the month of the date.
 * @return
 */
unsigned int Date::getMonth()
{
  return month;
}

/**
 * Gets the day of the date.
 * @return
 */
unsigned int Date::getDay()
{
  return day;
}

/**
 * Prints the date in the format dd/mm/yyyy.
 */
void Date::printDate() const
{
  cout << day << "/" << month << "/" << year;
}

/**
 * Sets the day of the date.
 * @param day The day of the date.
 */
void Date::setDay(unsigned int day)
{
  if (1 <= day && day <= 31)
  {
    this->day = day;
  }
  else
  {
    throw InvalidDate(day, "day", INVALID_DAY);
  }
}

/**
 * Sets the month of the date.
 * @param month The month of the date.
 */
void Date::setMonth(unsigned int month)
{
  if (1 <= month && month <= 12)
  {
    this->month = month;
  }
  else
  {
    throw InvalidDate(month, "month", INVALID_MONTH);
  }
}

/**
 * Sets the year of the date.
 * @param year The year of the date.
 */
void Date::setYear(int year)
{
  if (0 <= year)
  {
    this->year = year;
  }
  else
  {
    throw InvalidDate(year, "year", INVALID_YEAR);
  }
}

/**
 * Compares if one date is smaller than the other
 * @param d1 A date to be used in the comparison
 * @return The smallest date
 */
bool Date::operator<(Date d1) const
{
  if (this->year == d1.year)
  {
    if (this->month == d1.month)
    {
      return this->day < d1.day;
    }

    return this->month < d1.month;
  }

  return this->year < d1.year;
}

/**
 * Compares if one date is bigger than the other
 * @param d1 A date to be used in the comparison
 * @return The biggest date
 */
bool Date::operator>(Date d1) const
{
  if (this->year == d1.year)
  {
    if (this->month == d1.month)
    {
      return this->day > d1.day;
    }

    return this->month > d1.month;
  }

  return this->year > d1.year;
}

/**
 * Converts a date to a string
 */
std::string Date::toString()
{
  std::string temp;
  if (day > 9)
    temp = std::to_string(day);
  else
    temp = "0" + std::to_string(day);

  if (month > 9)
    temp += std::to_string(month);
  else
    temp += "0" + std::to_string(month);

  temp += std::to_string(year);

  return temp;
}
