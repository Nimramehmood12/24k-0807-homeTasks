#include<iostream>
using namespace std;

class Exam{
  int *marks;

  public:
  Exam(int m){
    marks=new int;
    *marks=m;
  }

  ~Exam(){
    delete marks;
  }

  void setMarks(int m){
    *marks=m;
  }

  int print() const{
    return *marks;
  }
};

int main(){
    Exam e1(67);
    cout<<"Original e1: "<<e1.print()<<endl;

    Exam e2=e1;
    cout<<"Copied e2: "<<e2.print()<<endl;

    e2.setMarks(100);

    cout << "After modifying e2:" << endl;
    cout << "e1 marks: " << e1.print() << endl;
    cout << "e2 marks: " << e2.print() << endl;
}

