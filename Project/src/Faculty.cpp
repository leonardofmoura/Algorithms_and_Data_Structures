#include "../include/Faculty.hpp"
#include "../include/Date.hpp"

/**
 * Constructs a Faculty object.
 */
Faculty::Faculty() : all_students(StudentPtr(NULL)) {}

/**
 * Constructs a Faculty object with all the attributes as parameters.
 * @param name The name of the Faculty.
 * @param departments The departments of the faculty.
 * @param facultyMembers The members of the faculty.
 */
Faculty::Faculty(std::string name, std::vector<Department *> departments,
                 std::vector<FacultyMember *> facultyMembers) : all_students(StudentPtr(NULL))
{
    if (name.length() == 0)
    {
        throw InvalidFaculty(1);
    }
    this->name = name;
    this->departments = departments;
    this->facultyMembers = facultyMembers;
}

/**
 * Destroys a Faculty object by deleting object in the vectors
 * departments and facultyMembers.
 */
Faculty::~Faculty()
{
    for (size_t i = 0; i != departments.size(); i++)
    {
        delete departments.at(i);
        i--;
    }
    departments.clear();
    for (size_t i = 0; i != facultyMembers.size(); i++)
    {
        delete facultyMembers.at(i);
        i--;
    }
    facultyMembers.clear();
}

/**
 * Gets the departments of the Faculty.
 * @return The departments of the faculty.
 */
std::vector<Department *> Faculty::getDepartments() const
{
    return departments;
}

/**
 * Gets the name of the Faculty.
 * @return The name of the faculty.
 */
std::string Faculty::getName() const
{
    return name;
}

/**
 * Gets the members of the faculty.
 * @return The members of the faculty.
 */
std::vector<FacultyMember *> Faculty::getFacultyMembers() const
{
    return facultyMembers;
}

/**
 * Sorts the departments by name in ascending order
 */
void Faculty::sort_departments_name_crescent()
{
    sort(departments.begin(), departments.end(), compare_department_name_crescent);
}

/**
 * Sorts the departments by name in descending order
 */
void Faculty::sort_departments_name_decrescent()
{
    sort(departments.begin(), departments.end(), compare_department_name_decrescent);
}

/**
 * Sorts departments by number of courses in ascending order
 */
void Faculty::sort_departments_number_of_courses_crescent()
{
    sort(departments.begin(), departments.end(), compare_department_number_of_courses_crescent);
}

/**
 * Sorts departments by number of courses in descending order
 */
void Faculty::sort_departments_number_of_courses_decrescent()
{
    sort(departments.begin(), departments.end(), compare_department_number_of_courses_decrescent);
}

/**
 * Sorts members by name in ascending order
 */
void Faculty::sort_member_name_crescent()
{
    sort(facultyMembers.begin(), facultyMembers.end(), compare_member_name_crescent);
}

/**
 * Sorts members by birth date in ascending order
 */
void Faculty::sort_member_birth_date_crescent()
{
    sort(facultyMembers.begin(), facultyMembers.end(), compare_member_birth_date_crescent);
}

/**
 * Sorts members by birth date in descending order
 */
void Faculty::sort_member_birth_date_decrescent()
{
    sort(facultyMembers.begin(), facultyMembers.end(), compare_member_birth_date_decrescent);
}

/**
 * Sorts members by code in ascending order
 */
void Faculty::sort_member_code_crescent()
{
    sort(facultyMembers.begin(), facultyMembers.end(), compare_member_code_crescent);
}

/**
 * Sorts members by code in descending order
 */
void Faculty::sort_member_code_decrescent()
{
    sort(facultyMembers.begin(), facultyMembers.end(), compare_member_code_decrescent);
}

/*COMPARE FUNCTIONS USED TO SORT*/
/**
 * Compare function used to sort departments by name
 * in ascending order
 * @param d1 The first department
 * @param d2 The second department
 * @return The smallest department
 */
bool compare_department_name_crescent(Department *d1, Department *d2)
{
    return d1->getName() < d2->getName();
}

/**
 * Compare function used to sort departments by name
 * in descending order
 * @param d1 The first department
 * @param d2 The second department
 * @return The biggest department
 */
bool compare_department_name_decrescent(Department *d1, Department *d2)
{
    return d1->getName() > d2->getName();
}

/**
 * Compare function used to sort departments by
 * number of courses in ascending order
 * @param d1 The first department
 * @param d2 The second department
 * @return The smallest department
 */
bool compare_department_number_of_courses_crescent(Department *d1, Department *d2)
{
    return d1->getCourses().size() < d2->getCourses().size();
}

/**
 * Compare function used to sort departments by
 * number of courses in descending order
 * @param d1 The first department
 * @param d2 The second department
 * @return The biggest department
 */
bool compare_department_number_of_courses_decrescent(Department *d1, Department *d2)
{
    return d1->getCourses().size() > d2->getCourses().size();
}

/**
 * Compare function used to sort
 * faculty members by name in ascending
 * order
 * @param f1 The first faculty member
 * @param f2 The second faculty member
 * @return The smallest faculty member
 */
