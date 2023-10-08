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

void insertionSort(string vet[], int n) {
  string aux;
  int j;
  for(int i = 1; i < n; i++) {
    aux = vet[i];

    for(j = i-1; (j>= 0) && (vet[j] > aux); j--)
      vet[j+1] = vet[j];
    vet[j+1] = aux;
  }

  //for(int i = 0; i < n; i++) cout << vet[i] << endl;
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
  int selectionT1, 
      selectionT5, 
      selectionT10, 
      selectionT15, 
      selectionT20, 
      selectionT30, 
      selectionT40;
  //Tempos insertion sort
  int insertionT1, 
      insertionT5, 
      insertionT10, 
      insertionT15, 
      insertionT20, 
      insertionT30, 
      insertionT40;

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
    //Recriando os vetores desordenados
    createArrays();
    
    //IMPLEMENTAÇÕES SELECTION SORT
    //n = 1000
    cout << "Selection Sort 1k" << endl;
    iniTime = (int) clock();
    selectionSort(vet1, V1LEN);
    endTime = (int) clock();
    selectionT1 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 5000
    cout << "Selection Sort 5k" << endl;
    iniTime = (int) clock();
    selectionSort(vet5, V5LEN);
    endTime = (int) clock();
    selectionT5 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 10000
    cout << "Selection Sort 10k" << endl;
    iniTime = (int) clock();
    selectionSort(vet10, V10LEN);
    endTime = (int) clock();
    selectionT10 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 15000
    cout << "Selection Sort 15k" << endl;
    iniTime = (int) clock();
    selectionSort(vet15, V15LEN);
    endTime = (int) clock();
    selectionT15 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 20000
    cout << "Selection Sort 20k" << endl;
    iniTime = (int) clock();
    selectionSort(vet20, V20LEN);
    endTime = (int) clock();
    selectionT20 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 30000
    cout << "Selection Sort 30k" << endl;
    iniTime = (int) clock();
    selectionSort(vet30, V30LEN);
    endTime = (int) clock();
    selectionT30 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 40000
    cout << "Selection Sort 40k" << endl;
    iniTime = (int) clock();
    selectionSort(vet40, V40LEN);
    endTime = (int) clock();
    selectionT40 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //Impressão da tabela parcial
    cout << "\nn\tBubble\t" << endl;
    cout << "1000\t" << selectionT1 << endl;
    cout << "5000\t" << selectionT5 << endl;
    cout << "10000\t" << selectionT10 << endl;
    cout << "15000\t" << selectionT15 << endl;
    cout << "20000\t" << selectionT20 << endl;
    cout << "30000\t" << selectionT30 << endl;
    cout << "40000\t" << selectionT40 << endl;
    //Recriando os vetores desordenados
    createArrays();
    
    //IMPLEMENTAÇÕES INSERTION SORT
    //n = 1000
    cout << "Insertion Sort 1k" << endl;
    iniTime = (int) clock();
    insertionSort(vet1, V1LEN);
    endTime = (int) clock();
    insertionT1 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 5000
    cout << "Insertion Sort 5k" << endl;
    iniTime = (int) clock();
    insertionSort(vet5, V5LEN);
    endTime = (int) clock();
    insertionT5 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 10000
    cout << "Insertion Sort 10k" << endl;
    iniTime = (int) clock();
    insertionSort(vet10, V10LEN);
    endTime = (int) clock();
    insertionT10 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 15000
    cout << "Insertion Sort 15k" << endl;
    iniTime = (int) clock();
    insertionSort(vet15, V15LEN);
    endTime = (int) clock();
    insertionT15 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 20000
    cout << "Insertion Sort 20k" << endl;
    iniTime = (int) clock();
    insertionSort(vet20, V20LEN);
    endTime = (int) clock();
    insertionT20 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 30000
    cout << "Insertion Sort 30k" << endl;
    iniTime = (int) clock();
    insertionSort(vet30, V30LEN);
    endTime = (int) clock();
    insertionT30 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 40000
    cout << "Insertion Sort 40k" << endl;
    iniTime = (int) clock();
    insertionSort(vet40, V40LEN);
    endTime = (int) clock();
    insertionT40 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //Impressão da tabela parcial
    cout << "\nn\tInsertion\t" << endl;
    cout << "1000\t" << insertionT1 << endl;
    cout << "5000\t" << insertionT5 << endl;
    cout << "10000\t" << insertionT10 << endl;
    cout << "15000\t" << insertionT15 << endl;
    cout << "20000\t" << insertionT20 << endl;
    cout << "30000\t" << insertionT30 << endl;
    cout << "40000\t" << insertionT40 << endl;
    //Recriando os vetores desordenados
    createArrays();
    
    //Impressão da tabela final
    cout << "\nTabela Final\n" << endl;
    cout << "\nn\tBubble\tSelection\tInsertion" << endl;
    cout << "1000\t"<< bubbleT1<<"\t"<<selectionT1<<"\t"<<insertionT1<<endl;
    cout << "5000\t"<< bubbleT5<<"\t"<<selectionT5<<"\t"<<insertionT5<<endl;
    cout << "10000\t"<<bubbleT10<<"\t"<<selectionT10<<"\t"<<insertionT10<<endl;
    cout << "15000\t"<<bubbleT15<<"\t"<<selectionT15<<"\t"<<insertionT15<<endl;
    cout << "20000\t"<<bubbleT20<<"\t"<<selectionT20<<"\t"<<insertionT20<<endl;
    cout << "30000\t"<<bubbleT30<<"\t"<<selectionT30<<"\t"<<insertionT30<<endl;
    cout << "40000\t"<<bubbleT40<<"\t"<<selectionT40<<"\t"<<insertionT40<<endl;
  } else {
    cout << "Erro ao abrir arquivo..." << endl;
  }

  return 0;
}
