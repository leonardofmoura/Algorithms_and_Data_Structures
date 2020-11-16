#include "../include/Subject.hpp"

/**
 * Constructs a subject with all the attribute values
 * as parameter values
 * @param namePT The portuguese name of the subject
 * @param nameEN The english name of the subject
 * @param regentCode The regent code of the subject
 * @param code The code of the subject
 * @param lectiveYear The lective year of the subject
 * @param ECTS The ECTSs of the subject
 * @param workLoad The workload of the subject
 * @param teachersCode The codes of the teachers that teach the subject
 * @param studentsCode The codes of the students that are enrolled in the subject
 */
Subject::Subject(std::string namePT, std::string nameEN, int regentCode,
                 int code, int lectiveYear, float ECTS, int workLoad)
{

    if (namePT.length() == 0)
    {
        throw InvalidSubject(EMPTY_SUB_NAME_PT);
    }
    if (nameEN.length() == 0)
    {
        throw InvalidSubject(EMPTY_SUB_NAME_EN);
    }
    if (code < 0)
    {
        throw InvalidSubject(NEGATIVE_SUB_CODE);
    }
    if (lectiveYear < 0)
    {
        throw InvalidSubject(NEGATIVE_SUB_YEAR);
    }
    if (ECTS < 0)
    {
        throw InvalidSubject(NEGATIVE_SUB_ECTS);
    }
    if (workLoad < 0)
    {
        throw InvalidSubject(NEGATIVE_SUB_WORKLOAD);
    }

    this->namePT = namePT;
    this->nameEN = nameEN;
    this->regentCode = regentCode;
    this->code = code;
    this->lectiveYear = lectiveYear;
    this->ECTS = ECTS;
    this->workLoad = workLoad;
}

/**
 * Gets the codes of every teacher that teaches the subject
 * @return  The codes of the teachers that teach the subject
 */
std::vector<int> Subject::getTeachersCode() const
{
    return teachersCode;
}

/**
 * Gets the codes of every student that is enrolled
 * in the subject
 * @return The codes of every student enrolled in the subject
 */
std::vector<int> Subject::getStudentsCode() const
{
    return studentsCode;
}

/**
 * Gets the portuguese name of the subject
 * @return The portuguese name of the subject
 */
std::string Subject::getNamePT() const
{
    return namePT;
}

/**
 * Gets the english name of the subject
 * @return The english name of the subjest
 */
std::string Subject::getNameEN() const
{
    return nameEN;
}

/**
 * Gets the code of the regent of the subject
 * @return The code of the regent of the subject
 */
int Subject::getRegentCode() const
{
    return regentCode;
}

/**
 * Gets the smallest subject of the two subjects
 * provided
 * @param C A subject to be compared
 * @return The smallest subject
 */
bool Subject::operator<(const Subject C) const
{
    return this->code < C.getCode();
}

/**
 * Tells if two subjects are equal
 * @param c A subject to be compared
 * @return The result of the operation
 */
bool Subject::operator==(const Subject c) const
{
    bool flag = false;
    if (this->code == c.code && this->lectiveYear == c.lectiveYear)
    {
        flag = true;
    }

    return flag;
}

/**
 * Returns the code of the subject
 * @return
 */
int Subject::getCode() const
{
    return code;
}

/**
 * Returns the lective year of the subject
 * @return
 */
int Subject::getLectiveYear() const
{
    return lectiveYear;
}

/**
 * Returns the ECTSs of the subject
 * @return The ECTSs of the subject
 */
float Subject::getECTS() const
{
    return ECTS;
}

/**
 * Gets the work load of the subject
 * @return The work load of the subject
 */
int Subject::getWorkLoad() const
{
    return workLoad;
}

/**
 * Gets the grades of a given student, in which
 * the first member of the map is the code of the student,
 * and the second member of the map is the grade of the
 * student in this subject
 * @return
 */
std::map<int, float> Subject::getGrades() const
{
    return grades;
}

/**
 * Gets the grade of a student in the subject
 * @param studentCode The code of the student
 * @return The grade of the subject
 */
float Subject::getStudentGrade(int studentCode) const
{
    float temp = this->grades.at(studentCode);

    return temp;
}

/**
 * Inserts the grade of a student
 * @param studendID The code of the student
 * @param grade The grade of the student
 */
void Subject::insertGrade(int studendID, float grade)
{
    grades.emplace(studendID, grade);
}

/**
 * Prints the info of the subject, that is,
 * the value of all its attributes
 */
