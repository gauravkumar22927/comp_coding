#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int power(int x,int p){
  int ans = 1;
  for(int i = 0;i<p;i++){
    ans *= x;
  }
  return ans;
}
void find_nth(vector<int> &arr,int nth){
  sort(arr.begin(),arr.end());
  int n = arr.size();
  int temp = arr[n-1];
  for(int i = n-2;i>= 0;i--){
    swap(arr[i],arr[i+1]);
  }
  int ans = 0;
  int pow = 0;
  
  while(nth){
    ans = ans + arr[(nth % n)] * power(10,pow);
    if(nth % 5 == 0){
      nth = nth/n;
      nth--;
    }
    else{
      nth = nth/n;
    }
    
    pow += 1;
  }
  cout << ans;
}
int main(){
  vector<int> arr = {1,3,7,5,9};
  int n;
  while(n!=-1){
  cout << "Enter value of nth :"<< endl;
  cin >> n;
  if(n == -1){
    break;
  }
  find_nth(arr,n);
  cout << endl;
  }
}