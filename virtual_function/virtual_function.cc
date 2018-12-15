/*
hackerrank c++ practice virtual function
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
    public:
        string name;
        int age;
    public:
        virtual void getdata(){};
        virtual void putdata(){};
};

class Professor : public Person {
    public: 
        int publication;
        static int seq_id;
        int cur_id;

    public:
        Professor(){
            ++seq_id;
            cur_id = seq_id;
        }

        void getdata(){
            cin >> this -> name >> this -> age >> this -> publication;
        }

        void putdata(){
            cout << this -> name << " " << this -> age << " " << this -> publication << " " << this -> cur_id << endl;
        }
};

int Professor:: seq_id = 0;

class Student : public Person {
    public: 
        static int seq_id;
        int cur_id; 
        vector< int > marks;

    public:
        Student(){
            ++seq_id;
            cur_id = seq_id;
            marks.resize(6);
        }
        
        void getdata(){
            cin >> this -> name >> this -> age;
            for(int i=0; i < this -> marks.size(); ++i) cin >> this -> marks[i];
        }

        void putdata(){
            int mark_sum(0);
            for(auto e : this -> marks) mark_sum += e;

            cout << this -> name << " " << this -> age << " ";
            cout << mark_sum << " " << this -> cur_id << endl;
        }
};

int Student:: seq_id = 0;


int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
