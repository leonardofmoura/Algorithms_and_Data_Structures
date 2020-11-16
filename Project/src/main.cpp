#include "../include/Course.hpp"
#include "../include/Department.hpp"
#include "../include/Faculty.hpp"
#include "../include/FacultyMember.hpp"
#include "../include/Subject.hpp"
#include "../include/Date.hpp"
#include "../include/utilities.hpp"
#include <sstream>
#include <climits>

Student *selectStudent(Faculty *f);
float calcAverage(vector<Subject> &subjectsTaken, int code);

bool checkBoundaries(int inputValue, int minValue,
                     int maxValue)
{
    if (inputValue >= minValue && inputValue <= maxValue)
    {
        return true;
    }
    cerr << "Out of bounds. ";
    return false;
}
int askNumericOption(int minValue = 0, int maxValue = INT_MAX,
                     string errorMsg = "Please pick a valid option.")
{
    int option;
    cin >> option;
    bool isBetweenBoundaries = checkBoundaries(option, minValue, maxValue);
    while (cin.fail() || !isBetweenBoundaries)
    {
        cin.clear();
        cin.ignore(999999999, '\n');
        cout << errorMsg << endl;
        cout << "> ";
        cin >> option;
        isBetweenBoundaries = checkBoundaries(option, minValue, maxValue);
    }
    cin.ignore(99999999, '\n');
    return option;
}

string askString()
{
    string s;
    getline(cin, s);
    while (s.empty())
    {
        cerr << "Empty string. Please enter a valid string." << endl;
        getline(cin, s);
    }
    return s;
}

char askCharOption(char yes = 'Y', char no = 'N',
                   string errorMsg = "Please pick a valid option.")
{
    char option;
    cin >> option;
    option = toupper(option);
    while (cin.fail() || (option != yes && option != no))
    {
        cin.clear();
        cin.ignore(99999999, '\n');
        cout << errorMsg << endl;
        cout << "> ";
        cin >> option;
        option = toupper(option);
    }
    cin.ignore(99999999, '\n');
    return option;
}

bool createDate(unsigned int &day, unsigned int &month,
                unsigned int &year, Date &date)
{
    try
    {
        date = Date(day, month, year);
    }
    catch (std::exception &err)
    {
        cout << err.what() << endl;
        return false;
    }
    return true;
}

Subject copySubject(Faculty *f, unsigned int courseCode, int subjectCode)
{
    vector<Subject> subjects, aux;
    for (unsigned int i = 0; i != f->getDepartments().size(); i++)
    {
        auto department = f->getDepartments().at(i);
        for (unsigned int j = 0; j != department->getCourses().size(); j++)
        {
            auto course = department->getCourses().at(j);
            if (course->getCode() == courseCode)
            {
                aux = course->getSubjects();
                for (unsigned int k = 0; k != aux.size(); k++)
                {
                    subjects.push_back(aux.at(k));
                }
            }
        }
    }
    for (unsigned int i = 0; i != subjects.size(); i++)
    {
        if (subjects.at(i).getCode() == subjectCode)
        {
            return subjects.at(i);
        }
    }
    Subject res;
    res.setNameEN("NULL");
    return res;
}

void askDate(unsigned int &day, unsigned int &month, unsigned int &year,
             Date &date)
{
    bool validDate = false;
    while (!validDate)
    {
        cout << "Day of birth:" << endl;
        cout << "> ";
        day = askNumericOption();
        cout << "Month of birth:" << endl;
        cout << "> ";
        month = askNumericOption();
        cout << "Year of birth:" << endl;
        cout << "> ";
        year = askNumericOption();
        if (createDate(day, month, year, date))
        {
            validDate = true;
        }
    }

    try
    {
        date.setDay(day);
        date.setMonth(month);
        date.setYear(year);
    }

    catch (std::exception &err)
    {
        cout << "Exception: " << err.what() << endl;
        cout << "Please insert the date again: " << endl;
        cout << "> ";
    }
}

int askFacultyMemberType()
{
    int type;
    cout << "Select the type of the faculty member:" << endl;
    cout << "1. Student;" << endl;
    cout << "2. Teacher;" << endl;
    cout << "3. Staff;" << endl;
    type = askNumericOption(1, 3);
    return type;
}

void askFacultyMemberInfo(string &name, string &address, int &cellphoneNumber,
                          int &code)
{
    cout << "Name:" << endl;
    cout << "> ";
    name = askString();
    cout << "Address:" << endl;
    cout << "> ";
    address = askString();
    cout << "Cellphone number:" << endl;
    cout << "> ";
    cellphoneNumber = askNumericOption();
    cout << "Code:" << endl;
    cout << "> ";
    code = askNumericOption();
}

