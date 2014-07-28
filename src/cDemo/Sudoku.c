//
//  main.c
//  Sudoku
//
//  Created by BW on 14-7-28.
//  Copyright (c) 2014年 bw. All rights reserved.
//

#include <stdio.h>
#define NUMBER 9

static int sudoku[81];

/**
 *  当前坐标在x轴可以使用的数字
 *
 *  @param array 数字数组
 *  @param x     x轴
 *  @param y     y轴
 */
void numberWithX(int array[9], int x, int y);

/**
 *  当前坐标在y轴可以使用的数字
 *
 *  @param array 数字数组
 *  @param x     x轴
 *  @param y     y轴
 */
void numberWithY(int array[9], int x, int y);

/**
 *  当前坐标在当前九宫格可以使用的数字
 *
 *  @param array 数字数组
 *  @param x     x轴
 *  @param y     y轴
 */
void numberWithArray(int array[9], int x, int y);

/**
 *  获取当前坐标所在的九宫格
 *
 *  @param array 九宫格数字数组
 *  @param x     x轴
 *  @param y     y轴
 */
void getArray(int array[9], int x, int y);

/**
 *  获取2个数组的交集
 *
 *  @param array       第1个数组
 *  @param otherArray  第2个数组
 *  @param resultArray 交集数组
 */
void numberWithArrayAndOtherArray(int array[9], int otherArray[9], int resultArray[9]);

int main(int argc, const char * argv[])
{

    // insert code here...
    return 0;
}



