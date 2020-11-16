#include "../include/Course.hpp"

/**
 * Constructs a Course object with all parameters.
 * @param code  The code of the course
 * @param name  The name of the course
 * @param curricularPlan    The curricular plan of the course
 * @param director  The director of the course
 */
Course::Course(unsigned int code, std::string name,
               std::map<int, std::vector<Subject *>> curricularPlan, std::string director)
{

    if (director.length() == 0)
    {
        throw InvalidCourse(EMPTY_COURSE_DIRECTOR);
    }
    if (name.length() == 0)
    {
        throw InvalidCourse(EMPTY_COURSE_NAME);
    }

    this->code = code;
    this->name = name;
    this->curricularPlan = curricularPlan;
    this->director = director;
}

/**
 * Destructs a Course object.
 */
Course::~Course()
{
    for (unsigned int i = 0; i != curricularPlan.size(); i++)
    {
        for (unsigned int j = 0; j != curricularPlan.at(i).size(); j++)
        {
            delete curricularPlan.at(i).at(j);
            j--;
        }
    }
}

/**
 * Prints the information of a Course object.
 * Every atribuite of the class's object is printed.
 */
void Course::printInfo() const
{
    string courseheader = "- Course: " + this->getName();
    cout << courseheader << endl;
    cout << "Code: " << code << endl;
    cout << "Director: " << director << endl;
    if (!this->curricularPlan.empty())
    {
        for(auto i = curricularPlan.begin();i!=curricularPlan.end();++i){
           auto first =  i->first;
           auto second = i->second;
           for(auto j = second.begin();j != second.end();++j){
               (*j)->printInfo();
           }

        }
        
    }
}
/**
 * Sets the name of a Course object.
 * @param name The name of the course.
 */
void Course::setName(string name)
{
    this->name = name;
}

/**
 * Sets the code of a Course object.
 * @param code  The code of the course.
 */
void Course::setCode(unsigned int code)
{
    this->code = code;
}

/**
 * Sets the curricular plan of the course.
 * @param cp The curricular plan of the course.
 */
void Course::setCurricularPlan(map<int, vector<Subject *>> cp)
{
    this->curricularPlan = cp;
}

/**
 * Sets the director of the course.
 * @param director  The director of the course.
 */
void Course::setDirector(string director)
{
    this->director = director;
}

/**
 * Inserts a number of subjects into the respective curricular year.
 * @param year  The curricular year.
 * @param subjects  The subjects to be inserted.
 */
void Course::insertYearSubjects(unsigned int year,
                                vector<Subject *> subjects)
{
    if (curricularPlan.find(year) == curricularPlan.end())
    {
        curricularPlan.insert(pair<int, vector<Subject *>>(year, subjects));
    }
    else
    {
        for (unsigned int i = 0; i != subjects.size(); i++)
        {
            curricularPlan.at(year).push_back(subjects.at(i));
        }
    }
    //curricularPlan.insert(pair<int, vector<Subject *>>(year, subjects));
}

/**
 * Constructs a Bachelors objects with all the parameters.
 * @param code  The code of the course.
 * @param name  The name of the course.
 * @param curricularPlan    The curricular plan of the course.
 * @param director  The director of the course.
 */
Bachelors::Bachelors(unsigned int code, std::string name,
                     std::map<int, std::vector<Subject *>> curricularPlan,
                     std::string director) : Course(code, name, curricularPlan, director)
{

    this->duration = 3;
}

/**
 * Prints the values of the Bachelors' class attributes.
 */
void Bachelors::printInfo() const
{
    Course::printInfo();
    cout << "Duration: " << duration << endl;
}

/**
 * Sets the duration of the course.
 * @param d     The duration of the course.
 */
void Bachelors::setDuration(unsigned int d)
{
    this->duration = d;
}

/**
 * Constructs an object Master with every attribute as parameters.
 * @param code The code of the course.
 * @param name The name of the course.
 * @param curricularPlan The curricular plan of the course.
 * @param director The director of the course.
 */
Masters::Masters(unsigned int code, std::string name,
                 std::map<int, std::vector<Subject *>> curricularPlan,
                 std::string director) : Course(code, name, curricularPlan, director)
{
    this->duration = 2;
}

/**
 * Prints the values of every attribute of the class.
 */
void Masters::printInfo() const
{
    Course::printInfo();
    cout << "Duration: " << duration << endl;
}

/**
 * Sets the duration of the course.
 * @param d The duration of the course.
 */
void Masters::setDuration(unsigned int d)
{
    this->duration = d;
}

/**
 * Constructs an IntegratedMasters objects with every attribute
 * value as parameters.
 * @param code The code of the course.
 * @param name The name of the course.
 * @param curricularPlan The curricular plan of the course.
 * @param director The director of the course.
 */
