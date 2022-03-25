#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n, temp, remaning;
  queue<int> cards;
  vector<int> descarte;
  while(true){
    cin >> n;
    if(n == 0){
      break;
    }
    for(int i = 1; i <= n; i++){
      cards.push(i);
    }
    for(int i = 0; i < n; i++){
      if(cards.size() == 1){
         remaning = cards.front();
         cards.pop();
        break;
      }
      descarte.push_back(cards.front());
      cards.pop();
      temp = cards.front();
      cards.pop();
      cards.push(temp);
    }
    cout << "Discarded cards: " << descarte[0];
    for(int i = 1; i < descarte.size(); i++){
      cout << ", " << descarte[i];
    }
    cout << endl;
    cout << "Remaining card: " << remaning << endl;
    descarte.clear();
  }
} 
