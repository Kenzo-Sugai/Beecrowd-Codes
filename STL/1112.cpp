#include <iostream>
#include <vector>

using namespace std;

int main(){

  int X, Y, N, C, T, X1, Y1, X2, Y2, aux, A1[2], A2[2];
  char Q;
  while(scanf("%d %d %d", &X, &Y, &C)){
    if(X == 0 && Y == 0 && C == 0){
      break;
    }

    int campo[X][Y];

    for(int i = 0; i < X; i++){
      for(int j = 0; j < Y; j++){
        campo[i][j] = 0;
      }
    }

    cin >> N;

    for(int i = 0; i < N; i++){
      cin >> Q;
      if(Q == 'A'){
        cin >> T >> X >> Y;
        campo[X][Y] += T;
      }
      if(Q == 'P'){
        cin >> A1[0] >> A1[1] >> A2[0] >> A2[1];
        if(A1[0] > A2[0]){
          aux = A1[0];
          A1[0] = A2[0];
          A1[0] = aux;
        }
        if(A1[1] > A2[1]){
          aux = A1[1];
          A1[1] = A2[1];
          A2[1] = aux;
        }
        int soma {0};
        for(int i = A1[0]; i <= A2[0]; i++){
          for(int j = A1[1]; j <= A2[1]; j++){
            soma += campo[i][j];
          }
        }
        printf("%d\n", soma*C);
      }
    }
  }
}