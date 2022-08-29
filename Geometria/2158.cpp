#include <iostream>

using namespace std;

int main(){

  // Euler constant [V + F = 2 + A]

  long long int FP, FH, A, V, F, i = 0;
  
  while(cin >> FP >> FH){

    i++;

    A = (5*FP + 6*FH)/2;

    F = FP + FH;

    V = 2 + A - F;

    cout << "Molecula #" << i <<".:." << endl;
    cout << "Possui " << V << " atomos e " << A << " ligacoes" << endl << endl;
  }

}