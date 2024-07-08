#include <iostream>
#include <vector>
#include <string>
#include<memory>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
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
/*
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

//};
/*
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
*/
/*class Recangle
{
private:
    int Length;
    int width;
public:
    Recangle():Length{0},width{0}
    {

    }
    Recangle(int L,int W): Length{L},width{W}
    {

    }
    void Set_parmeters()
    {
        cout<<"Enter The Length"<<endl;
        cin>>Length;
        cout<<"Enter The Width"<<endl;
        cin>>width;

    }
    void Get_parameters()
    {
        cout<<"The Length:"<<Length<<endl;
        cout<<"The width:"<<width<<endl;
    }
    ~Recangle()
    {

    }
    // add Length1 and Length2
    /* void Merge(Recangle r1,Recangle r2)
     {
         // this is pointer to  object that will call this function
         this->Length=r1.Length+r2.Length;
          this->width=r1.width+r2.width;
     }*/
/* Recangle Merge(Recangle r1,Recangle r2)
 {
     Recangle res;

     res.Length=r1.Length+r2.Length;
      res.width=r1.width+r2.width;
      return res;
 }*/
/*Recangle Merge(Recangle r)
{
    Recangle res;

    res.Length=r.Length+Length;
    res.width=r.width+width;
    return res;
}*/
/* Recangle operator+(Recangle r)
 {
     Recangle res;

     res.Length=r.Length+Length;
     res.width=r.width+width;
     return res;
 }*/
/*
Recangle operator-(Recangle r)
{
    Recangle res;

    res.Length=-r.Length+Length;
    res.width=-r.width+width;
    return res;
}
Recangle operator*(Recangle r)
{
    Recangle res;

    res.Length=r.Length*Length;
    res.width=r.width*width;
    return res;
}
Recangle operator/(Recangle r)
{
    Recangle res;

    res.Length=Length/r.Length;
    res.width=width/r.width;
    return res;
}
};
*/
/*
class Triangle
{
private:
    int Base;
    int Height;
public:
    Triangle():Base{0},Height{0}
    {

    }
    Triangle(int B,int H): Base{B},Height{H}
    {

    }
    void Set_parmeters()
    {
        cout<<"Enter The Base"<<endl;
        cin>>Base;
        cout<<"Enter The Height"<<endl;
        cin>>Height;

    }
    void Get_Area()
    {
        cout<<"The Area:"<<0.5*Base*Height<<endl;
    }
    ~Triangle()
    {

    }

    Triangle operator+(Triangle t)
    {
        Triangle tri;

        tri.Base=t.Base+Base;
        tri.Height=t.Height+Height;
        return tri;
    }

};
*/

