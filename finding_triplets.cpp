#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

vector<vector<int>>triplets(int arr[],int n){
  vector<vector<int>>sol;
  int curr,right,sum,left,count=0;
  bool f1=false;
  for(left=0;left<n-2;left++){
    cout << "------------------------------------------" << endl;
    if(f1 && arr[left] == arr[left-1]){
      continue;
    }
    f1=true;
    right = n-1;
    curr = left+1;
    bool f2 = false;
    bool f3 = false;
    while(curr < right){
      if(f2 && (arr[curr] == arr[curr-1])){
        curr++;
        continue;
      }
      if(f3 && (arr[right] == arr[right+1])){
        right--;
        continue;
      }
      sum = arr[left]+arr[curr]-arr[right];
      if(sum == 0){
        count++;
        vector<int>res(3);
        res[0]=arr[left];
        res[1]=arr[curr];
        res[2]=arr[right];
        sol.push_back(res);
        curr++;
      }
      else if(sum > 0){
        right--;
        f3=true;
      }
      else{
        curr++;
        f2=true;
      }
    }
  }
  cout << "Number of triplets found are:" << count << endl;
   return sol;
}

int main(int argc, char const *argv[]) {
  int n;
  cout << "enter the length of the array:";
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
 sort(arr,arr+n);
  for(int i=0;i<n;i++){
    cout << arr[i] << " ";
  }
  cout << endl;

  vector<vector<int>> sol = triplets(arr,n);

  return 0;
}
