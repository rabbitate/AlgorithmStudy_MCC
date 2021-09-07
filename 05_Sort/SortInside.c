//
//  main.c
//  SortInside
//
//  Created by rabbi on 2021/09/04.
//

// 백준 No.1427
// 배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.
// 첫째 줄에 정렬하고자하는 수 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY 10 // N은 1,000,000,000보다 작거나 같은 자연수

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
            if(array[j] < array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

// 숫자를 분리해 배열 안에 넣는 함수
void DivideArray(int num, int* array, int* psize) {
    while(num != 0) {
        array[*psize] = num % 10;
        *psize += 1;
        DivideArray(num / 10, array, psize);
        return;
    }
}

int main(int argc, const char * argv[]) {
    int num;
    int size = 0; // 분리한 숫자의 개수
    int array[MAX_ARRAY];
    scanf("%d", &num);
    DivideArray(num, array, &size);
    BubbleSort(array, size);
    for(int i = 0; i < size; i++) {
        printf("%d", array[i]);
    }
    return 0;
}
