#include<iostream>
using namespace std;

class student{
    string name;
    public: //By default : PRIVATE
    int age;
    bool gender;

    // DEFAULT CONSTRUCTOR
    student(){
        cout<<"Default constructor"<<endl;
    }

    //  parameterized constructor

    student(string s,int a,int g){
        cout<<"PARAMETERISED CONTRUCTOR"<<endl;
        name=s;
        age=a;
        gender=g;
    }

    // Copy constructor
    student(student &a){
        cout<<"Copy constructor"<<endl;
        name=a.name;
        age=a.age;
        gender=a.gender;
    }

    ~student(){
        cout<<"DESTRUCTOR CALLED"<<endl;;
    }

    // To access private data(here its string)
    // setter function
    void setname(string s){
        name = s;

    }

    // getter function
    void getname(){
        cout<<name<<endl;
    }

    void printinfo(){
        cout<<endl;
        cout<<"Name = ";
        cout<<name<<endl;
        cout<<"Age = ";
        cout<<age<<endl;
        cout<<"Gender = ";
        cout<<gender<<endl;

    }

// OPERATOR OVERLOADING
    bool operator == (student &a){
        if(name==a.name && age==a.age && gender==a.gender){
            return true;
        }else{
            return false;

        }
    }
};

int main(){
//  WE CAN ENTER DATA IN CLASSES INDIVIDUALLY OR IN GROUPS:
    // student a;
    // a.name='Urvi';
    // a.age=20;
    // a.gender=1;

    // NOW FOR EASY CODES WE CAN USE ARRAYS TO ENTER DATA
    // student arr[3];
    // for(int i=0;i<3;i++){
    //     string s;
    //     cout<<"Name = ";
    //     cin>>s;
    //     arr[i].setname(s);
    //     cout<<"Age = ";
    //     cin>>arr[i].age;
    //     cout<<"Gender = ";
    //     cin>>arr[i].gender;
    // }

    // for(int i=0;i<3;i++){
    //     arr[i].printinfo();
    // }

    // USING CONTRUCTOR FUNCTION
    student a("Neha",21,0);
    // a.printinfo();
    student b("Rahul",21,0);
    
    student c=a;

    if(c==a){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not same"<<endl;
    }

    return 0; //Destructor called here as all the objects of classes are destroyed while ending main function 

}
