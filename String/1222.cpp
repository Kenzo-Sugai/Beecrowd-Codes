#include <iostream>
#include <cmath>

using namespace std;

int main(){
  double N, L, C, pagina;
  string palavra;

  while(cin >> N >> L >> C){
    double sum = N - 1;
    for(int i = 0; i < N; i++){
      cin >> palavra;
      sum += palavra.size();
    }
    pagina = L*C;
    double p = sum/pagina;
    cout << ceil(p) << endl;
  }
}