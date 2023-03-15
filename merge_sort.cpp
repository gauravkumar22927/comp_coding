#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr,int s,int e){
  int i = s;
  int mid = (s+e)/2;
  int j = mid+1;

  vector<int> temp;
  while(i<= mid & j<= e){
    if(arr[i] < arr[j]){
      temp.push_back(arr[i]);
      i++;
    }
    else{
      temp.push_back(arr[j]);
      j++;
    }
  }
  while(i<=mid){
    temp.push_back(arr[i++]);
  }
  while(j<=e){
    temp.push_back(arr[j++]);
  }

  int k = 0;
  for(int x = s;x <= e;x++){
    arr[x] = temp[k++];
  }
}

void merge_sort(vector<int> &arr,int s,int e){
  if(s>=e){
    return;
  }
  int mid = (s + e)/2;
  merge_sort(arr,s,mid);
  merge_sort(arr,mid+1,e);
  merge(arr,s,e);
}

int main(){
  vector<int> v = {5,4,3,2,8,7,6,9};
  int end = v.size();
  merge_sort(v,0,end);

  for(int i = 0;i< end;i++){
    cout << v[i] << " ";
  }
  return 0;
}