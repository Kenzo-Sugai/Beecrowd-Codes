#include <iostream>
#include <vector>

using namespace std;

class jogadores{
  public:
    string nome;
    int valor;
    bool estado;

    jogadores(string nome, int valor, bool estado){
      this->nome = nome;
      this->valor = valor;
      this->estado = estado;
    }
};

vector<jogadores> J;

int jogo(){
  int contador = 0, qnt = J[1].valor, index = 0;
  while(contador != J.size()){
    cout << "contador: " << contador << endl;
    if(contador == 0)
      index = 1;
    else{
      qnt = J[index].valor;
    }
    while(true){
      cout << "qnt: " << qnt << endl;
      for(int i = index; i < J.size(); i++){
        if(i == J.size()-1)
          i = 0;
        if(J[i].estado == true){
          qnt--;
          if(qnt == 0){
            index = i;
            J[i].estado = false;
            contador++;
            cout << J[i].nome << " false!" << endl;
            break;
          }
        }
      }
      if(qnt == 0){
        break;
      }
    }
  }
}

int main(){
  int T, n;
  string nome;
  while(true){
    cin >> T;
    if(T == 0){
      break;
    }
    J.clear();
    while(T--){
      cin >> nome >> n;
      J.push_back(jogadores(nome, n, true));
    }
    jogo();
  }
}

/*

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class jogadores{
  public:
    string nome;
    int valor;
    bool estado;

    jogadores(string nome, int valor, bool estado){
      this->nome = nome;
      this->valor = valor;
      this->estado = estado;
    }
};

queue<jogadores> Q;
queue<jogadores> Q_r;

int jogo(){
  int contador = 0;
  while(true){
    if(contador == 0)
      Q.pop();
    int qnt = Q.front().valor;
    while(!Q.empty()){
      Q_r.push(Q.front());
      Q.pop();
    }
  }
}

int main(){
  int T, n;
  string nome;
  while(true){
    cin >> T;
    if(T == 0){
      break;
    } 
    while(T--){
      cin >> nome >> n;
      Q.push(jogadores(nome, n, true));
    }
  }
}
*/