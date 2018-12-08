/**Q4:CSE department wants to select Programming Coach for its students.Any student of the department can be a coach.
He need to have high profile at least three ACM regional contest participation and number of problem solutions of ACM need to more 300.
Students need to apply in the department,if anyone’s performance is below the requirement he will discard automatically.
As a student of CSE, write OOP code for the project.All the communications will be held by message**/

#include<bits/stdc++.h>
using namespace std;

class Birthday
{
public:
    int day,month,year;
    Birthday(){};
    Birthday(int d,int m,int y){day=d;month=m;year=y;}
};

class Person                 ///Person class
{
public:
    string name;
    Birthday d1;
    Person(){}; ///Constructor-1 /Default Constructor
    Person(string n){name=n;}
    Person(string n,Birthday *d){name=n;d1=*d;}
};

class Department
{
public:
    string dept_name;
    Department(){};
    Department(string n){dept_name=n;}
};

class Student : public Person             /// Student class
{
public:
    int id,ACM,solve;
    Department d;
    Student(){};                                ///Constructor-1 /Default Constructor
    Student(string n,Birthday *d2,Department *dp,int dd,int acm,int s) : Person(n,d2){id=dd;d=*dp;ACM=acm;solve=s;}  ///constructor-2
    View_Student_Info()                        ///function for viewing student info
    {
        cout<<"Student Name: "<<name<<endl;
        cout<<"Department: "<<d.dept_name<<endl;
        cout<<"Students Birthday: "<<d1.day<<"-"<<d1.month<<"-"<<d1.year<<endl;
        cout<<"Number Of ACM Participation: "<<ACM<<endl;
        cout<<"Number Of Solved Problems: "<<solve<<endl;
    }
};

class Faculty : public Person                               ///faculty class
{
public:
    Student *s;
    string designation;
    Department dp;
    Faculty() {};                                                 ///Constructor-1 /Default Constructor
    Faculty(string d,string n,Department *dp1):Person(d)          ///constructor-2
    {
        designation=n;
        dp=*dp1;
    }
    View_Faculty()                                                ///faculty viewing function
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Department: "<<dp.dept_name<<endl;
        cout<<"Designation: "<<designation<<endl;
    }
    int select_coach(Student *s1)
    {
        s=s1;
        if(s->ACM>=3&&s->solve>300)
            return 1;
        else
            return 0;
    }
};

int main()
{
    Department *dp[5]=                      ///department type object declaration
    {
        new Department("CSE"),
        new Department("CSE"),
        new Department("CSE"),
        new Department("CSE"),
        new Department("CSE"),
    };

    Birthday *dt[4]=                             ///date type object declaration
    {
        new Birthday(20,8,1996),
        new Birthday(15,05,1995),
        new Birthday(13,11,1993),
        new Birthday(18,02,1983)
    };

    Student *s[3]=                               ///Student type object declaration
    {
        new Student("Ashikur",dt[0],dp[0],1001,4,301),
        new Student("Showrov",dt[1],dp[1],1002,4,400),
        new Student("Rahman",dt[2],dp[2],1003,2,200)
    };

    Faculty *f[2]=                                ///faculty object declaration.
    {
        new Faculty("Zakir","Professor",dp[3]),
        new Faculty("Anower","Lecturer",dp[4])
    };

    cout<<"The Details of Faculty Member: "<<endl<<endl;

    for(int i=0; i<2; i++){
          f[i]->View_Faculty();
          cout<<endl;
        }
      cout<<endl<<endl;
      cout<<"The Details of Students: "<<endl<<endl;
    for(int i=0; i<3; i++){
        s[i]->View_Student_Info();
            cout<<endl;
        }
    int x;
      cout<<endl<<endl;
    for(int i=0;i<3;i++)
    {
        x=f[i]->select_coach(s[i]);
        if(x==1)
        {
            cout<<"The Student Can be Selected as COACH......"<<endl<<endl;
            cout<<"Details Of The Student is: "<<endl<<endl;
            s[i]->View_Student_Info();
            cout<<endl<<endl<<endl<<endl;
        }
        else
        {
            cout<<"The Student is Not Selected as COACH......"<<endl<<endl;
            cout<<"Details Of The Student is: "<<endl<<endl;
            s[i]->View_Student_Info();
            cout<<endl<<endl;
        }
    }
   return 0;
}
