#include <iostream>
#include <vector>

using namespace std;

int main(){
  
  int N, tam, n, h, number;
  
  scanf("%d", &N);

  while(N--){
    vector<vector<int>> hash;

    scanf("%d %d", &tam, &n);

    hash.resize(tam);

    for(int i = 0; i < n; i++){
      scanf("%d", &number);
      hash[number % 13].push_back(number);
    }

    for(int i = 0; i < tam; i++){
      printf("%d -> ", i);
      for(int j = 0; j < hash[i].size(); j++){
        printf("%d", hash[i][j]);
        printf(" -> ");
      }
      printf("\\\n");
    }
  }
}