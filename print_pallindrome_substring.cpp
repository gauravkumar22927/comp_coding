#include<iostream>
#include<string>
#include<set>
#include<vector>

using namespace std;
void find_substring(string s,vector<string> &v,string c){
  if(s.length() == 0){
    v.push_back(c);
    return;
  }
  char ch = s[0];
  s = s.substr(1);
  find_substring(s,v,c+ch);
  find_substring(s,v,c);
  return;
}
bool ispalindrome(string s){
  int i =0;
  int n = s.length();
  int j = n-1;
  while(i < j){
    if(s[i] == s[j]){
      i++;
      j--;
    }
    else{
      return false;
    }
  }
  return true;
}
int main(){
  string s = "abcba";
  vector<string> v;
  //vector<string> res;
  set<string> set_res;
  string emp = "";
  find_substring(s,v,emp);
  int n = v.size();
  for(int i = 0;i<n;i++){
    if(ispalindrome(v[i]) && v[i] != ""){ // excluding NULL
      //res.push_back(v[i]);
      set_res.insert(v[i]);
    }
  }
  for(auto x:set_res){
    cout << x << endl;
  }
  cout << set_res.size() << endl;
}