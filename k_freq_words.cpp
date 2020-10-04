#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<queue>

using namespace std;

struct MyComp {
    bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
        if(a.first != b.first) {
            return a.first > b.first;
        }
        else {
            return a.second < b.second;
        }
    }
};

vector<string> topKFrequent(vector<string>&, int);

int main(int argc, char const *argv[]) {
  vector<string> vec {"i", "love", "leetcode", "i", "love", "coding"};
  int k=2;
  vector<string> v = topKFrequent(vec,k);
  for(string str:v){
    cout << str << " ";
  }
  cout << endl;
  return 0;
}

vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hashmap;
        for(string& word : words) {
            hashmap[word] += 1;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp> pq;
        for(auto it = hashmap.begin(); it != hashmap.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > k) pq.pop();
        }
        vector<string> res;
        while(!pq.empty()) {
            res.insert(res.begin(), pq.top().second);
            pq.pop();
        }
        return res;
}
