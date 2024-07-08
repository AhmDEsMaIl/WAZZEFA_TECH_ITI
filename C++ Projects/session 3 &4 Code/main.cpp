#include <iostream>
#include <vector>
#include <string>
using namespace std ;

/*class student
{
private :
    string name;
    int ID;
    int GPA;
public:
    // Setters
    void Set_name(string n);

    void Set_ID(int n);

    void Set_GPA(int x);

    // getters
    string Get_name(void);

    int Get_ID(void);

    int Get_GPA(void);

    void Display_data(void);
    student();
    student(int i);
    student (int i,int g,string n);
    student(const student & scource);
    ~student();





};
// dealcator constructor method
/*student::student():student(0,0,"ahmed")
{

    cout<<endl<<"constructor defualt";


}
student::student(int i):student(i,0,"ahmed")
{

    cout<<endl<<"one constructor paranters";
}
student::student(int i,int g,string n):GPA{g},ID{i},name{n}
{
    cout<<endl<<"constructor parmters";
}*/
// copy constructor
/*
student :: student (const student & scource):ID{scource.ID},GPA{scource.GPA},name{scource.name}
{
    cout<<endl<<"copy constructor";
}
student::student():student(0,0,"ahmed")
{

    cout<<endl<<"constructor defualt";


}
student::student(int i):student(i,0,"ahmed")
{

    cout<<endl<<"one constructor paranters";
}
student::student(int i,int g,string n):GPA{g},ID{i},name{n}
{
    cout<<endl<<"constructor parmters";
}

// deconstrouctor
student::~student()
{
    cout<<endl<<"i am the deconstrouctor";
}

void student :: Set_name(string n)
{
    name=n;
}
void student :: Set_ID(int n)
{
    ID=n;
}
void student :: Set_GPA(int x)
{
    GPA=x;
}
string student :: Get_name(void)
{
    return name;
}
int student ::  Get_ID(void)
{
    return ID;
}
int student :: Get_GPA(void)
{
    return GPA;
}
void student :: Display_data(void)
{
    cout<<"the name"<<name<<endl;
    cout<<"the ID"<<ID<<endl;
    cout<<"the GPA"<<GPA<<endl;
}

class Player
{
private:
    int *data;
public :
    // Setters
    int Get_data();
    int Set_data(int x)
    {
        *data=x;
    }
    /*void Set_name(string n);



    void Set_exp(int x);

    // getters
    string Get_name(void);

    int Get_num(void);

    int Get_xp(void);

    void Display_data(void);*/
/*  Player(int x)
  {
      data= new int;
      *data=x;
      cout<<"i am the player constructor"<<endl;
  }
  ~Player()
  {
      delete data;
      cout<<"i am the player desstructor"<<endl;
  }
  Player(const Player & source)
  {
      data =new int;
      *data=*source.data;
      cout<<"i am the player copy----constructor"<<endl;
  }

};
// shallow copy passing by  value
void display_class(Player s)
{
  cout<<endl<<"data :"<<s.Get_data()<<endl;

}
int Player :: Get_data()
{
  return *data;
}
/*
void Player :: Set_name(string n)
{
  name=n;
}

void Player :: Set_exp(int x)
{
  xp=x;
}
string Player :: Get_name(void)
{
  return name;
}
int Player ::  Get_num(void)
{
  return num;
}
int Player :: Get_xp(void)
{
  return xp;
}
void Player :: Display_data(void)
{
  cout<<"the name"<<name<<endl;
  cout<<"the num"<<num<<endl;
  cout<<"the exp"<<xp<<endl;
}
int add(int x,int y)
{
  int res=x+y;
  return res;
}
float add(float x,float y)
{
  float  res=x+y;
  return res;
}
void add(void)
{
  cout<<"HeLLO\n";
}
/*char add(int x,int y,int z=0,int q=0)
{
  char  res=x+y+z+q;
  return res;
}*/
void temp(int &x,int  &y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}
/*class mine
{
private :
    int ID;
    string name;
public:
    void Set_ID(int ID)
    {
        this->ID=ID;
    }
    void Set_name(string name)
    {
        this->name=name;
    }
    mine * Get_ID()
    {
        return this;
    }
    string Get_name()
    {
        return name;
    }
};*/
/*class Car
{
    friend void display(Car c);
private:
    int model=2013;
    string factory;

};
void display(Car c)
{
    cout<<c.model<<endl;
}
*/
/*class Parent
{
private :

    int ID;

public :
    Parent(): ID{5}
    {
        cout<<"Parent default constrator"<<endl;
    }
    Parent( int ID):ID{ID}
    {
        cout<<"Parent paramters constrator"<<endl;
    }
    ~Parent()
    {
        cout<<"Parent  desconstrator"<<endl;
    }
    /*void Set_name(string name)
    {
        this->name=name;
    }
    void Set_ID(int ID)
    {
        this->ID=ID;
    }
    void Set_city(string city)
    {
        this->city=city;
    }
    string Get_name()
    {
        return name;
    }
    int Get_ID()
    {
        return ID;
    }
    string Get_city()
    {
        return city;
    }
*/

