#include <iostream>
#include <vector>

using namespace std;

double distance(int x, int y, int x2, int y2){
  return sqrt(pow(x-x2, 2) + pow(y-y2, 2));
};

struct cordenadas{
  int X;
  int Y;
};

int main(){
  
  int N, X, Y;
  double raio = 0.5;

  while(cin >> N){
    if(N == 0)
      break;

    vector<cordenadas> C;
    
    int maior = 0;
    cordenadas centro;
    for(int i = 0; i < N; i++){
      cin >> X >> Y;
      C.push_back({X, Y});
      int soma = abs(X)+abs(Y);
      if(soma > maior)
        maior = soma;
        centro = {X, Y}; 
    }
    for(int j = 0; j < 4; j++){
     for(int i = 1; i <= C.size(); i++){
      cout << i << ": " << C[i].X << " " << C[i].Y << endl;
      cout << distance(C[j].X, C[j].Y, C[i].X, C[i].Y) << endl;
      }
      C.erase(C.begin());
      cout << endl;
    }

    cout << centro.X << " " << centro.Y << endl;

  }
}