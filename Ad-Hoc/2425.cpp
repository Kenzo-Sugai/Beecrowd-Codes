#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct clispec {
    int entrada;
    int tempo;
};

bool sorteador(clispec a, clispec b){
    if(a.entrada < b.entrada){
        return a.tempo < b.tempo;
    }
    return a.entrada < b.entrada;

}

int main() {

    int qntcx, cli, ent, temp;

    cin >> qntcx >> cli;

    int caixas[qntcx] = {0};
    vector<clispec> clientes;

    for(int i = 0; i < cli; i++){

        cin >> ent >> temp;
        clientes.push_back({ent, temp});

    }

    sort(clientes.begin(), clientes.end(), sorteador);

    int i = 0;
    priority_queue<int> filaCaixas(qntcx, 0);

    while(clientes.size() != 0){




    }









    return 0;
}
