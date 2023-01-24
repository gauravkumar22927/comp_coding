#include <iostream>

using namespace std;

int convert_binary(int n){
int ans = 0;
int power = 1;
while(n>0)
{
  int last_bit = n&1;
  if(last_bit){
    ans += power;
  }
  power = power * 10;
  n = n>>1;
}
return ans;
}
int main(){
  int n;
  cout << "Enter number to convert binary : " << endl;
  cin >> n;
  cout << convert_binary(n) << endl;
}