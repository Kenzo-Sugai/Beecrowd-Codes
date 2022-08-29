#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct desempate {
  int equal = 0;
  vector<int> idx;
};

int main(){

    int N;
    string frase;

    cin >> N;

    for(int i = 0; i < N; i++){
        vector<string> telefone;
        for(int j = 0; j < 3; j++){
            if(cin.peek() == '\n') cin.ignore();
            getline(cin, frase);
            telefone.push_back(frase);
        }
        vector<desempate> same(2);
        for(int j = 1; j <= 2; j++){
            for(int k = 0; k < telefone[0].size(); k++){
                if(telefone[0][k] == telefone[j][k]){
                  same[j - 1].equal++;
                  //cout << telefone[0][k] << " == " << telefone[j][k] << " same "  << j-1 << " " << same[j - 1].equal << endl;
                  same[j - 1].idx.push_back(k);
                }
                //else cout << telefone[0][k] << " != " << telefone[j][k] << " same "  << j-1 << " " << same[j - 1].equal << endl;
            }
        }
        vector<string> aux;
        aux.push_back(telefone[1]); aux.push_back(telefone[2]);
        cout << "Instancia " << i+1 << endl;
        if(same[0].equal == same[1].equal){
          if(same[0].idx.size() == 0 && same[1].idx.size() == 0){
            cout << "empate" << endl;
          }
          else{
            for(int i = 0; i < same[0].idx.size(); i++){
              if(same[0].idx[i] < same[1].idx[i]){
                cout << "time 1" << endl;
                break;
              }
              if(same[0].idx[i] > same[1].idx[i]){
                cout << "time 2" << endl;
                break;
              }
              if(i == same[0].idx.size() - 1){
                cout << "empate" << endl;
              }
            }
          }
        } 
        if(same[0].equal > same[1].equal){
            cout << "time 1" << endl;
        }
        if(same[0].equal < same[1].equal){
            cout << "time 2" << endl;
        }
        cout << endl;
    }
}