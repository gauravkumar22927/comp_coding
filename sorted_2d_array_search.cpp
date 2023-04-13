#include<iostream>

using namespace std;

int** create_2d_arr(int n,int m){
  int **arr;
  arr = new int*[n];
  for(int i=0;i<n;i++){
    arr[i] = new int[m];
  }
  return arr;
}

pair<int,int> search(int **arr,int key,int n,int m){
  int i = 0;
  int j = m-1;
  while( 0 <= i && i <= n-1 && 0 <= j && j <= m){
    if(arr[i][j] == key){
      return make_pair(i,j);
    }
    else if(key < arr[i][j]){
      j--;
    }
    else if(key > arr[i][j]){
      i++;
    }
  }
  return make_pair(-1,-1);
}
int main(){
  int n = 4;
  int m = 4;
  int **arr = create_2d_arr(n,m);

  int count = 0;
  for(int i =0;i<n;i++){
    for(int j = 0;j<m;j++){
      arr[i][j] = count;
      count++;
    }
  }
  cout << "printing array : " << endl;
  for(int i =0;i<n;i++){
    for(int j = 0;j<m;j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << "searching key : " << endl;
  int key;
  cout << "Enter key to search : " << endl;
  cin >> key;
  pair<int,int> res = search(arr,key,n,m);
  cout << "Present at : ("<< res.first << " " << res.second << ")" << endl;
  
}