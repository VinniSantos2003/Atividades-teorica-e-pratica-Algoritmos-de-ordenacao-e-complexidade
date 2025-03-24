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
    clock_t *inicioTempoQuickSort,*fimTempoQuickSort,*inicioTempoMergeSort,*fimTempoMergeSort;

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

    A->QuickSort(vetor,0,tamanhoVetor,inicioTempoQuickSort,fimTempoQuickSort);
    A->mostrarIntervalo(inicioTempoQuickSort,fimTempoQuickSort,"QuickSort");
    /*
    A contagem de tempo do quicksort foi feito de maneira diferente pois é uma função recursiva, 
    então haveria muitas instancias de contagem de inicio e fim, escolhi criar um ponteiro que pode ser acessado por todas as funções
    que serão abertas
    */
    A->ShellSort(vetor,tamanhoVetor);
    A->MergeSort(vetor,aux,0,tamanhoVetor,inicioTempoMergeSort,fimTempoMergeSort); 
    A->mostrarIntervalo(inicioTempoMergeSort,fimTempoMergeSort,"MergeSort");

    return 0;
}