#include <iostream>

using namespace std;
int first_occ(int arr[],int n,int key){
  if(n==0){
    return -1;
  }
  if(arr[0] == key){
    return 0;
  }
  int sub_index = first_occ(arr+1,n-1,key);
  if(sub_index != -1){
    return sub_index + 1;
  }
  return -1;
}
int main(){
  int n;
  cout << "Enter number of element to enter :";
  cin >> n;
  int *arr = new int[n];
  cout << "Enter array of size :" << n<<endl;
  for(int i =0;i<n;i++){
    cin >> arr[i];
  }
  cout << "-----------------" << endl;
  int key;
  cout << "Enter key to search :" ;
  cin >> key;
  cout << first_occ(arr,n,8);
  delete [] arr;
}