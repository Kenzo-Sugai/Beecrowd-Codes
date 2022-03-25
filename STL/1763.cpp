#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

int main(void){
  map<string, string> mensagem;

  // Dados
  mensagem["brasil"] = "Feliz Natal!";
  mensagem["alemanha"] = "Frohliche Weihnachten!";
  mensagem["austria"] = "Frohe Weihnacht!";
  mensagem["coreia"] = "Chuk Sung Tan!";
  mensagem["espanha"] = "Feliz Navidad!";
  mensagem["grecia"] = "Kala Christougena!";
  mensagem["estados-unidos"] = "Merry Christmas!";
  mensagem["inglaterra"] = "Merry Christmas!";
  mensagem["australia"] = "Merry Christmas!";
  mensagem["portugal"] = "Feliz Natal!";
  mensagem["suecia"] = "God Jul!";
  mensagem["turquia"] = "Mutlu Noeller";
  mensagem["argentina"] = "Feliz Navidad!";
  mensagem["chile"] = "Feliz Navidad!";
  mensagem["mexico"] = "Feliz Navidad!";
  mensagem["antardida"] = "Merry Christmas!";
  mensagem["canada"] = "Merry Christmas!";
  mensagem["irlanda"] = "Nollaig Shona Dhuit!";
  mensagem["belgica"] = "Zalig Kerstfeest!";
  mensagem["italia"] = "Buon Natale!";
  mensagem["libia"] = "Buon Natale!";
  mensagem["siria"] = "Milad Mubarak!";
  mensagem["marrocos"] = "Milad Mubarak!";
  mensagem["japao"] = "Merii Kurisumasu!";
  string country;

  while(getline(cin, country)){
    if(!mensagem[country].empty()){
      cout << mensagem[country] << endl;
      }
    else{
      cout << "--- NOT FOUND ---" << endl;
    }
  }
  return 0;
}
