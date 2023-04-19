#include <iostream>
#include "Sort.hpp"

using namespace std;

void menu1()
{
    system("cls");
    cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n"; // Menu principal.
    cout << "▓                           ▓\n";
    cout << "▓    SORTING ALGORITHMS     ▓\n";
    cout << "▓                           ▓\n";
    cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n";
    cout << "\n1. Bubble Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Selection Sort\n";
    cout << "4. Shell Sort\n";
    cout << "5. Quick Sort\n";
    cout << "6. Merge Sort\n";
    cout << "0. Exit\n\n";
}

void menu2()
{
    system("cls");
    cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n"; // Menu principal.
    cout << "▓                           ▓\n";
    cout << "▓    SORTING ALGORITHMS     ▓\n";
    cout << "▓                           ▓\n";
    cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n";
    cout << "\n1. Random Dictionary (29855)\n";
    cout << "2. Random Dictionary (261791)\n";
    cout << "3. Inversed Dictionary (29855)\n";
    cout << "4. Inversed Dictionary (261791)\n";
    cout << "5. Ordered Dictionary (26855)\n";
    cout << "6. Ordered Dictionary (261791)\n";
    cout << "7. Random Numbers (1000)\n";
    cout << "8. Random Numbers (10000)\n";
    cout << "9. Random Numbers (100000)\n";
    cout << "10. Random Numbers (1000000)\n";
    cout << "11. Inverse Numbers (1000)\n";
    cout << "12. Inverse Numbers (10000)\n";
    cout << "13. Inverse Numbers (100000)\n";
    cout << "14. Inverse Numbers (1000000)\n";
    cout << "15. Ordered Numbers (1000)\n";
    cout << "16. Ordered Numbers (10000)\n";
    cout << "17. Ordered Numbers (100000)\n";
    cout << "18. Ordered Numbers (1000000)\n";
    cout << "19. Almost Ordered Numbers (1000)\n";
    cout << "20. Almost Ordered Numbers (10000)\n";
    cout << "21. Almost Ordered Numbers (100000)\n";
    cout << "22. Almost Ordered Numbers (1000000)\n";
    cout << "0. Exit.\n\n";
}

void BubbleSort(auto array[], uint64_t size, uint64_t &comp, uint64_t &move)
{
    uint64_t i, j, swap;
    auto aux = array[0];
    for (i = size - 1; i > 0; i--)
    {
        swap = 0;
        for (j = 0; j < i; j++)
        {
            comp = comp + 1;
            if (array[j] > array[j + 1])
            {
                move = move + 1;
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                swap = 1;
            }
        }
        if (swap == 0)
        {
            break;
        }
    }
}

void InsertionSort(auto array[], int size, uint64_t &comp, uint64_t &move)
{
    int j;
    auto aux = array[0];

    for (int i = 1; i < size; i++)
    {
        aux = array[i];
        j = i - 1;

        comp += 1;
        while (j >= 0 && array[j] > aux)
        {
            comp += 1;
            move += 1;

            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = aux;
    }
}

void SelectionSort(auto array[], int size, uint64_t &comp, uint64_t &move)
{
    int min;
    auto aux = array[0];

    for (int i = 0; i < size - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < size; j++)
        {
            comp += 1;

            if (array[j] < array[min])
            {
                min = j;
            }
        }
        move += 1;

        aux = array[i];
        array[i] = array[min];
        array[min] = aux;
    }
}

void ShellSort(auto array[], int size, uint64_t &comp, uint64_t &move)
{
    int i, j, h;
    auto aux = array[0];

    for (h = 1; h < size; h = 3 * h + 1)
        ;

    while (h > 1)
    {
        h = h / 3;

        for (i = h; i < size; i++)
        {
            aux = array[i];
            j = i;

            while (j >= h && array[j - h] > aux)
            {
                comp += 2;
                move += 1;

                array[j] = array[j - h];
                j = j - h;
            }
            array[j] = aux;
        }
    }
}

void QuickSort(auto array[], int left, int right, uint64_t &comp, uint64_t &move)
{
    auto aux = array[0];
    int i = left, j = right;
    auto pivot = array[(left + right) / 2];

    while (i <= j)
    {
        comp += 1;
        while (array[i] < pivot)
        {
            comp += 1;
            i++;
        }
        comp += 1;
        while (array[j] > pivot)
        {
            comp += 1;
            j--;
        }
        comp += 1;
        if (i <= j)
        {
            move += 1;
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }
    if (left < j)
    {
        QuickSort(array, left, j, comp, move);
    }
    if (i < right)
    {
        QuickSort(array, i, right, comp, move);
    }
}

void Merge(auto array[], int p, int q, int r, uint64_t &comp, uint64_t &move)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = new int[n1];
    int *M = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = array[p + i];
        move += 1;
    }
    for (int j = 0; j < n2; j++)
    {
        M[j] = array[q + 1 + j];
        move += 1;
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        comp += 1;
        if (L[i] <= M[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        move += 1;
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        move += 1;
        array[k] = M[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] M;
}

void MergeSort(auto array[], int l, int r, uint64_t &comp, uint64_t &move)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        MergeSort(array, l, m, comp, move);
        MergeSort(array, m + 1, r, comp, move);

        Merge(array, l, m, r, comp, move);
    }
}

void MergeS(auto array[], int p, int q, int r, uint64_t &comp, uint64_t &move)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    string *L = new string[n1];
    string *M = new string[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = array[p + i];
        move += 1;
    }
    for (int j = 0; j < n2; j++)
    {
        M[j] = array[q + 1 + j];
        move += 1;
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        comp += 1;
        if (L[i] <= M[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        move += 1;
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        move += 1;
        array[k] = M[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] M;
}

void MergeSortS(auto array[], int l, int r, uint64_t &comp, uint64_t &move)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        MergeSortS(array, l, m, comp, move);
        MergeSortS(array, m + 1, r, comp, move);

        MergeS(array, l, m, r, comp, move);
    }
}

