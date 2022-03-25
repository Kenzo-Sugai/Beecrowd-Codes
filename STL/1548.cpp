#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  vector<int> alunos;
  set<int, greater<>> alunos_compare;
  set<int>::iterator itr;
  int N, M, P, nota, change = 0, cont = 0, t;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> M;
    for(int j = 0; j < M; j++){
      cin >> nota;
      alunos.push_back(nota);
      alunos_compare.insert(nota);
      }
      for(itr = alunos_compare.begin(), t = 0; itr != alunos_compare.end(); ++itr, t++){
        if(alunos[t] == *itr){
          change++;
        }
      }
      cout << change << endl;
      change = 0;
      alunos_compare.clear();
      alunos.clear();
    }
  }
