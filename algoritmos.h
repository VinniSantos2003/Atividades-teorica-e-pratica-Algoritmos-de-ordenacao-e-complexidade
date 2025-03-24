#include "math.h"
#include <iostream>
#include <time.h>
#include "ctime"
#include "stdlib.h"
#include <iostream>
#include <iomanip>
class algoritmos{
    private:

    public:
        algoritmos(/* args */);
        ~algoritmos();
        void BubbleSort(float *vetor,int tamanhoVetor ,bool saidaOrdenada);
        void InsertSort(float *vetor,int tamanhoVetor,bool saidaOrdenada);
        void SelectionSort(float *vetor,int tamanhoVetor,bool saidaOrdenada);
        void QuickSort(float *vetor,int inicio,int fim);
        void ShellSort(float *vetor,int tamanhoVetor,bool saidaOrdenada);
        void MergeSort(float *vetor,float * aux, int inicio,int fim);
        void merge(float* vetor, float * aux,int inicio,int meio,int fim);
        void RadixSort(float *vetor, int tamanhoVetor,bool saidaOrdenada);
        void mostrarIntervalo(clock_t *inicioTempo,clock_t *fimTempo,char* algoritmo);
        void mostrarIntervalo(clock_t inicioTempo,clock_t fimTempo,char* algoritmo);
        float* copiarVetor(float *vetor,int tamanhoVetor);

    private:
         
        //void particao(float *vetor,int baixo,int cima);
};