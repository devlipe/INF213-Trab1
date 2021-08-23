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
        return (int)dado1.getDateInt()== (int)dado2.getDateInt();
    }
};

class FunctorCompDadoTicker
{
public:
    template <class T, class T2>
    bool operator()(const T &dado1, const T2 &dado2) const
    {
        return !dado1.getTicker().compare(dado2.getTicker());
    }
};

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
    int buscaSequencial(T *vetor, T2 chaveBusca, int meio, T3 compDataIgual, T4 compTicker)
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

    template <typename T, typename T2, typename T3, typename T4>
    int buscaBinaria(T *vetor, T2 chaveBusca, int begin, int end, T3 compDataMenor, T4 compDataIgual)
    {
        int meio = (end - begin) / 2 + begin;

        if (begin > end)
        {
            return -1;
        }
        if (compDataIgual(chaveBusca, vetor[meio])) //Se encontrarmos uma data que seja satizfatoria, podemos fazer uma busca sequencial, ja que em um mesmo dia, nao se tem dados de dais de 500 acoes, logo no pior caso, temos complexidade O(500)
        {
            FunctorCompDadoTicker compTicker;
            return buscaSequencial(vetor, chaveBusca, meio, compDataIgual, compTicker);
        }
        if (compDataMenor(chaveBusca, vetor[meio]))
        {
            return buscaBinaria(vetor, chaveBusca, begin, meio - 1, compDataMenor, compDataIgual);
        }
        return buscaBinaria(vetor, chaveBusca, meio + 1, end, compDataMenor, compDataIgual);
    }

    ///Fucao para buscar um Dado por nome e por data dentro de um array, retorna -1 se o elemento n for encontrado
    template <typename T, typename T2>
    int buscaBinariaDado(T *vetor, T2 chaveBusca, unsigned int tamVetor)
    {
        FunctorCompDadoDataMenor compDataMenor;
        FunctorCompDadoDataIgual compDataIgual;
        return buscaBinaria(vetor, chaveBusca, 0, tamVetor, compDataMenor, compDataIgual);
    }
}