IntegratedMasters::IntegratedMasters(unsigned int code,
                                     std::string name,
                                     std::map<int, std::vector<Subject *>> curricularPlan,
                                     std::string director) : Course(code, name, curricularPlan, director)
{
    this->duration = 5;
}

/**
 * Prints the values of every attribute of the class.
 */
void IntegratedMasters::printInfo() const
{
    Course::printInfo();
    cout << "Duration: " << duration << endl;
}

/**
 * Sets the duration of the course.
 * @param d The duration of the course.
 */
void IntegratedMasters::setDuration(unsigned int d)
{
    this->duration = d;
}

/**
 * Gets the code of the course.
 * @return The code of the course.
 */
unsigned int Course::getCode() const
{
    return code;
}

/**
 * Gets the name of the course.
 * @return The name of the course.
 */
std::string Course::getName() const
{
    return name;
}

/**
 * Gets the curricular plan of the course.
 * @return The curricular plan of the course.
 */
std::map<int, std::vector<Subject *>> Course::getCurricularPlan() const
{
    return curricularPlan;
}
/**
 * Gets the director of the course.
 * @return The director of the course.
 */
std::string Course::getDirector() const
{
    return director;
}

/**
 * Gets the duration of the course.
 * @return The duration of the course.
 */
unsigned int Bachelors::getDuration() const
{
    return duration;
}

/**
 * Gets the duration of the course.
 * @return The duration of the course.
 */
unsigned int Masters::getDuration() const
{
    return duration;
}

/**
 * Gets the duration of the course.
 * @return The duration of the course.
 */
unsigned int IntegratedMasters::getDuration() const
{
    return duration;
}

/**
 * Gets every subjec of the course.
 * @return Every subject of the course.
 */
vector<Subject> Course::getSubjects()
{
    vector<Subject> subjects;
    for (unsigned int i = 0; i != curricularPlan.size(); i++)
    {
        vector<Subject *> subjectsOfYear = curricularPlan.at(i + 1);
        for (unsigned int j = 0; j != subjectsOfYear.size(); j++)
        {
            Subject s = *(subjectsOfYear.at(j));
            subjects.push_back(s);
        }
    }
    return subjects;
}

/**
 * Erases a subject from the course.
 * @param subject A subject of the course.
 */
void Course::eraseSubject(Subject subject)
{
    for (unsigned int i = 0; i != curricularPlan.size(); i++)
    {
        for (unsigned int j = 0; j != curricularPlan.at(i).size(); j++)
        {
            if (*curricularPlan.at(i).at(j) == subject)
            {
                curricularPlan.at(i).erase(curricularPlan.at(i).begin() + j);
                return;
            }
        }
    }
}

/**
 * Compacts the information of a Bachelors course
 */
void Bachelors::compatedInformation(std::ofstream & f){
  f << "#Bachelor\n";
  f << duration << "\n"
  << code << "\n"
  << name << "\n"
  << director << "\n";

  for(std::map<int,std::vector<Subject *>>::iterator it = curricularPlan.begin() ; it!=curricularPlan.end() ;it++){
    f<<":"<<it->first<<"\n";
    std::vector<Subject *> temp = it->second;
    for(size_t i = 0; i < temp.size();i++){
      temp.at(i)->compatedInformation(f);

    }
    f<<"/"<<"\n";
  }

f<< "#Bachelor#\n";
}

/**
 * Compacts the information of a Masters
 */
void Masters::compatedInformation(std::ofstream & f){
  f << "#Masters\n";
  f << duration << "\n"
  << code << "\n"
  << name << "\n"
  << director << "\n";

  for(std::map<int,std::vector<Subject *>>::iterator it = curricularPlan.begin() ;it!=curricularPlan.end() ;it++){
    f<<":"<<it->first<<"\n";
    std::vector<Subject *> temp = it->second;
    for(size_t i = 0; i < temp.size();i++){
      temp.at(i)->compatedInformation(f);

    }
    f<<"/"<<"\n";
  }

f <<"#Masters#\n";

}

/**
 * Compacts the information of an Integrated Masters 
 */
void IntegratedMasters::compatedInformation(std::ofstream & f){
  f << "#IntegratedMasters\n";
  f << duration << "\n"
  << code << "\n"
  << name << "\n"
  << director << "\n";

  for(std::map<int,std::vector<Subject *>>::iterator it = curricularPlan.begin() ;it!=curricularPlan.end() ;it++){
    f<<":"<<it->first<<"\n";
    std::vector<Subject *> temp = it->second;
    for(size_t i = 0; i < temp.size();i++){
      temp.at(i)->compatedInformation(f);

    }
    f<<"/"<<"\n";
  }

f << "#IntegratedMasters#\n";

}
