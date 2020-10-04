#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int count_anagrams(string word,string pword){
  int count = 0;
  vector<int> hash(26,0),phash(26,0);
  int len = word.size();
  int window = pword.size();
  int left=0,right=0;
  if(len < window){
    return 0;
  }
  while(right < window){
    hash[word[right]-'a']++;
    phash[pword[right++]-'a']++;
  }

  right -= 1;

  while(right<len){
    if(hash == phash){
      count++;
    }
    right++;
    if(right < len){
      hash[word[right]-'a'] += 1;
    }
    hash[word[left]-'a'] -= 1;
    left++;
  }
  return count;
}

int main(int argc, char const *argv[]) {
  string word,pword;
  cout << "Enter the string:";
  getline(cin,word);
  cout << "Enter the word:";
  getline(cin,pword);

  int count = count_anagrams(word,pword);
  cout << "Number of anagrams found:" << count << endl;
  return 0;
}
