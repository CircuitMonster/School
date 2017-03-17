// PriorQ.h
// after T. Budd, pp. 364;

// uses functions push_heap and pop_heap which will be
// dealt with later ....


#include <vector>

using namespace std;

template <class T>
void print_vector(const vector<T>&);

template <class R>
void swap1 (R& x, R& y)
{
	R temp = x;
	x = y;
	y = temp;
}

template <class T>
class PriorQ
{
 public:

  // see p. 364 ...

  bool empty() {return heap.empty();}

  int size() {return heap.size();}

  T& top() {return heap[0];}

  void push(T& newElement)
  {
    heap.push_back(newElement);
    //push_heap(heap.begin(), heap.end());
    push_heap();
  }

  void pop()
  {
    //pop_heap(heap.begin(), heap.end());
    pop_heap();
    heap.pop_back();
  }


 private:

  void push_heap();
  void pop_heap();
  void adjust_heap();

  vector<T> heap;
};


template <class T>
void PriorityQueue<T>::push_heap()
{
  int position = heap.size() - 1;
  int parent = (position - 1) / 2; // integer div;

  //cout << "push_heap for item " << heap[position] << endl;

  while (position > 0 && heap[position] > heap[parent])
    {
      //print_vector(heap);
      
      swap1(heap[position], heap[parent]);
      position = parent;
      parent = (position - 1)/2;
    }
}


// ...... fix pq; needs top be heap .... ;

template <class T>
void PriorityQueue<T>::pop_heap()
{
  //cout << "pop_heap for item " << pq[0] << endl;
  //print_vector(pq);
  int lastpos = pq.size() - 1;
  swap1(pq[0],pq[lastpos]);
  pq.pop_back(); // new; moved downform pop
  adjust_heap();
}

template <class T>
void PriorityQueue<T>::adjust_heap() 
{
  //cout << "adjust_heap for item " << pq[0] << endl;

  int position = 0; // position of root
  int heapSize = pq.size();
  while (position < heap.size())
	{
	  //print_vector(pq);

	  // position is within heap to adjust ..
	  // get pos of left chld;
	  int childpos = position * 2 + 1; // index of left child

	  if (childpos < heapSize)
	    {
	      // there is a left child within heap to adjust;
	      // is this the larger child? if there exists a right
	      // child within the heap to adjust, and this right
	      // child is larger, set childpos to the index of the
	      // larger child; (otherwise, just keep index of left
	      // child;
	      if ((childpos + 1 < heapSize) &&
		  pq[childpos + 1] > pq[childpos])
		childpos++;

	      // if value at position is larger than the
	      // larger child, then the value is in its
	      // propoer place; done;
	      if (pq[position] > pq[childpos])
		return;
	      else
		swap(pq[position],pq[childpos]); // swap value with larger child;
	    }
	  position = childpos; // 
	}
}


template <class T>
void PriorityQueue<T>::print_tree_aux(int pos, int level) const
{
  if (pq.empty())
    {
      cout << "empty" << endl;
      return;
    }

  // print level many dots followed by value at index pos;
  for (int i = 1; i <= level; i++)
    cout << ".";
  cout << pq[pos] << endl;;

  if (2*pos+1 >= pq.size())
    return; // value at pos is a leaf;

  print_tree_aux(2 * pos+ 1, level + 1); // print left subtree;
  
  if (2 * pos + 2 < pq.size())
    print_tree_aux(2 * pos + 2, level + 1); // print right subtree;
}

template <class T>
void print_vector(const vector<T>& vec)
{
	cout << endl;
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl << endl;
}
