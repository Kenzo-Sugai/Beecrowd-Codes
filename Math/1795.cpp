#include <iostream>

using namespace std;

long long int Fatorial(long long int n){
  if(n < 1) return 1;
  else return n * Fatorial(n - 1);
}

long long int Binomial(int n){
  long long int soma = 0;
  for(int j = 1; j <= n; j++){
    cout << (Fatorial(n) / (Fatorial(j) * Fatorial(n - j))) << endl;
    soma += (Fatorial(n) / (Fatorial(j) * Fatorial(n - j)));
  }
  cout << (Fatorial(n) / (Fatorial(0) * Fatorial(n - 0))) << endl;
   soma += (Fatorial(n) / (Fatorial(0) * Fatorial(n - 0)));
  return soma;
}

int main(){
  int n;
  cin >> n;
  cout << Binomial(n) << endl;
}