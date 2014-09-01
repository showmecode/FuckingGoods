//
//  main.c
//  Sudoku
//
//  Created by BW on 14-7-28.
//  Copyright (c) 2014年 bw. All rights reserved.
//

/**
 *  游戏说明
 *  1.游戏难度分为简单（40个已知数字）中等（30个已知数字）和困难（20个已知数字）3个难度
 *  2.游戏操作按要求格式键入指定文字并按下回车进行操作
 *  3.游戏规则:使用1-9 9个数字，使每一横，每一竖以及每个九宫格（线条隔开的小方框）的数字不重复
 *  每个空位都填满数字，则为胜利
 */

#include <stdio.h>
#define NUMBER 9

typedef struct _cell {
    
    int x;
    int y;
    int value;
    int init;
    int array[NUMBER];
} myCell;

static int sudoku[NUMBER][NUMBER];
static myCell myCells[NUMBER][NUMBER];

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

/**
 *  初始化数据源
 */
void initData();

/**
 *  初始化cell
 *
 *  @param x 第x ＋ 1排
 *  @param y 第y ＋ 1列
 */
void initMyCell(int x, int y);

/**
 *  修改cell的值
 *
 *  @param x     第x ＋ 1排
 *  @param y     第y ＋ 1列
 *  @param value 值
 */
void changCellValue(int x, int y, int value);

/**
 *  获取数组大于0的数字位数,并排序
 *
 *  @param array 计算与修改的数组
 *
 *  @return 数组长度
 */
int number(int array[NUMBER]);

/**
 *  使数组的某位数为0,并排序
 *
 *  @param array 修改的数组
 *  @param value 值
 */
void setArray(int array[NUMBER], int value);

/**
 *  使数组存在某位数字,并排序
 *
 *  @param array 需添加的数组
 *  @param value 值
 */
void addArray(int array[NUMBER], int value);

/**
 *  数组排序，从小到大，0在最后
 *
 *  @param array 需改变的数组
 */
void sortArray(int array[NUMBER]);

/**
 *  初始化游戏通过难度
 *
 *  @param difficulty 难度
 */
void startGame(int difficulty);

/**
 *  打印数独数字
 */
void printSudoku();

int rand();
void	 srand(unsigned);

time_t time(time_t *);

