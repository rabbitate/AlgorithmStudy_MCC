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
    if(start>=end) return; // 등호를 통해 리스트 크기가 1인 경우를 걸러준다
    
    int pivot = start;
    
    int l = start+1;
    int r = end;
    
    // l과 r이 엇갈릴 때까지
    while(l<=r) {
        // 2개의 while문 중 pivot과의 비교에서의 등호가 1개 이상 필요
        // -> 등호가 2개 다 없다면, pivot 과 l,r 번째 인덱스의 값이 다 같을때 l,r 값 변화가 없다
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
