#include "Evento.h"

/// Functor utilizado para comparar objetos do tipo Dado de acordo com a data de cada um
class FunctorCompDadoDataMenor
{
public:
    template <class T, class T2>
    bool operator()(const T &dado1, const T2 &dado2) const
    {
        return dado1.getDateInt() < dado2.getDateInt();
    }
};

class FunctorCompDadoDataMenorOuIgual
{
public:
    template <class T, class T2>
    bool operator()(const T &dado1, const T2 &dado2) const
    {
        return dado1.getDateInt() <= dado2.getDateInt();
    }
};

class FunctorCompDadoDataMaior
{
public:
    template <class T, class T2>
    bool operator()(const T &dado1, const T2 &dado2) const
    {
        return dado1.getDateInt() > dado2.getDateInt();
    }
};

class FunctorCompDadoDataIgual
{
public:
    template <class T, class T2>
    bool operator()(const T &dado1, const T2 &dado2) const
    {
        return dado1.getDateInt() == dado2.getDateInt();
    }
};

class FunctorCompDadoTickerIgual
{
public:
    template <class T, class T2>
    bool operator()(const T &dado1, const T2 &dado2) const
    {
        return (dado1.getTicker() == dado2.getTicker());
    }
};

//Functor para comparar os tipos de evento do menor para o maior (Dividendo, Split, Operacao, Impressao) nessa Ordem
class FunctorCompEventoTipoMenor
{
public:
    bool operator()(const Evento &dado1, const Evento &dado2) const
    {
        return dado1.getTipoEvento() <= dado2.getTipoEvento();
    }
};

///Funcao auxiliar para o merge sort
namespace algoritmos
{
    ///!+++++++++++++++++++++++++++++++++++++++++++++++++++ QUICK SORT +++++++++++++++++++++++++++++++++++++++++++

    template <typename T>
    void swap(T &dado1, T &dado2)
    {
        //Funcao swap implementada para permitir a troca de posicoes dento do quick sort
        T temp = dado1;
        dado1 = dado2;
        dado2 = temp;
    }

    template <typename T, typename T2>
    void insertionSort(T *vetor, int beg, int end, T2 comparaDataMenor)
    {
        for (int i = beg + 1; i < end; i++)
        {
            T elemInserir = vetor[i];
            int j = i - 1;
            while (j >= beg && !comparaDataMenor(vetor[j], elemInserir)) // O isertion sort funcinoa comparadando se o vetor[j] > elemInserir, logo o !
            {
                vetor[j + 1] = vetor[j];
                j--;
            }
            vetor[j + 1] = elemInserir;
        }
    }

    template <typename T, typename T2>
    int particiona(T *vetor, int beg, int end, int pivo, T2 comparaDataMenor)
    {
        //Pegamos um elemento para ser o pivo da divisao
        T elemPivo = vetor[pivo];
        //Posicionamos o pivo no final do vetor
        swap(vetor[pivo], vetor[end - 1]);

        int pos = beg;
        for (int i = beg; i < end - 1; i++)
        {
            ///Ordenamos o vetor a partir da data e em ordem crescente
            if (comparaDataMenor(vetor[i], elemPivo))
            {
                swap(vetor[pos], vetor[i]);
                pos++;
            }
        }
        swap(vetor[pos], vetor[end - 1]);
        return pos;
    }

    template <typename T, typename T2>
    void quickSort(T *vetor, int beg, int end, T2 comparaDataMenor)
    {
        if (beg == end)
        {
            return;
        }
        srand(time(NULL));
        int piv = (rand() % (end - beg)) + beg;
        ///Chamamos a funcao particiona para ordenar o vetor a partir de um pivo (metade do subarray)
        int pos = particiona(vetor, beg, end, piv, comparaDataMenor);

        //Caso o subarray seja menor que 30 elementos, chamamos o insertion sort para agilizar o processo
        if (30 > (end - beg))
        {
            insertionSort(vetor, beg, end, comparaDataMenor);
        }
        else
        {
            //Chamando o quick sort recursivamente para ordenar o restante o array
            //Nessa parte ele e dividido ao meio para ordenar
            quickSort(vetor, beg, pos, comparaDataMenor);
            quickSort(vetor, pos + 1, end, comparaDataMenor);
        }
    }

    template <typename T>
    void quickSortDadoDataCres(T *vetor, int size)
    {
        FunctorCompDadoDataMenor compDataMenor;
        quickSort(vetor, 0, size, compDataMenor);
    }

    ///!+++++++++++++++++++++++++++++++++++++++++++++++++++ BUSCA BINARIA +++++++++++++++++++++++++++++++++++++++++++