bool compare_member_name_crescent(FacultyMember *f1, FacultyMember *f2)
{
    return f1->getName() < f2->getName();
}

/**
 * Compare function used to sort
 * faculty members by name in descending
 * order
 * @param f1 The first faculty member
 * @param f2 The second faculty member
 * @return The buggest faculty member
 */
bool compare_member_name_decrescent(FacultyMember *f1, FacultyMember *f2)
{
    return f1->getName() > f2->getName();
}

/**
 * Compare function used to sort
 * faculty members by birth date in
 * ascending order
 * @param f1 The first faculty member
 * @param f2 The second faculty member
 * @return The smallest faculty member
 */
bool compare_member_birth_date_crescent(FacultyMember *f1, FacultyMember *f2)
{
    Date f1_ = f1->getBirthDate();
    Date f2_ = f2->getBirthDate();

    return (f1_ < f2_);
}

/**
 * Compare function used to sort
 * faculty members by birth date in
 * descending order
 * @param f1 The first faculty member
 * @param f2 The second faculty member
 * @return The biggest faculty member
 */
bool compare_member_birth_date_decrescent(FacultyMember *f1, FacultyMember *f2)
{
    Date f1_ = f1->getBirthDate();
    Date f2_ = f2->getBirthDate();

    return (f1_ > f2_);
}

/**
 * Compare function used to sort
 * faculty members by code in
 * ascending order
 * @param f1 The first faculty member
 * @param f2 The second faculty member
 * @return The smallest faculty member
 */
bool compare_member_code_crescent(FacultyMember *f1, FacultyMember *f2)
{
    return (f1->getCode() < f2->getCode());
}

/**
 * Compare function used to sort
 * faculty members by code in
 * descending order
 * @param f1 The first faculty member
 * @param f2 The second faculty member
 * @return The biggest faculty member
 */
bool compare_member_code_decrescent(FacultyMember *f1, FacultyMember *f2)
{
    return (f1->getCode() > f2->getCode());
}
/**
 * Adds a department to the faculty.
 * @param d A department.
 */
void Faculty::addDepartment(Department *d)
{
    departments.push_back(d);
}

/**
 * Prints the information of a faculty, which is all the values
 * of its attributes.
 */
void Faculty::printInfo() const
{
    string header = "- Faculty: " + this->getName();
    cout << header << endl;
    for (unsigned int i = 0; i != departments.size(); i++)
    {
        this->departments.at(i)->printInfo();
    }
    for (unsigned int i = 0; i != facultyMembers.size(); i++)
    {
        this->facultyMembers.at(i)->printInfo();
    }
}

/**
 * Adds a faculty member to the university.
 * @param fm A faculty member.
 */
void Faculty::addFacultyMember(FacultyMember *fm)
{
    facultyMembers.push_back(fm);

    // test if its a student and add it to the bst
    Student *st = dynamic_cast<Student *>(fm);

    if (st != NULL)
    {
        StudentPtr stptr = StudentPtr(st);
        all_students.insert(st);
    }
    else{
        const FacultyMember temp = *fm;
        employeeRegister.insert(temp);
    }
}

/**
 * Sets the name of the faculty.
 * @param name A name for the faculty.
 */
void Faculty::setName(string name)
{
    this->name = name;
}

/**
 * Sets the departments of the faculty.
 * @param departments Some departments for the faculty.
 */
void Faculty::setDepartments(vector<Department *> departments)
{
    this->departments = departments;
}

/**
 * Erases a department of the faculty.
 * @param d A department of the faculty.
 */
void Faculty::eraseDepartment(Department *d)
{
    for (unsigned int i = 0; i != departments.size(); i++)
    {
        if (departments.at(i) == d)
        {
            departments.erase(departments.begin() + i);
            break;
        }
    }
}

/**
 * @brief Erases a faculty member
 * 
 * @param fm A faculty member
 * @return true Found the member and deleted it
 * @return false Didn't find the member and, thus, didn't delete it
 */
bool Faculty::eraseFacultyMember(FacultyMember *fm)
{
    for (unsigned int i = 0; i != facultyMembers.size(); i++)
    {
        if (facultyMembers.at(i) == fm)
        {
            facultyMembers.erase(facultyMembers.begin() + i);
            return true;
        }
    }
    return false;
}

bool Faculty::eraseStudent(Student *s)
{
    for (unsigned int i = 0; i != students.size(); i++)
    {
        if (students.at(i) == s)
        {   
            StudentPtr stu(students.at(i));
            all_students.remove(stu);
            students.erase(students.begin() + i);
            return true;
        }
    }
    return false;
}

/**
 * Finds a department with the provided name
 * @param name The name of the department to find
 * @return A pointer to the found department, or,
 * if not found, a NULL pointer
 */
Department *Faculty::find_deparment_by_name(std::string name) const
{
    for (size_t i = 0; i < this->departments.size(); i++)
    {
        if (this->departments[i]->getName() == name)
        {
            return this->departments[i];
        }
    }

    return NULL;
}

