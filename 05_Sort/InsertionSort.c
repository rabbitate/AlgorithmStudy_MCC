//
//  main.c
//  InsertionSort
//
//  Created by rabbi on 2021/08/30.
//

// Insertion Sort
// 정렬 안된 부분을 정렬 된 부분의 알맞는 특정 위치에 삽입해가며 정렬
// 시간복잡도: O(n^2)
// Best Case: 이미 다 정렬 되어 있어 안쪽 for문의 if 문이 거짓이 되어 break문이 실행되고 바깥 for문의 반복 횟수만큼만 진행된다
// Worst Case: 바깥 for문의 반복 횟수 * 안쪽 for문의 반복 횟수

#include <stdio.h>
#include <stdlib.h>

// parameter의 두 변수가 가리키는 곳의 data를 swap하는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InsertionSort(int* array, int size) {
    int i,j;
    for(i = 1; i < size; i++) {
        int data = array[i]; // 배열의 i번째 요소를 정렬 대상으로 지정
        for(j = i-1; j >= 0; j--) {
            if(array[j] > data) {
                array[j+1] = array[j];
            } else {
                break; // 삽입 위치를 찾았다면 break
            }
        }
        array[j+1] = data;
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
    
    InsertionSort(array, size);
    
    printf("정렬 후: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}
