#ifndef SORT_H
#define SORT_H

#include <iostream>

void menu1();
void menu2();
void BubbleSort(auto array[], uint64_t size, uint64_t &comp, uint64_t &move);
void InsertionSort(auto array[], int size, uint64_t &comp, uint64_t &move);
void SelectionSort(auto array[], int size, uint64_t &comp, uint64_t &move);
void ShellSort(auto array[], int size, uint64_t &comp, uint64_t &move);
void QuickSort(auto array[], int left, int right, uint64_t &comp, uint64_t &move);
void Merge(auto array[], int p, int q, int r, uint64_t &comp, uint64_t &move);
void MergeSort(auto array[], int l, int r, uint64_t &comp, uint64_t &move);
void MergeS(auto array[], int p, int q, int r, uint64_t &comp, uint64_t &move);
void MergeSortS(auto array[], int l, int r, uint64_t &comp, uint64_t &move);

#endif