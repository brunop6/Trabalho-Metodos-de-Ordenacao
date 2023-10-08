#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int V1LEN = 1000;
const int V5LEN = 5000;
const int V10LEN = 10000;
const int V15LEN = 15000;
const int V20LEN = 20000;
const int V30LEN = 30000;
const int V40LEN = 40000;

string vet1[V1LEN], vet5[V5LEN], vet10[V10LEN], vet15[V15LEN];
string vet20[V20LEN], vet30[V30LEN], vet40[V40LEN];

//Função para leitura do arquivo e criação dos vetores de string;
bool createArrays() {
  int line = 0;
  string fOutput;
  ifstream file("aurelio40000.txt");

  if(file.is_open()) {
    while(getline(file, fOutput)) {
      if(line < V1LEN) vet1[line] = fOutput;
      if(line < V5LEN) vet5[line] = fOutput;
      if(line < V10LEN) vet10[line] = fOutput;
      if(line < V15LEN) vet15[line] = fOutput;
      if(line < V20LEN) vet20[line] = fOutput;
      if(line < V30LEN) vet30[line] = fOutput;
      vet40[line] = fOutput;

      line++;
    }
    file.close();

    system("cls");
    cout << "Vetores criados!\n" << endl;
    return true;
  }else {
    return false;
  }
}

int main() {
  //Valida a criação dos vetores com os valores do arquivo p/ prosseguir
  if(createArrays()){
    
  } else {
    cout << "Erro ao abrir arquivo..." << endl;
  }

  return 0;
}