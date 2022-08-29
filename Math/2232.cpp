#include <iostream>

using namespace std;

long long int Fatorial(long long int n){
  if(n < 1) return 1;
  else return n * Fatorial(n - 1);
}

long long int Binomial(int n){
  long long int soma = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < i + 1; j++){
      soma += (Fatorial(i) / (Fatorial(j) * Fatorial(i - j)));
    }
  }
  return soma;
}

int main(){
  int N, n;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> n;
    cout << Binomial(n) << endl;
  }
}