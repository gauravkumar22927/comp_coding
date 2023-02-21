#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

void split(string s,vector<string> &arr){

  char *ptr = new char[s.size()+1];
  strcpy(ptr,s.c_str());

  char *temp = strtok(ptr," ");
  while(temp != NULL){
    arr.push_back(temp);
    temp = strtok(NULL, " ");
  }
  return;
}

int main()
{
    string s = "adfa dff fsdg gfdgdef ";
    vector<string> arr;
    split(s,arr);
    int len;
    for(string x:arr){
      len = x.length();
      cout << x << endl;
    }

    cout << "Length of last string : " << len << endl;
    return 0;
}