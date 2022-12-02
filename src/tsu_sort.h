#pragma once

template <class T>
void swap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
bool defSortCondition(T* a, int i, int j) {
    return(a[i] > a[j]);
}

/* can sort based on any condition 
just pass the condition function as a function pointer argument 
    bool conditionFunc(<type> * array, int i, int j){
        return(<insert condition for sort>)
    }
*/
template <class T>
void bubbleSort(T * a, int size, bool (*condition)(T*, int, int) = &defSortCondition<T>){
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (condition(a, i, j)) {
                swap(a[i], a[j]);
                //ArrayDump(a,size);
            }
        }
    }
}