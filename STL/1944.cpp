#include <iostream>
#include <stack>
using namespace std;

int main(){

  int N, contador = 0;
  string n1, n2, n3, n4;
  cin >> N;
  stack<string> S;
  S.push("FACE");
  while(N--){
    cin >> n1 >> n2 >> n3 >> n4;
    string total = n1+n2+n3+n4, topo = S.top();
    bool verify = false;
    for(int i = 0; i < 4; i++){
      if(topo[3-i] != total[i]){
        verify = true;
        break;
      }
    }
    if(verify == false){
      if(S.size() > 1){
        S.pop();
      }
      contador++;
    }
    else{
      S.push(total);
    }
  }
  cout << contador << endl;
}