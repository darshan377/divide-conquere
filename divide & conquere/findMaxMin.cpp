#include<iostream>
using namespace std;

void Rmaxmin(int a[],int i,int j,int &fmax,int &fmin){
     if(i == j){
        fmax = a[i];
        fmin = a[j];
     }
     else if(i == j-1){
        if(a[i] > a[j]){
            fmax = a[i];
            fmin = a[j];
        }
        else{
            fmax = a[j];
            fmin = a[i];
        }
     }
     else{
        int mid = (i+j)/2;
        int gmax,gmin;
        int hmax,hmin;
        Rmaxmin(a,i,mid,gmax,gmin);
        Rmaxmin(a,mid+1,j,hmax,hmin);
        fmax = max(gmax,hmax);
        fmin = min(gmin,hmin);
     }
}

int main(){
    int a[] = {3,5,4,15,29,1,71,11};
    int n = sizeof(a)/sizeof(int);
    int fmax,fmin;
    Rmaxmin(a,0,n-1,fmax,fmin);
    cout<<"max:"<<fmax<<endl;
    cout<<"min:"<<fmin<<endl;
}