void askStudentInfo(int &course, int &curricularYear, int &amountSubjects)
{
    cout << "Course code:" << endl;
    cout << "> ";
    course = askNumericOption();
    cout << "Insert the curricular year of the student:" << endl;
    cout << "> ";
    curricularYear = askNumericOption();
    cout << "Insert the amount of subjects the student "
         << "is or has been enrolled in: " << endl;
    cout << "> ";
    amountSubjects = askNumericOption();
}

void askSubjectCode(int &subjectCode)
{
    cout << "Insert the code of the subject: " << endl;
    cout << "> ";
    subjectCode = askNumericOption();
}

bool subjectExists(Subject s)
{

    if (s.getNameEN() == "NULL")
    {
        cout << "The subject doesn't exist! ";
        cout << "Please insert the code of an ";
        cout << "existing subject." << endl;
        return false;
    }
    return true;
}

void setFacultyMemberInfo(FacultyMember *member, string name, string address,
                          Date birthDate, int cellphoneNumber, int code)
{
    member->setName(name);
    member->setAddress(address);
    member->setDate(birthDate);
    member->setCellphoneNumber(cellphoneNumber);
    member->setCode(code);
}

void setStudentInfo(int course, float average, int curricularYear,
                    vector<Subject> &subjectsTaken, Student *student)
{
    student->setCourse(course);
    student->setCurricularYear(curricularYear);
    student->setSubjectsTaken(subjectsTaken);
    student->setAverage(average);
}

Subject addSubjectToStudent(int course, Faculty *f)
{
    int subjectCode;
    askSubjectCode(subjectCode);
    Subject aux = copySubject(f, course, subjectCode);
    if (!subjectExists(aux))
    {
        cout << "Doesn't exist!" << endl;
        aux.setNameEN("NULL");
    }
    return aux;
}

float calcAverage(vector<Subject> &subjectsTaken, int code)
{
    if (subjectsTaken.empty())
    {
        return 0;
    }
    float sum = 0;
    for (Subject &subject : subjectsTaken)
    {
        sum += subject.getGrades().at(code);
    }
    return sum / (subjectsTaken.size());
}

void addStudent(int &course, int &curricularYear,
                Faculty *f, vector<Subject> &subjectsTaken,
                vector<FacultyMember *> &members, string &name,
                string &address, Date &birthDate, int &cellphoneNumber,
                int &code, vector<Student *> &students)
{
    Student *student = new Student();
    int amountSubjects;
    askStudentInfo(course, curricularYear, amountSubjects);
    for (int j = 0; j < amountSubjects; j++)
    {
        Subject subject = addSubjectToStudent(course, f);
        if (subject.getNameEN() == "NULL")
        {
            j--;
        }
        else
        {
            subjectsTaken.push_back(subject);
        }
    }
    float average = calcAverage(subjectsTaken, code);
    student->setAverage(average);
    setFacultyMemberInfo(student, name, address, birthDate,
                         cellphoneNumber, code);
    setStudentInfo(course, average, curricularYear, subjectsTaken, student);
    members.push_back(student);
    students.push_back(student);
    f->addStudentScholarshipQueue(*student);
}

int selectAmountFacultyMembers()
{
    int amount;
    cout << "----- Faculty Member setup -----" << endl;
    cout << "Insert the amount of faculty members you would like to add:";
    cout << endl
         << "> ";
    amount = askNumericOption();
    return amount;
}

void askTeacherInfo(int &taxpayerNumber, int &salary, string &category,
                    int &amount)
{
    cout << "Taxpayer number: " << endl;
    cout << "> ";
    taxpayerNumber = askNumericOption();
    cout << "Salary: " << endl;
    cout << "> ";
    salary = askNumericOption();
    cout << "Category: " << endl;
    cout << "> ";
    category = askString();
    cout << "Insert the amount of subjects the teacher"
         << "is responsible for:" << endl;
    cout << "> ";
    amount = askNumericOption();
}

int askCourseCode()
{
    int courseCode;
    cout << "Insert the code of the course of the subject:" << endl;
    cout << "> ";
    courseCode = askNumericOption();
    return courseCode;
}

