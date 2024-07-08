#include <iostream>
#include <vector>
#include <string>
using namespace std ;

class student
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
    student (int i,int g,string n);
    ~student();




};
// constructor method
student::student():ID(0),GPA(1),name("yes")
{
    cout<<"constructor defualt";

}
student::student(int i,int g,string n):ID{i},GPA{g},name{n}
{
    cout<<"constructor parmters";
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
    string name;
    int num;
    int xp;
public :
    // Setters
    void Set_name(string n);

    void Set_num(int n);

    void Set_exp(int x);

    // getters
    string Get_name(void);

    int Get_num(void);

    int Get_xp(void);

    void Display_data(void);

};


void Player :: Set_name(string n)
{
    name=n;
}
void Player :: Set_num(int n)
{
    num=n;
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
/*void results (void)
{
    CPA=Get_ID();
    if(GPA==4)
    {
        cout<<"A";
    }
}*/
int main(void)
{


    /* string name;
     int ID, GPA;

     cout<<"enter name"<<endl;
     cin>>name;

     cout<<"enter ID"<<endl;
     cin>>ID;

     cout<<"enter GPA"<<endl;
     cin>>GPA;*/

    //student p1;

    //student p2(5,11,"esmail");

    /* p1.Set_name(name);
     p1.Set_ID(ID);
     p1.Set_GPA(GPA);*/


    cout<<endl;
    cout<<p2.Get_name()<<endl;
    cout<<p2.Get_ID()<<endl;
    cout<<p2.Get_GPA()<<endl;

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
    /*int Size{0};
    int arr[Size];
    cout<<"Enter Size";
    cin>>Size;
    for(int i=0; i<Size; i++)
    {
        cout<<"Enter element"<<endl;
        cin>>arr[i];
    }
    for(int i=0; i<Size; i++)
    {
        cout<<"element"<<endl;
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
