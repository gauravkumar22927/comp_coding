#include<iostream>
#include<string>

using namespace std;
void compare_rot_string(string s1,string s2){
  int n1 = s1.length();
  int n2 = s2.length();
  if(n1 != n2){
    cout << "Not Equal" << endl;
    return;
  }
  if(s1.compare(s2) == 0){
    cout << "Equal";
    return;
  }
  int j = 0;
  int rem = 0;
  for(int i =0;i<n2;i++){
    if(s1[j] == s2[i]){
      rem = i - j;
      j++;
      continue;
    }
    else if(s1[j] != s2[i]){
      continue;
    }
  }
  cout << rem;
  for(int i =0;i<n2;i++){
    if(s1[i] == s2[(i+rem)%n2]){
      continue;
    }
    else{
      cout << "Not Equal"<<endl;
      return;
    }
  }

}
int main(){
  string s1 = "ACAB"; //ACAB
  string s2 = "ABAC"; //ABAC

  compare_rot_string(s1,s2);
}