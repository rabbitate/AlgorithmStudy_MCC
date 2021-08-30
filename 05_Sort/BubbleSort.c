//
//  main.c
//  BubbleSort
//
//  Created by rabbi on 2021/08/30.
//

// Bubble Sort
// 시간 복잡도에 대한 빅오를 비교 횟수를 기준으로 결정한다
// 시간복잡도: O(n^2)
// Best Case: 이미 정렬이 되어있는 상태여서 데이터의 이동이 발생하지 않는 경우
// Worst Case: 정렬기준의 반대로 저장되어 있어 비교할 때마다 데이터의 이동이 발생하는 경우

#include <stdio.h>
#include <stdlib.h>

// parameter의 두 변수가 가리키는 곳의 data를 swap하는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort 함수
void BubbleSort(int* array, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < (size - 1 - i); j++) {
            if(array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int* array;
    int size;
    printf("배열의 크기를 입력하세요: ");
    scanf("%d", &size);
    array = (int*)malloc(sizeof(int) * size);
    
    printf("배열의 요소를 입력하세요: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("정렬 전: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    
    printf("\n");
    
    BubbleSort(array, size);
    
    printf("정렬 후: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