void addFacultyMembers(Faculty *f)
{
    Date date;
    vector<FacultyMember *> members;
    vector<Student *> studentsToAdd;
    unsigned int day, month, year;
    int type, cellphoneNumber, course, code, curricularYear,
        amount = selectAmountFacultyMembers();
    vector<Subject> subjectsTaken;
    string name, address;
    for (int i = 0; i < amount; i++)
    {
        type = askFacultyMemberType();
        askFacultyMemberInfo(name, address, cellphoneNumber, code);
        askDate(day, month, year, date);
        switch (type)
        {
        case 1:
        {
            addStudent(course, curricularYear, f,
                       subjectsTaken, members, name, address, date,
                       cellphoneNumber, code, studentsToAdd);
            break;
        }
        case 2:
        {
            int taxpayerNumber, salary;
            string category;
            Teacher *teacher = new Teacher();
            askTeacherInfo(taxpayerNumber, salary, category, amount);
            for (int j = 0; j < amount; j++)
            {
                unsigned int subjectCode, courseCode = askCourseCode();

                if ((f->findCourse(courseCode)->getCode()) == courseCode)
                {
                    cout << "Insert the code of the subject: " << endl;
                    cout << "> ";
                    subjectCode = askNumericOption();
                    Subject aux = copySubject(f, courseCode, subjectCode);
                    if (aux.getNameEN() == "NULL")
                    {
                        cout << "The subject doesn't exist! ";
                        cout << "Please insert the code of an ";
                        cout << "existing subject." << endl;
                        j--;
                    }
                    else
                    {
                        subjectsTaken.push_back(aux);
                    }
                }
                else
                {
                    cout << "The course doesn't exist! ";
                    cout << "Please insert the code of an ";
                    cout << "existing course." << endl;
                }
            }

            teacher->setName(name);
            teacher->setAddress(address);
            teacher->setDate(date);
            teacher->setCellphoneNumber(cellphoneNumber);
            teacher->setCode(code);
            teacher->setTaxpayerNumber(taxpayerNumber);
            teacher->setSalary(salary);
            teacher->setCategory(category);
            teacher->setSubjects(subjectsTaken);
            members.push_back(teacher);
            break;
        }
        case 3:
        {
            int taxpayerNumber, salary;
            string fieldOfWork;
            Staff *staff = new Staff();
            cout << "Taxpayer number: " << endl;
            cout << "> ";
            taxpayerNumber = askNumericOption();
            cout << "Salary: " << endl;
            cout << "> ";
            salary = askNumericOption();
            cout << "Field of work: " << endl;
            cout << "> ";
            fieldOfWork = askString();
            staff->setName(name);
            staff->setAddress(address);
            staff->setDate(date);
            staff->setCellphoneNumber(cellphoneNumber);
            staff->setCode(code);
            staff->setTaxpayerNumber(taxpayerNumber);
            staff->setSalary(salary);
            staff->setFieldOfWork(fieldOfWork);
            members.push_back(staff);
            break;
        }
        }
    }

    for (unsigned int i = 0; i < members.size(); i++)
    {
        f->addFacultyMember(members.at(i));
    }
    f->addStudents(studentsToAdd);
}

void askSubjectInfo(string &nameEN, string &namePT, int &regentCode,
                    int &code, int &lectiveYear, int &workLoad,
                    float &ECTS)
{
    string header = "--- Subject setup ---";
    cout << header << endl;
    cout << "English name of the subject:" << endl;
    cout << "> ";
    nameEN = askString();
    cout << "Portuguese name of the subject:" << endl;
    cout << "> ";
    namePT = askString();
    cout << "Code of regent:" << endl;
    cout << "> ";
    regentCode = askNumericOption();
    cout << "Code of the subject:" << endl;
    cout << "> ";
    code = askNumericOption();
    cout << "Lective year:" << endl;
    cout << "> ";
    lectiveYear = askNumericOption();
    cout << "ECTS of the subject:" << endl;
    cout << "> ";
    ECTS = askNumericOption();
    cout << "Workload of the subject:" << endl;
    cout << "> ";
    workLoad = askNumericOption();
}

void setSubjectInfo(Subject *s, string nameEN, string namePT,
                    int regentCode, int code, int lectiveYear, int workLoad,
                    float ECTS)
{
    s->setNameEN(nameEN);
    s->setNamePT(namePT);
    s->setRegentCode(regentCode);
    s->setCode(code);
    s->setLectiveYear(lectiveYear);
    s->setECTS(ECTS);
    s->setWorkLoad(workLoad);
}

int selectAmountTeachers()
{
    int amount;
    cout << "How many teachers would you like to add?" << endl;
    cout << "> ";
    amount = askNumericOption();
    return amount;
}

int askTeacherCode()
{
    int code;
    cout << "Insert the code of the teacher:" << endl;
    cout << "> ";
    code = askNumericOption();
    return code;
}

void addTeachersToSubject(Subject *subject)
{
    char option;
    cout << "Would you like to add teachers? (Y/N)" << endl;
    cout << "> ";
    option = askCharOption();
    if (option == 'Y')
    {
        int amount, code;
        amount = selectAmountTeachers();
        for (int i = 0; i < amount; i++)
        {
            code = askTeacherCode();
            subject->addTeachersCode(code);
        }
    }
}

FacultyMember *searchFacultyMemberByCode(Faculty *f, int code)
{
    for (FacultyMember *member : f->getFacultyMembers())
    {
        if (member->getCode() == code)
        {
            return member;
        }
    }
    return NULL;
}