    template <typename T, typename T2, typename T3, typename T4>
    int buscaSequencial(const T *vetor, const T2 &chaveBusca, const int &meio, const T3 &compDataIgual, const T4 &compTicker)
    {
        //Procuramos no subarray comecando do ponto em que a busca binaria encontrou um data que seja correta
        //Depois pesquisamos para tras desse ponto ate que a data fique menor, ou encontre o ticker que estamos precisando
        for (int i = meio; compDataIgual(chaveBusca, vetor[i]); i--)
        {
            if (compTicker(chaveBusca, vetor[i]))
            {
                return i;
            }
        }
        //Caso o ticker nao seja encontrado para tras, pesquisamos para frente
        //Esse tipo de implementacao tem uma falha, sendo que caso o ticker procurado n esteja no vetor, ele acessara memoria indevida
        //Entretanto, estamos assumindo que todas as consultas sao validas, por isso nao precisamos de fazer esse tipo de verificacao
        for (int i = meio; compDataIgual(chaveBusca, vetor[i]); i++)
        {
            if (compTicker(chaveBusca, vetor[i]))
            {
                return i;
            }
        }
        return -1;
    }

    ///Busca binaria por data 
    template <typename T, typename T2, typename T3, typename T4>
    int buscaBinaria(const T *vetor, const T2 &chaveBusca, const int &begin, const int &end, const T3 &compMenor, const T4 &compIgual)
    {
        int meio = (end - begin) / 2 + begin;

        if (begin > end)
        {
            return -1;
        }
        if (compIgual(chaveBusca, vetor[meio])) //Se encontrarmos uma data que seja satizfatoria, podemos fazer uma busca sequencial, ja que em um mesmo dia, nao se tem dados de dais de 500 acoes, logo no pior caso, temos complexidade O(500)
        {
            return meio;
        }
        if (compMenor(chaveBusca, vetor[meio]))
        {
            return buscaBinaria(vetor, chaveBusca, begin, meio - 1, compMenor, compIgual);
        }
        return buscaBinaria(vetor, chaveBusca, meio + 1, end, compMenor, compIgual);
    }

    ///Fucao para buscar um Dado por nome e por data dentro de um array, retorna -1 se o elemento n for encontrado
    template <typename T, typename T2>
    int buscaBinariaDadoDataNome(const T *vetor, const T2 &chaveBusca, const unsigned int &tamVetor)
    {
        FunctorCompDadoDataMenor compDataMenor;
        FunctorCompDadoDataIgual compDataIgual;
        int result = buscaBinaria(vetor, chaveBusca, 0, tamVetor, compDataMenor, compDataIgual);
        FunctorCompDadoTickerIgual compTicker;
        return buscaSequencial(vetor, chaveBusca, result, compDataIgual, compTicker);
    }

    ///!+++++++++++++++++++++++++++++++++++++++++++++++++++ MERGE SORT +++++++++++++++++++++++++++++++++++++++++++

    template <typename T, typename T2>
    void merge(T *vetor, const int &begin, const int &meio, const int &end, T *aux, T2 &comparador)
    {
        int tam = end - begin;
        int i = begin; //cursor 1
        int j = meio;  //cursor 2
        int k = 0;     //cursor para aux
        while (i < meio && j < end)
        {
            if (comparador(vetor[i], vetor[j]))
            {
                aux[k++] = vetor[i++];
            }
            else
            {
                aux[k++] = vetor[j++];
            }
        }
        while (i < meio)
        {
            aux[k++] = vetor[i++];
        }
        while (j < end)
        {
            aux[k++] = vetor[j++];
        }
        for (k = 0; k < tam; k++)
        {
            vetor[begin + k] = aux[k];
        }
    }

    template <typename T, typename T2>
    void mergeSort(T *vetor, const int &end, T *aux, T2 &comparador)
    {
        // com um elemento, já está ordenado
        for (int TamanhoBloco = 1; TamanhoBloco < end; TamanhoBloco *= 2)
        {
            for (int begin = 0; begin < end; begin += 2 * TamanhoBloco)
            {
                int meio = (begin + TamanhoBloco < end) ? begin + TamanhoBloco : end;
                int finalBloco = (begin + 2 * TamanhoBloco < end) ? begin + 2 * TamanhoBloco : end;
                merge(vetor, begin, meio, finalBloco, aux, comparador); //intercala
            }
        }
    }

    template <typename T>
    void mergeSortEventoTipo(T *vetor, int size)
    {
        FunctorCompEventoTipoMenor compEventoMenor;
        T *aux = new T[size];
        mergeSort(vetor, size, aux, compEventoMenor);
        delete[] aux;
    }

    template <typename T>
    void mergeSortDadoDataCres(T *vetor, int size)
    {
        FunctorCompDadoDataMenorOuIgual comDataMenorIgual;
        T *aux = new T[size];
        mergeSort(vetor, size, aux, comDataMenorIgual);
        delete[] aux;
    }
}