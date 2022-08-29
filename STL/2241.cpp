#include <iostream>

using namespace std;

int main(){
  int N, P, X, Y, preto = 0, branco = 0;
  cin >> N >> P;
  int go[N][N];
  int goC[N][N];
  branco = P, preto = P;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      go[i][j] = 0;
      goC[i][j] = 0;
    }
  }
  for(int i = 0; i < P; i++){
    cin >> X >> Y;
    X--;
    Y--;
    go[X][Y] = 1;
    goC[X][Y] = 1;
  }
  for(int i = 0; i < P; i++){
    cin >> X >> Y;
    X--;
    Y--;
    go[X][Y] = 2;
    goC[X][Y] = 2;
  }

  for(int tam = 1; tam <= N; tam++){
    for(int i = 0; i < N-tam; i++){
      for(int j = 0; j < N-tam; j++){
        for(int a = i; a < tam; a++){
          for(int b = j; b < tam; b++){
            cout << a << " " << b << endl;
            go[a][b] = 3;
          }
        }
        for(int a = 0; a < N; a++){
          for(int b = 0; b < N; b++){
            cout << go[a][b] << " ";
          }
          cout << endl;
        }
        cout << endl;

        for(int a = 0; a < N; a++){
          for(int b = 0; b < N; b++){
            go[a][b] = goC[a][b];
          }
        }
      }
    }
  }

  cout << preto << " " << branco << endl;
}