#include "../include/utilities.hpp"

using namespace std;
/**
 * @brief Function that splits a string into multiple ints
 * 
 * @param s -inputstring
 * @return vector<int> - The ints found
 */
vector<int> stringToInts(string &s)
{
    string temp;
    vector<int> result;

    while (!s.empty())
    {
        temp = s.substr(0, s.find(' '));
        s.erase(s.begin(), s.begin() + s.find(' ') + 1);
        result.push_back(stoi(temp));
    }
    return result;
}
/**
 * @brief Reconstructs maps for serialization purpose
 * 
 * @param s - Input String
 * @return map<int, float> - Output Map 
 */
map<int, float> mapReconstruction(string &s)
{
    string temp, first, second;
    map<int, float> result;

    while (!s.empty())
    {
        temp = s.substr(0, s.find(' '));
        if (temp.empty())
        {
            break;
        }
        s.erase(s.begin(), s.begin() + s.find(' ') + 1);
        first = temp.substr(0, temp.find('|'));
        second = temp.substr(temp.find('|') + 1, temp.find(' '));
        result.emplace(stoi(first), stof(second));
    }
    return result;
}
/**
 * @brief Saves the data Structure
 * 
 * @param filename - Filename to save to
 * @param faculty - Faculty to save
 */
void writeFile(std::string filename, Faculty &faculty)
{

    ofstream f;

    f.open(filename + ".txt");

    if (!f.is_open())
    {
        cout << "Error Opening file\n";
    }

    faculty.compatedInformation(f);

    f.close();
}
/**
 * @brief Incializes a subject from the text file
 * 
 * @param f - file stream
 * @param disciplinas - 
 * @return Subject* 
 */
Subject *process_subject(ifstream &f, vector<Subject *> &disciplinas)
{
    cout<<"Subject in\n";
    string line;
    Subject *p = new Subject;
    disciplinas.push_back(p);
    getline(f, line);
    p->setNamePT(line);
    getline(f, line, '\n');
    p->setNameEN(line);
    getline(f, line, '\n');
    p->setRegentCode(stoi(line));
    getline(f, line, '\n');
    p->setCode(stoi(line));
    getline(f, line, '\n');
    p->setLectiveYear(stoi(line));
    getline(f, line, '\n');
    p->setECTS(stof(line));
    getline(f, line, '\n');
    p->setWorkLoad(stoi(line));

    getline(f, line, '\n');
    p->setTeachersCode(stringToInts(line));
    getline(f, line, '\n');
    p->setStudentsCode(stringToInts(line));
    getline(f, line, '\n');
    p->setGrades(mapReconstruction(line));
    getline(f, line, '\n');
    cout<<"Subject out: " << line <<"\n";
    if (line == "#Subject#")
    {
        return p;
    }
}

//vectors
//vector<Faculty *> faculdades;
//int id_faculdade = 0;
static vector<Department *> departamentos;
//int id_departamentos = 0;
//static vector<Course *> cursos;
//int id_cursos = 0;
static vector<Subject *> disciplinas_g;
//int id_disciplinas = 0;
static vector<Staff *> staffs;
static vector<Teacher *> professores;
/**
 * @brief Incializes a Bachelors from the text file
 * 
 * @param f .file stream
 * @param cursos - vector to add the object created
 * @return Bachelors* -returns a pointer to the object
 */
Bachelors *process_Bachelors(ifstream &f, vector<Course *> &cursos)
{
    string line;
    Bachelors *p = new Bachelors;
    cursos.push_back(p);
    map<int, std::vector<Subject *>> curricularPlan;

    getline(f, line, '\n');
    p->setDuration(stoi(line));

    getline(f, line, '\n');
    p->setCode(stoi(line));
    getline(f, line, '\n');
    p->setName(line);
    getline(f, line, '\n');
    p->setDirector(line);

    while (line != "#Bachelors#")
    {
        getline(f, line, '\n');
        int first = stoi(line.substr(1));

        vector<Subject *> second;
        getline(f, line, '\n');
        while (line != "/")
        {
            second.push_back(process_subject(f, disciplinas_g));
            getline(f, line, '\n');
        }
        getline(f, line, '\n');
        curricularPlan.emplace(first, second);
        second.erase(second.begin(), second.end());
    }
    p->setCurricularPlan(curricularPlan);
    return p;
}
/**
 * @brief Incializes a Masters from the text file
 * 
 * @param f .file stream
 * @param cursos - vector to add the object created
 * @return Bachelors* -returns a pointer to the object
 */