//};
/*class child : public Parent
{
private :
    int salary;

    /*int private_1(int x)
    {
        this->ID=x;
    }*/


/*public:
    child() : salary{0}
    {
        cout<<"child default constrator"<<endl;
    }
    child(int s) : Parent(s), salary{s}
    {
        cout<<"child paramters constrator"<<endl;
    }
    ~child()
    {

        cout<<"child  desconstrator"<<endl;
    }
    /*void Set_salary(int salary)
    {
        this->salary=salary;
    }

    void Set_Position(string Position)
    {
        this->Position=Position;
    }
    string Get_Position()
    {
        return Position;
    }
    int Set_salary()
    {
        return salary;
    }

};*/
/*
class Parent
{
protected :
    int Level;
    string name;
    int ID;

public :
    Parent(): ID{5}
    {
        cout<<"Parent default constrator"<<endl;
    }
    Parent( int ID):ID{ID}
    {
        cout<<"Parent paramters constrator"<<endl;
    }
    ~Parent()
    {
        cout<<"Parent  desconstrator"<<endl;
    }

};
class child : public Parent
{


public:
    child()
    {
        cout<<"child default constrator"<<endl;
    }

    ~child()
    {

        cout<<"child  desconstrator"<<endl;
    }
    void Set_ID(int ID)
    {
        this->ID=ID;
    }

    void Set_name(string name)
    {
        this->name=name;
    }
     void Set_Level(int Level)
    {
        this->Level=Level;
    }
    string Get_name()
    {
        return name;
    }
    int Get_ID()
    {
        return ID;
    }
    int Set_Level()
    {
        return Level;
    }

};*/
/*class Person
{
private :
    string name;
    string gender;
    int ID;
public :
    Person() : name{"none"},gender{"male"},ID{0}
    {
        cout<<endl<<"Person Default constrctor"<<endl;
    }
    Person(string n, string g,int i) : name{n}, gender{g}, ID{i}
    {
        cout<<endl<<"Psrson parmenter constrctor"<<endl;
    }
    ~Person()
    {
        cout<<endl<<"Person parmenter desnstrctor";
    }
    void Set_name(string n)
    {
        name=n;
    }
    void Set_gender(string g)
    {
        gender=g;
    }
    void Set_Id(int i)
    {
        ID=i;
    }
    string Get_name()
    {
        return name;
    }
    string Get_gender()
    {
        return gender;
    }
    int Get_ID()
    {
        return ID;
    }
    void display()
    {
        cout<<endl<<"Name:"<<name;
        cout<<endl<<"Gender:"<<gender;
        cout<<endl<<"ID:"<<ID;
    }

};
class Student
{
private :
    int Level;
    float GPA;
    string Name;
public:
    Student(): Level{0},GPA{0.0}
    {
        cout<<endl<<"Student Default constrctor"<<endl;
    }
    Student(int l, float g):Level{l},GPA{g}
    {
        cout<<endl<<"Student paramters constrctor"<<endl;
    }
    ~Student()
    {
        cout<<endl<<"Student paramters desnstrctor"<<endl;
    }
    void Set_Level(int l)
    {
        Level=l;
    }
    void Set_GPA(float g)
    {
        GPA=g;
    }
    float Get_GPA()
    {
        return GPA;
    }
    int Get_Level()
    {
        return Level;
    }
    void Set_name(string n)
    {
        Name=n;
    }
    string Get_name()
    {
        return Name;
    }
    void display()
    {
        cout<<endl<<"Level:"<<Level;
        cout<<endl<<"GPA:"<<GPA;
    }
};
class CollageStudent : public Person, public Student
{
private:
    string Study;
public:
    void Set_Study(string s)
    {
        Study=s;
    }
    string Get_Study()
    {
        return Study;
    }
    CollageStudent(string n,string ge, int i, int l,float g,string s): Person(n,ge,i),Student(l,g),Study{s}
    {
        cout<<endl<<"CollageStudent the paramters constrotor";
    }
    CollageStudent(): Person(),Student(),Study{"No study"}
    {
        cout<<endl<<"CollageStudent the default constrotor";
    }
    ~CollageStudent()
    {
        cout<<endl<<"CollageStudent the  desonstrotor";
    }
    void display()
    {
        // calling data in person by display
         Person::display();
         // calling data in s by Student display
         Student::display();
         cout<<endl<<"Study:"<<Study;
    }
};*/
/*
class Person
{
private :
    string name;
    string gender;
    int ID;
public :
    Person() : name{"none"},gender{"male"},ID{0}
    {
        cout<<endl<<"Person Default constrctor"<<endl;
    }
    Person(string n, string g,int i) : name{n}, gender{g}, ID{i}
    {
        cout<<endl<<"Psrson parmenter constrctor"<<endl;
    }
    ~Person()
    {
        cout<<endl<<"Person parmenter desnstrctor";
    }
    void Set_name(string n)
    {
        name=n;
    }
    void Set_gender(string g)
    {
        gender=g;
    }
    void Set_Id(int i)
    {
        ID=i;
    }
    string Get_name()
    {
        return name;
    }
    string Get_gender()
    {
        return gender;
    }
    int Get_ID()
    {
        return ID;
    }
    void display()
    {
        cout<<endl<<"Name:"<<name;
        cout<<endl<<"Gender:"<<gender;
        cout<<endl<<"ID:"<<ID;
    }

};
class Student : public Person
{
private :
    int Level;
    float GPA;
public:
    Student(): Person(),Level{0},GPA{0.0}
    {
        cout<<endl<<"Student Default constrctor"<<endl;
    }
    Student(string n,string ge,int id, int l, float g):Person(n,ge,id),Level{l},GPA{g}
    {
        cout<<endl<<"Student paramters constrctor"<<endl;
    }
    ~Student()
    {
        cout<<endl<<"Student paramters desnstrctor"<<endl;
    }
    void Set_Level(int l)
    {
        Level=l;
    }
    void Set_GPA(float g)
    {
        GPA=g;
    }
    float Get_GPA()
    {
        return GPA;
    }
    int Get_Level()
    {
        return Level;
    }
    void display()
    {
        cout<<endl<<"Level:"<<Level;
        cout<<endl<<"GPA:"<<GPA;
    }
};
class Employee : public Student
{
private:
    string Job;
    int Salary;
    int Bouns;
public:
    void Set_Job(string j)
    {
        Job=j;
    }
    string Get_Job()
    {
        return Job;
    }
    void Set_Salary(int s)
    {
        Salary=s;
    }
    int Get_Salary()
    {
        return Salary;
    }
    void Set_Bouns(int b)
    {
        Bouns=b;
    }
    int Get_Bouns()
    {
        return Bouns;
    }
    Employee(string n,string ge,int i,int l,float g,string j,int s,int b): Student(n,ge,i,l,g),Job{j},Salary{s},Bouns{b}
    {
        cout<<endl<<"Employee the paramters constrotor";
    }
    Employee(): Student(),Job{"No"},Salary{0},Bouns{0}
    {
        cout<<endl<<"Employee the default constrotor";
    }
    ~Employee()
    {
        cout<<endl<<"Employee the  desonstrotor";
    }
    void display()
    {
        // calling data in person by display
         Person::display();
         // calling data in s by Student display
         Student::display();
         cout<<endl<<"Job:"<<Job;
         cout<<endl<<"Salary:"<<Salary;
         cout<<endl<<"Bouns:"<<Bouns;
    }
};*/

