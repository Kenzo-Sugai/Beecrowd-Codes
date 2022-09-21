#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

  int N, itens, tam, temp;

  cin >> N;

  while(N--){
    
    cin >> itens >> tam;
    vector<int> blocos(itens), Solution(tam+1, INT_MAX);
    for(int i = 0; i < itens; i++){
      cin >> blocos[i];
    }

    sort(blocos.begin(), blocos.end());

    Solution[0] = 0;

    for(int i = 1; i <= tam; i++){

      for(int j = 0; j < itens; j++){

        if(i < blocos[j]) break;

        temp = Solution[i - blocos[j]];
        if(temp + 1 < Solution[i]) Solution[i] = temp + 1;

      }
    }

    cout << Solution[tam] << endl;
    
  }

}
