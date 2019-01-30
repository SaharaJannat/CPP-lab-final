#include<bits/stdc++.h>

using namespace std;

class Problem_Set
{
    string problem, solution;
    public:
    Problem_Set(){}
    Problem_Set(string problem, string solution)
    {
        this->problem = problem;
        this->solution = solution;
    }
    void show_Problem_Set()
    {
        cout<<"Problem: "<<this->problem<<endl;
        cout<<"Solution: "<<this->solution<<endl;
    }
};

class Person
{
    public:
    string name, birthday;
    Person(){};
    Person(string name,string birthday)
    {
        this->name=name;
        this->birthday=birthday;
    }
    void view_Person()
    {
        cout<<"Name: "<<this->name<<endl;
        cout<<"Birthday: "<<this->birthday<<endl;
    }

};

class Student : public Person
{
public:
    int id;
    int solved = 0;
    Problem_Set problem_set;
    bool finalist = 0;
    Student(){};
    Student(string name,string birthday,int id,int solved,Problem_Set problem_set , bool finalist ): Person(name,birthday)
    {
        this->id=id;
        this->solved=solved;
        this->problem_set=problem_set;
        this->finalist=finalist;
    }
    void view_student()
    {
        view_Person();
        cout<<"ID: "<<this->id<<endl;
        cout<<"No Of Solves: "<<this->solved<<endl;
        if(finalist)
            cout<<"ACM World Finalist"<<endl;
    }
    friend int getSolved(Student student);
    friend bool getStatus(Student student);
};
int getSolved(Student student)
{
    return student.solved;
}
bool getStatus(Student student)
{
    return student.finalist;
}

int main()
{
    Problem_Set problem_1("Problem 1,2,3","Solution 1,2,3");
    Problem_Set problem_2("Problem 4,5,6","Solution 4,5,6");
    Problem_Set problem_3("Problem 7,8,9","Solution 7,8,9");
    Problem_Set problem_4("Problem 10,11,12","Solution 10,11,12");
    Student *students[4]=
    {
       new Student("Tamim Shahriyar","12-07-98",1121,100,problem_1,true),
       new Student("Jasim Uddin","10-09-97",1141,20,problem_2,false),
       new Student("Kazi Nazrul","21-02-96",1162,220,problem_3,true),
       new Student("Abdur Rahman","16-12-96",1110,70,problem_4,false)
    };

    for(int i=0;i<4;i++)
    {
        int x=getSolved(*students[i]);
        if(x>200)
        {
            cout<<"No of selected Problems: 2"<<endl;
            students[i]->view_student();
        }
        else if(getStatus(*students[i]) || (x>=100 && x<=200))
        {
            cout<<"No of selected Problems: 1"<<endl;
            students[i]->view_student();
        }
        else
        {
            cout<<"No Problem Selected"<<endl;
            students[i]->view_student();
        }
        cout<<endl;
    }
    return 0;
}
