#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

void backtrack(string s, int idx, int N) {
    if (idx == N)
      cout << s << endl;
    else {
      for (int i = idx; i <= N; i++) {
        swap(s[idx], s[i]);
        backtrack(s, idx + 1, N);
        swap(s[idx], s[i]);
      }
    }
}
int main(){
  string s = "ABCD";
  int N = s.length();
  backtrack(s, 0, N - 1);

  return 0;
}