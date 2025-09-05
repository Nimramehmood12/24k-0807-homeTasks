#include<iostream>
#include<string>
using namespace std;

class ResearchPaper{
    string *name;
    int c;

 public:
    ResearchPaper():name(NULL),c(0){}

    ResearchPaper(const string author[],int count){
        c=count;
        if(count>0){
            name=new string[count];
            for(int i=0;i<count;i++){
                name[i]=author[i];
            }
                
        }
    }
    
    ResearchPaper(const ResearchPaper &obj){
        c=obj.c;
        if(c>0){
        name=new string[c];
        for(int i=0;i<c;i++){
            name[i]=obj.name[i];
        }}
    }

    ResearchPaper& operator=(const ResearchPaper& obj){
        if(this==&obj) return *this;

        delete[] name;

        c=obj.c;
        if(c>0){
        name=new string[c];
        for(int i=0;i<c;i++){
            name[i]=obj.name[i];
        }
    }
    return *this;
    }

    ~ResearchPaper(){
        delete[] name;
    }

    void add(const string& n){
        string *newArr=new string[c+1];
        for(int i=0;i<c;i++){
            newArr[i]=name[i];
        }
        newArr[c]=n;
        delete[] name;
        name=newArr;
        c++;
    }

    void print()const{
        cout<<"Authors:\n";
        for(int i=0;i<c;i++){
            cout<<" "<<(i+1)<<" "<<name[i]<<endl;
        }
    }
};

int main(){
    string author[]={"John","Ali","Sara","Shorouq"};
    ResearchPaper p1(author,4);

    cout<<"Original:"<<endl;
    p1.print();

    ResearchPaper p2=p1;
    ResearchPaper p3;
    p3=p1;

    cout << "Copy constructer:\n"; 
    p2.print();
    cout << "Assignment Operator:\n"; 
    p3.print();

    p1.add("Hafsa");

    cout<<"After changes:"<<endl;
    p1.print();
    p2.print();
    p3.print();
}

