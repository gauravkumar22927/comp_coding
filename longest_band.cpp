#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<vector>

using namespace std;

int largestBand(vector<int> arr){
  int n = arr.size();
  unordered_set<int> s;
  for(int i = 0;i<n;i++){
    s.insert(arr[i]);
  }
  int largest = 1;
  for(int i = 0;i<n;){
    int count = 1;
    int j = arr[i];
    if(s.find(j-1) != s.end()){
      i++;
    }
    else{
      while(s.find(j) != s.end()){
        count++;
        j++;
      }
      i++;
      largest = max(largest,count);
    }
  }
  return largest;
}

int main(){
  vector<int> arr{1,9,3,0,18,5,2,4,10,7,12,6,-1};
  cout << largestBand(arr);

  return 0;
}