vector<int> addGradesToSubject(Subject *s, /*map<int, float> grades, */ Faculty *f)
{
    //s->setGrades(grades);
    vector<int> codes; // Codes of the students that were given a grade in a subject
    int num;
    cout << "How many grades would you like to insert?" << endl;
    cout << "> ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int code;
        float grade;
        FacultyMember *aux;
        cout << "Insert the code of the student:" << endl;
        cout << "> ";
        code = askNumericOption();
        codes.push_back(code);
        cout << "Insert the grade of the student:" << endl;
        cout << "> ";
        grade = askNumericOption();
        s->insertGrade(code, grade);
        aux = searchFacultyMemberByCode(f, code);
        if (aux != NULL)
        {
            float average = dynamic_cast<Student *>(aux)->calculateAverage();
            dynamic_cast<Student *>(aux)->setAverage(average);
        }
        // To do so, should search for student and then recalculate average.
        // ALREADY DID IT!! Probably should test it now...
    }
    return codes;
}

bool addStudentsToSubject(Subject *s, Faculty *f)
{
    char option;
    map<int, float> grades;
    cout << "Would you like to add students? (Y/N)" << endl;
    cout << "> ";
    option = askCharOption();
    if (option == 'Y')
    {
        int num, code;
        cout << "How many students would you like to add?" << endl;
        cout << "> ";
        num = askNumericOption();
        for (int i = 0; i < num; i++)
        {
            cout << "Insert the code of the student:" << endl;
            cout << "> ";
            code = askNumericOption();
            s->addStudentsCode(code);
        }
        cout << "Would you like to add the grades of the students? " << endl;
        cout << "> ";
        option = askCharOption();
        if (option == 'Y')
        {
            addGradesToSubject(s, f);
        }
        return true;
    }
    return false;
}

Subject *createSubject()
{
    Subject *s = new Subject();
    string namePT = "", nameEN = "";
    int regentCode = 0, code = 0, lectiveYear = 0, workLoad = 0;
    float ECTS = 0;
    askSubjectInfo(nameEN, namePT, regentCode, code, lectiveYear, workLoad,
                   ECTS);
    setSubjectInfo(s, nameEN, namePT, regentCode, code, lectiveYear, workLoad,
                   ECTS);
    return s;
}

void addCurricularPlan(Course *c, Faculty *f)
{
    unsigned int numSubjects;
    for (unsigned int i = 0; i != c->getDuration(); i++)
    {
        cout << "How many subjects will year " << i + 1 << " have? " << endl;
        cout << "> ";
        numSubjects = askNumericOption();
        vector<Subject *> subjects;
        for (unsigned int j = 0; j != numSubjects; j++)
        {
            Subject *s = createSubject();
            addTeachersToSubject(s);
            addStudentsToSubject(s, f);
            subjects.push_back(s);
        }
        c->insertYearSubjects(i + 1, subjects);
    }
}

void askCourseInfo(string &name, unsigned int &code,
                   unsigned int &typeOfCourse, string &director, char &option)
{
    string header = "--- Course setup ---";
    cout << header << endl;
    cout << "Course name:" << endl;
    cout << ">  ";
    name = askString();
    cout << "Course code:" << endl;
    cout << ">  ";
    code = askNumericOption();
    cout << "What is the type of the course?" << endl;
    cout << "1. Bachelors" << endl;
    cout << "2. Masters" << endl;
    cout << "3. Integrated masters" << endl;
    cout << ">  ";
    typeOfCourse = askNumericOption(1, 3);
    cout << "Course director:" << endl;
    cout << ">  ";
    director = askString();
    cout << "Would you like to add a curricular plan? (Y/N)" << endl;
    cout << ">  ";
    option = askCharOption();
}

void setCourseInfo(Course *c, int duration, string name,
                   unsigned int code, string director, char option,
                   vector<Course *> courses, Faculty *f)
{
    c->setName(name);
    c->setCode(code);
    c->setDirector(director);
    c->setDuration(duration);
    if (option == 'Y')
    {
        addCurricularPlan(c, f);
    }
    courses.push_back(c);
}

void insertCoursesIntoDepartment(Department *d, vector<Course *> courses)
{
    for (unsigned int i = 0; i != courses.size(); i++)
    {
        d->addCourse(courses.at(i));
    }
}

void addCourses(Department *d, Faculty *f)
{
    unsigned int code, num, typeOfCourse;
    vector<Course *> courses;
    string name, director;
    char option;
    cout << "How many courses would you like to add?" << endl;
    cout << ">  ";
    num = askNumericOption();
    for (unsigned int i = 0; i < num; i++)
    {
        askCourseInfo(name, code, typeOfCourse, director, option);
        switch (typeOfCourse)
        {
        case 1:
        {
            Bachelors *b = new Bachelors();
            setCourseInfo(b, 3, name, code, director, option, courses, f);
            d->addCourse(b);
            break;
        }
        case 2:
        {
            Masters *m = new Masters();
            setCourseInfo(m, 2, name, code, director, option, courses, f);
            d->addCourse(m);
            break;
        }
        case 3:
        {
            IntegratedMasters *i = new IntegratedMasters();
            setCourseInfo(i, 5, name, code, director, option, courses, f);
            d->addCourse(i);
            break;
        }
        }
    }
}

