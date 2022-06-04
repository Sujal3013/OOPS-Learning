#include <iostream>
using namespace std;
//function overloading
class Myworld{
    public:
    void func(){
        cout<<"I am a function with no argument"<<endl;
    }
    void func(int x){
        cout<<"I am a function with int argument"<<endl;
    }
    void func(double x){
        cout<<"I am a function with double argument"<<endl;
    }
};

int main(){
    Myworld obj;
    obj.func();
    obj.func(4);
    obj.func(6.2);

    return 0;
}