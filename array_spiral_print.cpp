#include<iostream>
#include<vector>
using namespace std;

void spiral_print(vector<vector<int>> &arr , int n ,int m){
  int start_row =0;
  int start_col =0;
  int end_row = n-1;
  int end_col = m-1;

  while(start_row<=end_row & start_col<= end_col){
    //first_row
    for(int i = start_col;i<=end_col;i++){
      cout << arr[start_row][i] << " ";
    }
    //last_col
    for(int i = start_row+1;i<=end_row;i++){
      cout << arr[i][end_col] << " ";
    }
    //last row
    for(int i = end_col-1;i>=start_col;i--){
      if(start_row == end_row){
        break;
      }
      cout << arr[end_row][i] << " ";
    }
    //first_col
    for(int i = end_col-1;i>=start_col+1;i--){
      if(start_col == end_col){
        break;
      }
      cout << arr[i][start_col] << " ";
    }

    start_row++;
    start_col++;
    end_row--;
    end_col--;

  }
  
}

int main(){
  vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
  spiral_print(arr,3,3);

}