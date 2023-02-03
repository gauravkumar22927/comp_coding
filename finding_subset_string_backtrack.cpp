#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
void find_subset(char *input,char* output,int i,int j,vector<string> &list){
if(input[i] =='\0'){
  output[j] = '\0';
  string temp(output);
  list.push_back(temp);
  return;
}
// include the ith letter
output[j] = input[i];
find_subset(input,output,i+1,j+1,list);
// exclude the ith letter
find_subset(input,output,i+1,j,list);
}

bool compare(string s1,string s2){
  if(s1.length() == s2.length()){
    return s1 < s2;
  }
  else{
    return s1.length() < s2.length();
  }
}
int main(){
  char input[100];
  char output[100];
  vector<string> list;
  cin >> input;
  cout << "subset----------------"<< endl;
  find_subset(input,output,0,0,list);
  sort(list.begin(),list.end(),compare);
  for(auto x:list){
    cout << x << " ";
  }
}