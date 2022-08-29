#include <iostream>
#include <stack>

using namespace std;

int main(){
  int N;
  string n;

  cin >> N;

  while(N--){
    stack<char> S;
    cin >> n;
    for(int i = 0; i < n.size(); i++){
      if(n[i] >= 'a' && n[i] <= 'z'){
        S.push(n[i]);
      }
    }
    while(!S.empty()){
      cout << S.top();
      S.pop();
    }
    cout << endl;
  }
}