#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void shellSort(int a[], int n){
    for(int gap=n/2; gap>0; gap=gap/2){
        for(int j=gap; j<n; j++){
            for(int i=j-gap; i>=0; i=i-gap){
                if(a[i]<a[i+gap]) break;
                else swap(a[i], a[i+gap]);
            }
        }
    }
}

int main(){
    int a[5] = {6,2,3,1,0};
    shellSort(a,5);
    for(int p=0; p<5; p++){
        cout<<a[p]<<",";
    }
    return 0;
}