Masters *process_Masters(ifstream &f, vector<Course *> &cursos)
{
    cout << "master in\n";
    string line;
    Masters *p = new Masters;
    cursos.push_back(p);
    map<int, std::vector<Subject *>> curricularPlan;

    getline(f, line, '\n');
    p->setDuration(stoi(line));

    getline(f, line, '\n');
    p->setCode(stoi(line));

    getline(f, line, '\n');
    p->setName(line);
    getline(f, line, '\n');
    p->setDirector(line);

    while (line != "#Masters#")
    {
        
        getline(f, line, '\n');
        int first = stoi(line.substr(1));
        vector<Subject *> second;
        getline(f, line, '\n');
        while (line != "/")
        {
            cout<< "why:" << line <<"\n";
            second.push_back(process_subject(f, disciplinas_g));
            getline(f, line, '\n');
        }
        getline(f, line, '\n');
        curricularPlan.emplace(first, second);
        second.erase(second.begin(), second.end());
    }
    p->setCurricularPlan(curricularPlan);
    cout << "masters out\n";
    return p;
}

/**
 * @brief Incializes a IntegratedMasters from the text file
 * 
 * @param f .file stream
 * @param cursos - vector to add the object created
 * @return Bachelors* -returns a pointer to the object
 */
IntegratedMasters *process_IntegratedMasters(ifstream &f, vector<Course *> &cursos)
{
    string line;
    IntegratedMasters *p = new IntegratedMasters;
    cursos.push_back(p);
    map<int, std::vector<Subject *>> curricularPlan;

    getline(f, line, '\n');
    p->setDuration(stoi(line));

    getline(f, line, '\n');
    p->setCode(stoi(line));
    getline(f, line, '\n');
    p->setName(line);
    getline(f, line, '\n');
    p->setDirector(line);

    while (line != "#IntegratedMasters#")
    {
        getline(f, line, '\n');
        int first = stoi(line.substr(1));

        vector<Subject *> second;
        getline(f, line, '\n');
        while (line != "/")
        {
            second.push_back(process_subject(f, disciplinas_g));
            getline(f, line, '\n');
        }

        curricularPlan.emplace(first, second);
        second.erase(second.begin(), second.end());
        getline(f, line, '\n');
    }
    p->setCurricularPlan(curricularPlan);
    return p;
}
/**
 *
 * @brief Incializes a Department from the text file
 * 
 * @param f .file stream
 * @param cursos - vector to add the object created
 * @return Bachelors* -returns a pointer to the object
 */
Department *process_department(ifstream &f, vector<Department *> &departamento)
{
    vector<Course *> courses;
    Department *p = new Department();
    departamentos.push_back(p);
    string line;
    getline(f, line, '\n');
    p->setName(line);

    getline(f, line, '\n');
    while (line != "#Department#")
    {

        if (line == "#Bachelors")
        {
            process_Bachelors(f, courses);
        }

        if (line == "#Masters")
        {
            process_Masters(f, courses);
        }

        if (line == "#IntegratedMasters")
        {
            process_IntegratedMasters(f, courses);
        }
        getline(f, line, '\n');
    }

    p->setCourses(courses);

    return p;
}
/**
 * @brief Incializes a Staff object from the text file
 * 
 * @param f .file stream
 * @param cursos - vector to add the object created
 * @return Bachelors* -returns a pointer to the object
 */
Staff *process_staff(ifstream &f)
{
    string line;
    Staff *p = new Staff();
    //staffs.push_back(p);

    getline(f, line, '\n');
    p->setName(line);
    getline(f, line, '\n');
    p->setAddress(line);
    getline(f, line, '\n');
    p->setBirthDate(line);
    getline(f, line, '\n');
    p->setCellphoneNumber(stoi(line));
    getline(f, line, '\n');
    p->setCode(stoi(line));
    getline(f, line, '\n');
    p->setTaxpayerNumber(stoi(line));
    getline(f, line, '\n');
    p->setSalary(stoi(line));
    getline(f, line, '\n');
    p->setFieldOfWork(line);

    return p;
}
/**
 * @brief Incializes a Teacher object from the text file
 * 
 * @param f .file stream
 * @param cursos - vector to add the object created
 * @return Bachelors* -returns a pointer to the object
 */
