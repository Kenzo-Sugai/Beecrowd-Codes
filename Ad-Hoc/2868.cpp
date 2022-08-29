#include <iostream>
#include <math.h>

using namespace std;

int resposta(char oper, int n1, int n2, int resp){
  switch (oper){
    case '+':
      return abs(n1+n2 - resp);
    case '-':
      return abs(n1-n2 - resp);
    case 'x':
      return abs(n1*n2 - resp);
    }
}

int main(){
  int N, n1, n2, resp;
  char oper, eq;  
  cin >> N;
  while(N--){
    cin >> n1 >> oper >> n2 >> eq >> resp;
    cout << "E";
    for(int i = 0; i < resposta(oper, n1, n2, resp); i++){
      cout << "r";
    }
    cout << "ou!" << endl;
  }
}