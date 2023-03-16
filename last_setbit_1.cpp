#include<iostream>

using namespace std;

int main(){
  int a = 23;
  int count = 0;
  bool flag  = 0;
  while(flag != 1){
    int var = a & 1;
    if(var == 0){
      count += 1;
      a = a >> 1;
    }
    else{
      count += 1;
      flag = 1;
      a = a >> 1;
    }
  }
  a = a << count;
  cout << a;
}