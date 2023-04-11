#include<iostream>

using namespace std;
void rotate_arr(int arr[],int k,int n){
  int* temp = new int[k];
  int count = 0;
  for(int i =0;i<k;i++){
    temp[i] = arr[i];
  }
  for(int i = k;i < n ;i++){
    arr[i - k] = arr[i];
  }
  for(int i = n-k;i < n ;i++){
    arr[i] = temp[count];
    count++;
  }
  cout << "temp deleted" << endl;
  delete [] temp;

}
int main(){
  int arr[] = {1,2,3,4,5,6,7,8};
  int k = 4;
  int n = sizeof(arr)/sizeof(arr[0]);
  rotate_arr(arr,k,n);

  for(auto x:arr){
    cout << x << " ";
  }
}