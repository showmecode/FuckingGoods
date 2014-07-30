//
//  main.c
//  Sudoku
//
//  Created by BW on 14-7-28.
//  Copyright (c) 2014年 bw. All rights reserved.
//

#include <stdio.h>
#define NUMBER 9

static int sudoku[NUMBER][NUMBER];

/**
 *  当前坐标在x轴可以使用的数字
 *
 *  @param array 数字数组
 *  @param x     x轴
 *  @param y     y轴
 */
void numberWithX(int array[], int x, int y);

/**
 *  当前坐标在y轴可以使用的数字
 *
 *  @param array 数字数组
 *  @param x     x轴
 *  @param y     y轴
 */
void numberWithY(int array[], int x, int y);

/**
 *  当前坐标在当前九宫格可以使用的数字
 *
 *  @param array 数字数组
 *  @param x     x轴
 *  @param y     y轴
 */
void numberWithArray(int array[], int x, int y);

/**
 *  获取当前坐标所在的九宫格
 *
 *  @param array 九宫格数字数组
 *  @param x     x轴
 *  @param y     y轴
 */
void getArray(int array[], int x, int y);

/**
 *  获取2个数组的并集
 *
 *  @param array       第1个数组
 *  @param otherArray  第2个数组
 *  @param resultArray 并集数组
 */
void numberWithArrayAndOtherArray(int array[], int otherArray[], int resultArray[]);

/**
 *  获取3个数组的并集
 *
 *  @param array1      第1个数组
 *  @param array2      第2个数组
 *  @param array3      第3个数组
 *  @param resultArray 并集数组
 */
void numberWithThreeArray(int array1[], int array2[], int array3[], int resultArray[]);

/**
 *  获取可用数子在一个数组中
 *
 *  @param array      修改数组
 *  @param otherArray 参照数组
 */
void getNumber(int array[], int otherArray[]);

int main(int argc, const char * argv[])
{
    
    // insert code here...
    
}

void numberWithX(int array[NUMBER], int x, int y) {
    
    int newArray[NUMBER];
    for (int i = 0; i < NUMBER; i++) {
        
        newArray[i] = sudoku[x][i];
    }
    getNumber(array, newArray);
}

void numberWithY(int array[NUMBER], int x, int y) {
    
    int newArray[NUMBER];
    for (int i = 0; i < NUMBER; i++) {
        
        newArray[i] = sudoku[i][y];
    }
    getNumber(array, newArray);
}

void numberWithArray(int array[NUMBER], int x, int y) {
    
    int newArray[NUMBER];
    getArray(newArray, x, y);
    getNumber(array, newArray);
}

void numberWithArrayAndOtherArray(int array[NUMBER], int otherArray[NUMBER], int resultArray[NUMBER]) {
    
    for (int i = 0; i < NUMBER; i++) {
        
        resultArray[i] = 0;
    }
    for (int i = 0; i < NUMBER; i++) {
        
        if (array[i] > 0 && array[i] < NUMBER) {
            
            resultArray[array[i]] = array[i];
        }
        if (otherArray[i] > 0 && otherArray[i] < NUMBER) {
            
            resultArray[array[i]] = otherArray[i];
        }
    }
}

void numberWithThreeArray(int array1[NUMBER], int array2[NUMBER], int array3[NUMBER], int resultArray[NUMBER]) {
    
    
}

void getNumber(int array[], int otherArray[]) {
    
    for (int i = 0; i < NUMBER; i++) {
        
        array[i] = i + 1;
    }
    for (int i = 0; i < NUMBER; i++) {
        
        if (otherArray[i] > 0) {
            
            array[otherArray[i]] = 0;
        }
    }
}

void getArray(int array[], int x, int y) {
    
    x = x <= 3 ? 0 :(x <= 6 ? 6 : 9);
    y = y <= 3 ? 0 :(y <= 6 ? 6 : 9);
    for (int i = x; i < 3; i++) {
        for (int j = y; j < 3; j++) {
            
            array[i * 3 + j] = sudoku[i][j];
        }
    }
}
