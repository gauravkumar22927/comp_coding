#include<iostream>

using namespace std;

class add{
public:
  int operator()(int a,int b){
    return a+b;
  }
};
int main(){
  add a;
  int ans = a(5,6);
  cout << ans;
}