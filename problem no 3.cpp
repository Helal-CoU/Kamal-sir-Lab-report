#include<bits/stdc++.h>
#include<string.h>
#include<ctime>
#include<fstream>
using namespace std;

class Date
{
    public:
    string date;
    Date(){};
    Date(string date){this->date=date;}
};

class Person
{
public:
    string name;
    Date d;
    Person(){};
    Person(string name){this->name=name;}
    Person(string name,string date){this->name=name;d.date=date;}
};

class Department
{
public:
    string dpt_name;
    Department(){};
    Department(string name){dpt_name=name;}
};

class Student : public Person
{
  public:
      string id;
      Department dept;
      Student(){};
      Student(string n,string d,Department dpt_name,string id_no) : Person(n,d){id=id_no;dept=dpt_name;}

      view_student_info()
      {
          cout<<"Student Name: "<<name<<endl;
          cout<<"Department: "<<dept.dpt_name<<endl;
          cout<<"Student ID: "<<id<<endl;
          cout<<"Students Birthday: "<<d.date<<endl<<endl;
      }
      friend orderfood();
      friend blacklist();
};

class Sellsman : public Person
{
public:
    int seller_no;
    Sellsman(){};
    Sellsman(string name,string date2,int seller_no): Person(name,date2){this->seller_no=seller_no;}
    view_sellsman(){cout<<"Sells Person Name: "<<name<<endl;cout<<"Birthday: "<<d.date<<endl<<endl;}
    friend orderfood();
};

class Login
{
    string user_name;
    string password;
public:
    Login(){};
    Login(string user_name,string password){this->user_name=user_name;this->password=password;}
    friend blacklist();
};

class Faculty : public Person
{
public:
    string designation;
    Department department;
    Login login;
    Faculty(){};
    Faculty(string d,string n,Department dept1,Login *login2):Person(n){designation=d;department=dept1;login=*login2;}

    view_faculty()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Department: "<<department.dpt_name<<endl;
        cout<<"Designation: "<<designation<<endl<<endl;
    }
    Blacklist(int order_data[],string deliver_data[],Student *student[],string blacklist[])
    {
        cout<<"Blacklisted names are: \n";
        for(int n=0;n<4;n++)
        {
            if(order_data[n]==1)
           if(deliver_data[n]=="Didn't")
           {
             blacklist[n]=student[n]->name;
             cout<<"Name: "<<student[n]->name<<"\nID: "<<student[n]->id<<"\nYou have been blacklisted, Contact with Department"<<endl;
           }
        }
    };
};


    int view_system_time()
    {
    time_t k = time(0);
    struct tm *t = localtime(&k);
    cout<< t->tm_hour << ":" << t->tm_min << endl;
    return t->tm_hour;
    }

int orderfood(Student *student)
{
    int tm=view_system_time();
    if(tm>22)
    {
        cout<<"Sorry, You cannot Place the pre-order.\n";
        return -1;
    }
    else
    {
        cout<<"Name: "<<student->name<<"\nID: "<<student->id<<"\nYour Order Has been placed.\n\n";
        return 1;
    }
}

int main()
{
    int number_of_students=4;
    int temp=number_of_students;
    Department department("CSE");
    Student *students[number_of_students]=
    {
        new Student("Showrov","20-6-1996",department,"1001"),
        new Student("Ashik","13-3-1998",department,"1002"),
        new Student("Akash","21-11-1996",department,"1003"),
        new Student("Rony","05-07-1997",department,"1004")
    };

    Sellsman sells_person("Arif Hossain","13-03-1985",1);
    sells_person.view_sellsman();
    Login *login_data[2]={
                 new Login("RAB","111"),
                 new Login("KAL","222")
                 };
    Faculty *faculty_member[2]=
    {
        new Faculty("Professor","Ashik Ahmed",department,login_data[0]),
        new Faculty("Lecturer","Rabiul Islam",department,login_data[1])
    };
    for(int i=0;i<3;i++)
        students[i]->view_student_info();

    for(int i=0;i<2;i++)
    faculty_member[i]->view_faculty();

    int order_data[number_of_students],g=0;
    for(int i=0;i<number_of_students;i++)
    {

        g=orderfood(students[i]);
        order_data[i]=g;

    }
    string delivery_info[number_of_students]={"ordered","Didn't","ordered","Didn't"};
     string blacklisted_members[number_of_students];
     faculty_member[0]->Blacklist(order_data,delivery_info,students,blacklisted_members);

     ofstream students_file;
     students_file.open("Students.csv");
     students_file<<"Students are: \n";
     students_file<<"Roll,Name,Department\n";
     for(int i=0;i<number_of_students;i++)
     {
        students_file<<students[i]->id<<","<<students[i]->name<<","<<students[i]->dept.dpt_name<<endl;
     }



     ofstream blacklist_file;                    ///Blacklist part
     blacklist_file.open("Blacklist.csv");

     int counter=1;
      blacklist_file<<"Blacklisted names are:\n\n";
      blacklist_file<<"Roll,Name,Department\n";
      string blacklisted_id[number_of_students];
     for(int i=0;i<number_of_students;i++)
     {
         if(blacklisted_members[i]!="\0")
         {
          blacklist_file<<students[i]->id<<","<<blacklisted_members[i]<<","<<students[i]->dept.dpt_name<<endl;
             counter++;
             blacklisted_id[i]=students[i]->id;

         }
     }
     blacklist_file.close();
    cout<<"Blacklisted person included in file.\n";
    cout<<"New to order service?\nPress 1 to register or 0 to exit"<<endl;
    int new_order;
    cin>>new_order;
    while(new_order!=0)
    {
        string name,department_name,birthday,roll;
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"\nEnter ID:";
        cin>>roll;
        cout<<"\nEnter Department: ";
        cin>>department_name;
        cout<<"\nEnter birthday:";
        cin>>birthday;

        students[number_of_students]={new Student(name,birthday,department_name,roll)};
        number_of_students+=1;
        int order_data1;
       order_data1=orderfood(students[number_of_students-1]);
       cout<<"New to order service?\nPress 1 to register or 0 to exit"<<endl<<endl;
       cin>>new_order;
       if(new_order!=1)
        break;
    }
   string delivery_data2[number_of_students]={"ordered","Didn't","ordered","Didn't","ordered"};

    for(int i=temp;i<number_of_students;i++)
    {
        students_file<<students[i]->id<<","<<students[i]->name<<","<<students[i]->dept.dpt_name<<endl;
    }
    for(int i=0;i<number_of_students;i++)
    {
        if(blacklisted_id[i]!="\0" && students[i]->id==blacklisted_id[i] )
            cout<<students[i]->name<<"\nYou cannot order,You have been blacklisted.\nContact with Department"<<endl<<endl;
        else
            orderfood(students[i]);
    }
   return 0;
}
