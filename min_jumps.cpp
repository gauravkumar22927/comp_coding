#include<iostream>

using namespace std;

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int count = 1;
        int ladder = arr[0];
        int max_stair = arr[0];
        if(arr[0] == 0){
            return -1;
        }
        for(int i = 1;i<n;i++){
            if(i >= n-1){
                return count;
            }
            if(ladder){
            ladder--;
            max_stair = max(max_stair,i+arr[i]);
            }
            if(ladder == 0){
                count++;
                if(i>= max_stair){
                    return -1;
                }
                ladder = max_stair - i;
            }
            
        }
        count = -1;
        
    return count;
    }
};