int main(int argc, const char * argv[])
{
    
    // insert code here...
    printf("欢迎使用数独游戏\n1.简单难度\n2.中等难度\n3.困难难度\n4.退出\n");
    char ch = ' ';
    int game = 1;
    while (game) {
        
        scanf("%c", &ch);
        int height = 2;
        switch (ch) {
            case '1':
                
                height--;
            case '2':
                
                height--;
            case '3':
                
                game = 0;
                startGame(height);
                break;
            case '4':
                
                game = 0;
                break;
            case '\n':
                
                break;
            default:
                
                printf("欢迎使用数独游戏\n1.简单难度\n2.中等难度\n3.困难难度\n4.退出\n");
                break;
        }
    }
    //    initData();
    //    for (int i = 0; i < NUMBER; i++) {
    //        for (int j = 0; j < NUMBER; j++) {
    //
    //            printf("%2d ", myCells[i][j].value);
    //            if ((j + 1) % 3 == 0) {
    //
    //                printf("\t");
    //            }
    //        }
    //        printf("\n");
    //        if ((i + 1) % 3 == 0) {
    //
    //            printf("\n");
    //        }
    //    }
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

void initData() {
    
    for (int i = 0; i < NUMBER; i++) {
        for (int j = 0; j < NUMBER; j++) {
            
            initMyCell(i, j);
        }
    }
    for (int i = 0; i < NUMBER; i++) {
        for (int j = 0; j < NUMBER; j++) {
            
            int cx = i / 3 * 3;
            int cy = j / 3 * 3;
            int array[NUMBER] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            for (int x = 0; x < NUMBER; x++) {
                
                if (myCells[i][x].value != 0 && x != j) {
                    
                    setArray(array, myCells[i][x].value);
                }
                if (myCells[x][j].value != 0 && x != i) {
                    
                    setArray(array, myCells[x][j].value);
                }
                if (myCells[i][j].array[x] != 0) {
                    
                    setArray(array, myCells[i][j].array[x]);
                }
            }
            for (int x = cx; x < cx + 3; x++) {
                for (int y = cy; y < cy + 3; y++) {
                    
                    if (myCells[x][y].value != 0 && i != x && j != y) {
                        
                        setArray(array, myCells[x][y].value);
                    }
                }
            }
            int num = number(array);
            if (num == 0) {
                
                myCells[i][j].value = 0;
                int n = number(myCells[i][j].array);
                for (int x = 0; x < n; x++) {
                    
                    myCells[i][j].array[x] = 0;
                }
                if (i == 0 && j == 0) {
                    
                    i = NUMBER;
                    j = NUMBER;
                    initData();
                    break;
                }
                if (j != 0) {
                    
                    j -= 2;
                }
                else {
                    
                    j = 7;
                    i --;
                }
                continue;
            }
            else {
                
                srand((unsigned)time(NULL));
                int index = rand() % num;
                changCellValue(i, j, array[index]);
            }
        }
    }
}

void initMyCell(int x, int y) {
    
    myCell cell;
    cell.x = x;
    cell.y = y;
    cell.value = 0;
    cell.init = 1;
    for (int i = 0; i < NUMBER; i++) {
        
        cell.array[i] = 0;
    }
    myCells[x][y] = cell;
}

void changCellValue(int x, int y, int value) {
    
    myCells[x][y].value = value;
    addArray(myCells[x][y].array, value);
    //    int cx = x / 3 * 3;
    //    int cy = y / 3 * 3;
    //    for (int i = 0; i < NUMBER; i++) {
    //
    //        //使当前cell的值固定
    //        myCells[x][y].array[i] = 0;
    //        if (i != y) {
    //
    //            //使当前排的cell的可选值减去当前设置值
    //            setArray(myCells[x][i].array, value);
    //            myCells[x][i].count = number(myCells[x][i].array);
    //        }
    //        if (i != x) {
    //
    //            //使当前列的cell的可选值减去当前设置值
    //            setArray(myCells[i][y].array, value);
    //            myCells[i][y].count = number(myCells[i][y].array);
    //        }
    //    }
    //    for (int i = cx; i < cx + 3; i++) {
    //        for (int j = cy; j < cy + 3; j++) {
    //
    //            if (!(i == x || j == y)) {
    //
    //                setArray(myCells[i][j].array, value);
    //                myCells[i][j].count = number(myCells[i][j].array);
    //            }
    //        }
    //    }
}

void setArray(int array[NUMBER], int value) {
    
    for (int i = 0; i < NUMBER; i++) {
        
        if (array[i] == value) {
            
            array[i] = 0;
            break;
        }
    }
    sortArray(array);
}

void addArray(int array[NUMBER], int value) {
    
    int index = number(array);
    if (index == NUMBER) {
        
        return;
    }
    for (int i = 0; i < index; i++) {
        
        if (array[i] == value) {
            
            return;
        }
    }
    array[index] = value;
    sortArray(array);
}

int number(int array[NUMBER]) {
    
    int count = 0;
    for (int i = 0; i < NUMBER; i++) {
        
        if (array[i] > 0) {
            
            count++;
        }
    }
    return count;
}

void sortArray(int array[NUMBER]) {
    
    for (int i = 0; i < NUMBER; i++) {
        
        int min = i;
        for (int j = i + 1; j < NUMBER; j++) {
            
            if (array[min] == 0 && array[j] != 0) {
                
                min = j;
            }
            if (array[min] > array[j] && array[j] != 0) {
                
                min = j;
            }
        }
        int a = array[i];
        array[i] = array[min];
        array[min] = a;
    }
}

void startGame(int difficulty) {
    
    initData();
    //    printSudoku();
    int diff[3] = {40, 30, 20};
    int array[81];
    int win  = diff[difficulty];
    for (int i = 0; i < 81; i++) {
        
        array[i] = i + 1;
    }
    for (int i = 0; i < diff[difficulty]; i++) {
        
        srand((unsigned)time(NULL));
        int index = rand() % (81 - i);
        array[index] = array[80 - i];
        array[80 - i] = 0;
    }
    for (int i = 0; i < 81; i++) {
        
        if (array[i] != 0) {
            
            int x = array[i] % 9;
            int y = array[i] / 9;
            myCells[y][x].value = 0;
            myCells[y][x].init = 0;
        }
        else {
            
            break;
        }
    }
    printSudoku();
    printf("添加或修改1个数字请输入s x(第x排) y(第y列) number(修改的数字)\n 如\" s 1 1 6 \"即把第1排第1列数字设置为6\n");
    printf("删除1个数字请输入d x(第x排) y(第y列)\n");
    printf("结束游戏请输入o\n");
    getchar();
    int game = 1;
    while (game) {
        
        char ch[4] = {' ', ' ', ' ', ' '};
        char in = ' ';
        int index = 0;
        while (in != '\n') {
            
            scanf("%c", &in);
            if (in == ' ') {
                
                continue;
            }
            ch[index] = in;
            index++;
        }
        if (ch[0] == 'O') {
            
            return;
        }
        else if (ch[0] == 'S' || ch[0] == 'D') {
            
            if (ch[1] > '0' && ch[1] <= '9' && ch[2] > '0' && ch[2] <= '9') {
                
                int i = ch[1] - '0' - 1;
                int j = ch[2] - '0' - 1;
                if (myCells[i][j].init == 1) {
                    
                    printf("初始数字不能修改或删除\n");
                    continue;
                }
                if (ch[0] == 'S') {
                    
                    if (ch[3] > '0' && ch[3] <= '9') {
                        
                        int value = ch[3] - '0';
                        int cx = i / 3 * 3;
                        int cy = j / 3 * 3;
                        int array[NUMBER] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
                        for (int x = 0; x < NUMBER; x++) {
                            
                            if (myCells[i][x].value != 0 && x != j) {
                                
                                setArray(array, myCells[i][x].value);
                            }
                            if (myCells[x][j].value != 0 && x != i) {
                                
                                setArray(array, myCells[x][j].value);
                            }
                        }
                        for (int x = cx; x < cx + 3; x++) {
                            for (int y = cy; y < cy + 3; y++) {
                                
                                if (myCells[x][y].value != 0 && i != x && j != y) {
                                    
                                    setArray(array, myCells[x][y].value);
                                }
                            }
                        }
                        int num = number(array);
                        int isRepet = 0;
                        for (int x = 0; x < num; x++) {
                            
                            if (array[x] == value) {
                                
                                myCells[i][j].value = value;
                                printSudoku();
                                isRepet = 1;
                                if (myCells[i][j].value == 0) {
                                    
                                    win++;
                                    if (win == 81) {
                                        
                                        printf("you win!\n");
                                        game = 0;
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        if (!isRepet) {
                            
                            printf("该数字已使用\n");
                            continue;
                        }
                    }
                    else {
                        
                        printf("无效输入\n");
                    }
                }
                else {
                    
                    win--;
                    myCells[i][j].value = 0;
                    printSudoku();
                }
            }
        }
        else {
            
            printf("无效输入\n");
        }
    }
}

void printSudoku() {
    
    for (int i = 0; i < NUMBER; i++) {
        
        if (i % 3 == 0) {
            
            printf("|-----------------------------|\n");
        }
        printf("|");
        for (int j = 0; j < NUMBER; j++) {
            
            if (myCells[i][j].value == 0) {
                
                printf("   ");
            }
            else {
                
                printf("%2d ", myCells[i][j].value);
            }
            if ((j + 1) % 3 == 0) {
                
                printf("|");
            }
        }
        printf("\n");
    }
    printf("|-----------------------------|\n");
}
