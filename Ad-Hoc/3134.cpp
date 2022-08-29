#include <iostream>

using namespace std;

bool resposta(float n1, float n2, float n3, float n4){
  if(n1 + n2 == n3 + n4)
    return true;
  if(n1 + n3 == n2 + n4)
    return true;
  if(n1 + n4 == n2 + n3)
    return true;
  if(n1 == n2 + n3 + n4)
    return true;
  if(n2 == n1 + n3 + n4)
    return true;
  if(n4 == n1 + n2 + n3)
    return true;
  return false;
}

int main(){

  float n1, n2, n3, n4;

  cin >> n1 >> n2 >> n3 >> n4;

  if(resposta(n1, n2, n3, n4)){
    cout << "YES" << endl;
    return 0;
  }
  else{
    cout << "NO" << endl; 
    return 0;
  }
}