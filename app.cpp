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

    return true;
  }else {
    return false;
  }
}

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
 
void shellSort(string vet[], int n) {
  string aux;
  int j, h = n/2;

  while(h >= 1) {
    for(int i = 1; i < n; i++) {
      aux = vet[i];
      for(j = i-h; (j >= 0) && (vet[j] > aux); j-=h)
        vet[j+h] = vet[j];
      vet[j+h] = aux;
    }
    h/=2;
  }
  
  //for(int i = 0; i < n; i++) cout << vet[i] << endl;
}

void mergeIntercala(string *vet, string *aux, int ini, int meio, int fin){
  int atual, fimEsq, n;
  atual = ini;
  fimEsq = meio - 1;
  n = fin - ini + 1;

  while ((ini <= fimEsq) && (meio <= fin))
  {
    if(vet[ini] <= vet[meio])
      aux[atual++] = vet[ini++];
    else
      aux[atual++] = vet[meio++];
  }

  while (ini <= fimEsq)
    aux[atual++] = vet[ini++];

  while(meio <= fin)
    aux[atual++] = vet[meio++];

  for(int i = 0; i < n; i++){
    vet[fin] = aux[fin];
    fin--;
  }
  
}

void mergeDivide(string *vet, string *aux, int ini, int fin){
  int meio;

  if(fin > ini){
    meio = (fin+ini)/2;
    mergeDivide(vet, aux, ini, meio);
    mergeDivide(vet, aux, meio+1, fin);
    mergeIntercala(vet, aux, ini, meio+1, fin);
  }
}

void merge(string *vet, int n){
  string aux[n];
  mergeDivide(vet, aux, 0, n-1);
}

int partition(string vet[], int esq, int dir){
  int i = esq, j = dir; 
  string aux, pivo = vet[esq];

  while(i < j){
    while((vet[i] <= pivo) && (i < dir)) i++;
    while((vet[j] >= pivo) && (j > esq)) j--;

    if(i < j) {
      aux = vet[j];
      vet[j] = vet[i];
      vet[i] = aux;
    }
  }
  
  vet[esq] = vet[j];
  vet[j] = pivo;
  return j;
}

void quickSort(string vet[], int esq, int dir) {
  if(esq < dir) {
    int pivo = partition(vet, esq, dir);
    quickSort(vet, esq, pivo-1);
    quickSort(vet, pivo+1, dir);
  }
}

