/*
Name: Brian Ackley
CSE 330
Lab 8
*/

#ifndef SET_H_
#define SET_H_

#include <iostream>
#include<vector>
using namespace std;

template <class T>
class Node
{ 
public:
   Node(T& v)
    : value(v), leftChild(0), rightChild(0), parent(0)
    {}

   Node(T& v, Node * n1, Node * n2, Node * p)
    :value(v), leftChild(n1), rightChild(n2), parent(p)
    {}

   void insert(Node<T> *);
   void print(vector<T>&);

   int size();

   bool find(T& x);


   Node<T>* remove(T&);
   Node<T>* merge(Node<T> *, Node<T> *);

   T value;
   Node * leftChild;
   Node * rightChild;
   Node * parent;

};


template <class T>
class Set
{
public:
   Set()
    :root(0) {}

   void insert(T& x)
   {
      Node<T>* newnode = new Node<T>(x, 0, 0, 0);
      
      if (root == 0)
         root = newnode;
      else
         root->insert(newnode);
   }

   void print(vector<T>& vals)
   {
      if (root == 0)
         cout << "empty";
      else
         root->print(vals); 
   }

   void erase(T& x)
   {
      if (root == 0)
         return root;
      else
         root = remove(root, x);    
   }

   int size()
   {
      if (root == 0)
        return 0;
      
      return root->size();
   }

   bool find(T& x)
   {
     if (root == 0)
       return false;
     
     return root->find(x);
   }

private:
   Node<T> * root;
};

template <class T>
void Node<T>::insert(Node<T>* newnode)
{
   T x = newnode->value;

   if (x < value)
   {
      if (leftChild == 0)
      {
	 leftChild = newnode;
      }
      else
         leftChild->insert(newnode);
   }
   else if (x > value)
   {
      if (rightChild == 0)
      {
         rightChild = newnode;
      }
      else
         rightChild->insert(newnode);
   }
}

template <class T>
void Node<T>::print(vector<T>& vals)
{
   if (leftChild != 0)
      leftChild->print(vals);

   cout << value << " ";

   if (rightChild != 0)
      rightChild->print(vals);
}

template <class T>
Node<T>* Node<T>::remove(T& x)
{
   if (value == x)
   {
      if (leftChild == 0 && rightChild == 0)
      {
	  delete this;
	  return 0;
      }
      return merge(leftChild, rightChild);
   }
   if (x < value)
   {
      if (leftChild == 0)
         return this;

      Node<T> * newleft = leftChild->remove(x);
      
      leftChild = newleft;
      if (newleft != 0)
         leftChild->parent = this;

   }
   else
   {
      if (rightChild == 0)
         return this;
      
      Node<T> * newright = rightChild->remove(x);
      rightChild = newright;

      if (newright != 0)
         rightChild->parent = this;
   }
   return this;
}

template <class T>
Node<T>* Node<T>::merge(Node<T> * left, Node<T> * right)
{
   if (left == 0)
      return right;
   if (right == 0)
      return left;

   Node<T> * child = merge(left, right->leftChild);

   child->parent = right;
   right->leftChild = child;
   return right;
}

template <class T>
int Node<T>::size()
{
   if (leftChild == 0 && rightChild == 0)
      return 1;
   if (rightChild == 0)
      return 1 + leftChild->size();
   if (leftChild == 0)
      return 1 + rightChild->size();
   return 1 + leftChild->size() + rightChild->size();
}

template <class T>
bool Node<T>::find(T& x)
{
   if (value == x)
      return true;
   if (leftChild == 0 && rightChild == 0)
      return false;
   if (rightChild == 0)
      return leftChild->find(x);
   if (leftChild == 0)
      return rightChild->find(x);

   return leftChild->find(x) || rightChild->find(x);
}

#endif
