#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;


void func(char **p){
  *p = new char[10];
  strcpy(*p,"hello");
}

int main()
{ 
  char* msg = NULL;
  func(&msg);
  cout << msg << endl;
  return 0;
}