class Shape
{
private :
    string Color;
public:
    void Set_color(string C)
    {
        Color=C;
    }
    string Get_Color()
    {
        return Color;
    }
    virtual int Get_area()=0;
    virtual void Set_Radius(int r)=0;
    virtual void Set_Length(int l)=0;
    virtual void Set_Width(int w)=0;
    // the same function
    /*virtual int Get_area()
    {
        return 0;
    }*/

};
class Rectangle : public Shape
{
private:
    int Length;
    int Width;
public:
    Rectangle(int l,int w) : Length{l},Width{w}
    {

    }
    void Set_Length(int l)
    {
        Length=l;
    }
    void Set_Width(int w)
    {
        Width=w;
    }
    int Get_area()
    {
        return Length*Width;
    }

};
#define pi            3.14
class circule : public Shape
{
private:
    int Radius;
public:

    void Set_Radius(int r)
    {
        Radius=r;
    }
    int Get_area()
    {
        return pi*Radius*Radius;
    }

};
int main(void)
{
    Shape *Ptr{nullptr},*Ptr_1{nullptr};
    circule c1(5);
    Rectangle R1(5,5);
    Ptr=&c1;
    Ptr_1=&R1;
    Ptr_1->Set_color("red");
    Ptr->Set_color("blue");
    Ptr->Set_Radius(5);
    cout<<"color"<<Ptr->Get_Color();
    cout<<"area :"<<Ptr->Get_area();
    cout<<"color"<<Ptr_1->Get_Color();
    cout<<"area :"<<Ptr_1->Get_area();
    /*
    Shape *Ptr{nullptr},*Ptr_1{nullptr};
    circule c1(5);
    Rectangle R1(5,5);
    Ptr=&c1;
    Ptr_1=&R1;
    Ptr_1->Set_color("red");
    Ptr->Set_color("blue");
    Ptr->Set_Radius(5);
    cout<<"color"<<Ptr->Get_Color();
    cout<<"area :"<<Ptr->Get_area();
    cout<<"color"<<Ptr_1->Get_Color();
    cout<<"area :"<<Ptr_1->Get_area();
*/





   /* Employee E("Ahmed","male",194103,500,3.8,"Embedded",10000,2003);
    // display data for person
    E.Person::display();
    // display data for Student
    E.Student::display();
    // display data for Employee
    E.Employee::display();
    // get set name from person bec it has two set name from person and student
    E.Person::Set_name("nooo");*/


    /*
        CollageStudent C("Ahmed","male",194103,500,3.8,"Embedded");
        // display data for person
       C.Person::display();
         // display data for Student
       C.Student::display();
        // display data for CollageStudent
       C.CollageStudent::display();
       // get set name from person bec it has two set name from person and student
       C.Person::Set_name("nooo");

    */
    /* child c;

     c.Set_name("Ahmed");

     cout<<"name "<<c.Get_name();*/






    /* string name;
     int ID, GPA;

     cout<<"enter name"<<endl;
     cin>>name;

     cout<<"enter ID"<<endl;
     cin>>ID;

     cout<<"enter GPA"<<endl;
     cin>>GPA;*/

    /* mine M1;
     M1.Set_name("Ahmed");
     M1.Set_ID(194103);
     cout<<endl<<M1.Get_name()<<endl;
     cout<<endl<<M1.Get_ID()<<endl;*/

    /* Car c1;
     display(c1);*/




    //  student p1(5,4,"ajh") ,p2(p1);


    /* p1.Set_name(name);
     p1.Set_ID(ID);
     p1.Set_GPA(GPA);*/


    /*cout<<endl;
    cout<<p3.Get_name()<<endl;
    cout<<p3.Get_ID()<<endl;
    cout<<p3.Get_GPA()<<endl;*/

    // p1.Display_data();












    /*string name;
    int num, xp;

    cout<<"enter name"<<endl;
    cin>>name;

    cout<<"enter number"<<endl;
    cin>>num;

    cout<<"enter exper"<<endl;
    cin>>xp;

    Player p1;
    p1.Set_name(name);
    p1.Set_num(num);
    p1.Set_exp(xp);

    cout<<p1.Get_name()<<endl;
    cout<<p1.Get_num()<<endl;
    cout<<p1.Get_xp()<<endl;

    p1.Display_data();*/







    /*  int x,y,z,sum=0;
      float ave;

          cout<<"enter your variable\n";
          cin>>x>>y>>z;
          sum=x+y+z;
          ave=sum/3.0;

      cout<<"sum : "<<sum<<endl;
       cout<<"aver : "<<ave<<endl;
    */

    /*int x,y,z,sum=0;
    float u,t,sum2=0;
      cout<<"enter your variable\n";
      cin>>x>>y;
      sum=add(x,y);
      cout<<"sum : "<<sum<<endl;*/

    /* cout<<"enter your variable\n";
     cin>>x>>y;
     sum=add(x,y);
     cout<<"sum: "<<sum<<endl;

     cout<<"enter your variable222\n";
     cin>>u>>t;
     sum2=add(u,t);
     cout<<"sum: "<<sum2<<endl;

     add();*/
    //vector <int>Scores{1000,2000,3000};
    /*vector <int>Scores(1,100);
    for(char i=0; i<Scores.size(); i++)
    {
        Scores.at(i)=10;
    }

    for(char i=0; i<Scores.size(); i++)
    {
        cout<<"Scores: "<<Scores.at(i)<<endl;
    }
    Scores.push_back(500);
    for(char i=0; i<Scores.size(); i++)
    {
        cout<<"Scores: "<<Scores.at(i)<<endl;
    }*/
    // vector<int>degree{100,200,300};

    /*  cout<<"size: "<<degree.size()<<endl;
      cout<<"size: "<<degree.capacity()<<endl;
      degree.push_back(300);
      cout<<"size: "<<degree.size()<<endl;
      cout<<"size: "<<degree.capacity()<<endl;*/
    /* int var;
     for(char i=0; i<1; i++)
     {
         cout<<"Enter the degree"<<endl;
         cin>>var;
         degree.push_back(var);
     }*/
    /*for(size_t i=0; i<degree.size(); i++)
    {
        cout<<"degree: "<<degree.at(i)<<endl;
    }
    */
    /* cout<<"size: "<<degree.size()<<endl;
     cout<<"size: "<<degree.capacity()<<endl;
     cout<<"size: "<<degree.max_size()<<endl;
    degree.resize(9);
     cout<<"size: "<<degree.size()<<endl;
     cout<<"size: "<<degree.capacity()<<endl;*/


    /* for(auto i=degree.rbegin(); i<degree.rend(); i++)
    {
        cout<<"degree: "<<*i<<endl;
    }*/
    /*
    if(degree.empty()==true)
    {
        cout<<"EMPTY";
    }
    else if (degree.empty()==false)
    {
        cout<<"E";
    }*/

    /* int *ptr{nullptr};
     ptr=new int;
     *ptr=5;*/


    /*    int *ptr= new int;
        *ptr=5;

        cout<<*ptr<<endl;
        delete ptr ;*/
    /*int Size;
    cout<<endl<<"Enter Size";
    cin>>Size;
    int arr[Size];
    for(int i=0; i<Size; i++)
    {
        cout<<"Enter element"<<endl;
        cin>>arr[i];
    }
    for(int i=0; i<Size; i++)
    {
        cout<<endl<<"element"<<endl;
        cout<<arr[i];
    }*/
    /* int Size{0};
     cout<<"Enter element"<<endl;
     cin>>Size;

     int  *ptr{nullptr};
     ptr=new int[Size];
      for(int i=0; i<Size; i++)
     {
         cout<<"Enter element"<<endl;
         cin>>ptr[i];
     }
    for(int i=0; i<Size; i++)
     {
         cout<<"element"<<endl;
         cout<<ptr[i];
     }*/

    /*int Size{0};
    cout<<"Enter Size";
    cin>>Size;
    int arr[Size];
    for(int i=0; i<Size; i++)
    {
       cout<<"Enter element"<<endl;
       cin>>arr[i];
    }
    for(auto element : arr)
    {
       cout<<element<<endl;
    }
    return 0;*/
    /* int mul=1;
     int fact=0;
     cout<<"Enter fact";
     cin>>fact;
     while(fact)
     {
         mul*=fact;
         fact--;
     }
    cout<<mul<<endl;*/
    /*int x=20;
    int & ref=x;
     cout<<x<<endl;
     ref=15;
     cout<<ref<<endl;*/
    /*int x=20;
    int y=10;

    temp(x,y);
    cout<<x<<endl;
    cout<<y<<endl;*/



}
