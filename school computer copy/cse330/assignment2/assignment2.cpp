/*
Name: Brian Ackley
CSE 300
Assignment 2
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <class Itr>
void m_sort(Itr start, unsigned int low, unsigned int high)
{
   if (low + 1 < high)
   {
      unsigned int center = (high + low) / 2;
      m_sort (start, low, center);
      m_sort ( start, center, high);
      inplace_merge (start + low, start + center, start + high);
   }
}

template <class T>
void mergeSort(vector<T> & s)
{
   m_sort(s.begin(), 0, s.size());
}



int main()
{
   vector<int> vec1;
   vector<int> vec2;

//Adding values to Vector #1
   vec1.push_back(7);
   vec1.push_back(15);
   vec1.push_back(33);
   vec1.push_back(3);
   vec1.push_back(11);
   vec1.push_back(22);
   vec1.push_back(10);
   vec1.push_back(50);
   vec1.push_back(31);
   vec1.push_back(7);

   cout << "Vector 1: ";
   for (int i = 0; i < vec1.size(); i++)
   {
      cout << vec1[i] << " ";
   }
   cout << endl << endl;

//Adding values to Vector #2
   vec2.push_back(5);
   vec2.push_back(43);
   vec2.push_back(20);
   vec2.push_back(25);
   vec2.push_back(1);
   vec2.push_back(4);
   vec2.push_back(16);
   vec2.push_back(27);
   vec2.push_back(7);
   vec2.push_back(44);

   cout << "Vector 2: ";
   for (int i = 0; i < vec2.size(); i++)
   {
      cout << vec2[i] << " ";
   }
   cout << endl << endl;

//Testing sorting with Vector #1
   cout << "Vector 1 sorted: ";
   mergeSort(vec1);
   for (int i = 0; i < vec1.size(); i++)
   {
      cout << vec1[i] << " ";
   }
   cout << endl << endl;  

//Testing sorting with Vector #2
   cout << "Vector 2 sorted: ";
   mergeSort(vec2);
   for (int i = 0; i < vec2.size(); i++)
   {
      cout << vec2[i] << " ";
   }
   cout << endl << endl;

//Combing both Vector #1 and #2 into Vector #3
   vector<int> vec3 = vec1;
   vec3.insert(vec3.end(), vec2.begin(), vec2.end());

//Testing sorting with Vector #3
   cout << "Vector 1 & 2 combined, & sorted: ";
   mergeSort(vec3);
   for (int i = 0; i < vec3.size(); i++)
   {
      cout << vec3[i] << " ";
   }
   cout << endl << endl;
}