void Subject::printInfo() const
{
    //string header = "--- " + nameEN + " - subject information ---";
    string header = "- Subject: " + nameEN, codes;
    cout << header << endl;
    cout << "Name (PT): " << namePT << endl;
    cout << "Regent's code: " << regentCode << endl;
    cout << "Code: " << code << endl;
    cout << "Lective year: " << lectiveYear << endl;
    cout << "ECTSs: " << ECTS << endl;
    cout << "Workload: " << workLoad << endl;
    if (!teachersCode.empty())
    {
        codes = "";
        cout << "Teachers' codes: ";
        for (unsigned int i = 0; i != teachersCode.size(); i++)
        {
            codes += to_string(teachersCode.at(i)) + ", ";
        }
        codes = codes.substr(0, codes.size() - 2);
        cout << codes << endl;
    }
    if (!studentsCode.empty())
    {
        codes = "";
        cout << "Students' codes: ";
        for (unsigned int i = 0; i != studentsCode.size(); i++)
        {
            codes += to_string(studentsCode.at(i)) + ", ";
        }
        codes = codes.substr(0, codes.size() - 2);
        cout << codes << endl;
    }
    cout << "Grades: ";
    for (auto it = grades.begin(); it != grades.end(); it++)
    {
        cout << "Student " << it->first << ": ";
        cout << it->second << endl;
    }
}

/**
 * Sets the portuguese name of the subject
 * @param name The name of the subject
 */
void Subject::setNamePT(string name)
{
    this->namePT = name;
}

/**
 * Sets the english name of the subject
 * @param name The english name of the subject
 */
void Subject::setNameEN(string name)
{
    this->nameEN = name;
}

/**
 * Sets the regent code of the subject
 * @param code Code of the regent
 */
void Subject::setRegentCode(int code)
{
    this->regentCode = code;
}

/**
 * Sets the code of the subject
 * @param code The code of the subject
 */
void Subject::setCode(int code)
{
    this->code = code;
}

/**
 * Sets the lective year of the subject
 * @param lectiveYear The lective year
 */
void Subject::setLectiveYear(int lectiveYear)
{
    this->lectiveYear = lectiveYear;
}

/**
 * Sets the ECTSs of the subject
 * @param ECTS The ECTSs
 */
void Subject::setECTS(float ECTS)
{
    this->ECTS = ECTS;
}

/**
 * Sets the work load of the subject
 * @param workLoad The work load
 */
void Subject::setWorkLoad(int workLoad)
{
    this->workLoad = workLoad;
}

/**
 * Adds the code of a teacher to the vector of
 * teachers that teach the subject
 * @param code The code of the teacher
 */
void Subject::addTeachersCode(int code)
{
    teachersCode.push_back(code);
}

/**
 * Adds the code of a student to the vector of
 * students that teach the subject
 * @param code The code of the student
 */
void Subject::addStudentsCode(int code)
{
    studentsCode.push_back(code);
}

/**
 * Sets the grades of every student
 * @param grades The grades of every student
 */
void Subject::setGrades(std::map<int, float> grades)
{
    this->grades = grades;
}


/**
 * Compacts the infomration of a subject
 */
void Subject::compatedInformation(std::ofstream &f)
{
    f << "#Subject\n";
    f << namePT
      << "\n" + nameEN + "\n"
      << std::to_string(regentCode) + "\n"
      << std::to_string(code) + "\n"
      << std::to_string(lectiveYear) + "\n"
      << std::to_string(ECTS) + "\n"
      << std::to_string(workLoad) + "\n";

    for (size_t i = 0; i < teachersCode.size(); i++)
    {
        f << std::to_string(teachersCode.at(i)) << " ";
    }
    f << "\n";

    for (size_t i = 0; i < studentsCode.size(); i++)
    {
        f << std::to_string(studentsCode.at(i)) << " ";
    }
    f << "\n";

    for (std::map<int, float>::iterator it = grades.begin(); it != grades.end(); it++)
    {
        f << std::to_string(it->first) + "|" + std::to_string(it->second) + " ";
    }
    f << "\n";

    //std::cout << temp;
    f << "#Subject#\n";
}

/**
 * Sets the code of a teacher
 */
void Subject::setTeachersCode(vector<int> codes)
{
    this->teachersCode = codes;
}

/**
 * Sets the code of a student
 */
void Subject::setStudentsCode(vector<int> codes)
{
    this->studentsCode = codes;
}