void addDepartments(Faculty *f)
{
    int num;
    string answer;
    cout << "How many departments would you like to add?" << endl;
    cout << ">  ";
    num = askNumericOption();
    for (int i = 0; i < num; i++)
    {
        Department *d = new Department();
        string name;
        string header = "--- Department setup ---";
        cout << header << endl;
        cout << "Department name:" << endl;
        cout << ">  ";
        name = askString();
        d->setName(name);
        cout << "Would you like to add courses? (Y/N)" << endl;
        cout << "> ";
        answer = askCharOption();
        if (answer == "Y")
        {
            addCourses(d, f);
        }
        f->addDepartment(d);
    }
}

void setupFaculty(Faculty *f)
{
    string name, answer;
    string header = "--- Faculty setup ---";
    cout << header << endl;
    cout << "Faculty name:" << endl;
    cout << "> ";
    name = askString();
    f->setName(name);
    cout << "Would you like to add departments? (Y/N)" << endl;
    cout << "> ";
    answer = askCharOption();
    if (answer == "Y")
    {
        addDepartments(f);
    }
    cout << "Would you like to add faculty members? (Y/N)" << endl;
    cout << "> ";
    answer = askCharOption();
    if (answer == "Y")
    {
        addFacultyMembers(f);
    }
}

Department *selectDepartment(Faculty *f)
{
    int option;
    cout << "Select a department:" << endl;
    for (unsigned int i = 0; i != f->getDepartments().size(); i++)
    {
        cout << i + 1 << ". " << f->getDepartments().at(i)->getName() << endl;
    }
    option = askNumericOption(1, f->getDepartments().size());
    return f->getDepartments().at(option - 1);
}

Course *selectCourse(Department *d)
{
    int option;
    cout << "Select a course:" << endl;
    for (unsigned int i = 0; i != d->getCourses().size(); i++)
    {
        cout << i + 1 << ". " << d->getCourses().at(i)->getName() << endl;
    }
    option = askNumericOption(1, d->getCourses().size());
    return d->getCourses().at(option - 1);
}

Subject selectSubject(Course *c)
{
    int option;
    cout << "Select a subject:" << endl;
    for (unsigned int i = 0; i != c->getSubjects().size(); i++)
    {
        cout << i + 1 << ". " << c->getSubjects().at(i).getNameEN() << endl;
    }
    option = askNumericOption(1, c->getSubjects().size());
    return c->getSubjects().at(option - 1);
}

FacultyMember *selectFacultyMember(Faculty *f)
{
    int option;
    for (unsigned int i = 0; i != f->getFacultyMembers().size(); i++)
    {
        cout << i + 1 << ". " << f->getFacultyMembers().at(i)->getName() << endl;
    }
    option = askNumericOption(1, f->getFacultyMembers().size());
    return f->getFacultyMembers().at(option - 1);
}

void printFacultyInfo(Faculty *f)
{
    f->sort_departments_name_crescent();
    f->sort_member_name_crescent();
    f->printInfo();
}

void printDepartmentInfo(Faculty *f)
{
    if (!f->getDepartments().empty())
    {
        auto department = selectDepartment(f);
        department->printInfo();
    }
    else
    {
        cerr << "There are no departments." << endl;
    }
}

bool printCourseInfo(Faculty *f)
{
    if (!f->getDepartments().empty())
    {
        auto department = selectDepartment(f);
        if (!department->getCourses().empty())
        {
            auto course = selectCourse(department);
            course->printInfo();
            return true;
        }
        else
        {
            cerr << "Courses are empty." << endl;
        }
    }
    else
    {
        cerr << "There are no departments." << endl;
    }
    return false;
}

bool printSubjectInfo(Faculty *f)
{
    if (!f->getDepartments().empty())
    {
        auto department = selectDepartment(f);
        if (!department->getCourses().empty())
        {
            auto course = selectCourse(department);
            if (!course->getSubjects().empty())
            {
                auto subject = selectSubject(course);
                subject.printInfo();
                return true;
            }
        }
        else
        {
            cerr << "Courses empty." << endl;
        }
    }
    else
    {
        cerr << "Departments empty." << endl;
    }
    return false;
}

bool printFacultyMemberInfo(Faculty *f)
{
    if (!f->getFacultyMembers().empty())
    {
        auto facultyMember = selectFacultyMember(f);
        facultyMember->printInfo();
        return true;
    }
    else
    {
        cerr << "Faculty members are empty." << endl;
    }
    return false;
}

