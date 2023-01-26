#include <iostream>

using namespace std;
int fast_power(int a,int n){
  if(n == 0){return 1;}
  int sub_prob = fast_power(a,n/2);
  int sub_prob_sq = sub_prob * sub_prob;
  if(n&1){
    return a*sub_prob_sq;
  }
  else{
    return sub_prob_sq;
  }
}
int main(){
  int a,n;
  cout << "Enter value of a , n :"<<endl;
  cin >> a >> n;

  cout << fast_power(a,n);
}