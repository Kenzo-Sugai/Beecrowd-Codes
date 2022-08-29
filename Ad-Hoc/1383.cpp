#include <iostream>

using namespace std;

int main() {
  
  int N, n, T;
  cin >> N;
  T = N;
  while(N--){
    bool verify = false;
    int inst = abs(T-N);
    cout << "Instancia " << inst << endl;
    int Sudoku[9][9];
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        cin >> Sudoku[i][j];
      }
    }
    
    /*
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        cout << Sudoku[i][j] << " ";
      }
      cout << endl;
    }
    */

    // linhas
    for(int i = 0; i < 9; i++){
      int counter = 1;
      //cout << "line " << i+1 << ": ";
      for(int j = 0; j < 9; j++){
        if(Sudoku[i][j] == counter){
          //cout << counter << " ";
          j = -1; // voltar j = 0;
          counter++;
          if(counter == 10){
            j = 9;
          }
        }
      }
      if(counter != 10){
        //cout << "False" << endl;
        verify = true;
        break;
      }
      else{
        //cout << "SIM" << endl;
      }
    }

    // colunas
    for(int i = 0; i < 9; i++){
      int counter = 1;
      //cout << "column " << i+1 << ": ";
      for(int j = 0; j < 9; j++){
        if(Sudoku[j][i] == counter){
          //cout << counter << " ";
          j = -1; // voltar j = 0;
          counter++;
          if(counter == 10){
            j = 9;
          }
        }
      }
      if(counter != 10){
        verify = true;
        break;
      }
      else{
        //cout << "SIM" << endl;
      }
    }

    // regioes
    int line = 0, column = -3;
    for(int i = 0; i < 9; i++){
      if(i == 3 || i == 6){
        line += 3;
      }
      if(column == 6){
        column = 0;
      }
      else{
        column += 3;
      }
      int counter = 1;
      //cout << "Regiao " << i+1 << ": ";
      for(int j = line; j < line+3; j++){
        for(int k = column; k < column+3; k++){
          if(Sudoku[j][k] == counter){
            //cout << counter << " ";
            j = -1;
            counter++;
            if(counter == 10){
              j = column+3;
            }
          }     
        }
      }
      if(counter != 10){
        verify = true;
        break;
      }
      else{
        //cout << "SIM" << endl;
      }
    }
    if(verify == false){
      cout << "SIM" << endl; 
    }
    else{
      cout << "NAO" << endl;
    }
    cout << endl;
  }
}