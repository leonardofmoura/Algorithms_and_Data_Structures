#include "../include/FacultyMember.hpp"

/**
 * Constructs a FacultyMember object.
 * @param name The name of a faculty member.
 * @param address The address of a faculty member.
 * @param birthDate The birth date of a faculty member.
 * @param cellphoneNumber The cellphone number of a faculty member.
 * @param code The code of a faculty member.
 */
FacultyMember::FacultyMember(std::string name, std::string address,
                             Date birthDate, int cellphoneNumber, int code) : birthDate(birthDate)
{

    if (name.length() == 0)
    {
        throw InvalidFacultyMember(EMPTY_NAME);
    }
    if (address.length() == 0)
    {
        throw InvalidFacultyMember(EMPTY_ADDRESS);
    }
    if (cellphoneNumber < 0)
    {
        throw InvalidFacultyMember(NEGATIVE_CELL);
    }
    if (code < 0)
    {
        throw InvalidFacultyMember(NEGATIVE_CELL);
    }

    this->name = name;
    this->address = address;
    this->birthDate = birthDate;
    this->cellphoneNumber = cellphoneNumber;
    this->code = code;
}

/**
 * Gets the name of a faculty member.
 * @returnThe name of a faculty member.
 */
std::string FacultyMember::getName() const
{
    return name;
}

/**
 * Gets the address of a faculty member.
 * @return The address of a faculty member.
 */
std::string FacultyMember::getAddress() const
{
    return address;
}

/**
 * Gets the birth date of a faculty member.
 * @return The birth date of a faculty member.
 */
Date FacultyMember::getBirthDate() const
{
    return birthDate;
}

/**
 * Gets the cellphone number of a faculty member.
 * @return The cellphone number of a faculty member.
 */
int FacultyMember::getCellphoneNumber() const
{
    return cellphoneNumber;
}

/**
 * Gets the code of a faculty member.
 * @return The code of a faculty member.
 */
int FacultyMember::getCode() const
{
    return code;
}

/**
 * Prints the information of a faculty member, which is
 * the values of every attribute of the class.
 */
void FacultyMember::printInfo() const
{
    string courseheader = "- Faculty member: " + this->getName();
    cout << courseheader << endl;
    cout << "Address: " << address << endl;
    cout << "Birth date: ";
    birthDate.printDate();
    cout << endl;
    cout << "Cellphone number: " << cellphoneNumber << endl;
    cout << "Code: " << code << endl;
}

/**
 * Sets the name of a faculty member.
 * @param name The name of a faculty member.
 */
void FacultyMember::setName(std::string name)
{
    this->name = name;
}

/**
 * Sets the address of a faculty member.
 * @param address The address of a faculty member.
 */
void FacultyMember::setAddress(std::string address)
{
    this->address = address;
}

/**
 * Sets the date of a faculty member.
 * @param date The date of a faculty member.
 */
void FacultyMember::setDate(Date date)
{
    this->birthDate = date;
}

/**
 * Sets the cellphone number of a faculty member.
 * @param cellphoneNumber The cellphone number of a faculty member.
 */
void FacultyMember::setCellphoneNumber(int cellphoneNumber)
{
    this->cellphoneNumber = cellphoneNumber;
}

/**
 * Sets the code of a faculty member.
 * @param code The code of a faculty member.
 */
void FacultyMember::setCode(int code)
{
    this->code = code;
}

Student::Student(std::string name, int course)
{
    this->name = name;
    this->course = course;
}

/**
 * Constructs a Student object with all the attribute values
 * of the class as parameters.
 * @param name The name of a student.
 * @param address The address of a student.
 * @param birthDate The birth date of a student.
 * @param cellphoneNumber The cellphone number of a student.
 * @param code The code of a student.
 */
Student::Student(std::string name, std::string address, Date birthDate,
                 int cellphoneNumber, int code, int course, float average) : FacultyMember(name, address, birthDate, cellphoneNumber, code)
{
    this->average = average;
    this->course = course;
}

/**
 * Gets the subjects in which the student is or has been enrolled.
 * @return
 */
std::vector<Subject> Student::getSubjectsTaken() const
{

    return subjectsTaken;
}

/**
 * Adds a subject which the student is or has been enrolled.
 * @param c The subject
 */
void Student::addSubjectTaken(const Subject c)
{
    subjectsTaken.push_back(c);
}

/**
 * @brief Gets the average of the student
 * 
 * @return float The average of the student
 */
float Student::getAverage()
{
    return this->average;
}

/**
 * @brief Sets the average of a student
 * 
 * @param average The average of a student
 */
void Student::setAverage(float average)
{
    this->average = average;
}

/**
 * Calculates the average of a student.
 * @return the average
 */
float Student::calculateAverage()
{
    if (subjectsTaken.empty())
    {
        return 0;
    }
    float sum = 0;
    for (std::vector<Subject>::iterator it = subjectsTaken.begin(); it != subjectsTaken.end(); it++)
    {
        sum = sum + it->getStudentGrade(code);
    }
    float average = sum / subjectsTaken.size();
    return average;
}

