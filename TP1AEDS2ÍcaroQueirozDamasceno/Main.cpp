#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <time.h>
#include "Sort.hpp"
#include "Sort.cpp"

using namespace std;

void Print(int *array, uint64_t n)
{
    for (uint64_t i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}

void PrintS(string *array, uint64_t n)
{
    for (uint64_t i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}

void load_fileN(int array[], string name, uint64_t size)
{
    ifstream fin;
    fin.open(name);
    if (!fin.fail())
    {

        for (uint64_t i = 0; i < size; i++)
        {
            fin >> array[i];
        }
    }
    else
    {
        cerr << "File was unable to open!";
    }
    fin.close();
}

void load_fileS(string array[], string name, uint64_t size)
{
    ifstream fin;
    fin.open(name);
    if (!fin.fail())
    {

        for (uint64_t i = 0; i < size; i++)
        {
            fin >> array[i];
        }
    }
    else
    {
        cerr << "File was unable to open!";
    }
    fin.close();
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int choice1, choice2;
    uint64_t move = 0, comp = 0;
    do
    {
        menu1();
        cout << "Choose an option:\n";
        cin >> choice1;
    } while (choice1 == 0 && choice1 > 7);
    do
    {
        system("cls");
        menu2();
        cout << "Choose an option:\n";
        cin >> choice2;
    } while (choice2 == 0 && choice2 > 23);

    string name;
    uint64_t size;
    switch (choice2)
    {
    case 1:
        name = "../DicionarioAleatorio-29855.txt";
        size = 29855;
        break;
    case 2:
        name = "../DicionarioAleatorio-261791.txt";
        size = 261791;
        break;
    case 3:
        name = "../DicionarioInversamenteOrdenado-29855.txt";
        size = 29855;
        break;
    case 4:
        name = "../DicionarioInversamenteOrdenado-261791.txt";
        size = 261791;
        break;
    case 5:
        name = "../DicionarioOrdenado-29855.txt";
        size = 29855;
        break;
    case 6:
        name = "../DicionarioOrdenado-261791.txt";
        size = 261791;
        break;
    case 7:
        name = "../ListaAleatoria-1000.txt";
        size = 1000;
        break;
    case 8:
        name = "../ListaAleatoria-10000.txt";
        size = 10000;
        break;
    case 9:
        name = "../ListaAleatoria-100000.txt";
        size = 100000;
        break;
    case 10:
        name = "../ListaAleatoria-1000000.txt";
        size = 1000000;
        break;
    case 11:
        name = "../ListaInversamenteOrdenada-1000.txt";
        size = 1000;
        break;
    case 12:
        name = "../ListaInversamenteOrdenada-10000.txt";
        size = 10000;
        break;
    case 13:
        name = "../ListaInversamenteOrdenada-100000.txt";
        size = 100000;
        break;
    case 14:
        name = "../ListaInversamenteOrdenada-1000000.txt";
        size = 1000000;
        break;
    case 15:
        name = "../ListaOrdenada-1000.txt";
        size = 1000;
        break;
    case 16:
        name = "../ListaOrdenada-10000.txt";
        size = 10000;
        break;
    case 17:
        name = "../ListaOrdenada-100000.txt";
        size = 100000;
        break;
    case 18:
        name = "../ListaOrdenada-1000000.txt";
        size = 1000000;
        break;
    case 19:
        name = "../ListaQuaseOrdenada-1000.txt";
        size = 1000;
        break;
    case 20:
        name = "../ListaQuaseOrdenada-10000.txt";
        size = 10000;
        break;
    case 21:
        name = "../ListaQuaseOrdenada-100000.txt";
        size = 100000;
        break;
    case 22:
        name = "../ListaQuaseOrdenada-1000000.txt";
        size = 1000000;
        break;
    }

    int *array = new int[size];
    load_fileN(array, name, size);
    string *arrayS = new string[size];
    load_fileS(arrayS, name, size);
    clock_t startTime;
    clock_t endTime;
    ofstream fout;
    fout.open("../Order.txt", fstream::app);
    if (choice2 >= 7 && choice2 < 23)
    {
        switch (choice1)
        {
        case 1:
            startTime = clock();
            BubbleSort(array, size, comp, move);
            endTime = clock();
            Print(array, size);
            if (!fout.fail())
            {
                fout << "Bubble Sort - " << name << ":" << endl;
            }
            else
            {
                cerr << "Unable to open file.";
            }

            break;
        case 2:
            startTime = clock();
            InsertionSort(array, size, comp, move);
            endTime = clock();
            Print(array, size);
            if (!fout.fail())
            {
                fout << "Insertion Sort - " << name << ":" << endl;
            }
            else
            {
                cerr << "Unable to open file.";
            }
            break;
        case 3:
            startTime = clock();
            SelectionSort(array, size, comp, move);
            endTime = clock();
            Print(array, size);
            if (!fout.fail())
            {
                fout << "Selection Sort - " << name << ":" << endl;
            }
            else
            {
                cerr << "Unable to open file.";
            }
            break;
        case 4:
            startTime = clock();
            ShellSort(array, size, comp, move);
            endTime = clock();
            Print(array, size);
            if (!fout.fail())
            {
                fout << "Shell Sort - " << name << ":" << endl;
            }
            else
            {
                cerr << "Unable to open file.";
            }
            break;
        case 5:
            startTime = clock();
            QuickSort(array, 0, size - 1, comp, move);
            endTime = clock();
            Print(array, size);
            if (!fout.fail())
            {
                fout << "Quick Sort - " << name << ":" << endl;
            }
            else
            {
                cerr << "Unable to open file.";
            }
            break;
        case 6:
            startTime = clock();
            MergeSort(array, 0, size - 1, comp, move);
            endTime = clock();
            Print(array, size);
            if (!fout.fail())
            {
                fout << "Merge Sort - " << name << ":" << endl;
            }
            else
            {
                cerr << "Unable to open file.";
            }
            break;
        };
    }
    else
    {
        switch (choice1)
        {
        case 1:
            startTime = clock();
            BubbleSort(arrayS, size, comp, move);
            endTime = clock();
            PrintS(arrayS, size);
            if (!fout.fail())
            {
                fout << "Bubble Sort - " << name << ":" << endl;
            }
            else
            {
                cerr << "Unable to open file.";
            }
            break;
        case 2:
            startTime = clock();
            InsertionSort(arrayS, size, comp, move);
            endTime = clock();
            PrintS(arrayS, size);
            if (!fout.fail())
            {
                fout << "Insertion Sort - " << name << ":" << endl;
            }
            else
            {
                cerr << "Unable to open file.";
            }
            break;
        case 3:
            startTime = clock();
            SelectionSort(arrayS, size, comp, move);
            endTime = clock();
            PrintS(arrayS, size);
            if (!fout.fail())
            {
                fout << "Selection Sort - " << name << ":" << endl;
            }
            else
            {
                cerr << "Unable to open file.";
            }
            break;
        case 4:
            startTime = clock();
            ShellSort(arrayS, size, comp, move);
            endTime = clock();
            PrintS(arrayS, size);
            if (!fout.fail())
            {
                fout << "Shell Sort - " << name << ":" << endl;
            }
            else
            {
                cerr << "Unable to open file.";
            }
            break;
        case 5:
            startTime = clock();
            QuickSort(arrayS, 0, size - 1, comp, move);
            endTime = clock();
            PrintS(arrayS, size);
            if (!fout.fail())
            {
                fout << "Quick Sort - " << name << ":" << endl;
            }
            else
            {
                cerr << "Unable to open file.";
            }
            break;
        case 6:
            startTime = clock();
            MergeSortS(arrayS, 0, size - 1, comp, move);
            endTime = clock();
            PrintS(arrayS, size);
            if (!fout.fail())
            {
                fout << "Merge Sort - " << name << ":" << endl;
            }
            else
            {
                cerr << "Unable to open file.";
            }
            break;
        };
        ;
    }

    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;
    cout << "\n\nTime to order the array: " << timeInSeconds << "\n";
    cout << "Comparisons to order the array: " << comp << "\n";
    cout << "Movements to order the array: " << move << "\n";
    if (!fout.fail())
    {
        fout << "\n\nTime to order the array: " << timeInSeconds << "\n";
        fout << "Comparisons to order the array: " << comp << "\n";
        fout << "Movements to order the array: " << move << "\n";
        fout << "-----------------------------------------------------\n";
    }
    else
    {
        cerr << "Unable to open file.";
    }
    
    fout.close();

    system("pause");

    delete array;
    delete arrayS;

    cout << endl;
    return 0;
}