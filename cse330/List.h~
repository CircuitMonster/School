/*
Name: Brian Ackley
Class: CSE 330
Professor: Kerstin Voigt
Lab #3
*/


#ifndef LIST_H_
#define LIST_H_
#include <algorithm>
using namespace std;

//forward reference
template <class T> class Link;
template <class T> class listIterator;

template <class T>
class List
{
public:
   //type definitions:
   typedef T value_type;
   typedef listIterator<T> iterator;

   //constructor and deconstructor
   List() : firstLink(0), lastLink(0) { }
   ~ List();

   //operations:
   bool empty() {return firstLink == 0;}
   int size();
   T & back() {return lastLink->value;}
   T & front() {return firstLink->value;}
   void push_front(T &);
   void push_back(T &);
   void pop_front();
   void pop_back();
   iterator begin() {return iterator (this, firstLink);}
   iterator end() {return iterator (this, 0);}
   void sort();
   void insert(iterator &, T &);
   void erase(iterator & itr) {erase (itr, itr);}
   void erase(iterator &, iterator &);

private:
   Link <T> * firstLink;
   Link <T> * lastLink;
};


//helper class
template <class T>
class Link
{
   Link (T & v) : value(v), nextLink(0), prevLink(0) {}
   T value;
   Link<T> * nextLink;
   Link<T> * prevLink;

   friend class List<T>;
   friend class listIterator<T>;


/*public:
   Link(T val)
      : value(val), nextLink(0), prevLink(0)
      {}
   Link(Link<T> other)
      : value(other.value), nextLink(other.nextLink), prevLink(other.prevLink)
      {}
   ~Link();

private:
   friend template <class<T> List;
//   friend template <class<T> ListIterator;
   T value;
   Link<T>* nextLink; //pointer to next link
   Link<T>* prevLink; //pointer to previous link
*/
};


template <class T>
class listIterator
{
typedef listIterator<T> iterator;

public:
   //constructor:
   listIterator(List<T> * t1, Link<T> * c1)
      : theList(t1), currentLink(c1) {}

   //iterator protocol
   T & operator * () {return currentLink->value;}
   void operator = (iterator & rhs) {theList = rhs.theList; currentLink = rhs.currentLink;}
   bool operator == (iterator & rhs) {return currentLink == rhs.currentLink;}
   iterator & operator ++ (int) {currentLink = currentLink->nextLink; return *this;}
   iterator operator ++ ();
   iterator & operator -- (int) {currentLink = currentLink->prevLink; return *this;}
   iterator operator -- ();

private:
   List <T> * theList;
   List <T> * currentLink;
};


//functions:

template <class T>
int List<T>::size()
{
   int counter = 0;
   for (Link<T> * ptr = firstLink; ptr != 0; ptr = ptr->nextLink)
      counter++;
   return counter;
}

template <class T>
void List<T>::push_front (T & newValue)
{
   Link<T> * newLink = new Link<T> (newValue);
   if (empty())
      firstLink = lastLink = newLink;
   else
   {
      firstLink->prevLink = newLink;
      newLink->nextLink = firstLink;
      firstLink = newLink;
   }
}

template <class T>
void List<T>::pop_front()
{
   Link <T> * save = firstLink;
   firstLink = firstLink->nextLink;
   if (firstLink != 0)
      firstLink->prevLink = 0;
   else
      lastLink = 0;
   delete save;
}

template <class T>
List<T>::~List()
{
   Link<T> * first = firstLink;
   while (first != 0)
   {
      Link <T> * next = first->nextLink;
      delete first;
      first = next;
   }
}

template <class T>
listIterator<T> listIterator<T>::operator ++ ()
{
   listIterator<T> clone (theList, currentLink);
   currentLink = currentLink->nextLink;
   return clone;
}

template <class T>
void List<T>::erase (listIterator<T> & start, listIterator<T> & stop)
{
   Link<T> * first = start->currentLink;
   Link<T> * prev = first->prevLink;
   Link<T> * last = stop->currentLink;
   if (prev == 0)
   {
      firstLink = last;
      if (last == 0)
         lastLink = 0;
      else
         last->prevLink = 0;
   }
   else
   {
      prev->nextLink = last;
      if (last == 0)
         lastLink = prev;
      else
         last->prevLink = prev;
   }
   while (start != stop)
   {
      listIterator<T> * next = start;
      ++next;
      delete start.currentLink;
      start = next;
   }   
}

template <class T>
void push_back(T & newValue)
{
   Link <T> firstLink;
   Link <T> lastLink;

	Link<T> * newback = new Link<T>(newValue);

	if (empty())
	{
		firstLink = newback;
		lastLink = newback;
	}
	else
	{
		lastLink->nextLink = newback;
		newback->prevLink = lastLink;
		lastLink = newback;
	}
}

template <class T>
void pop_back()
{
   Link <T> firstLink;
   Link <T> lastLink;

	if (firstLink == 0)
		return;

	Link<T>* save = lastLink;

	lastLink = lastLink->prevLink;
	
	if (lastLink != 0)
		lastLink->nextLink = 0;
	else
		firstLink = 0;

	save->prevLink = 0;
	delete save;
}


template <class T>
Link<T>::~Link()
{
   if (nextLink != 0)
      delete nextLink;
   if (prevLink != 0)
      delete prevLink;
}
#endif
