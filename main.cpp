#include "algoritmos.h"

using namespace std;

float gerarNumeroAleatorio(float min, float max) {
    float numero = min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (max - min));

    // Arredondar para 1 casa decimal
    return floor(numero * 10.0f + 0.5f) / 10.0f;
}


int main(){
    srand(static_cast<unsigned>(time(0)));
    clock_t inicioTempoQuickSort,fimTempoQuickSort,inicioTempoMergeSort,fimTempoMergeSort;
    algoritmos *A = new algoritmos();
    int tamanho;

    cout << "Insira o tamanho do vetor: ";
    cin >> tamanho;

    A->setTamanho(tamanho);
    A->setVetorNaoOrdenada(A->gerarLista(A->getTamanho()));
   
    //BubbleSort
    A->BubbleSort(A->getVetorNaoOrdenada(),A->getTamanho());

    //InsertSort
    A->InsertSort(A->getVetorNaoOrdenada(),A->getTamanho());

    //SelectionSort
    A->SelectionSort(A->getVetorNaoOrdenada(),A->getTamanho());

    //QuickSort
    float* vetorQuickSort = A->copiarVetor(A->getVetorNaoOrdenada(),A->getTamanho());
    inicioTempoQuickSort = clock();
    A->QuickSort(vetorQuickSort,0,A->getTamanho());
    fimTempoQuickSort = clock();
    A->mostrarIntervalo(inicioTempoQuickSort,fimTempoQuickSort,"QuickSort");
    free(vetorQuickSort);

    //ShellSort
    A->ShellSort(A->getVetorNaoOrdenada(),A->getTamanho());

    //MergeSort
    float* vetorMergeSort = A->copiarVetor(A->getVetorNaoOrdenada(),A->getTamanho());
    float * aux = new float[A->getTamanho()];
    inicioTempoMergeSort = clock();
    A->MergeSort(vetorMergeSort,aux,0,A->getTamanho());
    fimTempoMergeSort = clock(); 
    A->mostrarIntervalo(inicioTempoMergeSort,fimTempoMergeSort,"MergeSort");
    free(vetorMergeSort);
    
    //RadixSort
    A->RadixSort(A->getVetorNaoOrdenada(),A->getTamanho());

    return 0;
}
