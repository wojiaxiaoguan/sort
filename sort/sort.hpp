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
#include "Compare.hpp"


template <class Record,class Compare>
class Sorter{
protected:
    static void swap(Record array[],int i,int j){
        Record temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    };
public:
    void Sort(Record array[],int n);
    void PrintArray(Record array[],int n){
        for(int i = 0 ;i<n;i++){
            std::cout<<array[i]<< " ";
        }
        std::cout<<std::endl;
    };
};


template <class Record,class Compare>
class InsertSort:public Sorter<Record, Compare>{};

template <class Record,class Compare>
class StraightSorter:public InsertSort< Record, Compare> {
    //直接插入排序
public:
    void Sort(Record array[],int n){
        for (int i = 0; i<n; i++) {
            for (int j = i; j > 0; j --) {
                if(Compare::lt(array[i],array[j]))
                  this->swap(array,j,j-1);
                else
                    break;
            }
        }
    };
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


template <class Record,class Compare>
class BubbleSorter:public Sorter< Record,  Compare> {
    
    
public:
    void Sort(Record array[],int n){
        for (int i = 1; i < n; i ++) {
            for (int j = n-1; j>=i; j--) {
                if (Compare::lt(array[j],array[j-1]))
                    this->swap(array,j,j-1);
            }
        }
    };
};

template <class Record,class Compare>
class ImproveBubbleSorter:public BubbleSorter< Record,  Compare> {
    
    
public:
    void Sort(Record array[],int n);
};

template <class Record,class Compare>
class StraightSelectSorter:public Sorter< Record,  Compare> {
    
    
public:
    void Sort(Record array[],int n){
        for (int i = 0 ; i< n -1; i ++) {
            int Smalllest = i;
            for (int j = i+1; j < n; j++) {
                if (Compare::lt(array[j],array[Smalllest]))
                    Smalllest = i;
            }
            this->swap(array,i,Smalllest);
        }
    };
};



#endif /* sort_hpp */
