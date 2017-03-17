#include <list>
using namespace std;

#ifndef STACK_H_
#define STACK_H_

template <class T>
class Stack
{
public:
   bool empty() {return c.empty();}
   int size() {return c.size();}
   T & top() {return c.back();}
   void push(T  x) {c.push_back(x);}
   void pop() {c.pop_back();}

private:
   list<T> c;
};
#endif
