#pragma once

/*
    Sorting can be done based on any condition. Just add a sortCondition function as
    bool conditionFunc(<type> * array, int i, int j){
        return(array[i] < array[j]); // for ascending
    }
    where i and j are comparison indexes and i<j
    and pass its address as a function pointer argument.
    Sortcondition functions should return the condition that the array should be sorted in 
    for eg: for ascending order the condition would be
        arr[i] < arr[j]
*/


template <class T>
void swap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
bool defSortCondition(T* a, int i, int j) {
    return(a[i] < a[j]);
}

template <class T>
void bubbleSort(T * a, int size, bool (*condition)(T*, int, int) = &defSortCondition<T>){
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (!condition(a, i, j)) {
                swap(a[i], a[j]);
            }
        }
    }
}

template <class T>
void insertionSort(T * a, int size, bool (*condition)(T*,int,int) = &defSortCondition){
    for (int i = 0; i<size -1; i++){
        if (!condition(a, i, i+1)){
            swap(a[i], a[i+1]);
            for (int j = i; j>0; j--){
                if (!condition(a,j-1,j)){
                    swap(a[j], a[j-1]);
                }
            }
        }
    }
}