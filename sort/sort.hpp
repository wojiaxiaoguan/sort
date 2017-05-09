//
//  sort.hpp
//  sort
//
//  Created by Wojiaxiaoguan on 2017/5/8.
//  Copyright © 2017年 Wojiaxiaoguan. All rights reserved.
//

#ifndef sort_hpp
#define sort_hpp

#include <iostream>


template <class Record,class Compare>
class Sorter{
protected:
    static void swap(Record array[],int i,int j);
public:
    void Sort(Record array[],int n);
    void PrintArray(Record array[],int n);
};


template <class Record,class Compare>
class InsertSort:public Sorter<Record, Compare>{};

template <class Record,class Compare>
class StraightSorter:public InsertSort< Record, Compare> {
    //直接插入排序
public:
    void Sort(Record array[],int n);
};


template <class Record,class Compare>
class ImproveInsertSorter:public InsertSort< Record,  Compare> {
    
    //优化的直接插入排序
public:
    void Sort(Record array[],int n);
};


template <class Record,class Compare>
class BinaryInsertSorter:public InsertSort< Record,  Compare> {
    //二分插入排序
    
public:
    void Sort(Record array[],int n);
};

#endif /* sort_hpp */
