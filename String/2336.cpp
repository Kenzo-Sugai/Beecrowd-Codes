#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){
  int mult;
  string palavra;
  while(cin >> palavra){
    unsigned long long int result = 0;
    for(int i = 0; i < palavra.size(); i++){
      mult = palavra.size()-1-i;
      result += (int(palavra[i])-65)*pow(26, mult);
    }
    cout << result << endl;
  }
}