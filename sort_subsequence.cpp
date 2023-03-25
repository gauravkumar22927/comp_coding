#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
void substring(string s,string o,vector<string> &v){
  if(s.size() == 0){
    v.push_back(o);
    return;
  }
  char c = s[0];
  string residue_string = s.substr(1);
  //include first char
  substring(residue_string,o+c,v);
  //exclude first char
  substring(residue_string,o,v);
}
bool custom_compare(string s1,string s2){
  if(s1.length() == s2.length()){
    return s1 < s2;
  }
  return s1.length() < s2.length();
}
int main(){
  string s = "abc";
  string output = "";
  vector<string> result;
  substring(s,output,result);
  cout << "All substrings are :" << endl;
  sort(result.begin(),result.end(),custom_compare);
  for(int i=0;i<result.size();i++){
    if(result[i] == ""){
      cout << "null" << endl;
    }else{
    cout << result[i] << " " << endl;
    }
  }
}