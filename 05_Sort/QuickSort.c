//
//  main.c
//  QuickSort
//
//  Created by rabbi on 2022/02/04.
//

#include <stdio.h>
#include <stdlib.h>

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort(int* array, int start, int end) {
    if(start>=end) return;
    
    int pivot = start;
    
    int l = start+1;
    int r = end;
    
    while(l<=r) {
        while(l <= end && array[l] <= array[pivot]) {
            l++;
        }
        while(r >= start+1 && array[r] >= array[pivot]) {
            r--;
        }
        
        if(l < r) {
            Swap(&array[l], &array[r]);
        } else {
            Swap(&array[pivot], &array[r]);
        }
    }
    
    QuickSort(array, start, r-1);
    QuickSort(array, r+1, end);
}

int main(int argc, const char * argv[]) {
    int index = 0;
    int array[100];
    
    while(scanf("%d", &array[index++]) != EOF) {
    }
    
    index--;
    
    QuickSort(array, 0, index-1);
    
    for(int i = 0; i < index; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}
