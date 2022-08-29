#include <iostream>

using namespace std;

bool isPrime(int n){
  int cnt {0};
  for(int i = 1; i < n; i++){
    if(n % i == 0){
      cnt++;
      if(cnt > 1){
        return false;
      }
    }
  }
  return true;
}

unsigned long long int Fatorial(unsigned long long int n){
  if(n <= 1){
    return n;
  }
  else{
    return n * Fatorial(n - 1);
  }
}

int main(){
  unsigned long long int N, n;

  cin >> N;

  for(int i = 0; i < N; i++){
    cin >> n;
    if(isPrime(n) && n != 1){
      cout << n << "! = " << Fatorial(n) << endl;
    }
  }
}