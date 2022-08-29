#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> M;

class pessoa{
  public:
    char T;
    int y;
    int x;
    vector<vector<int>> cor;

    pessoa(){}

    pessoa(char T, int y, int x){
      this->T = T;
      this->y = y;
      this->x = x;
    }
};

int C, N;

void printM(){
  cout << "----------" << endl;
  for(int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cout << M[i][j] << " ";
    }
    cout << endl;      
  }
  cout << "----------" << endl;
}

int main(){

  string line;

  cin >> C;

  while(C--){

    cin >> N;

    M.resize(N);

    pessoa p[3];
    p[0].T = 'A';
    p[1].T = 'B';
    p[2].T = 'C'; 
    p[0].cor.resize(N);
    p[1].cor.resize(N);
    p[2].cor.resize(N);

    for(int i = 0; i < N; i++){
      cin >> line;
      for (int j = 0; j < N; j++){
        if(line[j] == 'A')
          p[0].y = i;
          p[0].x = j;
        if(line[j] == 'B')
          p[1].y = i;
          p[1].x = j;
        if(line[j] == 'C')
          p[2].y = i;
          p[2].x = j;
        if(line[j] == '.'){
          p[0].cor[i][j] = 0;
          p[1].cor[i][j] = 0;
          p[2].cor[i][j] = 0;
        }
        if(line[j] == '#'){
          p[0].cor[i][j] = 1;
          p[1].cor[i][j] = 1;
          p[2].cor[i][j] = 1;
        }
        if(line[j] == 'X'){
          p[0].cor[i][j] = 2;
          p[1].cor[i][j] = 2;
          p[2].cor[i][j] = 2;
        }
        M[i].push_back(line[j]);
      }      
    }

    queue<pessoa> Q;
    Q.push(p[0]);
    Q.push(p[1]);
    Q.push(p[2]);

    while(!Q.empty()){
      pessoa uA = Q.front(); Q.pop();
      pessoa uB = Q.front(); Q.pop();
      pessoa uC = Q.front(); Q.pop();
      pessoa R[3] = {uA, uB, uC};
      for(int i = 0; i < 4; i++){
        if(R[i].x+1 < N && R[i].cor[R[i].y][R[i].x+1] == 0 || R[i].cor[R[i].y][R[i].x+1] == 2){
          if(R[i].cor[R[i].y][R[i].x+1] == 0)
            R[i].cor[R[i].y][R[i].x+1] = 1;
          pessoa pr(R[i].T, R[i].y, R[i].x);
          Q.push(pr);
        } else{Q.push(R[i]);}

        if(R[i].x-1 >= 0 && R[i].cor[R[i].y][R[i].x-1] == 0){
          pessoa pr(R[i].T, R[i].y, R[i].x);
          R[i].cor[R[i].y][R[i].x-1] = 1;
          Q.push(pr);
        } else{Q.push(R[i]);}

        if(R[i].y+1 < N && R[i].cor[R[i].y+1][R[i].x] == 0){
          pessoa pr(R[i].T, R[i].y, R[i].x);
          R[i].cor[R[i].y+1][R[i].x] = 1;
          Q.push(pr);
        } else{Q.push(R[i]);}

        if(R[i].y-1 >= 0 && R[i].cor[R[i].y-1][R[i].x] == 0){
          pessoa pr(R[i].T, R[i].y, R[i].x);
          R[i].cor[R[i].y-1][R[i].x] = 1;
          Q.push(pr);
        } else{Q.push(R[i]);}
      }
      

    }
    


  }
}