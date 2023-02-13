#include <iostream>
#include <vector>

using namespace std;

void parenthesis(int n, int open, int close,string s,vector<string> &v){
  
  if(open == n & close == n){
    v.push_back(s);
  }
  else{
    if(open < n){
      parenthesis(n,open+1,close,s + '(',v);
    }
    if(open > close){
      parenthesis(n,open,close+1,s + ')',v);
    }
  }
}
int main(){
  vector<string> v;
  cout << "Enter number of pairs of parenthesis: ";
  int n;
  cin >> n;
  parenthesis(n,0,0,"",v);
  for(auto s: v){
    cout << s << endl;
  }
}