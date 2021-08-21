///Somente utilize esse name space para ordenar objetos do tipo dado
namespace ordenacao
{
    template <typename T>
    void swap(T &dado1, T &dado2)
    {
        T temp = dado1;
        dado1 = dado2;
        dado2 = temp;
    }

    template <typename T>
    void insertionSort(T *vetor, int beg, int end)
    {
        for (int i = beg + 1; i < end; i++)
        {
            T elemInserir = vetor[i];
            int j = i - 1;
            while (j >= beg && vetor[j].getDateInt() > elemInserir.getDateInt())
            {
                vetor[j + 1] = vetor[j];
                j--;
            }
            vetor[j + 1] = elemInserir;
        }
    }

    template <typename T>
    int particiona(T *vetor, int beg, int end, int pivo)
    {
        //Pegamos um elemento para ser o pivo da divisao
        T Pivo = vetor[pivo];
        //Posicionamos o pivo no final do vetor 
        swap(vetor[pivo], vetor[end - 1]);

        int pos = beg;
        for (int i = beg; i < end - 1; i++)
        {
            ///Ordenamos o vetor a partir da data e em ordem crescente
            if (vetor[i].getDateInt() < Pivo.getDateInt())
            {
                swap(vetor[pos], vetor[i]);
                pos++;
            }
        }
        swap(vetor[pos], vetor[end - 1]);
        return pos;
    }

    template <typename T>
    void quickSort2(T *vetor, int beg, int end)
    {
        ///Chamamos a funcao particiona para ordenar o vetor a partir de um pivo (metade do subarray)
        int pos = particiona(vetor, beg, end, (end - beg)/2 + beg);

        //Caso o subarray seja menor que 30 elementos, chamamos o insertion sort para agilizar o processo
        if (30 > (end - beg))
        {
            insertionSort(vetor, beg, end);
        }
        else
        {
            //Chamando o quick sort recursivamente para ordenar o restante o array 
            //Nessa parte ele e dividido ao meio para ordenar
            quickSort2(vetor, beg, pos);
            quickSort2(vetor, pos + 1, end);
        }
    }

    template <typename T>
    void quickSort(T *vetor, int n)
    {
        quickSort2(vetor, 0, n);
    }


}