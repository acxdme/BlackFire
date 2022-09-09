//Find the peak ,in a rotated sorted array.
#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[] = {4,5,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s <= e){
        if(arr[mid] < arr[mid+1])
         s = mid+1;
        else
         e = mid;
         
      mid = s + (e-s)/2;
    }
    cout<<mid<<endl;    
    return mid;//code
}
