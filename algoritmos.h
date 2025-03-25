#include "math.h"
#include <iostream>
#include <time.h>
#include "ctime"
#include "stdlib.h"
#include <iostream>
#include <iomanip>
class algoritmos{
    private:
		float * vetorNaoOrdenada;
		int tamanho;
    public:
        algoritmos(/* args */);
        ~algoritmos();

        //Metodos do Vetor 
        int getTamanho();
        void setTamanho(int tamanaho);
        float * getVetorNaoOrdenada();
        void setVetorNaoOrdenada(float* vetor);
        float gerarNumeroAleatorio(float min,float max);
        void impressao(float * listaOrganizada);
        float * gerarLista(int tamanhoLista);
        float* copiarVetor(float *vetor,int tamanhoVetor);

        //Metodos dos algoritmos
        void BubbleSort(float *vetor,int tamanhoVetor);
        void InsertSort(float *vetor,int tamanhoVetor);
        void SelectionSort(float *vetor,int tamanhoVetor);
        void QuickSort(float *vetor,int inicio,int fim);
        void ShellSort(float *vetor,int tamanhoVetor);
        void MergeSort(float *vetor,float * aux, int inicio,int fim);
        void merge(float* vetor, float * aux,int inicio,int meio,int fim);
        void RadixSort(float *vetor, int tamanhoVetor);
        void mostrarIntervalo(clock_t *inicioTempo,clock_t *fimTempo,char* algoritmo);
        void mostrarIntervalo(clock_t inicioTempo,clock_t fimTempo,char* algoritmo);
        

    private:
         
        //void particao(float *vetor,int baixo,int cima);
};
