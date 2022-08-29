#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  string name;
  char type;
  int N, yes = 0, no = 0;
  cin >> N;
  string list[N];
  for(int i = 0; i < N; i++){
    cin >> type >> name;
    list[i] = name;
    (type == '+') ? yes++ : no++;
  }

  sort(list, list + N);

  for(int i = 0; i < N; i++){
    cout << list[i] << endl;
  }

  cout << "Se comportaram: " << yes << " | " << "Nao se comportaram: " << no << endl;
}