Teacher *process_teacher(ifstream &f)
{

    string line;
    Teacher *p = new Teacher();
    // professores.push_back(p);
    getline(f, line, '\n');
    p->setName(line);
    //cout << line << ":name\n";

    getline(f, line, '\n');
    p->setAddress(line);

    getline(f, line, '\n');
    //cout << line << ":Date\n";
    p->setBirthDate(line);
    
    getline(f, line, '\n');
    p->setCellphoneNumber(stoi(line));
    getline(f, line, '\n');
    p->setCode(stoi(line));
    //cout << line << ":CellPhoneNumber\n";

    getline(f, line, '\n');
    p->setCategory(line);
    //cout << line << "Category\n";

    getline(f, line, '\n');
    p->setTaxpayerNumber(stoi(line));

    getline(f, line, '\n');
    p->setSalary(stoi(line));

    getline(f, line, '\n');
    vector<int> temp;
    vector<Subject> final;

    getline(f, line, '\n');
    cout << "line before student:" << line << "\n";
    while (line != "#Student#")
    {

        temp.push_back(stoi(line));
        getline(f, line, '\n');
    }
    for (unsigned int i = 0; i < temp.size(); i++)
    {
        for (unsigned int j = 0; j < disciplinas_g.size(); j++)
        {
            if (disciplinas_g.at(j)->getCode() == temp.at(i))
            {
                final.push_back(*disciplinas_g.at(j));
                break;
            }
        }
    }
    getline(f, line, '\n');
    return p;
}
/**
 * @brief Incializes a Student object from the text file
 * 
 * @param f .file stream
 * @param cursos - vector to add the object created
 * @return Bachelors* -returns a pointer to the object
 */
Student *process_student(ifstream &f)
{
    string line;
    Student *p = new Student();
    //estudantes.push_back(p);

    getline(f, line, '\n');
    p->setName(line);

    getline(f, line, '\n');
    p->setAddress(line);

    getline(f, line, '\n');
    p->setBirthDate(line);

    getline(f, line, '\n');
    p->setCellphoneNumber(stoi(line));

    getline(f, line, '\n');
    p->setCode(stoi(line));

    getline(f, line, '\n');
    p->setCourse(stoi(line));

    getline(f, line, '\n');
    p->setAverage(stof(line));

    getline(f, line, '\n');
    p->setCurricularYear(stoi(line));

    getline(f, line, '\n');
    vector<int> temp;
    vector<Subject> final;
    while (line != "#Student#")
    {
        temp.push_back(stoi(line));
        getline(f, line, '\n');
    }
    for (unsigned int i = 0; i < temp.size(); i++)
    {
        for (unsigned int j = 0; j < disciplinas_g.size(); j++)
        {
            if (disciplinas_g.at(j)->getCode() == temp.at(i))
            {
                final.push_back(*disciplinas_g.at(j));
                break;
            }
        }
    }

    getline(f, line, '\n');
    p->setSubjectsTaken(final);
    return p;
}


/**
 * @brief read faculty from file
 * 
 * @param filename - File to read
 * @return Faculty* - Pointer to loaded Faculty
 */
Faculty *readFile(std::string filename)
{
    string line;
    ifstream f(filename + ".txt");

    if (!f.is_open())
    {
        cerr << "file not found!" << endl;
        return NULL;
    }

    while (line != "#Faculty")
    {
        getline(f, line, '\n');
    }

    Faculty *p = new Faculty;
    getline(f, line, '\n');
    p->setName(line);

    vector<Department *> departments;
    vector<FacultyMember *> facultyMembers;
    vector<Student *> students;
    getline(f, line, '\n');
    while (line != "#Faculty#")
    {
        cout << "new interaction\n";
        if (f.eof())
        {
            break;
        }

        if (line == "#Department")
        {
            cout << "departo in\n";
            departments.push_back(process_department(f, departamentos));
            getline(f, line, '\n');
            cout << "departamento out\n";
            continue;
        }

        if (line == "#Student")
        {
            cout << "Student in\n";
            auto temp = process_student(f);
            facultyMembers.push_back(temp);
            students.push_back(temp);
            getline(f, line, '\n');
            cout << "Student out";
            continue;
        }

        if (line == "#Teacher")
        {
            cout << "Teacher in\n";
            facultyMembers.push_back(process_teacher(f));
            getline(f, line, '\n');
            cout << "Teacher out\n";
            cout << line << ":end teach content\n";
            continue;
        }

        if (line == "#Staff")
        {
            cout << "Staff in\n";
            facultyMembers.push_back(process_staff(f));
            getline(f, line, '\n');
            cout << "Staff out\n";

            continue;
        }
        cout << "unknown\n";
    }
    //p->setFacultyMembers(facultyMembers);
    for(auto i = facultyMembers.begin(); i!= facultyMembers.end();i++){
        p->addFacultyMember(*i);
    }

    p->setDepartments(departments);
    p->setStudents(students);
   /* for (auto i = facultyMembers.begin(); i != facultyMembers.end(); i++)
    {
        p->addFacultyMember(*i);
    }*/
    disciplinas_g.erase(disciplinas_g.begin(), disciplinas_g.end());
    cout << "Done loading\n";
    return p;
}
