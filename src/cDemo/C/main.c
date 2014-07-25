//
//  main.c
//  C
//
//  Created by BW on 14-7-22.
//  Copyright (c) 2014年 bw. All rights reserved.
//

#include <stdio.h>

int *array(int index, int *h);

void shu(int index, int array[]);

typedef struct _array {
    
    int number;
    struct _array *add;
} myArray;

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    int i = 0;
//    int *j = &i;
//    array(5, j);
    int array[13];
    shu(11, array);
    return 0;
}

int *array(int index, int *h) {
    
    if (index == 1) {
        
        *h = 3;
        int newArray[3] = {0, 1, 0};
        int *addArr = newArray;
        return addArr;
    }
    else {
        
        int hen = 0;
        int *addHen = &hen;
        int *arr = array(index - 1, addHen);
        for (int i = 0; i < hen; i++) {
            
            printf("%5d ", arr[i]);
        }
        printf("\n");
        int newArray[hen + 1];
        newArray[0] = 0;
        for (int i = 1; i < hen; i ++) {
            
            newArray[i] = arr[i - 1] + arr[i];
        }
        newArray[hen] = 0;
        int *addArr = newArray;
        return addArr;
    }
}

void shu(int index, int array[index + 2]) {
    
    if (index == 1) {
        
        array[0] = 0;
        array[1] = 1;
        array[2] = 0;
        printf("%10d\n", 1);
    }
    else {
        
        int newArray[index + 1];
        shu(index - 1, newArray);
        
        array[0] = 0;
        array[index + 1] = 0;
        for (int i = 0; i < index; i++) {
            
            array[i + 1] = newArray[i] + newArray[i + 1];
            printf("%10d ", array[i + 1]);
        }
        printf("\n");
    }
}

