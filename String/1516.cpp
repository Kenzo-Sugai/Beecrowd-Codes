#include <iostream>

using namespace std;

int main(){
  int N, M, A, B;

  while(cin >> N >> M){
    if(!N && !M) return 0;

    char pixel[N][M];
    for(int i = 0; i < N; i++){

      for(int j = 0; j < M; j++){

        cin >> pixel[i][j];
    
      }
    }

    cin >> A >> B;
    int expA = A/N, expB = B/M;

    for(int i = 0; i < N; i++){
    
    for(int b = 0; b < expA; b++){
      for(int j = 0; j < M; j++){
        for(int a = 0; a < expB; a++){
            cout << pixel[i][j];
          } 
        }
        cout << endl;
      }
    }
    cout << endl;
  }
}