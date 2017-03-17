// set_of_pairs.cpp

#include <iostream>
#include <string>
#include <set>
#include "Pair.h"

using namespace std;

template <class T1, class T2>
bool find_pair_by_key(const set<Pair<T1,T2> >&, T1, Pair<T1,T2>&);

template <class T1, class T2>
void update(set<Pair<T1,T2> >&, T1, T2);

/*
template <class T1, class T2>
class Map :public set<Pair<T1,T2> >
{
public:

  Map() :themap() {}

  Map(const set<Pair<T1,T2> > & s) :themap(s) {}

  T2& operator [](const T1& key)
  {
  // .....
  }
    
protected:

  set<Pair<T1,T2> > themap;
};
*/


int main()
{
  int val;
  string key;

  set<Pair<string,int> > basket;

  for (int i = 1; i <= 5; i++)
    {
      cout << endl;
      cout << "A fruit: ";
      cin >> key;
      cout<< endl;
      cout << "How many? ";
      cin >> val;

      //Pair<string,int> entry(key,val);
      //basket.insert(entry);
      
      update(basket, key, val);
    }

  set<Pair<string, int> >::iterator itr = basket.begin();

  for (; itr != basket.end(); ++itr)
    cout << (*itr).first << ": " << (*itr).second << endl;
      

  cout << endl;
  cout << "erase which one? ";
  cin >> key;

  Pair<string,int> gotit;

  if (find_pair_by_key(basket,key,gotit))
    {
      basket.erase(gotit);
    }

  itr = basket.begin();
  for (; itr != basket.end(); ++itr)
    cout << (*itr).first << ": " << (*itr).second << endl;

  cout << endl;
  cout << "Make a change: ";
  cin >> key >> val;

  update(basket, key, val);

  cout << endl;
  cout << "Make another change: ";
  cin >> key >> val;

  update(basket,key,val);

  itr = basket.begin();
  for (; itr != basket.end(); ++itr)
    cout << (*itr).first << ": " << (*itr).second << endl;

  return 0;
}

template <class T1, class T2>
bool find_pair_by_key(const set<Pair<T1,T2> >& pairs, T1 key, 
		      Pair<T1,T2>& found)
{

  if (pairs.empty())
    return false;

  typename set<Pair<T1,T2> >::iterator itr = pairs.begin();

  for (; itr != pairs.end(); ++itr)
    {
      if ((*itr).first == key)
        {
          found = *itr;
          return true;
        }
    }
  return false;
}

template <class T1, class T2>
void update(set<Pair<T1,T2> >& pairs, T1 key, T2 newval)
{
  Pair<T1,T2> gotit;

  if (find_pair_by_key(pairs, key, gotit))
    {
      cout << " ... found it ... now erase it" << endl;
      airs.erase(gotit);
    }
  cout << " ... now inserting new  ..." << endl;
  pairs.insert(Pair<T1,T2>(key,newval));
}