bool printPriorityQueueInfo(Faculty *f)
{
    priority_queue<Student> aux = f->getScholarshipQueue();
    if (aux.empty())
    {
        cout << "The priority queue is empty." << endl;
        return false;
    }
    string queue = "";
    cout << "The priority queue is the following, from top to bottom: " << endl;
    while (!aux.empty())
    {
        queue += aux.top().getName() + ", ";
        aux.pop();
    }
    queue = queue.substr(0, queue.length() - 2);
    cout << queue << endl;
    return true;
}

void printHashTableInfo(Faculty *f)
{
    for (auto it = f->getEmployeeRegister().begin();
            it != f->getEmployeeRegister().end(); 
            it++)
    {
        cout << it->getName() << endl;
    }
}

void printInfo(Faculty *f)
{
    int option;
    cout << "1. Print faculty info;" << endl;
    cout << "2. Print department info;" << endl;
    cout << "3. Print course info;" << endl;
    cout << "4. Print subject info;" << endl;
    cout << "5. Print faculty member info;" << endl;
    cout << "6. Print priority queue info;" << endl;
    cout << "7. Print hash table info;" << endl;
    cout << "8. Go back;" << endl;
    cout << "> ";
    option = askNumericOption(1, 8);
    switch (option)
    {
    case 1:
    {
        printFacultyInfo(f);
        break;
    }
    case 2:
    {
        printDepartmentInfo(f);
        break;
    }
    case 3:
    {
        printCourseInfo(f);
        break;
    }
    case 4:
    {
        printSubjectInfo(f);
        break;
    }
    case 5:
    {
        printFacultyMemberInfo(f);
        break;
    }
    case 6:
    {
        printPriorityQueueInfo(f);
        break;
    }
    case 7:
    {
        printHashTableInfo(f);
        break;
    }
    case 8:
    {
        break;
    }
    }
}

bool addCourse(Faculty *f)
{
    if (!f->getDepartments().empty())
    {
        auto department = selectDepartment(f);
        addCourses(department, f);
        return true;
    }
    return false;
}

bool addSubject(Faculty *f)
{
    int year;
    vector<int> codes;
    if (!f->getDepartments().empty())
    {
        auto department = selectDepartment(f);
        if (!department->getCourses().empty())
        {
            auto course = selectCourse(department);
            if (!course->getCurricularPlan().empty())
            {
                auto subject = createSubject();
                vector<Subject *> aux;
                aux.push_back(subject);
                cout << "Which year is the subject part of?" << endl;
                cout << "> ";
                year = askNumericOption(1, course->getDuration());
                cout << "Would you like to add the grades of the students? ";
                cout << endl;
                cout << "> ";
                char option = askCharOption();
                if (option == 'Y')
                {
                    codes = addGradesToSubject(subject, f);
                }
                course->insertYearSubjects(year, aux);
                for (unsigned int i = 0; i != codes.size(); i++)
                {
                    for (auto &student : f->getStudents())
                    {
                        if (student->getCode() == codes.at(i))

                        {
                            // THIS WORKS!!!
                            student->addSubjectTaken(*subject);
                            float average = student->calculateAverage();
                            student->setAverage(average);
                        }
                    }
                }
                return true;
            }
        }
    }
    return false;
}

void addElements(Faculty *f)
{
    int option;
    cout << "Please pick one of the following options:" << endl;
    cout << "1. Add department;" << endl;
    cout << "2. Add course;" << endl;
    cout << "3. Add subject;" << endl;
    cout << "4. Add faculty member;" << endl;
    cout << "5. Go back;" << endl;
    option = askNumericOption(1, 5);
    switch (option)
    {
    case 1:
    {
        addDepartments(f);
        break;
    }
    case 2:
    {
        addCourse(f);
        break;
    }
    case 3:
    {
        addSubject(f);
        break;
    }
    case 4:
    {
        addFacultyMembers(f);
        break;
    }
    case 5:
    {
        break;
    }
    }
}

bool eraseDepartment(Faculty *f)
{
    if (!f->getDepartments().empty())
    {
        auto department = selectDepartment(f);
        for (unsigned int i = 0; i != f->getDepartments().size(); i++)
        {
            if (f->getDepartments().at(i) == department)
            {
                f->eraseDepartment(department);
                return true;
            }
        }
    }
    return false;
}

bool eraseCourse(Faculty *f)
{
    if (!f->getDepartments().empty())
    {
        auto department = selectDepartment(f);
        if (!department->getCourses().empty())
        {
            auto course = selectCourse(department);
            for (unsigned int i = 0; i != department->getCourses().size(); i++)
            {
                if (department->getCourses().at(i) == course)
                {
                    department->eraseCourse(course);
                    return true;
                }
            }
        }
        else
        {
            cerr << "Course list is empty." << endl;
        }
    }
    else
    {
        cerr << "Department list is empty." << endl;
    }
    return false;
}

