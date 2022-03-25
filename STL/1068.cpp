#include <iostream>
#include <queue>

using namespace std;

int main(){
  int i, verificar;
  string inp;
  while (getline(cin, inp)) {
    queue<char> Q;
    for(i = 0; i < inp.length(); i++){
      switch(inp[i]){     
        case '(':
          Q.push('(');
          break;
        case ')':
          if(!Q.empty()){
            Q.pop();
          }
          else{
            cout << "Incorrect" << endl;
            break;
          }  
        default:
          break;
      }
    }
    if(Q.empty()){
      cout << "Correct" << endl;
    }
    else{
      cout << "Incorrect" << endl;
    }
  return 0;
  }
}
