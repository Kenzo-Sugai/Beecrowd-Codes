#include <iostream>

#define DEBUG

using namespace std;
int main() {
  int n = 2, N1, N2, D1, D2;
  string oper, bar, bar2;

  cin >> n;
  for(int i = 0; i < n; i++){

    cin >> N1 >> bar >> D1 >> oper >> N2 >> bar2 >> D2;
    
    int N3 = 0;
    int D3 = 0;

    if(oper == "+"){
      N3 = (N1*D2 + N2*D1);
      D3 = (D1*D2);
      //cout << N3 << "/" << D3 <<;
    } else if(oper == "-"){
      N3 = (N1*D2 - N2*D1);
      D3 = (D1*D2);
    } else if(oper == "*"){
      N3 = (N1*N2);
      D3 = (D1*D2);
    } else if(oper == "/"){
      N3 = (N1*D2);
      D3 = (N2*D1);
    }
    cout << N3 << "/" << D3 << " = ";
    int v[5] = {2, 3, 5, 7, 11}; 
    for(int i = 0; i < 5; i++){
      if(N3 % v[i] == 0 && D3 % v[i] == 0){
        N3 = N3/v[i];
        D3 = D3/v[i];
        if(N3 % v[i] == 0 && D3 % v[i] == 0){
          N3 = N3/v[i];
          D3 = D3/v[i];
        }
      }
      if(N3 == D3){
        N3 = N3/D3;
        D3 = N3;
      }
    }
    cout << N3 << "/" << D3 << endl;
  }
} 
