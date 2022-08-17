#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool valid(string s1, string s2, string s){
    if(s1.length() + s2.length() != s.length()) return false;

    sort(s.begin(), s.end());
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    cout<<s1<<","<<s2<<","<<s<<endl;

    int i=0,j=0;
    for(int k=0; k<s.length(); k++){
        if(s[k] == s1[i]) i++;
        else if(s[k] == s2[j]) j++;
        else return false;
    }
    return true;
}

int main(){
    cout<<valid("1y", "x2", "x1y2")<<endl;
}