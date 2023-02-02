#include <iostream>
#include <vector>

using namespace std;
int partition(vector<int> &arr,int s,int e){
  int pivot = arr[e];
  int i = s-1;
  for(int j = s; j<e;j++){
    if(arr[j] < pivot){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[e]);
  return i+1;
}
void quicksort(vector<int> &arr,int s,int e){
  if(s >= e){
    return;
  }
  int p = partition(arr,s,e);
  quicksort(arr,0,p-1);
  quicksort(arr,p+1,e);
}
int main(){
  vector<int> arr{2,4,6,8,0,9,7,5,3,1};
  int n = arr.size();
  cout << n<<endl;
  quicksort(arr,0,n-1);
  for(int i =0;i<n;i++){
    cout << arr[i] << " ";
  }
}