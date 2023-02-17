#include <iostream>
#include <string>

using namespace std;
void print_reverse(char* arr,int index,int size){
  if(index == size){
    return;
  }
  print_reverse(arr+1,index+1,size);
  cout << *arr << "";
}

int main(){
  char arr[] = "abcdefghij";
  int n = sizeof(arr) / sizeof(arr[0]);
  print_reverse(arr,0,n);
}