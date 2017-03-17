/*
Name: Brian Ackley
Date: 3-14-13
Assignment 4
File: hw4.cpp
Description: Program adds in strings into a vector (front or back), and then also runs through the vector to remove what is called for (front, back, and using itterators). The end display will show everything that wasn't removed.
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
   class Mlist
{
public:
   Mlist();//creates the list 
   T front();//returns the front of the list 
   T end();//returns the end of the list and moves every entry up one position;
   bool in(T x);//returns true if x is in the list and false otherwise
   bool empty(); //{ return mlist.size() == 0; }// returns true if the list is empty
   void addfront(T entry); //{mlist.push_back(entry);}//add entry to the back of the list
   void addend(T entry); //{mlist.push_back(entry);}//add entry to the back of the list
   void removefront();//removes the front of the list
   void removeend();//removes the back of the list
   void remove(T n){remove(mlist.begin(),n);}//searches the list and removes the entry with value n
private:
   vector<T> mlist;
   void remove(typename vector<T>::iterator ix, T n);//uses an iterator and recursion to remove value n
}; // Mlist

template<typename T>
Mlist<T>::Mlist()
{
}

template<typename T>
T Mlist<T> ::front()
{
   return *(mlist.begin());
}

template<typename T>
T Mlist<T>::end()
{
   return *(--mlist.end());
}

template<typename T>
bool Mlist<T>::in(T x)
{
   typename vector<T>::iterator ix;
   for (mlist.begin(); ix != mlist.end(); ix++)
   {
      if (*ix == x)
      {
         return true;
      }
   }
   return false;
}

template<typename T>
bool Mlist<T>::empty()
{
   return mlist.size() == 0;
}

template<typename T>
void Mlist<T>::addfront(T entry)
{
   mlist.insert(mlist.begin(), entry);
}

template<typename T>
void Mlist<T>::addend(T entry)
{
   mlist.insert(mlist.end(), entry);
}

template<typename T>
void Mlist<T>::removefront()
{
   mlist.erase(mlist.begin());
}

template<typename T>
void Mlist<T>::removeend()
{
   mlist.erase(mlist.end());
}

template<typename T>
void Mlist<T>::remove(typename vector<T>::iterator ix, T n)
{
   if (mlist.end() == ix)
      return;
   else
      if (*ix == n)
      {
         mlist.erase(ix);
         return remove(ix, n);
      }
   else
      return remove (++ix, n);
 return;
}

int main()
{
   Mlist<int> test1=Mlist<int>();
   test1.addfront(5);
   test1.addfront(7);
   test1.addend(4);
   test1.remove(7);
   cout << test1.front()<< endl;
   cout << test1.end()<< endl;
   Mlist<string> test2= Mlist<string>();
   test2.addfront("John");
   test2.addfront("Paul");
   test2.addend("Mary");
   test2.addend("Kate");
   test2.remove("Paul");
   cout << test2.front()<< endl;
   cout << test2.end()<< endl;
}
