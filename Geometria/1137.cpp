#include <iostream>
#include <vector>

using namespace std;

struct ponto{
  int x;
  int y;
};

int main(){

  int N, X, Y;
  
  cin >> N;

  vector<ponto> plano;

  for(int i = 0; i < N; i++){
    
    cin >> X >> Y;
    
    plano.push_back({X, Y});
  }
}