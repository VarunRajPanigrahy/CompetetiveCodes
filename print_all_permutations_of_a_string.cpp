#include<iostream>
#include<string>

using namespace std;

void permute(string a, int l, int r)
{
    if (l == r)
        cout<<a<<endl;
    else
    {
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l+1, r);

            //backtrack
            swap(a[l], a[i]);
        }
    }
}

int main(int argc, char const *argv[]) {
  string word;
  cout << "Enter the word:";
  getline(cin,word);

  cout << word << endl;
  int n = word.length();  
  permute(word,0,n-1);
  return 0;
}
