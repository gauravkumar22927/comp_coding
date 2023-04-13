#include<iostream>
#include<string>
#include<vector>

using namespace std;

void string_compress(string s){
  int n = s.length();
  string res;
  int count = 1;
  for(int i = 0;i<n;i++){
    if(s[i] == s[i+1]){
      count += 1;
    }
    else{
      res += s[i];
      res += to_string(count);
      count = 1;
    }
  }
  for(auto x: res){
    cout << x << " ";
  }
}
int main(){
  string s = "aabbbcccccccdddde";
  string_compress(s);
}