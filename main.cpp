#include "algoritmos.h"

using namespace std;

float gerarNumeroAleatorio(float min, float max) {
    float numero = min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (max - min));

    // Arredondar para 1 casa decimal
    return std::floor(numero * 10.0f + 0.5f) / 10.0f;
}


int main(){
    srand(static_cast<unsigned>(time(0)));

    bool imprimirOrdenado;
    char escolha;
    int tamanhoVetor;
    clock_t inicioTempoQuickSort,fimTempoQuickSort,inicioTempoMergeSort,fimTempoMergeSort;

    cout << "Insira o tamanho do vetor desejado: ";
    cin >> tamanhoVetor;
    cout << "Quer imprimir o vetor ordenado apos cada execucao de algoritmo(Y/N): ";
    cin >> escolha;

    if(escolha == 'Y' || escolha == 'y'){
        imprimirOrdenado = true;
    }else if(escolha == 'N' || escolha == 'n'){
        imprimirOrdenado = false;
    }

    float * vetor = new float[tamanhoVetor];
    float * aux = new float[tamanhoVetor];
    for (int i = 0; i < tamanhoVetor; i++)
    {
        vetor[i] = gerarNumeroAleatorio(0.0f,1000.0f);
    }
   
    algoritmos *A = new algoritmos();
    A->BubbleSort(vetor,tamanhoVetor,imprimirOrdenado);
    A->InsertSort(vetor,tamanhoVetor,imprimirOrdenado);
    A->SelectionSort(vetor,tamanhoVetor,imprimirOrdenado);

    float* vetorQuickSort = A->copiarVetor(vetor,tamanhoVetor);
    inicioTempoQuickSort = clock();
    A->QuickSort(vetorQuickSort,0,tamanhoVetor);
    fimTempoQuickSort = clock();
    A->mostrarIntervalo(inicioTempoQuickSort,fimTempoQuickSort,"QuickSort");
    free(vetorQuickSort);

    A->ShellSort(vetor,tamanhoVetor,imprimirOrdenado);

    float* vetorMergeSort = A->copiarVetor(vetor,tamanhoVetor);
    inicioTempoMergeSort = clock();
    A->MergeSort(vetorMergeSort,aux,0,tamanhoVetor);
    fimTempoMergeSort = clock(); 
    A->mostrarIntervalo(inicioTempoMergeSort,fimTempoMergeSort,"MergeSort");
    free(vetorMergeSort);
    
    A->RadixSort(vetor,tamanhoVetor,imprimirOrdenado);

    return 0;
}