bool eraseSubject(Faculty *f)
{
    if (!f->getDepartments().empty())
    {
        auto department = selectDepartment(f);
        if (!department->getCourses().empty())
        {
            auto course = selectCourse(department);
            if (!course->getCurricularPlan().empty())
            {
                auto subject = selectSubject(course);
                course->eraseSubject(subject);
                return true;
            }
            else
            {
                cerr << "Curricular plan if empty" << endl;
            }
        }
        else
        {
            cerr << "Course list is empty." << endl;
        }
    }
    else
    {
        cerr << "Department list is empty." << endl;
    }
    return false;
}

bool eraseFacultyMember(Faculty *f)
{
    if (!f->getFacultyMembers().empty())
    {
        auto facultyMember = selectFacultyMember(f);
        // TODO: facultyMember
        Student *st = dynamic_cast<Student *>(facultyMember);
        if (st != NULL)
        {
            f->eraseStudent(st);
        }
        f->eraseFacultyMember(facultyMember);
        return true;
    }
    else
    {
        cerr << "Faculty member list is empty." << endl;
    }
    return false;
}


void eraseElements(Faculty *f)
{
    int option;
    cout << "Please pick one of the following options:" << endl;
    cout << "1. Erase department;" << endl;
    cout << "2. Erase course;" << endl;
    cout << "3. Erase subject;" << endl;
    cout << "4. Erase faculty member;" << endl;
    cout << "5. Pop student from priority queue;" << endl;
    cout << "6. Go back;" << endl;
    option = askNumericOption(1, 6);
    switch (option)
    {
    case 1:
    {
        eraseDepartment(f);
        break;
    }
    case 2:
    {
        eraseCourse(f);
        break;
    }
    case 3:
    {
        eraseSubject(f);
        break;
    }
    case 4:
    {
        eraseFacultyMember(f);
        break;
    }
    case 5:
    {
        f->popPriorityQueue();
        cout << "Student popped from queue" << endl;
        break;
    }
    case 6:
    {
        break;
    }
    }
}

void sortElements(Faculty *f)
{
    int option;
    cout << "Please pick one of the following options:" << endl;
    cout << "1. Sort departments by name (ascending order)" << endl;
    cout << "2. Sort departments by name (descending order)" << endl;
    cout << "3. Sort departments by number of courses (ascending order)" << endl;
    cout << "4. Sort departments by number of courses (descending order)" << endl;
    cout << "5. Sort faculty members by name (ascending order)" << endl;
    cout << "6. Sort faculty members by birth date (ascending order)" << endl;
    cout << "7. Sort faculty members by birth date (descending order)" << endl;
    cout << "8. Sort faculty members by code (ascending order)" << endl;
    cout << "9. Sort faculty members by code (descending order)" << endl;
    cout << "10. Sort courses by name (ascending order)" << endl;
    cout << "11. Go back" << endl;
    option = askNumericOption(1, 12);
    switch (option)
    {
    case 1:
    {
        f->sort_departments_name_crescent();
        cout << "Departments sorted." << endl;
        break;
    }
    case 2:
    {
        f->sort_departments_name_decrescent();
        cout << "Departments sorted." << endl;
        break;
    }
    case 3:
    {
        f->sort_departments_number_of_courses_crescent();
        cout << "Departments sorted." << endl;
        break;
    }
    case 4:
    {
        f->sort_departments_number_of_courses_decrescent();
        cout << "Departments sorted." << endl;
        break;
    }
    case 5:
    {
        f->sort_member_name_crescent();
        cout << "Faculty members sorted." << endl;
        break;
    }
    case 6:
    {
        f->sort_member_birth_date_crescent();
        cout << "Faculty members sorted." << endl;
        break;
    }
    case 7:
    {
        f->sort_member_birth_date_decrescent();
        cout << "Faculty members sorted." << endl;
        break;
    }
    case 8:
    {
        f->sort_member_code_crescent();
        cout << "Faculty members sorted." << endl;
        break;
    }
    case 9:
    {
        f->sort_member_code_decrescent();
        cout << "Faculty members sorted." << endl;
        break;
    }
    case 10:
    {
        if (!f->getDepartments().empty())
        {
            auto department = selectDepartment(f);
            department->sort_courses_name_crescent();
            cout << "Courses sorted." << endl;
        }
        break;
    }
    case 11:
    {
        return;
    }
    }
}

bool findDepartmentByName(Faculty *f)
{
    string name;
    cout << "Insert the name of the department:" << endl;
    cout << "> ";
    name = askString();
    auto d = f->find_deparment_by_name(name);
    if (d != NULL)
    {
        d->printInfo();
        return true;
    }
    cerr << "No department found." << endl;
    return false;
}

bool findFacultyMemberByName(Faculty *f)
{
    string name;
    cout << "Insert the name of the faculty member:" << endl;
    cout << "> ";
    name = askString();
    auto fm = f->find_member_by_name(name);
    if (fm != NULL)
    {
        fm->printInfo();
        return true;
    }
    cerr << "No member found." << endl;
    return false;
}

