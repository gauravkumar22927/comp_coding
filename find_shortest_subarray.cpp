//Input: nums = [1,2,2,3,1,4,2]
//Output: 6
//Explanation: 
//The degree is 3 because the element 2 is repeated 3 times.
//So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.

#include<iostream>
#include<unordered_map>

using namespace std;

int find_shortest_subarray(int arr[],int n){
  int ans = 0;
  int degree = 0;

  unordered_map<int,int> count_freq;
  unordered_map<int,int> start_idx;

  for(int i = 0;i<n;i++){
    if(!count_freq.count(arr[i]) && !start_idx.count(arr[i])){
      count_freq[arr[i]] = 1;
      start_idx[arr[i]] = i;
    }
    else{
      count_freq[arr[i]] += 1;
    }
    if(count_freq[arr[i]] > degree){
      degree = count_freq[arr[i]];
      ans = i - start_idx[arr[i]] + 1;
    }
    else if(count_freq[arr[i]] == degree){
      ans = min(ans, (i - start_idx[arr[i]] + 1));
    }
  }

  return ans;
}

int main(){
  int arr[] = {1,2,2,3,1,4,2};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << find_shortest_subarray(arr,n);

}