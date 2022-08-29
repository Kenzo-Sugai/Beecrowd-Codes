#include <iostream>

using namespace std;

int operation(int n1, int n2, char oper){
  if(n1 == 7)
    n1 = 0;
  if(n2 == 7)
    n2 = 0;
  
  if(n1 == 17)
    n1 -= 10;
  if(n2 == 17)
    n2 -= 10;

  if(n1 == 27)
    n1 -= 20;
  if(n2 == 17)
    n2 -= 10;
  int result = 0;
  switch(oper){
    case '+':
      return n1+n2;
    case 'x':
      return n1*n2;
    case '-':
      return n1-n2;
    case '/':
      return n1/n2;
  }
}

int main(){
  int n1, n2;
  char oper;

  cin >> n1 >> oper >> n2;

  int r = operation(n1, n2, oper);

  cout << r << endl;




}