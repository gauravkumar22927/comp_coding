#include<iostream>
#include<string>

using namespace std;

void max_len_char(string s){
  int max_all = 0;
  int end_idx = -1;
  int n = s.length();
  int count = 1;
  if(n == 0 | n == 1){
    cout << n << endl;
    return;
  }
  for(int i = 1;i<n;i++){
    if(s[i] == s[i-1]){
      count++;
    }
    else{
      count = 1;
    }
    if(count > max_all){
      max_all = count;
      end_idx = i;
    }
  }
  cout << "Max all :" << max_all << " idx : " << end_idx << endl; 

}

int main(){
  string s;
  cout << "Enter the string :" << endl;
  getline(cin,s);
  max_len_char(s);
}