/**
 * Finds a faculty member with the provided name
 * @param name The name of faculty member
 * @return A pointer to the found department, or,
 * if not found, a NULL pointer
 */
FacultyMember *Faculty::find_member_by_name(std::string name) const
{
    for (size_t i = 0; i < this->facultyMembers.size(); i++)
    {
        if (this->facultyMembers[i]->getName() == name)
        {
            return this->facultyMembers[i];
        }
    }

    return NULL;
}

/**
 * Finds a faculty member with the provided name
 * @param code The code of faculty member
 * @return A pointer to the found department, or,
 * if not found, a NULL pointer
 */
FacultyMember *Faculty::find_member_by_code(int code) const
{
    for (size_t i = 0; i < this->facultyMembers.size(); i++)
    {
        if (this->facultyMembers[i]->getCode() == code)
        {
            return this->facultyMembers[i];
        }
    }

    return NULL;
}

/**
 * Gets every course of the faculty.
 * @return Every course of the faculty.
 */
vector<Course *> Faculty::getCourses()
{
    vector<Course *> courses;
    for (unsigned int i = 0; i != departments.size(); i++)
    {
        for (unsigned int j = 0; j != departments.at(i)->getCourses().size(); j++)
        {
            courses.push_back(departments.at(i)->getCourses().at(j));
        }
    }
    return courses;
}

/**
 * Finds the course of the faculty.
 * @param code The code of a course.
 * @return A pointer to a course.
 */
Course *Faculty::findCourse(unsigned int code)
{
    vector<Course *> courses = getCourses();
    for (unsigned int i = 0; i != courses.size(); i++)
    {
        if (courses.at(i)->getCode() == code)
        {
            return courses.at(i);
        }
    }
    Bachelors *c = new Bachelors();
    c->setName("NULL");
    return c;
}

/**
 * Adds a student to the scholarship queue
 */
void Faculty::addStudentScholarshipQueue(Student s)
{
    scholarship_queue.push(s);
}

/**
 * Gets the scholarship queue of the faculty
 */
priority_queue<Student> Faculty::getScholarshipQueue() const
{
    return this->scholarship_queue;
}

/**
 * Inserts a student in the faculty
 */
void Faculty::insertStudent(Student *s)
{
    StudentPtr st = StudentPtr(s);
    this->all_students.insert(st);
}

/**
 * Gets every student in the BST
 */
BST<StudentPtr> Faculty::getAllStudents() const
{
    return this->all_students;
}

/**
 * Finds a student in the BST
 */
Student *Faculty::findStudent(std::string name, int course) const
{
    Student finding = Student(name, course);
    StudentPtr findingPtr = StudentPtr(&finding);
    StudentPtr nfPtr = StudentPtr();
    StudentPtr found = all_students.find(findingPtr);

    if (found == nfPtr)
    {
        return NULL;
    }
    else
    {
        return found.getPtr();
    }
}

/**
 * Tests if the BST has everything stored correctly. For debugging 
 * purposes
 */
void Faculty::test()
{
    BSTItrIn<StudentPtr> it(this->all_students);

    while (!it.isAtEnd())
    {
        StudentPtr stu = it.retrieve();

        cout << stu.getPtr() << "\n";

        it.advance();
    }
}

/**
 * Adds a student to the faculty
 */
void Faculty::addStudents(vector<Student *> studentsToAdd)
{
    for (unsigned int i = 0; i != studentsToAdd.size(); i++)
    {
        this->students.push_back(studentsToAdd.at(i));
    }
}

/**
 * Gets the students of the faculty
 */
vector<Student *> Faculty::getStudents() const
{
    return students;
}


/**
 * Compacts the information of a Faculty
 */
void Faculty::compatedInformation(std::ofstream &f)
{
  f << "#Faculty\n"
    << name << "\n";

  for (size_t i = 0; i < departments.size(); i++)
  {
    departments.at(i)->compatedInformation(f);
  }

  //f << "!Member\n ";

  for (size_t i = 0; i < facultyMembers.size(); i++)
  {
    facultyMembers.at(i)->compatedInformation(f);
  }



  //f << "!Member!\n ";
  f << "#Faculty#\n";
}

/**
 * Sets the faculty members of a faculty
 */
void Faculty::setFacultyMembers(std::vector<FacultyMember *> v){
  this->facultyMembers = v;

}

/**
 * Sets the students of a faculty
 */
void Faculty::setStudents(std::vector<Student*> v){
    this->students = v;
}

/**
 * Prints the employtt register
 */
void Faculty::printEmployeeRegister(){
    for(auto i = employeeRegister.begin(); i != employeeRegister.end();i++){
        i->printInfo();
    }
}

/**
 * Gets the employee register
 */
HashTabStaff& Faculty::getEmployeeRegister() 
{
    return this->employeeRegister;
}

/**
 * Pops an element from the priority queue
 */
void Faculty::popPriorityQueue()
{
    this->scholarship_queue.pop();
}

/**
 * Deletes a employee from the register
 */
void Faculty::EmployeeRegister_delete(FacultyMember f){
   auto i =  employeeRegister.find(f);
    employeeRegister.erase(i);
}
