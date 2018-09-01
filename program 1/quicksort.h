/**
Program 1
Ian Osea
CSCE 350 Spring 2018
Prof. O'Reilly

Description:
This program implements Quicksort using Hoare's Partition.
**/
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>

using std::swap;

//note returns INDEX of median
template<typename T> inline
int medianOf3(T A[], int l, int r){
	//this is overcommented... also, try and avoid using pointers
	T* a = A + l;//array name is just pointer to 1st (0 index) elem., + l shifts l*(T size)
	T* b = A + l + (r-l)/2;//middle item... int division rounds down
	T* c = A + r;

	//when a is a pointer, *a is the dereference operator (gives value a points to)
	T* m;
	if(*a < *b){
		if(*b < *c) m=b; 
		else if(*c < *a) m=a;
		else m=c;
	} else{ //b <=a
		if(*a < *c) m=a;
		else if(*c < *b) m=b;
		else m=c;
	}
	return m-A; //m-A is the number of elements from A[0]

}

//remember: l and r are INLCUSIVE (just like Lomuto)
template<typename T>
int hoarePartition(T A[], int l, int r) {
   
  //int mid = 0; 
  //the median of three values are used to find the pivot "int mid." 
  int mid = medianOf3(A, l, r);
  //swap() is used to wap the median to the left position and the
  //algorithm in the book is started.
  swap(A[l], A[mid]);
  //variable "index" is created to hold the "l" value of the array.
  T index = A[l];
    
  int i = l;
  int j = r + 1;
 
  //while (true){
  //the rest is the implementation of hoare's partition.
  do {
    do {

        ++i;

  } while (A[i] < index && i <= r);

    do {

        --j;

  } while (A[j] > index && j >= l);
      
      swap(A[i], A[j]);

  } while (i < j);
       
    swap(A[i], A[j]);
    swap(A[l], A[j]);
    return j;
}
template<typename T>
//this quicksort was derived from the book and from the help of online resources.
void quicksort(T A[], int l, int r){

    if (l < r) {
                                    
    int index = hoarePartition(A, l, r);
    quicksort(A, l, index - 1);
    quicksort(A, index + 1, r);
    } 
}
#endif
