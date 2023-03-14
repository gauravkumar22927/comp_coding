#include <iostream>

using namespace std;

int array_to_int(char* arr){
  int res = 0;
  int i=0;
  while(arr[i] != '\0'){
    res = res * 10 + (arr[i] - '0');
    i++;
  }

  return res;
}

int main(){

  char* arr = "12345";
  cout << sizeof(arr) << endl;
  int val = array_to_int(arr);
  cout << "Integer value for string is : " << val << endl;
}