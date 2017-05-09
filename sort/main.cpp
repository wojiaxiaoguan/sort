//
//  main.cpp
//  sort
//
//  Created by Wojiaxiaoguan on 2017/5/8.
//  Copyright © 2017年 Wojiaxiaoguan. All rights reserved.
//

#include <iostream>
#include "sort.hpp"
#include "Compare.hpp"
#include "stdlib.h"
#include "string.h"


/*
 *不支持模板类的分离编译 但是可以再测试函数里面同时包括 #include "x.h" 和 #include "x.cpp"也可以的
 *只有支持export关键字的编译器才支持模板接口与定义分离。
 */
using namespace std;

template <class T>
int count(T& x)
{
    int s1 = sizeof(x);
    int s2 = sizeof(x[0]);
    int result = s1 / s2;
    return result;
}

// 设定随即函数的种子
inline void Randomize()
{ srand(1); }
//返回一个0到n-1之间的随机数
inline int Random(int n)
{ return rand() % (n); }

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
//    int array[] = {45,34,78,12,34,32,29,64};
////    Sorter<int, int_intCompare> *sort = new StraightSelectSorter<int, int_intCompare>();
//    StraightSelectSorter<int, Compare> sort;
//    sort.Sort(array, 8);
//    sort.PrintArray(array, 8);
    //产生随机数组,长度为100
    Randomize();
    int * sortarray =new int[100];
    for(int i=0;i<100;i++)
        sortarray[i]=Random(100);
    int choice;
    cout<<"选择排序方式： 1---Bubblesort,2---Insertionsort,3---Selestsort,4---Shellsort"<<endl;
    cin>>choice;
    if(choice==1)//排序
    {//实例化起泡排序类
        BubbleSorter<int,Compare> sorter;
        cout<<"排序前：";cout<<endl;
        sorter.PrintArray(sortarray,100);
        sorter.Sort(sortarray,100);
        //输出排序后数组内容
        cout<<"排序后：";cout<<endl;
        sorter.PrintArray(sortarray,100);
    }
    if(choice==2)
    {//实例化直接插入排序类
        StraightSorter<int,Compare> sorter;
        cout<<"排序前：";cout<<endl;
        sorter.PrintArray(sortarray,100);
        sorter.Sort(sortarray,100);
        //输出排序后数组内容
        cout<<"排序后：";cout<<endl;
        sorter.PrintArray(sortarray,100);
    }
    if(choice==3)
    {//实例化直接选择排序类
        StraightSelectSorter<int,Compare> sorter;
        cout<<"排序前：";cout<<endl;
        sorter.PrintArray(sortarray,100);
        sorter.Sort(sortarray,100);
        //输出排序后数组内容
        cout<<"排序后：";cout<<endl;
        sorter.PrintArray(sortarray,100);
    }
    if(choice==4)
    {//实例化Shell排序类
//        ShellSorter<int,Compare> sorter;
//        cout<<"排序前：";cout<<endl;
//        sorter.PrintArray(sortarray,100);
//        //输出排序后数组内容
//        cout<<"排序后：";cout<<endl;
//        sorter.PrintArray(sortarray,100);
    }
    return 0;
}
