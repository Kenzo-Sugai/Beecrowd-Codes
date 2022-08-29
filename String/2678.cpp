#include <iostream>
#include <map>
#include <cctype>

int main(){

  std::string discado;

  std::map<char, int> telefone = {
  {'A', 2}, {'B', 2}, {'C', 2},
  {'D', 3}, {'E', 3}, {'F', 3},
  {'G', 4}, {'H', 4}, {'I', 4},
  {'J', 5}, {'K', 5}, {'L', 5},
  {'M', 6}, {'N', 6}, {'O', 6},
  {'P', 7}, {'Q', 7}, {'R', 7}, {'S', 7},
  {'T', 8}, {'U', 8}, {'V', 8},
  {'W', 9}, {'X', 9}, {'Y', 9}, {'Z', 9}
  }; 

  while(std::getline(std::cin, discado)){
    
    for(int i {}; i < discado.size(); i++){
      if(discado[i] >= '0' && discado[i] <= '9' || discado[i] == '*' || discado[i] == '#'){
        std::cout << discado[i];
      }
      else if(discado[i] >= 'A' && discado[i] <= 'Z' || discado[i] >= 'a' && discado[i] <= 'z'){
        std::cout << telefone[toupper(discado[i])];
      }
    }
    std::cout << '\n';
  }
}