bool findFacultyMemberByCode(Faculty *f)
{
    int code;
    cout << "Insert the code of the faculty member:" << endl;
    cout << "> ";
    code = askNumericOption();
    auto fm = f->find_member_by_code(code);
    if (fm != NULL)
    {
        fm->printInfo();
        return true;
    }
    cerr << "No member found." << endl;
    return false;
}

bool findStudentNameCourseBST(Faculty *f)
{
    string name;
    int course_code;
    cout << "Insert the name of the student:" << endl;
    cout << "> ";
    name = askString();
    cout << "Insert the code of the student's course:" << endl;
    cout << "> ";
    course_code = askNumericOption();
    auto student = f->findStudent(name, course_code);
    if (student != NULL)
    {
        student->printInfo();
        return true;
    }
    cerr << "No member found." << endl;
    return false;
}

void findElements(Faculty *f)
{
    int option;
    cout << "Please pick one of the following options:" << endl;
    cout << "1. Find department by name" << endl;
    cout << "2. Find faculty member by name" << endl;
    cout << "3. Find member by code" << endl;
    cout << "4. Find Student by name and course (BST -> fast search)" << endl;
    cout << "5. Go back" << endl;
    option = askNumericOption(1, 5);
    switch (option)
    {
    case 1:
    {
        findDepartmentByName(f);
        break;
    }
    case 2:
    {
        findFacultyMemberByName(f);
        break;
    }
    case 3:
    {
        findFacultyMemberByCode(f);
        break;
    }
    case 4:
    {
        findStudentNameCourseBST(f);
        break;
    }
    case 5:
        break;
    }
}

Student *selectStudent(Faculty *f)
{
    int option;

    for (unsigned int i = 0; i != f->getStudents().size(); i++)
    {
        cout << i + 1 << ". " << f->getStudents().at(i)->getName() << endl;
    }
    option = askNumericOption(1, f->getStudents().size());
    return f->getStudents().at(option - 1);
}

bool calculateStudentsAverages(Faculty *f)
{
    if (f->getStudents().empty())
    {
        cerr << "No students available." << endl;
        return false;
    }
    Student *s = selectStudent(f);
    //float average = s->getAverage();
    vector<Subject> subjectsTaken = s->getSubjectsTaken();
    int code = s->getCode();
    float average = calcAverage(subjectsTaken, code);
    s->setAverage(average);
    cout << "The student's average is: " << average << endl;
    return true;
}

int main()
{
    int option;
    Faculty* f;
    
    while(true){
        cout << "Please pick one of the following option: " << endl;
        cout << "1. Create Faculty" << endl;
        cout << "2. Load Faculty" << endl;
        cout << "3. Exit" << endl;
        option = askNumericOption(1,7);
        switch(option){
            case 1:{
                
                f = new Faculty();
                setupFaculty(f);
                break;
            }

            case 2:{
                f =readFile("save");
                break;
            }

            case 3:{
                return 0;
                break;
            }


        }

    break;
    }

    
    while (true) {
        cout << "Please pick one of the following option: " << endl;
        cout << "1. Print info" << endl;
        cout << "2. Add elements" << endl;
        cout << "3. Erase elements" << endl;
        cout << "4. Calculate students averages" << endl;
        cout << "5. Sort elements" << endl;
        cout << "6. Find elements" << endl;
        cout << "7. Save Faculty" <<endl;
        cout << "8. Quit" << endl;
        option = askNumericOption(1,8);
        switch (option) {
            case 1:
            {
                printInfo(f);
                break;
            }
            case 2:
            {
                addElements(f);
                break;
            }
            case 3:
            {
                eraseElements(f);
                break;
            }
            case 4:
            {
                int counter = 0;
                for (unsigned int i = 0; i != f->getFacultyMembers().size(); i++)
                {
                    if (dynamic_cast<Student *>(f->getFacultyMembers().at(i)))
                    {
                        counter++;
                    }
                }
                if (counter == 0)
                {
                    cerr << "No students available." << endl;
                    break;
                }
                    cout << "Faculty member needs to be a student!" << endl;
                    auto fm = selectFacultyMember(f);
                    if (dynamic_cast<Student *>(fm))
                    {
                        Student *s = dynamic_cast<Student *>(fm);
                        int average = s->getAverage();
                        cout << "The student's average is: " << average << "." << endl;
                        break;
                    }
                    break;
            }
            case 5:
            {
                sortElements(f);
                break;

            }
            case 6:
            {
                findElements(f);
                break;
            }
            case 8:
            {
                return 0;
            }

            case 7:
            {
                writeFile("save",*f);
                cout << "SAVED!" << endl;
                break;
            }
            
            
        }
    }
}
