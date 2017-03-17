/** Specification and Interface for a Stack as a generic ADT
*/
template<typename T> class istack
{
  public:
	virtual void pop()=0;
	virtual void push(T item)=0;
	virtual bool empty() const=0;
	virtual T top() const=0;
};

