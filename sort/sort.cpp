//
//  sort.cpp
//  sort
//
//  Created by Wojiaxiaoguan on 2017/5/8.
//  Copyright © 2017年 Wojiaxiaoguan. All rights reserved.
//

#include "sort.hpp"

template <class Record,class Compare>

void Sorter<Record,Compare>::swap(Record array[],int i,int j)
{
    Record temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

template <class Record,class Compare>
void Sorter<Record,Compare>::PrintArray(Record array[],int n)
{
    for(int i = 0 ;i<n;i++){
        std::cout<<array[i]<< " ";
    }
    std::cout<<std::endl;
}

template <class Record,class Compare>
void StraightSorter<Record, Compare>::Sort(Record array[], int n){
    for (int i = 0; i<n; i++) {
        for (int j = i; j > 0; j --) {
            if(Compare::lt(array[i],array[j]))
                swap(array,j,j-1);
            else
                break;
        }
    }
}

template <class Record,class Compare>
void ImproveInsertSorter<Record,Compare>::Sort(Record array[], int n){
    Record temp;
    for (int i =1; i<n; i++) {
        temp = array[i];
        int j = i - 1;
        while ((j<=0) && (Compare::lt(temp,array[j]))) {
            array[i+1] = array[j];
            j= j -1;
        }
        array[j+1] = temp;
    }
}


