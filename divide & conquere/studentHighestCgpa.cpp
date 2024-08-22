#include<iostream>
using namespace std;

struct student{
    string name;
    int id;
    double cgpa;
};

typedef struct student student;

student findHighestCgpa(student stdu[],int low,int high){
         if(low == high){
            return stdu[low];
         }
         int mid = (low+high)/2;
         student leftstudent = findHighestCgpa(stdu,low,mid);
         student rightstudent = findHighestCgpa(stdu,mid+1,high);

         return (leftstudent.cgpa > rightstudent.cgpa) ? leftstudent:rightstudent;
}

int main(){

    student stu[] = {
        {"Bob", 2, 3.8},
        {"Alice", 1, 3.5},
        {"Charlie", 3, 3.9},
        {"David", 4, 3.7},
        {"Eva", 5, 3.6}
    };

    int n = sizeof(student) / sizeof(stu[0]);
    student topStudent = findHighestCgpa(stu, 0, n - 1);
    cout << "Student with highest CGPA: " << topStudent.name << " with CGPA " << topStudent.cgpa << endl;
}
