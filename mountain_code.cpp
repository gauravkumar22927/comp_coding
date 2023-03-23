#include<iostream>
#include<algorithm>

using namespace std;

int largest_peak(int arr[],int n){
  int largest = 0;
  for(int i = 1;i<=n-2;){
    if(arr[i]>arr[i-1] & arr[i]>arr[i+1]){
      int count = 1;
      int j = i;
      while(j>=1 & arr[j]>arr[j-1]){
        count++;
        j--;
      }
      while(i<(n-1) & arr[i+1] < arr[i]){
        i++;
        count++;
      }
      largest = max(count,largest);
    }
    else{
      i++;
    }
  }
return largest;
}

int main(){
  int arr[] = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << "largest peak is : ";
  cout << largest_peak(arr,n) << endl;
}