#ifndef PAIR_H
#define PAIR_H

using namespace std;

template <class T1, class T2>
class Pair
{
 public:
 Pair(): first(), second() {}

 Pair(T1&  first, T2&  second): first(first), second(second) { }

 Pair(const Pair<T1,T2>& other)
   :first(other.first), second(other.second) {}

  // to support the following, modified comparator operators to be "friend" of String                       
  bool operator ==(const Pair<T1,T2> & other) const { return first == other.first; }
  bool operator <=(const Pair<T1,T2> & other) const { return first <= other.first; }
  bool operator <(const Pair<T1,T2> & other)  const { return first < other.first; }
  bool operator >(const Pair<T1,T2> & other)  const { return first > other.first; }

  T1 first;
  T2 second;
};

#endif

