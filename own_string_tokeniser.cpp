#include<iostream>
#include<string>
#include<cstring>

using namespace std;
char *tokenizer(char *str,char delim){

  static char *input = NULL;
  if(str != NULL){
    input = str;
  }
  if(input == NULL){
    return NULL;
  }
  char* token = new char[strlen(input) + 1];
  int i =0;
  for(;input[i] != '\0';i++){
    if(input[i] != delim){
      token[i] = input[i];
    }
    else{
      token[i] = '\0';
      input = input + i + 1;
      return token;
    }
  }
  // last char finished add null to token
  token[i] = '\0';
  input = NULL;
  return token;
}


int main(){
  char ch[1000];
  cout << "Enter input of string for tokeniser : " << endl;
  cin.getline(ch,1000);

  char *token = tokenizer(ch,' ');

  while(token != NULL){
    cout << token << endl;
    token = tokenizer(NULL, ' ');
  }
}