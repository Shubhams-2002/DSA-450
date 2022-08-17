#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    int i=n-1, j=0;
	    while(i>=0 && j<m){
	        if(arr1[i]>arr2[j]){
	            swap(arr1[i], arr2[j]);
	            i--;
	            j++;
	        }
	        else break;
	    }
	    sort(arr1, arr1+n);
	    sort(arr2, arr2+m);
	}
};

int main(){
    int n=4,m=5;
    int arr1[n]={1,3,5,7};
    int arr2[m]={0,2,6,8,9};

	int i=0,j=0;
	for(int gap=(m+n)/2; gap>0; gap=gap/2){
        for(int j=gap; j<n; j++){
            for(int i=j-gap; i>=0; i=i-gap){
                if(arr1[i]<arr1[i+gap]) break;
                else swap(arr1[i], arr1[i+gap]);
            }
        }
		for(int j=0; j<m;j++){
			for(int i=j+n-gap; i>=0; i=i-gap){
				if(i<n){
					if(arr1[i]<arr2[i+gap-n]) break;
                	else swap(arr1[i], arr2[i+gap-n]);
				}
                else{
					if(arr2[i-n]<arr2[i+gap-n]) break;
                	else swap(arr2[i-n], arr2[i+gap-n]);
				}
            }
		}
    }

    // int i=0,j=0;
	//     while(i<n){
	//         //if(i<n){
	//             if(arr2[j] < arr1[i]){
	//                 int t = arr2[j];
	//                 arr2[j] = arr1[n-1];
	//                 for(int k=n-1; k>i; k){
	//                     arr1[k]=arr1[k-1];
	//                 }
	//                 arr1[i] = t;
	//                 i++;
	//                 j++;
	//             }
	//             else{
	//                 i++;
	//             }
	//         }
	//         //else{
	//             sort(arr2, arr2 + m);
	//            // for(int a=0; a<m; a++){
	//            //     int minIdx=a;
	//            //     for(int b=a+1; b<m; b++){
	//            //         if(arr2[minIdx ]> arr2[b]){
	//            //             minIdx = b;
	//            //         }
	//            //     }
	//            //     int temp = arr2[minIdx];
	//            //     arr2[minIdx] = arr2[a];
	//            //     arr2[a] = temp;
	//            // }
	//         //}
	//     //}

    for(int p=0; p<(n); p++){
        cout<<arr1[p]<<",";
    }
    for(int p=0; p<(m); p++){
        cout<<arr2[p]<<",";
    }
    return 0;
}