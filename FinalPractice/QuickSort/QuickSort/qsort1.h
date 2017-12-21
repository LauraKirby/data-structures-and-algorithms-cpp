//
//  qsort1.h
//  QuickSort
//
//  Created by Laura Kirby on 12/21/17.
//  Copyright © 2017 LK. All rights reserved.
//

#ifndef qsort1_h
#define qsort1_h
// Simple findpivot: Pick middle value in array
template <typename E>
inline int findpivot(E A[], int i, int j)
{ return (i+j)/2; }

// Partition the array
template <typename E, typename Comp>
inline int partition(E A[], int l, int r, E& pivot) {
    do {             // Move the bounds inward until they meet
        while (Comp::prior(A[++l], pivot));  // Move l right and
        while ((l < r) && Comp::prior(pivot, A[--r])); // r left
        swap(A, l, r);              // Swap out-of-place values
    } while (l < r);              // Stop when they cross
    return l;      // Return first position in right partition
}

// qsort core function: Basic qsort
template <typename E, typename Comp>
void qsort(E A[], int i, int j) { // Quicksort
    if (j <= i) return; // Don't sort 0 or 1 element
    int pivotindex = findpivot(A, i, j);
    swap(A, pivotindex, j);    // Put pivot at end
    // k will be the first position in the right subarray
    int k = partition<E,Comp>(A, i-1, j, A[j]);
    swap(A, k, j);             // Put pivot in place
    qsort<E,Comp>(A, i, k-1);
    qsort<E,Comp>(A, k+1, j);
}

template <typename E, typename Comp>
void sort(E* array, int n) {
    qsort<E,Comp>(array, 0, n-1);
}


#endif /* qsort1_h */
