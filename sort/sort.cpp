//
//  sort.cpp
//  sort
//
//  Created by Wojiaxiaoguan on 2017/5/8.
//  Copyright © 2017年 Wojiaxiaoguan. All rights reserved.
//

#include "sort.hpp"

//template <class Record,class Compare>

//void Sorter<Record,Compare>::swap(Record array[],int i,int j)
//{
//    Record temp = array[i];
//    array[i] = array[j];
//    array[j] = temp;
//}

//template <class Record,class Compare>
//void Sorter<Record,Compare>::PrintArray(Record array[],int n)
//{
//    for(int i = 0 ;i<n;i++){
//        std::cout<<array[i]<< " ";
//    }
//    std::cout<<std::endl;
//}
//
//template <class Record,class Compare>
//void StraightSorter<Record, Compare>::Sort(Record array[], int n){
//    for (int i = 0; i<n; i++) {
//        for (int j = i; j > 0; j --) {
//            if(Compare::lt(array[i],array[j]))
//                swap(array,j,j-1);
//            else
//                break;
//        }
//    }
//}

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

template <class Record,class Compare>
void BinaryInsertSorter<Record,Compare>::Sort(Record array[], int n){
    Record temp;
    int left,right,middle;
    for (int i = 1; i<n; i++) {
        temp = array[i];
        left = 0;
        right = i-1;
        while (left <= right) {
            middle = (left + right)/2;
            if(Compare::lt(temp,array[middle]))
                right = middle - 1;
            else
                left = middle + 1;
        }
        for (int j = i -1; j>=left; j--) {
            array[j+1] = array[j];
        }
        array[left] = temp;
    }
}

//template <class Record,class Compare>
//void BubbleSorter<Record,Compare>::Sort(Record array[], int n) {
//    for (int i = 1; i < n; i ++) {
//        for (int j = n-1; j>=i; j--) {
//            if (Compare::lt(array[j],array[j-1]))
//                swap(array,j,j-1);
//        }
//    }
//}

template <class Record,class Compare>
void ImproveBubbleSorter<Record,Compare>::Sort(Record array[], int n) {
    bool noSwap;
    for (int i = 1; i < n; i ++) {
        for (int j = n-1; j>=i; j--) {
            noSwap = true;
            if (Compare::lt(array[j],array[j-1]))
            {
                swap(array,j,j-1);
                noSwap = false;
            }
            
            if (noSwap) return;
        }
    }
}

//template <class Record,class Compare>
//void StraightSelectSorter<Record,Compare>::Sort(Record array[], int n) {
//    for (int i = 0 ; i< n -1; i ++) {
//        int Smalllest = i;
//        for (int j = i+1; j < n; j++) {
//            if (Compare::lt(array[j],array[Smalllest]))
//                Smalllest = i;
//        }
//        swap(array,i,Smalllest);
//    }
//}


