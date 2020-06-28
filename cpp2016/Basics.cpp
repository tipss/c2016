#include <iostream>
using namespace std;
#define NAME_SIZE 50
/*
1. By default all variables, functions in Class are Private
2. A class with virtual function not implmented can;t be instantiated.
3. Class ends with semi colon.
4. Default variables in function definition are matched from Right to Left.
   This is C++ only feature,
    So if user call a function with less than number of variables in the function
    definition, it will stil be ok, as long as there are default values for rest of the
     parameters which are not passed looking right to left. 
5. Virtual Function allow you to help during static binding (compile time) to an existing Functions if implmented from child class.
6. Deleteing a class is very important freeing up memory.
7. Operator Overloading :  Enables us to apply operators like + to objects that would 
 otherwise not support these operations directly. 
 E.g Merge two objects book shelf
 Bookshelf  Bookshelf::operator+(Bookshelf &other) { //Merge Here }
7. 
*/

class Person {
public:
    int age;
    string name;
    public:
    Person(int age, string myname) {
        this->age  = age;
        this->name = myname; 
        cout << "I am a Person, aged " << age << "name="<< myname << endl;
    }
    virtual void addCourse(string s) = 0;
};

class Student: public Person {
   public:
   void aboutMe( ) {
        cout << "I am a Person, aged " << this->age << "name="<< this->name << endl;
   }
   void addCourse(string s){
    cout << "Added Course " << s << endl;
   }
};

int main() {
    Person *p = new Student(30);    
    Person *q = new Student("mike",30);    
    cout<<"Hello\n";
    p->aboutMe();
    q->aboutMe();
    p->addCourse("History");
    q->addCourse("History");
    delete p;
    return (0);
}
