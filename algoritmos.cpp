#include "algoritmos.h"

using namespace std;


algoritmos::algoritmos(/* args */){
}

algoritmos::~algoritmos(){
}

void algoritmos::mostrarIntervalo(clock_t *inicioTempo,clock_t *fimTempo,char* algoritmo){
    double intervalo = double(*inicioTempo - *fimTempo) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(6);
    cout << endl << "Tempo de ordenacao do " << algoritmo << " : " << intervalo << endl;
}
void algoritmos::mostrarIntervalo(clock_t inicioTempo,clock_t fimTempo, char* algoritmo){
    double intervalo = double(fimTempo -inicioTempo ) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(6);
    cout << endl << "Tempo de ordenacao do " << algoritmo << " : " << intervalo << endl;
}

void algoritmos::BubbleSort(float *vetor,int tamanhoVetor ,bool saidaOrdenada){
    //Fonte do código: https://www.dio.me/articles/algoritmo-bubble-sort-comentado
    int i, j; 
    float vetorCopia[tamanhoVetor];
    for(i = 0; i<tamanhoVetor;i++){
        vetorCopia[i] = vetor[i];
    }
    
    //Inicio da ordenação
    clock_t inicio = clock();
    for (i = 0; i < tamanhoVetor-1; i++){
        for (j = 0; j < tamanhoVetor-i-1; j++){
            if (vetorCopia[j] > vetorCopia[j+1]){
                float temp = vetorCopia[j]; 
                vetorCopia[j] = vetorCopia[j+1]; 
                vetorCopia[j+1] = temp;  
            }
        }
    }
    clock_t fim = clock();
    
    //Fim da ordenação
    if(saidaOrdenada){//Mostra o vetor ordenado ou não
        cout << "Vetor do Buuble sort: " <<endl;
        for(i = 0; i<tamanhoVetor;i++){
            cout << vetorCopia[i] << "-";
        }
    }

    mostrarIntervalo(inicio,fim,"BubbleSort");
    
}

void algoritmos::InsertSort(float *vetor,int tamanhoVetor,bool saidaOrdenada){
    //Fonte do código: https://www.geeksforgeeks.org/cpp-program-for-insertion-sort/
    int i;
    float vetorCopia[tamanhoVetor];
    for(i = 0; i<tamanhoVetor;i++){
        vetorCopia[i] = vetor[i];
    }
    //Inicio da ordenação
    clock_t inicio  = clock();
    for (i = 1; i < tamanhoVetor; ++i) {
        float key = vetorCopia[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && vetorCopia[j] > key) {
            vetorCopia[j + 1] = vetorCopia[j];
            j = j - 1;
        }
        vetorCopia[j + 1] = key;
    }
    clock_t fim = clock();
    
    //Fim da ordenação
    if(saidaOrdenada){//Mostra o vetor ordenado ou não
        for(i = 0; i<tamanhoVetor;i++){
            cout << vetorCopia[i] << "-";
        }
    }
    mostrarIntervalo(inicio,fim,"InsertSort");
}

void algoritmos::SelectionSort(float *vetor,int tamanhoVetor,bool saidaOrdenada){
    //Fonte do Código: https://pt.wikipedia.org/wiki/Selection_sort
    float aux;
    int i,j,k;
    float vetorCopia[tamanhoVetor];
    for(i = 0; i<tamanhoVetor;i++){
        vetorCopia[i] = vetor[i];
    }
    //Inicio da ordenaçao
    clock_t inicio  = clock();
    for ( i = 0; i < tamanhoVetor; ++i) {
         j = i;
        for ( k = i+1; k < tamanhoVetor; ++k) {
            if (vetorCopia[k] < vetorCopia[j]) {
                j = k;
            }
        }
        aux = vetorCopia[i];
        vetorCopia[i] = vetorCopia[j];
        vetorCopia[j] = aux;
    }
    clock_t fim = clock();
    //Fim da ordenaçao
    if(saidaOrdenada){//Mostra o vetor ordenado ou não
        for(i = 0; i<tamanhoVetor;i++){
            cout << vetorCopia[i] << "-";
        }
    }
    mostrarIntervalo(inicio,fim,"SelectionSort");
}

