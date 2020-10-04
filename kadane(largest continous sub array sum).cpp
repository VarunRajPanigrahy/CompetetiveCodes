#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int kadane(int arr[],int n){
  int i,meh = 0,msf=INT_MIN;
  for(i=0;i<n;i++){
    meh = meh+arr[i];
    if(meh < arr[i]){
      meh = arr[i];
    }
    if (msf<meh) {
      msf=meh;
    }
  }
  return msf;
}

int main(int argc, char const *argv[]) {
  int n;
  cout << "enter the length of the array:";
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  for(int i=0;i<n;i++){
    cout << arr[i] << " ";
  }
  cout << endl;

  int max_sum = kadane(arr,n);
  cout << max_sum <<endl;
  return 0;
}
