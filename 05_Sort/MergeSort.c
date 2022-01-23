//
//  main.c
//  MergeSort
//
//  Created by rabbi on 2022/01/22.
//

#include <stdio.h>

void Merge(int data[], int start, int mid, int end) {
    int s = start; int m = mid+1;
    int temp[end-start+1]; // 정렬한 데이터를 저장할 temp 배열
    int index = start;
    
    // 한 구역을 다 옮길 때까지 크기 순으로 temp 배열에 정렬
    while(s <= mid && m <= end) {
        temp[index++] = (data[s] >= data[m])? data[m++] : data[s++];
    }
    
    // 다 옮기지 못한 나머지도 옮겨준다
    while(s<=mid) temp[index++] = data[s++];
    while(m<=end) temp[index++] = data[m++];
    
    // temp 배열을 원본 배열에 복사한다
    for(int i = start; i <= end; i++) data[i] = temp[i];
}

void MergeSort(int data[], int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        MergeSort(data, start, mid);
        MergeSort(data, mid+1, end);
        Merge(data, start, mid, end);
    }
}

int main(int argc, const char * argv[]) {
    int data[100]; // data 배열
    int count = 0; // 원소 개수
    
    while(scanf("%d", &data[count++]) != EOF) {
    }
    
    count--;
    
    MergeSort(data, 0, count-1);
    
    for(int index = 0; index < count; index++) printf("%d ", data[index]);
    
    return 0;
}
