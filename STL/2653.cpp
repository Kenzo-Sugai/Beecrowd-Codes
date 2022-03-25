#include <iostream>
#include <set>

using namespace std;
int main() {
  set<string> total;
  string joias;
  while(getline(cin, joias)){
    total.insert(joias);
  }
  int result = total.size();
  printf("%d\n", result);
} 
