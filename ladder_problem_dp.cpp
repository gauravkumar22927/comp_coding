#include<iostream>

using namespace std;
int * create_dynamic_1d_arr(int n){
  int *arr = new int[n];
  return arr;
}
int countways(int n,int arr[]){
  if(n<0){
    return 0;
  }
  if(n == 0){
    return 1;
  }
  if(n==1){
    return 1;
  }
  if(arr[n] != 0){
    return arr[n];
  }
  int ans = countways(n-1,arr) + countways(n-2,arr) + countways(n-3,arr);

  return ans;
}
int main(){
  int n;
  cout <<"Enter the value of n :";
  cin >> n;
  int *arr = create_dynamic_1d_arr(n+1);
  int count  = 0;
  for(int i = 0 ; i<= n;i++){
    arr[i] = count;
  }
  cout << countways(n,arr);
  
}