/**
 * Prints the information of a student, that is,
 * the value of every attribute of the object
 */
void Student::printInfo() const
{
    string subjectInfo;
    FacultyMember::printInfo();
    cout << "Course: " << course << endl;
    cout << "Curricular year: " << curricularYear << endl;
    cout << "Average: " << average << endl;
    cout << "Subjects taken: ";
    for (unsigned int i = 0; i != subjectsTaken.size(); i++)
    {
        subjectInfo += subjectsTaken.at(i).getNameEN() + ", ";
    }
    subjectInfo = subjectInfo.substr(0, subjectInfo.size() - 2);
    cout << subjectInfo << endl;
}
/**
 * Sets the course of a student
 * @param course The course
 */
void Student::setCourse(int course)
{
    this->course = course;
}
/**
 * Gets the course of a student
 * @return The course of the student
 */
int Student::getCourse() const
{
    return this->course;
}

/**
 * Sets the subjects taken by the student
 * @param subjects Subjects taken by the student
 */
void Student::setSubjectsTaken(vector<Subject> subjects)
{
    this->subjectsTaken = subjects;
}

/**
 * @brief Returns the curricular year of a student
 * 
 * @return unsigned int The curricular year of the student
 */
unsigned int Student::getCurricularYear() const
{
    return curricularYear;
}

void Student::setCurricularYear(unsigned int curricularYear)
{
    this->curricularYear = curricularYear;
}

/**
 * @brief Returns the smallest student according to their average, curricular 
 * year and birthdate, respectively.
 * 
 * @param s A student to be used in the comparison
 * @return true Student is smaller than s
 * @return false Student is bigger than s
 */
bool Student::operator<(const Student &s) const
{
    if (this->average == s.average)
    {
        if (this->getCurricularYear() == s.getCurricularYear())
        {
            return this->getBirthDate() < s.getBirthDate();
        }
        return this->getCurricularYear() < s.getCurricularYear();
    }
    return this->average < s.average;
}

bool Student::operator==(const Student &s1) const
{
    return this->code == s1.code;
}

/**
 * Constructs a Teacher object with every atribute value as
 * parameters
 * @param name The name of the teacher
 * @param address The address of the teacher
 * @param birthDate The birth date of the teacher
 * @param cellphoneNumber The cellphone number of the teacher
 * @param code The code of the teacher
 * @param taxPayerNumber The taxpayer number of the teacher
 * @param salary The salary of the teacher
 * @param category The category of the teacher
 * @param subjects The subjects of the teacher
 */
Teacher::Teacher(std::string name, std::string address, Date birthDate,
                 int cellphoneNumber, int code, int taxPayerNumber, int salary,
                 std::string category) : FacultyMember(name, address, birthDate, cellphoneNumber, code)
{

    if (taxPayerNumber < 0)
    {
        throw InvalidFacultyMember(NEGATIVE_TAX);
    }
    if (salary < 0)
    {
        throw InvalidFacultyMember(NEGATIVE_SALARY);
    }
    this->taxpayerNumber = taxPayerNumber;
    this->salary = salary;
    this->category = category;
    this->subjects = subjects;
}

/**
 * Gets the taxpayer number of a teacher
 * @return the taxpayer number of the teacher
 */
int Teacher::getTaxpayerNumber() const
{
    return taxpayerNumber;
}

/**
 * Gets the salary of a teacher
 * @return The salary of the teacher
 */
int Teacher::getSalary() const
{
    return salary;
}

/**
 * Prints the information of the teacher,
 * that is, the value of every attribute
 * of the object
 */
void Teacher::printInfo() const
{
    string subjectInfo = "";
    FacultyMember::printInfo();
    cout << "Taxpayer number: " << taxpayerNumber << endl;
    cout << "Salary: " << salary << endl;
    cout << "Category: " << category << endl;
    cout << "Subjects: " << endl;
    for (unsigned int i = 0; i != subjects.size(); i++)
    {
        subjectInfo += subjects.at(i).getNameEN() + ", ";
    }
    subjectInfo = subjectInfo.substr(0, subjectInfo.size() - 2);
    cout << subjectInfo << endl;
}

/**
 * Sets the taxpayer number of the teacher
 * @param number The taxpayer number of the teacher
 */
void Teacher::setTaxpayerNumber(int number)
{
    this->taxpayerNumber = number;
}

/**
 * Sets the salary of the teacher
 * @param salary The salary of the teacher
 */
void Teacher::setSalary(int salary)
{
    this->salary = salary;
}
/**
 * Sets the category of the teacher
 * @param category The category of the teacher
 */
void Teacher::setCategory(std::string category)
{
    this->category = category;
}
/**
 * Sets the subjects of the teacher
 * @param subjects The subjects of the teacher
 */
void Teacher::setSubjects(vector<Subject> subjects)
{
    this->subjects = subjects;
}