int main() {
  system("cls");
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
  //Tempos shell sort
  int shellT1, 
      shellT5, 
      shellT10, 
      shellT15, 
      shellT20, 
      shellT30, 
      shellT40;
//Tempos merge sort
  int mergeT1, 
      mergeT5, 
      mergeT10, 
      mergeT15, 
      mergeT20, 
      mergeT30, 
      mergeT40;
  //Tempos quick sort
  int quickT1, 
      quickT5, 
      quickT10, 
      quickT15, 
      quickT20, 
      quickT30, 
      quickT40;

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
    cout << "\nSelection Sort 1k" << endl;
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
    cout << "\nInsertion Sort 1k" << endl;
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
    
    //IMPLEMENTAÇÕES SHELL SORT
    //n = 1000
    cout << "\nShell Sort 1k" << endl;
    iniTime = (int) clock();
    shellSort(vet1, V1LEN);
    endTime = (int) clock();
    shellT1 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 5000
    cout << "Shell Sort 5k" << endl;
    iniTime = (int) clock();
    shellSort(vet5, V5LEN);
    endTime = (int) clock();
    shellT5 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 10000
    cout << "Shell Sort 10k" << endl;
    iniTime = (int) clock();
    shellSort(vet10, V10LEN);
    endTime = (int) clock();
    shellT10 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 15000
    cout << "Shell Sort 15k" << endl;
    iniTime = (int) clock();
    shellSort(vet15, V15LEN);
    endTime = (int) clock();
    shellT15 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 20000
    cout << "Shell Sort 20k" << endl;
    iniTime = (int) clock();
    shellSort(vet20, V20LEN);
    endTime = (int) clock();
    shellT20 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 30000
    cout << "Shell Sort 30k" << endl;
    iniTime = (int) clock();
    shellSort(vet30, V30LEN);
    endTime = (int) clock();
    shellT30 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 40000
    cout << "Shell Sort 40k" << endl;
    iniTime = (int) clock();
    shellSort(vet40, V40LEN);
    endTime = (int) clock();
    shellT40 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //Impressão da tabela parcial
    cout << "\nn\tShell\t" << endl;
    cout << "1000\t" << shellT1 << endl;
    cout << "5000\t" << shellT5 << endl;
    cout << "10000\t" << shellT10 << endl;
    cout << "15000\t" << shellT15 << endl;
    cout << "20000\t" << shellT20 << endl;
    cout << "30000\t" << shellT30 << endl;
    cout << "40000\t" << shellT40 << endl;
    //Recriando os vetores desordenados
    createArrays();

    //IMPLEMENTAÇÕES MERGE SORT
    //n = 1000
    cout << "\nMerge Sort 1k" << endl;
    iniTime = (int) clock();
    merge(vet1, V1LEN);
    endTime = (int) clock();
    mergeT1 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 5000
    cout << "Merge Sort 5k" << endl;
    iniTime = (int) clock();
    merge(vet5, V5LEN);
    endTime = (int) clock();
    mergeT5 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 10000
    cout << "Merge Sort 10k" << endl;
    iniTime = (int) clock();
    merge(vet10, V10LEN);
    endTime = (int) clock();
    mergeT10 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 15000
    cout << "Merge Sort 15k" << endl;
    iniTime = (int) clock();
    merge(vet15, V15LEN);
    endTime = (int) clock();
    mergeT15 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 20000
    cout << "Merge Sort 20k" << endl;
    iniTime = (int) clock();
    merge(vet20, V20LEN);
    endTime = (int) clock();
    mergeT20 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 30000
    cout << "Merge Sort 30k" << endl;
    iniTime = (int) clock();
    merge(vet30, V30LEN);
    endTime = (int) clock();
    mergeT30 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 40000
    cout << "Merge Sort 40k" << endl;
    iniTime = (int) clock();
    merge(vet40, V40LEN);
    endTime = (int) clock();
    mergeT40 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //Impressão da tabela parcial
    cout << "\nn\tInsertion\t" << endl;
    cout << "1000\t" << mergeT1 << endl;
    cout << "5000\t" << mergeT5 << endl;
    cout << "10000\t" << mergeT10 << endl;
    cout << "15000\t" << mergeT15 << endl;
    cout << "20000\t" << mergeT20 << endl;
    cout << "30000\t" << mergeT30 << endl;
    cout << "40000\t" << mergeT40 << endl;
    //Recriando os vetores desordenados
    createArrays();
  
    //IMPLEMENTAÇÕES QUICK SORT
    //n = 1000
    cout << "Quick Sort 1k" << endl;
    iniTime = (int) clock();
    quickSort(vet1, 0, V1LEN-1);
    endTime = (int) clock();
    quickT1 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 5000
    cout << "Quick Sort 5k" << endl;
    iniTime = (int) clock();
    quickSort(vet5, 0, V5LEN-1);
    endTime = (int) clock();
    quickT5 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 10000
    cout << "Quick Sort 10k" << endl;
    iniTime = (int) clock();
    quickSort(vet10, 0, V10LEN-1);
    endTime = (int) clock();
    quickT10 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 15000
    cout << "Quick Sort 15k" << endl;
    iniTime = (int) clock();
    quickSort(vet15, 0, V15LEN-1);
    endTime = (int) clock();
    quickT15 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 20000
    cout << "Quick Sort 20k" << endl;
    iniTime = (int) clock();
    quickSort(vet20, 0, V20LEN-1);
    endTime = (int) clock();
    quickT20 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 30000
    cout << "Quick Sort 30k" << endl;
    iniTime = (int) clock();
    quickSort(vet30, 0, V30LEN-1);
    endTime = (int) clock();
    quickT30 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //n = 40000
    cout << "Quick Sort 40k" << endl;
    iniTime = (int) clock();
    quickSort(vet40, 0, V40LEN-1);
    endTime = (int) clock();
    quickT40 = ((endTime - iniTime)*1000/CLOCKS_PER_SEC);
    //Impressão da tabela parcial
    cout << "\nn\tQuick\t" << endl;
    cout << "1000\t" << quickT1 << endl;
    cout << "5000\t" << quickT5 << endl;
    cout << "10000\t" << quickT10 << endl;
    cout << "15000\t" << quickT15 << endl;
    cout << "20000\t" << quickT20 << endl;
    cout << "30000\t" << quickT30 << endl;
    cout << "40000\t" << quickT40 << endl;

    //Impressão da tabela final
    cout << "\nTabela Final\n" << endl;
    cout << "n    \tBubble \t\tSelection \tInsertion \tShell \t\tMerge \t\tQuick" << endl;
    cout << "1000 \t"<< bubbleT1<<"\t\t"<< selectionT1<<"\t\t"<< insertionT1<<"\t\t"<< shellT1<<"\t\t"<<mergeT1<<"\t\t"<< quickT1<<endl;
    cout << "5000 \t"<< bubbleT5<<"\t\t"<< selectionT5<<"\t\t"<< insertionT5<<"\t\t"<< shellT5<<"\t\t"<<mergeT5<<"\t\t"<< quickT5<<endl;
    cout << "10000\t"<<bubbleT10<<"\t\t"<<selectionT10<<"\t\t"<<insertionT10<<"\t\t"<<shellT10<<"\t\t"<<mergeT10<<"\t\t"<<quickT10<<endl;
    cout << "15000\t"<<bubbleT15<<"\t\t"<<selectionT15<<"\t\t"<<insertionT15<<"\t\t"<<shellT15<<"\t\t"<<mergeT15<<"\t\t"<<quickT15<<endl;
    cout << "20000\t"<<bubbleT20<<"\t\t"<<selectionT20<<"\t\t"<<insertionT20<<"\t\t"<<shellT20<<"\t\t"<<mergeT20<<"\t\t"<<quickT20<<endl;
    cout << "30000\t"<<bubbleT30<<"\t\t"<<selectionT30<<"\t\t"<<insertionT30<<"\t\t"<<shellT30<<"\t\t"<<mergeT30<<"\t\t"<<quickT30<<endl;
    cout << "40000\t"<<bubbleT40<<"\t\t"<<selectionT40<<"\t\t"<<insertionT40<<"\t\t"<<shellT40<<"\t\t"<<mergeT40<<"\t\t"<<quickT40<<endl;
  } else {
    cout << "Erro ao abrir arquivo..." << endl;
  }

  return 0;
}
