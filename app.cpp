#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

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
    return true;
  }else {
    return false;
  }
}

/*
Realizando a passagem por valor e não por referência
para manter desordenado para os próximos algoritmos.
Obs.: Os valores não serão retornados pois nos interessa apenas
os tempos gastos em ordenação;
*/
void bubbleSort(string vet[], int n) {
  string aux;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n-1-i; j++){
      if(vet[j+1] < vet[j]){
        aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = aux;
      }
    }
  }

  //for(int i = 0; i < n; i++) cout << vet[i] << endl;
}

void selectionSort(string vet[], int n){
	string aux;
	int menor;
	
	for(int i = 0; i < n-1; i++){
		menor = i;
		for(int j = (i+1); j < n; j++){
			if(vet[j] < vet[menor])
				menor = j;
		}
		aux = vet[i];
		vet[i] = vet[menor];
		vet[menor] = aux;
	}
}

int main() {
  /*
  Salvaremos os tempos em variáveis individuais afim de
  melhorar a vizualização da tabela final
  */ 
  //Auxiliares p/ cálculo dos tempos
  int iniTime, endTime;
  //Tempos bubble sort
  int bubbleT1, 
      bubbleT5, 
      bubbleT10, 
      bubbleT15, 
      bubbleT20, 
      bubbleT30, 
      bubbleT40;
  //Tempos selection sort


  //Valida a criação dos vetores com os valores do arquivo p/ prosseguir
  if(createArrays()){
    //IMPLEMENTAÇÕES BUBBLE SORT
    //n = 1000
    cout << "Bubble Sort 1k" << endl;
    iniTime = (int) clock();
    bubbleSort(vet1, V1LEN);
    endTime = (int) clock();
    bubbleT1 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 5000
    cout << "Bubble Sort 5k" << endl;
    iniTime = (int) clock();
    bubbleSort(vet5, V5LEN);
    endTime = (int) clock();
    bubbleT5 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 10000
    cout << "Bubble Sort 10k" << endl;
    iniTime = (int) clock();
    bubbleSort(vet10, V10LEN);
    endTime = (int) clock();
    bubbleT10 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 15000
    cout << "Bubble Sort 15k" << endl;
    iniTime = (int) clock();
    bubbleSort(vet15, V15LEN);
    endTime = (int) clock();
    bubbleT15 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 20000
    cout << "Bubble Sort 20k" << endl;
    iniTime = (int) clock();
    bubbleSort(vet20, V20LEN);
    endTime = (int) clock();
    bubbleT20 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 30000
    cout << "Bubble Sort 30k" << endl;
    iniTime = (int) clock();
    bubbleSort(vet30, V30LEN);
    endTime = (int) clock();
    bubbleT30 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 40000
    cout << "Bubble Sort 40k" << endl;
    iniTime = (int) clock();
    bubbleSort(vet40, V40LEN);
    endTime = (int) clock();
    bubbleT40 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //Impressão da tabela parcial
    cout << "\nn\tBubble\t" << endl;
    cout << "1000\t" << bubbleT1 << endl;
    cout << "5000\t" << bubbleT5 << endl;
    cout << "10000\t" << bubbleT10 << endl;
    cout << "15000\t" << bubbleT15 << endl;
    cout << "20000\t" << bubbleT20 << endl;
    cout << "30000\t" << bubbleT30 << endl;
    cout << "40000\t" << bubbleT40 << endl;

    //IMPLEMENTAÇÕES SELECTION SORT
    //...

    //Impressão da tabela final
    cout << "\nTabela Final\n" << endl;
    cout << "\nn\tBubble\tSelection" << endl;
    cout << "1000\t" << bubbleT1 << endl;
    cout << "5000\t" << bubbleT5 << endl;
    cout << "10000\t" << bubbleT10 << endl;
    cout << "15000\t" << bubbleT15 << endl;
    cout << "20000\t" << bubbleT20 << endl;
    cout << "30000\t" << bubbleT30 << endl;
    cout << "40000\t" << bubbleT40 << endl;
  } else {
    cout << "Erro ao abrir arquivo..." << endl;
  }

  return 0;
}
