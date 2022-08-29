#include <iostream>
#include <string>

using namespace std;

int main(){

  int N, n1, n2, aux;
  string S, numeros[2];

  cin >> N;

  while(N--){
    cin >> S;

    for(int i = 0, j = 0; i < S.size(); i++){
      if(S[i] == 'x'){
        j++; i++;
      }
      numeros[j] += S[i];
    }

    n1 = stoi(numeros[0]); n2 = stoi(numeros[1]);
    
    for(int i = 5; i <= 10; i++){
      cout << n1 << " x " << i << " = " << n1*i;
      cout << " && " << n2 << " x " << i << " = " << n2*i << endl; 
    }
  }
}