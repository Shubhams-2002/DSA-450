#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool areRotations(string s1, string s2){
    int n = s2.length();
    if (s1.length() != s2.length()) return false;
    string s = s1 + s1;
    for(int i=0; i<=n; i++){
        if(s.substr(i,n) == s2) return true;
    }
    return false;
}

int main() {
	cout<<areRotations("ABCD", "CDAB");
	return 0;
}