#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void using_extra_space(vector<int>v){

    vector<int>left(v.begin(),v.end());
    vector<int>right(v.begin(),v.end());
    int i;
    for(i=1;i<v.size();i++){
      left[i] *= left[i-1];
    }
    cout << "left: " << endl;

    for(i=0;i<v.size();i++){
      cout << left[i] << " ";
    }

    cout << endl;

    for(i=v.size()-2;i>=0;i--){
      right[i] *= right[i+1];
    }
    cout << "right: " << endl;

    for(i=0;i<v.size();i++){
      cout << right[i] << " ";
    }
    cout << endl;

    for(i=0;i<v.size();i++){
      if(i==0){
        v[i] == right[i+1];
        continue;
      }
      else if(i==v.size()-1){
        v[i] = left[i-1];
        continue;
      }
      v[i] = left[i-1]*right[i+1];
    }

    for(i=0;i<v.size();i++){
      cout << v[i] << " ";
    }
    cout << endl;
}

void not_using_extra_space(vector<int>v){

  vector<int>left(v.begin(),v.end());
  int i;
  for(i=1;i<v.size();i++){
    left[i] *= left[i-1];
  }
  cout << "left: " << endl;

  for(i=0;i<v.size();i++){
    cout << left[i] << " ";
  }
  cout << endl;

  int prod=1;
  for(i=v.size()-1;i>=0;i--){
    if(i == v.size()-1){
      left[i] = left[i-1];
      prod *= v[i];
      continue;
    }
    else if(i==0){
      left[i] = prod;
      prod *= v[i];
      continue;
    }
    left[i] = prod*left[i-1];
    prod = prod*v[i];
  }

  for(i=0;i<v.size();i++){
    cout << left[i] << " ";
  }
  cout << endl;

}


int main(int argc, char const *argv[]) {
  vector<int>v{1,2,3,4};
  cout << "Using extra space:" << endl;
  using_extra_space(v);

  cout << "Not using extra space:" << endl;
  not_using_extra_space(v);
  return 0;
}
