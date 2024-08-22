//count vowels in a string

#include<iostream>
using namespace std;

bool isVowel(char c){
     c = tolower(c);
     return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int countVowels(string s, int low, int high){
    if(low == high){
        return isVowel(s[low]) ? 1:0 ;
    }

    int mid = (low + high)/2 ;
    int l = countVowels(s,low,mid);
    int r = countVowels(s,mid+1,high);

    return l+r;
}

int main(){
    string s = "you can do it DARSHAN";
    int totalVowels = countVowels(s,0,s.length()-1);
    cout<<"total vowels: "<<totalVowels<<endl;
}
