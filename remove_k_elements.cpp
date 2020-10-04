#include<iostream>
#include<string>
#include <bits/stdc++.h>

using namespace std;

string least_num(string num,int k){
  int n = num.size();

          stack<char> mystack;
          for(char c: num)
          {
              while(!mystack.empty() && k>0 && mystack.top()>c)
              {   mystack.pop();      k-=1;   }

              if(!mystack.empty() || c!='0')
                  mystack.push(c);
          }

          while(!mystack.empty() && k--)
              mystack.pop();
          if(mystack.empty())
              return "0";

          //Now retrieve the number from stack into a string (reusing num)
          while(!mystack.empty())
          {
              num[n-1] = mystack.top();
              mystack.pop();
              n-=1;
          }
          return num.substr(n);
}

int main(int argc, char const *argv[]) {
  string str;
  getline(cin,str);
  int k;
  cin >> k;
  string out = least_num(str,k);
  cout << "Least number:" << out << endl;
  return 0;
}
