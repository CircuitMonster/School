/* Implementation of istack.n
*/
#include <vector>
#include "istack.h"
using namespace std;

template <typename T> class stack :public istack<T> 
{
  public:  // functions
    void pop(){ vstack.pop_back();                       }
    void push(T item){ vstack.push_back(item);     }
    T top() const{  return vstack.back();                    }
    bool empty() const{ return vstack.empty();    }

  private: // data
   vector<T> vstack;

};

/*
#include <vector>
#include "istack.h"
using namespace std;

template <typename T> class stack :public istack<T> 
{
  public:  // functions
    void pop(){ stack.erase(stack.begin());                       }
    void push(T item){ stack.insert(stack.push_back(), item);     }
    T top() const{  return stack.begin();                    }
    bool empty() const{ return stack.size() == 0;    }

  private: // data
   vector<T> stack;

};

*/
