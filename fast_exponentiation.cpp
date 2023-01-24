#include <iostream>
#include <string>

using namespace std;
void fast_exponentiation(int a,int n){
  int ans = 1;

  while(n>0){
    int lastbit = n & 1;
    if(lastbit){
      ans = ans* a;
    }
    a = a*a;
    n = n>>1;
  }
  cout << "Exponentiation Result: " << ans;
}
int main(){
  int a,n;
  cout << "Enter value of base:"<< endl;
  cin >> a;
  cout << "Enter value of exponentiation:"<< endl;
  cin >> n;
  fast_exponentiation(a,n);
}