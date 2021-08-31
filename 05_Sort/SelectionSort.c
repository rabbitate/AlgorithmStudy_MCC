//
//  main.c
//  SelectionSort
//
//  Created by rabbi on 2021/08/30.
//

// Selection Sort
// 정렬 순서상 앞서는 것을 가장 왼쪽으로 이동시키고, 빈 자리에 원래 데이터를 넣는다
// 비교 횟수: n-1 + n-2 + n-3 + ... + 2 + 1
// 시간 복잡도: O(n^2)
// Bubble Sort는 Best Case에서 한 번도 swap하지 않는다는 장점이,
// Selection Sort는 swap이 바깥쪽 for문에 위치에 swap 횟수가 n-1이여서 Worst Case에서의 장점이 있다

#include <stdio.h>
#include <stdlib.h>

// parameter의 두 변수가 가리키는 곳의 data를 swap하는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int* array, int size) {
    for(int i = 0; i < size; i++) {
        int minIdx = i; // 배열의 i번째 index를 최솟값을 가진 index로 지정
        for(int j = i + 1; j < size; j++) {
            if(array[minIdx] > array[j]) { // 최솟값보다 더 작은 값이 있다면
                minIdx = j; // 최솟값을 가진 index로 지정한다
            }
        }
        swap(&array[i], &array[minIdx]); // 배열의 i번째 요소와 배열의 나머지 요소 중 최솟값을 가진 요소와 swap
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
    
    SelectionSort(array, size);
    
    printf("정렬 후: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}
