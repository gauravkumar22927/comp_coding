#include<iostream>

using namespace std;
void print_board(int arr[][20] , int n){
  for(int i =0;i<n;i++){
    for(int j = 0;j<n;j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}
bool can_place(int arr[][20],int x,int y,int n){
  for(int j = x;j>=0;j--){
    if(arr[j][y] == 1){
      return false;
    }
  }
  int i = x;
  int j = y;
  while(i>=0 && j >= 0){
    if(arr[i][j] == 1){
      return false;
    }
    i--;j--;
  }
  i = x;
  j = y;
  while(i>=0 && j <= n){
    if(arr[i][j] == 1){
      return false;
    }
    i--;j++;
  }
return true;
}
bool board_form(int arr[][20],int n,int i){
  if(i == n){
    print_board(arr,n);
    return true;
  }
  for(int j = 0;j<n;j++){
    if(can_place(arr,i,j,n)){
      arr[i][j] = 1;
      bool success = board_form(arr,n,i+1);
      if(success){
        return true;
      }
      // backtrack
      arr[i][j]= 0;
    }
  }
  return false;
}
int main(){
  int n = 4;
  int arr[20][20] = {0};
  board_form(arr,n,0);
}