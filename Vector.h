#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <vector>
#include <stdexcept>

 using namespace std;

template <class T>
class Vector {
  T* arr;
  int sz, capacity;
 
  void grow() {
  	capacity = capacity *2; // allocate a new array with double the capacity,
  	T*temp = new T[capacity];
  	for(int i=0 ; i< sz ; i++){
  		temp[i]=arr[i]; // copy arr over the the new array,
  		
	  }
	  delete []arr; // deallocate arr,
	  arr =temp;  // point arr to the new array,
  }

  public:
  Vector() { //allocate a new array with size 0 (nothing is in it yet) 
  	sz=0;
  	arr= new T[10];
  	capacity = 10; //and capacity 10
  }

  
  ~Vector() {  // deallocate arr
  	if(arr!= NULL)
  	delete [] arr;
  }

  
  void push_back(const T& elt) {  // add elt to the end of arr (remember to update sz!)
  if(sz== capacity){ // if size = the capacity it should grow the array
  	grow ();
  }
  	arr[sz]=elt; // else put elt at the back of the array 
  	sz++; // incerment the size
  }

  
  void pop_back() { // remove the last element in arr (remember to update sz!)
  	if(!empty()) // check if the array is empty
  		sz--;  // decrement the size
}
  

void insert(const T& elt, int pos) {
	if(sz==capacity){ // if size = the capacity it should grow the array
  		grow();
  	}
  	if(pos > sz || pos<0 ){ // the pos greater than the size or less than 0 throw an exception
  		throw exception();
  	}
	for (int i = sz; i > pos; i--) { // looping from the end of the array that the number which in one array is insert it to the the array before it  
      arr[i] = arr[i - 1];
	}
	arr[pos]= elt; // add elt to arr at position pos
  	sz++;	// increment the size
}
  	
  
  void erase(int pos) {
  	if(pos>=sz || pos<0) // the pos greater than the size or less than 0 throw an exception
  	 throw exception();
  	 
  	 for(int i=pos ; i<sz-1 ; i++){ // looping on array till the end of the array-1 that the number which in one array will be in the array after it  
  	 arr[i]=arr[i+1];
  }
   sz--;   // erase elt at position pos by decrementing the size.
}
	
	T& front() {
		return arr[0]; // return first element in vector
	}

	T& back() {
		return arr[sz-1];	// return last element in vector
	}

  T& at(int pos) {
  	if(pos>=sz || pos<0) // the pos greater than the size or less than 0 throw an exception
  throw exception();
  	
  	return arr[pos];  // return element at position pos
  }

  T& operator[](int pos) {
  	if(pos>sz || pos<0) // the pos greater than the size or less than 0 throw an exception
  	throw exception();
	  	
  	return arr[pos];// return element at position pos 
  	
  }

  int size() {
   return sz; // return the size
   }

  bool empty() {
  	if (sz== 0)
 	return true; // return true if vector is empty
 	else
 	return false;// otherwize return false
}
};

#endif
 
