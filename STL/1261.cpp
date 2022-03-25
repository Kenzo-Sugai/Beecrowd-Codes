#include <iostream>
#include <map>

using namespace std;

int main() {
  map<string, int> dicionario;
  int dic, amount, text, total = 0;
  string word, txt, palavra;
  cin >> dic;
  cin >> text;

  for(int i = 0; i < dic; i++){
    cin >> word;
    cin >> amount;
    dicionario.emplace(word, amount);
  }
  for(int i = 0; i < text; i++){
    while(txt != "."){
      cin >> txt;
      total = total + dicionario[txt];
    }
    cout << total << endl;
    total = 0;
    txt = "default";
  }
}
