#include <iostream>
#include <map>

using namespace std;

map<char, int> letra; 

int main(){

  string frase;
  int N;
  cin >> N;

  while(N--){

    letra['a'] = 0, letra['b'] = 0, letra['c'] = 0, letra['d'] = 0, letra['e'] = 0, letra['f'] = 0, letra['g'] = 0, letra['h'] = 0,
    letra['i'] = 0, letra['j'] = 0, letra['k'] = 0, letra['l'] = 0, letra['m'] = 0, letra['n'] = 0, letra['o'] = 0, letra['p'] = 0,
    letra['q'] = 0, letra['r'] = 0, letra['s'] = 0, letra['t'] = 0, letra['u'] = 0, letra['v'] = 0, letra['w'] = 0, letra['x'] = 0,
    letra['y'] = 0, letra['z'] = 0;

    getline(cin, frase);

    for(int i = 0; i < frase.size(); i++){
      if(frase[i] >= 'a' && frase[i] <= 'z')
        letra[frase[i]]++;
    }

    int cnt = 0;

    for(int i = 'a'; i <= 'z'; i++){
      if(letra[char(i)] != 0)
        cnt++;
    }

    if(cnt < 13)
      cout << "frase mal elaborada" << endl;
    else if(cnt >= 14 && cnt < 26)
      cout << "frase quase completa" << endl;
    else
      cout << "frase completa" << endl;
  }

}