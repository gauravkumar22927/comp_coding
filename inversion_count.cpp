#include<iostream>
#include<vector>

using namespace std;

int merge(vector<int> &arr,int s,int e){
  int mid = (s+e)/2;
  int i = s;
  int j = mid+1;
  int count = 0;
  vector<int> temp;//(e-s+1) initialize by 0 default
  while(i<=mid && j<= e){
    if(arr[i] < arr[j]){
      temp.push_back(arr[i]);
      i++;
    }
    else if(arr[i] > arr[j]){
      temp.push_back(arr[j]);
      j++;
      count += mid - i + 1;
    }
  }
  while(i<=mid){
    temp.push_back(arr[i]);
    i++;
  }
  while(j<= e){
    temp.push_back(arr[j]);
    j++;
    count += mid - i +1;
  }
  int idx = 0;
  for(int x=s;x<=e;x++){
    arr[x] = temp[idx];
    idx++;
  }
  return count;
}
int merge_sort(vector<int> &arr,int s,int e){
  if(s>=e){
    return 0;
  }
  int mid = (s+e)/2;
  int c1 = merge_sort(arr,s,mid);
  int c2 = merge_sort(arr,mid+1,e);
  int c = merge(arr,s,e);
  return c+c1+c2;
}
int main(){
vector<int> arr{10,5,2,0,7,6,4};
int n = arr.size();
cout << "Number of inversions are : ";
cout << merge_sort(arr,0,n-1);
cout << endl;
for(auto x:arr){
  cout << x << " ";
}
}