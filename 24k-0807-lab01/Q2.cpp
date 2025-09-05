#include<iostream>
using namespace std;

class Box{
    int *volume;

    public:
    Box(){
        volume=new int(0);
    }

    Box(int v){
        volume=new int(v);
    }

    Box(const Box& obj){
        volume=new int(*obj.volume);
    }

    ~Box(){
        delete volume;
    }

    void setVolume(int v){
        *volume=v;

    }

    void print() const{
        cout<<"Box volume :"<< *volume <<endl;
}
};

int main(){
    Box b1;
    b1.print();

    Box b2(45);
    b2.print();

    Box b3=b2;
    cout << "After copy constructor:" << endl;
    b2.print();
    b3.print();

    b2.setVolume(60);
    cout<<"after changing b2: "<<endl;
    b2.print();
    b3.print();
}