class Unary
{
private:
    int x;
public:
    Unary() : x{0}
    {

    }
    Unary(int xa) : x{xa}
    {

    }
    ~Unary()
    {

    }
    void display()
    {
        cout<<"the X value:"<<x<<endl;
    }
    //x++ same as ++x
    /* Unary operator++()
     {
        ++x;
       return *this;
     }
     Unary operator++()
     {
        x++;
       return *this;
     }
     */
    Unary operator++()
    {
        ++x;
        return *this;
    }
// int not used
    Unary operator++(int)
    {
        Unary obj=*this;
        ++x;
        return obj;
    }
    Unary operator--()
    {
        --x;
        return *this;
    }
// int not used
    Unary operator--(int)
    {
        Unary obj=*this;
        --x;
        return obj;
    }
    Unary operator-()
    {
        x=-x;
        return *this;
    }
    bool operator!()
    {
        if(x!=0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    void operator+=(Unary obj)
    {
        x=x+obj.x;
    }
    void operator-=(Unary obj)
    {
        x=x-obj.x;
    }
    void operator*=(Unary obj)
    {
        x=x*obj.x;
    }
    void operator/=(Unary obj)
    {
        x=x/obj.x;
    }
    int operator<=(Unary obj)
    {
        if(x<=obj.x)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int operator>=(Unary obj)
    {
        if(x>=obj.x)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int operator==(Unary obj)
    {
        if(x==obj.x)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int operator!=(Unary obj)
    {
        if(x!=obj.x)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int operator%(Unary obj)
    {
        int y;

        y=(x%obj.x);

        return y;
    }
};


class Unary_Two
{
private:
    int x;
    int y;
public:
    Unary_Two() : x{0},y{0}
    {

    }
    Unary_Two(int xa,int ya) : x{xa},y{ya}
    {

    }
    ~Unary_Two()
    {

    }
    void display()
    {
        cout<<"the X value:"<<x<<endl;
        cout<<"the Y value:"<<y<<endl;
    }
    //x++ same as ++x
    /*Unary operator++()
    {
       ++x;
      return *this;
    }
    Unary operator++()
    {
       x++;
      return *this;
    }
    */

    Unary_Two operator++()
    {
        ++x;
        ++y;
        return *this;
    }
// int not used
    Unary_Two operator++(int)
    {
        Unary_Two obj=*this;
        ++x;
        ++y;
        return obj;
    }
    Unary_Two operator--()
    {
        --x;
        --y;
        return *this;
    }
// int not used
    Unary_Two operator--(int)
    {
        Unary_Two obj=*this;
        --x;
        --y;
        return obj;
    }
    Unary_Two operator-()
    {
        x=-x;
        y=-y;
        return *this;
    }
    bool operator!()
    {
        /* if((x==0)&&(y==0))
         {
             return 1;
         }
         else
         {
             return 0;
         }*/
        return ((x==0)&&(y==0));

    }


    void operator+=(Unary_Two obj)
    {
        x=x+obj.x;
        y=y+obj.y;
    }
    void operator-=(Unary_Two obj)
    {
        x=x-obj.x;
        y=y-obj.y;
    }
    void operator*=(Unary_Two obj)
    {
        x=x*obj.x;
        y=y*obj.y;
    }
    void operator/=(Unary_Two obj)
    {
        x=x/obj.x;
        y=y/obj.y;
    }
};


class Data
{
private:
    int data;
public:
    Data():data{0}
    {
        cout<<"the default constructor"<<endl;
    }
    Data(int d) :data{d}
    {
        cout<<"the paramters constructor"<<endl;
    }
    ~Data()
    {
        cout<<"the destructor"<<endl;
    }
    void Set_data(int d)
    {
        data=d;
    }
    int Get_data()
    {
        return data;
    }
};

int main(void)
{



    /*
    queue<float>q;
    float var;

    for(size_t i=0; i<5; i++)
    {
        cout<<"Enter Number"<<endl;
        cin>>var;
        q.push(var);
    }
    /*while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }*/
    /*
        cout<<endl<<"the size:"<<q.size()<<endl;
        for(size_t i=0; i<10; i++)
        {
            cout<<q.front()<<endl;
            q.pop();
        }
    */












    /* int var;
     stack<int>s;
     stack<int>s1;
     for(size_t i=0;i<5;i++)
     {
         cout<<"enter the value"<<endl;
         cin>>var;
         s.push(var);
     }
    */
    /*for (auto i:s)
    {
        cout<<s.top();
        s.pop();
    }
    */
// if you access more than its size  will give error
    /*for(size_t i=0;i<6;i++)
    {
        cout<<s.top();
        s.pop();
    }
    */
    /*s1=s;
    while(!s1.empty())
    {
        cout<<s1.top();
        s1.pop();
    }*/
//sizeof stack
//cout<<s.size();






// remove repeat value and sort it inscending
//set<int>s{1,2,3,9,5,5,4};
//set<int>::iterator it=s.begin();
// s.find ()
// if find element it return its number of iterator and you must *
// if dont find it it will return iterator to end
//s.count
//it is return 1 if it is find it
//return 0 if it is not find it
    /*if(s.count(10))
    {
       cout<<"existed"<<endl;
    }
    else
    {
        cout<<"existed"<<endl;
    }
    if(s.find(3)!=s.end())
    {
       cout<<"existed"<<endl;
    }
    else
    {
        cout<<"existed"<<endl;
    }
    for(auto i:s)
    {
        cout<<i<<endl;
    }


    */














    /* string Key;
     int value;
     map <string,int>mp;
     map <string,int>::iterator it=mp.begin();*/

    /* for(size_t i=0;i<5;i++)
     {
         cout<<"enter the key"<<endl;
         cin>>Key;
           cout<<"enter the value"<<endl;
         cin>>value;
         mp.insert(pair<string,int>(Key,value));

     }*/
    /*for(auto i : mp)
    {
         cout<<it->first<<"\t"<<it->second;
    }*/
    /*
    it=mp.begin();
    while(it!=mp.end())
    {
       cout<<it->first<<"\t"<<it->second;
       it++;
    }*/
    // sort by alapha

    // we can not repeat key (name) so if repeat will remove
    // but number can be repeat
    /* mp=
     {

           {"Ahmed",77},{"Ismail",55},{"saleh",77},{"saleh",67}

     };
     cout<<mp.size()<<endl;
     //we can add another key(first) and value (second)
      mp["mohamed"]=99;
      mp.insert(pair<string,int>("mahmoud",99));
      for(it=mp.begin();it!=mp.end();it++)
      {

          cout<<"the key is"<<it->first<<" "<<"the value"<<it->second<<endl;
      }*/
    /*for(auto i:mp)
    {
        cout<<"the key is"<<i.first<<" "<<"the value"<<i.second<<endl;
    }
    */

//key is number and value is string
    /* mp=
        {

              {77,"ahmed"},{88,"ismai"}

        };
    */













    //int element;
    // vector<int>V1{1,-7,3,-4,-2}; //this will increase its size to hold extra element
    //vector<int>V2{6,7,8,9,10,66,77}; //this will decrease its size
    /*vector<int>V1;
    vector<int>::iterator it1=V1.begin();
    for(size_t i=0; i<10; i++)
    {
        cout<<"enter elment num"<<""<<i<<endl;
       cin>>element;
       V1.insert(V1.begin()+i,element);


    }
    */
    //vector<int>::iterator it2=V2.begin();
// sawp two vectors v1 has element of V2 and vice vice
    //swap(V1,V2);
    // sort inscending
    //sort(V1.begin(),V1.end());
    // sort deascending
    // sort(V1.begin(),V1.end(),greater<int>());
    /*for(it1=V1.begin(); it1!=V1.end(); it1++)
    {
        cout<<*it1<<endl;
    }
    cout<<"-------------------------------------------"<<endl;
    sort(V1.begin(),V1.end(),greater<int>());
    for(it1=V1.begin(); it1!=V1.end(); it1++)
    {
        cout<<*it1<<endl;
    }
    cout<<"last"<<V1.back();
    cout<<"front"<<V1.front();*/

    /* for(it2=V2.begin(); it2!=V2.end(); it2++)
     {
         cout<<*it2<<endl;
     }
    */









/*
vector<int>vec;
vector<int>::iterator it=vec.begin();
auto it=vec.begin();
auto it=vec.rbegin();
auto it=vec.cbegin();
vec.push_back(element)

for(it=vec.begin();it=!end();it++)
{
    cout<<*it;
}
vec.insert(vec.begin(),50);
vec.insert(vec.begin()+2,55);
vec.erase(vec.begin());
vec.erase(vec.end()-1)
vec.erase(vec.begin(),vec.begin()+2);
vec.clear();
vec.pop_back();
vec.back();
vec.front();
vec.emplace_back();
*/


    // int element;
// implment container
//vector<int>V1;
// use iterator acccording to required data structure with forward iterator
//vector<int>::iterator it=V1.begin();
// auto can be iterator with const and any type
//auto it=V1.begin();
//auto it=V1.rbegin();
// const pointer to show only not edit
//auto it=V1.cbegin();
    /*for(size_t i=0;i<5;i++)
    {
        cout<<"enter elment num"<<""<<i<<endl;
        cin>>element;
        //V1.push_back(element);
        V1.insert(V1.begin()+i,element);
    }*/
// begin and end is pointer where i can show and edit on value
    /*
    vector<int>::const_iterator it=V1.begin();
    for(it=V1.begin();it!=V1.end();it++)
    {
        //*it=5;
        cout<<"the elment"<<""<<*it<<endl;
    }
    */
// put value 50 in began of vector
//V1.insert(V1.begin(),50);
// put value 50 in third place of vector bec it is vector began from zero index
//V1.insert(V1.begin()+2,50);
//V1.erase(V1.begin()+1);
//V1.erase(V1.end()-1);
// remove by range
//V1.erase(V1.begin(),V1.begin()+2);
// remove all element of vector
//V1.clear();
//remove last element
//V1.pop_back();
// return last elment
//auto x=V1.back();
// return first elment
//auto x=V1.front();
// same func of push_back put in last empty place in vector
//V1.emplace_back(20);
    /*for(it=V1.begin();it!=V1.end();it++)
    {
        cout<<"the elment"<<""<<*it<<endl;
    }*
    //cout<<"BackX:"<<x<<endl;
    /*
    for(size_t i=0;i<7;i++)
    {
        cout<<V1[i]<<endl;
    }*/
    /*
    for(size_t i=0;i<7;i++)
    {
        cout<<V1.at(i)<<endl;
    }
    */
//rebegin start from last element and ++ will move backward
    /*
    vector<int>::reverse_iterator it=V1.rbegin();
    for(it=V1.rbegin();it!=V1.rend();it++)
    {
        cout<<"the elment"<<""<<*it<<endl;
    }*/














    /*
    vector <shared_ptr<Data>>vec={make_shared<Data>(100),make_shared<Data>(200),make_shared<Data>(300),make_shared<Data>(400)};

    vec.push_back(make_shared<Data>(5));
    vec.push_back(make_shared<Data>(10));
    vec.push_back(make_shared<Data>(20));
    vec.push_back(make_shared<Data>(30));
    for(auto v:vec)
    {
        cout<<v->Get_data()<<endl;
    }
    */
    /*
        //init vector -> hold -> unique ptr -.ptr-. hold obj ->data

        vector<unique_ptr<Data>>vec;//{make_unique<Data>(5),make_unique<Data>(10),make_unique<Data>(20),make_unique<Data>(30)};

        vec.push_back(make_unique<Data>(5));
        vec.push_back(make_unique<Data>(10));
        vec.push_back(make_unique<Data>(20));
        vec.push_back(make_unique<Data>(30));
        // we put & bec in for loop it copy address that hold by unique pointer and unique pointer can not be copy so it is become complier error
        // so we put & to copy address of unique pointer so to be by refercence not by value
        for (auto &a:vec)
        {
            cout<<a->Get_data()<<endl;
        }

    */








    /*

    // can not asssign bbut can be intizalite
        unique_ptr<Data>p{new Data(5)};

        cout<<p->Get_data()<<endl;


    // address that  pointer hold
        cout<<p.get()<<endl;

    // can not be copied
        unique_ptr<Data>p2;

    // can be move address from pointer to another pointer and first pointer will be null

        p2=move(p);
    // p will hold null now
        p2->Set_data(20);
        cout<<p2->Get_data()<<endl;

        if(p)
        {
            cout<<endl<<"the pointer is existed"<<endl;
        }
        else
        {
            cout<<endl<<"the pointer is null"<<endl;
        }
        */
    // another init
    // unique_ptr<Data>P3={make_unique<Data>(5)};










    /*

    Data *ptr{new Data(5)};

    cout<<ptr->Get_data();

    delete ptr;
    */











    /*
        Unary_Two U1(10,0),U2(2,4);
       U1=U2--;
        U1.display();*/




    /*Unary u1(5),u2;

       cout<<"the bool "<<!u1;
      // u1.display();
       //u1.display();*/


    /*Unary u1(5),u2;
    // default is prefix as ++u not u++ as operator overloading
    u2=-u1; // postfix
    u2.display();
    u1.display();*/

    /*
        Unary u1(5),u2;
    // default is prefix as ++u not u++ as operator overloading
        u2=u1--; // postfix
        u2.display();
        u1.display();*/







    /*Triangle T1(5,6),T2(8,10),T3;

        T3=T1+T2;  // the same as calling to R3=R1.Merge(R2);
        T3.Get_Area();
    */


    /*Recangle R1(5,6),R2(8,10),R3;

    R3=R1+R2;  // the same as calling to R3=R1.Merge(R2);
    R3.Get_parameters();

    */

    /*Recangle R1(5,6),R2(8,10),R3;
       R3=R1.Merge(R2);
        R3.Get_parameters();*/



    /* Recangle R1(5,6),R2(8,10),R3;
     R3.Merge(R1,R2);
     R3.Get_parameters();*/






    /*  string name1="Ahmed ";

      string name2="Ismail";


      string name3=name1+name2;

      cout<<endl<<"the first name  "<<name1;
       cout<<endl<<"the second name  "<<name2;
        cout<<endl<<"the complete name "<<name3;*/










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
