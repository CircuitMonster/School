/*
Name: Brian Ackley
Class: CSE 330
lab 2
*/

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

template <class T> class Vector
{
public:
   typedef T * iterator;

   Vector()
      : myCapacity(0), mySize(0), buffer(0)
      {
      }

  Vector(unsigned int sz)
      : buffer(0)
      {
         resize(sz);
      }
   
   Vector(unsigned int sz, T initial)
      : buffer(0)
      {
         resize(sz);
	 fill(buffer, buffer+mySize, initial);
      }


   //Copy constructor
   Vector(Vector<T>&);

   //Destructor
   ~Vector() {delete [] buffer;}

   //member functions
   T front() {return buffer[0];}
   T back() {return buffer[mySize - 1];}
   iterator begin() {return buffer;}
   iterator end() {return begin() + mySize;}
   
   void reserve(unsigned int newCapcity);

   void resize(unsigned int newSize)
   {
      reserve(newSize);
      mySize = newSize;
   }
   bool empty() {return mySize == 0;}
   unsigned int size() {return mySize;}
   unsigned int capacity() {return myCapacity;}

   T& operator [](unsigned int index) {return buffer[index];}
   
   void push_back(T);
   void pop_back() {mySize--;}


   //Assignment 1
   void erase(unsigned int);	//erases the value at location index
   void insert(unsigned int, T val);	//inserts value val at location index

private:
   unsigned int myCapacity;
   unsigned int mySize;

   T * buffer;
};



template <class T>
void Vector<T>::reserve(unsigned int newCap)
{
   if (buffer == 0)
   {
      mySize = 0;
      myCapacity = 0;
   }
   if (newCap <= myCapacity)
      return;

   T * newBuffer = new T[newCap];
   assert(newBuffer);

   copy(buffer, buffer + mySize, newBuffer);

   myCapacity = newCap;
   delete [] buffer;
   buffer = newBuffer;
}

template <class T>
void Vector<T>::push_back(T val)
{
   if (mySize == myCapacity)
   {
      reserve(myCapacity + 5);
   }
   buffer[mySize] = val;
   mySize++;
}

template <class T>
Vector<T>::Vector(Vector<T>& v)
{
   buffer = 0;
   resize(v.size());
   //copy from beginning to end of v
   copy(v.begin(), v.end(), begin());
}


//Assignment 1 (member functions)
template <class T>
void Vector<T>::insert(unsigned int index, T val)
{
   push_back(back());

   for (int i = mySize-2; i >= index+1; i--)
   {
      buffer[i] = buffer[i-1];
   }
   buffer[index] = val;
}


template <class T>
void Vector<T>::erase(unsigned int index)
{
   if (index >= mySize)
      return;
   else if (index == mySize-1)
      {
      pop_back();
      return;
      }
   else
      for(int i = index; i <= mySize-2; i++)
      {
	 buffer[i] = buffer[i+1];

      }
   pop_back();
}
