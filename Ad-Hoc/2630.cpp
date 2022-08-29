#include <iostream>
#include <cmath>

using namespace std;

int main(){

  int T, R, G, B;
  string type;

  cin >> T;

  for(int i = 1 ; i <= T; i++){
    cin >> type;

    cin >> R >> G >> B;
    cout << "Caso #" << i << ": ";
    if(type == "min"){
      if(B <= R && B <= G){
        cout << B << endl;
      }
      else if(R <= G && R <= B){
        cout << R << endl;
      }
      else if(G <= R && G <= B){
        cout << G << endl;
      }
    }
    if(type == "max"){
      if(B >= R && B >= G){
        cout << B << endl;
      }
      else if(R >= G && R >= B){
        cout << R << endl;
      }
      else if(G >= R && G >= B){
        cout << G << endl;
      }
    }
    if(type == "mean"){
      cout << (R+G+B)/3 << endl;
    }
    if(type == "eye"){
      double p = 0.30*R + 0.59*G + 0.11*B;
      cout << trunc(p) << endl;
    }
  }
}