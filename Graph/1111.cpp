#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

int main(){
  int C, n, xo, yo, x1, y1, T, N, L, O, S, test = 0;
  while(true){
    cin >> C;
    if(C == 0){
      cout << endl;
      break;
    }
    if(test != 0){
      cout << endl;
    }
    vector<vector<vector<int>>> cidade;
    vector<vector<bool>> cor;
    vector<vector<int>> d;
    cidade.resize(C+1,vector<vector<int> >(C+1,vector<int>(5)));
    //cidade.resize((C*C)+1);
    cor.resize((C*C)+1);
    d.resize((C*C)+1);
    for(int i = 0; i < C; i++){
      for(int j = 0; j < C; j++){
        cor[i].push_back(false);
        d[i].push_back(-1);
        cin >> N >> S >> O >> L;
          //string s = string((N+S+O+L), 1);
          //cout << "string: " << s << endl;
        cidade[i][j][0] = N;
        cidade[i][j][1] = S;
        cidade[i][j][2] = O;
        cidade[i][j][3] = L;
        /*
        cout << "i: " << i << endl;
        cout << "j: " << j << endl;
        cout << "0: " << cidade[i][j][0] << endl;
        cout << "1: " << cidade[i][j][1] << endl;
        cout << "2: " << cidade[i][j][2] << endl;
        cout << "3: " << cidade[i][j][3] << endl;
        */
      }
    }
    cin >> T;
    while(T--){
      bool loop = false;
      cin >> xo >> yo >> x1 >> y1;
      if(xo == x1 && yo == y1){
        loop = true;
      }
      yo = abs(yo-(C-1));
      y1 = abs(y1-(C-1));
      //cout << yo << " " << y1 << endl;
      bool verify = false;
      for(int i = 0; i < C; i++){
        for(int j = 0; j < C; j++){
          cor[i][j] = false;
          d[i][j] = -1;
        }
      }
      queue<int> linha;
      queue<int> coluna;
      linha.push(yo);
      coluna.push(xo);
      d[yo][xo] = 0;
      while(!linha.empty() && !coluna.empty()){
        if(loop == true){
          verify = true;
          break;
        }
        int l = linha.front();
        int c = coluna.front();
        /*
        cout << "l: " << l << endl;
        cout << "c: " << c << endl;
        cout << "0: " << cidade[l][c][0] << endl;
        cout << "1: " << cidade[l][c][1] << endl;
        cout << "2: " << cidade[l][c][2] << endl;
        cout << "3: " << cidade[l][c][3] << endl;
        */
        cor[l][c] = true;
        linha.pop(), coluna.pop();
        if(cidade[l][c][0] == 1 && cor[l-1][c] == false){
          d[l-1][c] = d[l][c] +1;
          linha.push(l-1);
          coluna.push(c);
          if(l-1 == y1 && c == x1){
            //cout << "ACHOU" << endl;
            verify = true;
            break;
          }
        }
        if(cidade[l][c][1] == 1 && cor[l+1][c] == false){
          d[l+1][c] = d[l][c] +1;
          linha.push(l+1);
          coluna.push(c);
          if(l+1 == y1 && c == x1){
            //cout << "ACHOU" << endl;
            verify = true;
            break;
          }
        }
        if(cidade[l][c][2] == 1 && cor[l][c-1] == false){
          d[l][c-1] = d[l][c] +1;
          linha.push(l);
          coluna.push(c-1);
          if(l == y1 && c-1 == x1){
            //cout << "ACHOU" << endl;
            verify = true;
            break;
          }
        }
        if(cidade[l][c][3] == 1 && cor[l][c+1] == false){
          d[l][c+1] = d[l][c] +1;
          linha.push(l);
          coluna.push(c+1);
          if(l == y1 && c+1 == x1){
            //cout << "ACHOU" << endl;
            verify = true;
            break;
          }
        }
      }
      if(verify == true){
        cout << d[y1][x1] << endl;
      }
      else{ 
        cout << "Impossible" << endl;
      }
    }
    test++;
  }
}
