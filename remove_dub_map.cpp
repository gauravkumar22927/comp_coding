#include<iostream>
#include<unordered_map>

using namespace std;

void remove_dub(int arr[],int n){
  unordered_map<int,int> um;
  for(int i =0 ;i<n;i++){
    if(um.count(arr[i])){
      continue;
    }
    else{
      um.insert(pair<int,int> (arr[i],1));
      cout << arr[i] << " ";
    }
  }
}
int main(){
  int arr[] = {1,2,4,2,6,3,4,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  remove_dub(arr,n);
}