void algoritmos::QuickSort(float *vetor,int inicio,int fim,clock_t *inicioTempo,clock_t *fimTempo){
    //Fonte do código: https://pt.wikipedia.org/wiki/Quicksort
    float vetorCopia[fim];
    for(int i = 0; i<fim;i++){
        vetorCopia[i] = vetor[i];
    }
    if (inicio >= fim - 1) return; // Caso base: array de 1 ou 0 elementos já está ordenado

    int i = inicio, j = fim - 1;
    float pivo = vetorCopia[inicio + (fim - inicio) / 2];
    float aux;
    //Inicio
    (*inicioTempo) += clock();
    while (i <= j)
    {
        while (i < fim && vetorCopia[i] < pivo)
            i++;
        while (j >= inicio && vetorCopia[j] > pivo)
            j--;

        if (i <= j)
        {
            aux = vetorCopia[i];
            vetorCopia[i] = vetorCopia[j];
            vetorCopia[j] = aux;
            i++;
            j--;
        }
    }

    if (inicio < j)
        QuickSort(vetorCopia, inicio, j + 1,inicioTempo,fimTempo);
    if (i < fim)
        QuickSort(vetorCopia, i, fim,inicioTempo,fimTempo);
    //Fim
    (*fimTempo) += clock();

}

void algoritmos::ShellSort(float *vetor,int tamanhoVetor){
    //Fonte : https://pt.wikipedia.org/wiki/Shell_sort
    int h = 1;
    int i, j;
    int rep = 0;
    float vetorCopia[tamanhoVetor];
    for(int i = 0; i<tamanhoVetor;i++){
        vetorCopia[i] = vetor[i];
    }
    //Inicio do código
    clock_t inicio = clock();
    while (h < tamanhoVetor) {
       h = h*3+1;
    }

    while (h > 1) {
        h /= 3;

        for (i = h; i < tamanhoVetor; i++) {
            float aux = vetorCopia[i];
            j = i;

            while (j >= h && aux <vetorCopia[j-h]) {
                vetorCopia[j] = vetorCopia[j-h];
                j -= h;
                rep++;
            }

            vetorCopia[j] = aux;
        }
    }
    clock_t fim = clock();

    mostrarIntervalo(inicio,fim,"ShellSort");
}

void algoritmos::MergeSort(float *vetor,float * aux, int inicio,int fim,clock_t *inicioTempoMerge,clock_t *fimTempoMerge){
    //Fonte: https://pt.wikipedia.org/wiki/Merge_sort
    
    float vetorCopia[fim];
    for(int i = 0; i<fim;i++){
        vetorCopia[i] = vetor[i];
    }
    if(inicio < fim){

        inicioTempoMerge += clock();
        int meio = (inicio + fim) / 2;
        MergeSort(vetorCopia, aux, inicio, meio,inicioTempoMerge,fimTempoMerge);
        MergeSort(vetorCopia, aux, meio + 1, fim,inicioTempoMerge,fimTempoMerge);
        merge(vetorCopia, aux, inicio, meio, fim);
        fimTempoMerge += clock();
        
    }
}
void algoritmos::merge(float* vetor, float * aux,int inicio,int meio,int fim){

    int i, j, k;
    i = inicio;
    j = meio + 1;
    k = inicio;
    while(i <= meio && j <= fim){
        if(aux[i] < aux[j]){
            vetor[k] = aux[i];
            i++;
        }
        else{
            vetor[k] = aux[j];
            j++;
        }
        k++;
    }

    while(i <= meio){
        vetor[k] = aux[i];
        i++;
        k++;
    }

    while(j <= fim){
        vetor[k] = aux[j];
        j++;
        k++;
    }
    //Copia os elementos que foram ordenados para o auxiliar
    for(int p = inicio; p <= fim; p++){
        aux[p] = vetor [p];
    }
       
    
}

void algoritmos::RadixSort(float *vetor, int tamanhoVetor) {
    int i;
    int* b = new int[tamanhoVetor]; // Alocação dinâmica de memória para o array b
    int maior = vetor[0];
    int exp = 1;
    clock_t inicio = clock();
    for (i = 0; i < tamanhoVetor; i++) {
        if (vetor[i] > maior)
            maior = vetor[i];
    }

    while (maior / exp > 0) {
        int* bucket = new int[10](); // Alocação dinâmica de memória para o array bucket
        for (i = 0; i < tamanhoVetor; i++)
            bucket[(int(vetor[i]) / exp) % 10]++;
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (i = tamanhoVetor - 1; i >= 0; i--)
            b[--bucket[(int(vetor[i]) / exp) % 10]] = vetor[i];
        for (i = 0; i < tamanhoVetor; i++)
            vetor[i] = b[i];
        exp *= 10;
        delete[] bucket; // Liberação da memória alocada para bucket
    }
    clock_t fim = clock();
    mostrarIntervalo(inicio,fim,"RadixSort");
    delete[] b; // Liberação da memória alocada para b
}
