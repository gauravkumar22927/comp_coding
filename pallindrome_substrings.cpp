#include<iostream>
#include<string>

using namespace std;
int numberof_palindrome(string s){
  int n = s.size();
  if(n == 0 || n == 1){
  return n;
  }
  int count = 0;
  for(int i = 0;i<n;i++){
    // even
    int j = i;
    int k = i;
    while(j>=0 && k<n && s[j] == s[k]){
      j--;
      k++;
      count++;
    }
    //odd
    j = i;
    k = i+1;
    while(j>=0 && k<n && s[j] == s[k]){
      j--;
      k++;
      count++;
    }
  }
  return count;
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
  cout << ispalindrome(s)<<endl;

  cout << numberof_palindrome(s) << endl;
}