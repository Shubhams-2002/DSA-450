#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
    int m=4;
    int a[5] = {2,3,3,5,6};
    int b[4] = {5,6,7,9};
        // sort(a, a+n);
        // sort(b, b+m);
        int arr[m+n];
        int i=0,j=0,k=0,count=0;
        while(i<n || j<m){
            if(a[i]<b[j]){
                if(arr[k-1]!=a[i]){
                    arr[k]=a[i];
                    k++;
                }
                cout<<a[i]<<",";
                i++;
                
            }
            else if(a[i] == b[j]){
                
                if(arr[k-1]!=a[i]){
                    arr[k]=a[i];
                    k++;
                }
                cout<<a[i]<<",";
                i++;
                j++;
                count++;
            }
            else{
                if(arr[k-1]!=b[j]) {
                    arr[k]=b[j];
                    k++;
                }
                cout<<b[j]<<",";
                j++;
            }
        }
    cout<<endl;
    for(int p=0; p<(m+n-count); p++){
        cout<<arr[p]<<",";
    }
    return 0;
}