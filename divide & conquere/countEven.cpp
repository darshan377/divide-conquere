#include<iostream>
using namespace std;

int countEven(int a[],int low,int high){
    if(low == high){
        if(a[low]%2 == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    int mid = (low+high)/2;
    int l = countEven(a,low,mid);
    int r = countEven(a,mid+1,high);
    return l+r;
}

int main(){
    int a[] = {10,5,7,8,9,0,2,1};
    int x = countEven(a,0,7);
    cout<<"number of even: "<<x<<endl;

}
