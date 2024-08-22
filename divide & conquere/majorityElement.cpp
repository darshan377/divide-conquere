#include<iostream>
using namespace std;

int majorityElement(int a[],int low,int high){
    if(low == high){
        return a[low];
    }
    int mid = (low+high)/2;
    int leftMajority = majorityElement(a,low,mid);
    int rightMajority = majorityElement(a,mid+1,high);

    if(leftMajority == rightMajority){
       return leftMajority;
    }

    int leftCount=0, rightCount = 0;
    for(int i = low;i <= high;i++){
        if(a[i] == leftMajority){
            leftCount++;
        }
        else if(a[i] == rightMajority){
            rightCount++;
        }
    }

    return (leftCount > rightCount) ? leftMajority:rightMajority;
}

int main(){
      int a[] = {5,2,4,5,2,1,5};
      int n = sizeof(a)/sizeof(a[0]);
      int m = majorityElement(a,0,n-1);
      cout<<"majority element: "<<m<<endl;
}