/**
 * Constructs a Teacher object with all the attribute
 * values as parameters
 * @param name The name of the teacher
 * @param address The address of the teacher
 * @param birthDate The birth date of the teacher
 * @param cellphoneNumber The cellphone number of the teacher
 * @param code The code of the teacher
 * @param taxPayerNumber The taxpayer number of the teacher
 * @param salary The salary of the teacher
 * @param fieldOfWork The field of work of the teacher
 */
Staff::Staff(std::string name, std::string address, Date birthDate,
             int cellphoneNumber, int code, int taxPayerNumber, int salary,
             std::string fieldOfWork) : FacultyMember(name, address, birthDate,
                                                      cellphoneNumber, code)
{

    if (taxPayerNumber < 0)
    {
        throw InvalidFacultyMember(NEGATIVE_TAX);
    }
    if (salary < 0)
    {
        throw InvalidFacultyMember(NEGATIVE_SALARY);
    }
    if (fieldOfWork.length() == 0)
    {
        throw InvalidFacultyMember(EMPTY_FIELD);
    }

    this->taxpayerNumber = taxPayerNumber;
    this->salary = salary;
    this->fieldOfWork = fieldOfWork;
}

/**
 * Prints the infomration of the staff member,
 * that is, the values of all its attributes
 */
void Staff::printInfo() const
{
    cout << "Taxpayer number: " << taxpayerNumber << endl;
    cout << "Salary: " << salary << endl;
    cout << "Field of work: " << fieldOfWork << endl;
}

/**
 * Sets the taxpayer number of the staff member
 * @param number The taxpayer number
 */
void Staff::setTaxpayerNumber(int number)
{
    this->taxpayerNumber = number;
}

/**
 * Sets the salary of the staff member
 * @param salary The salary of the staff member
 */
void Staff::setSalary(int salary)
{
    this->salary = salary;
}

/**
 * Sets the field of work of the staff member
 * @param field The field of work of the staff member
 */
void Staff::setFieldOfWork(string field)
{
    this->fieldOfWork = field;
}

/**
 * Creates a student pointer
 */
StudentPtr::StudentPtr(Student *s)
{
    this->st = s;
}

/**
 * Gets a student pointer
 */
Student *StudentPtr::getPtr() const
{
    return this->st;
}

/**
 * Prints the information of the student pointer
 */
void StudentPtr::print() const
{
    std::cout << this->st;
}

/**
 * Compares two students by course, and if it's the same, by name.
 */
bool StudentPtr::operator<(const StudentPtr &s1) const
{
    if (this->st == NULL || s1.getPtr() == NULL)
    {
        cout << "NULL\n";
        return false;
    }

    if (this->st->getCourse() == s1.getPtr()->getCourse())
    {
        return this->st->getName() < s1.getPtr()->getName();
    }
    else
    {
        return this->st->getCourse() < s1.getPtr()->getCourse();
    }
}

/**
 * Checks if two students are the same
 */
bool StudentPtr::operator==(const StudentPtr &s1) const
{
    if (this->st == s1.getPtr())
    {
        return true;
    }
    else if (this->st == NULL || s1.getPtr() == NULL)
    {
        return false;
    }
    else
    {
        return this->st->getName() == s1.getPtr()->getName() && this->st->getCourse() == s1.getPtr()->getCourse();
    }
}

/**
 * Compacts the information of a staff member
 */
void Staff::compatedInformation(std::ofstream &f)
{
  f << "#Staff\n"
    << name << "\n"
    << address << "\n"
    << birthDate.toString() << "\n"
    << cellphoneNumber << "\n"
    << code << "\n"
    << taxpayerNumber << "\n"
    << salary << "\n"
    << fieldOfWork << "\n";

  f << "#Staff#\n";
}

/**
 * Compacts the information of a teacher
 */
void Teacher::compatedInformation(std::ofstream &f)
{
  f << "#Teacher\n"
    << name << "\n"
    << address << "\n"
    << birthDate.toString() << "\n"
    << cellphoneNumber << "\n"
    << code << "\n"
    << category << "\n"
    << taxpayerNumber << "\n"
    << salary << "\n";

  f<<"#Student\n";
    for (size_t i = 0; i < subjects.size(); i++)
  {
    f << subjects.at(i).getCode() << "\n";
  }

  f << "#Student#\n";
    

  f << "#Teacher#\n";
}


/**
 * Compacts the information of a student
 */
void Student::compatedInformation(std::ofstream &f)
{
  f << "#Student\n"
    << name << "\n"
    << address << "\n"
    << birthDate.toString() << "\n"
    << cellphoneNumber << "\n"
    << code << "\n"
    << course << "\n"
    << average <<"\n"
    << curricularYear <<"\n";

  for (size_t i = 0; i < subjectsTaken.size(); i++)
  {
    f << subjectsTaken.at(i).getCode() << "\n";
  }

  f << "#Student#\n";
}

/**
 * Sets the birthDate of a faculty member
 */
void FacultyMember::setBirthDate(std::string date)
{

 unsigned int day = stoi(date.substr(0, 2));

 unsigned int month = stoi(date.substr(2, 2));

  int year = stoi(date.substr(4));
 this->birthDate = Date(day,month,year);
}
