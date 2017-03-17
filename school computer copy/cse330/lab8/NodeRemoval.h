// not ot be used as is ...
// this code is to be inserted into file Set.h of Lab8


template <class T>
Node<T>* Node<T>::remove(T& x)
{
	//cout << endl;
	//cout << "removing " << x << " from Node:" << value << endl;

	if (value == x)
	{
		// node holds value, no left or right child; 
		// node elimintes itself; result is pointer to null
		if (leftChild == 0 && rightChild == 0)
		{
			delete this;
			return 0;
		}
		
		// left and/or right children exist; with node itself to go
		// return result of merging left and right subtree;
		return merge(leftChild, rightChild);
	}

	if (x < value)
	{
		// x is smaller than value at node,  but node has no left subtree;
		// x is not stored under this node; return without change to node
		// and its subtrees;
		if (leftChild == 0)
			return this;

		// remove x from left subtree of node; set leftChild to the resulting
		// new left subtree and hook it up to this node as its parent;
		Node<T> * newleft = leftChild->remove(x);

		leftChild = newleft; 
		if (newleft != 0)
			leftChild->parent = this;
		
		
	}
	else
	{
		// x > value; with missing right child, x is not stored under this node;
		// no change; return this node;
		if (rightChild == 0)
			return this;
		
		// remove x from right subtree of node; set rightChild to the resulting
		// new right subtree and hook it up to this node as its parent;
		Node<T> * newright = rightChild->remove(x);
		rightChild = newright;

		if (newright != 0)
			rightChild->parent = this;
	}
	return this;
}


/* merge two subtrees, rooted in left and right, respectively, 
 into a single one with binary search tree properties; 
 assumption: left and right subtrees are rooted in children of the same node;
 every value in left is smaller than every value in right; 
 
 left        *                   right +
            / \                       / \
	   / L \                     / R \
	   -----  --> attach here ->*----- 
                                   / \
                                  / L \
				  -----

  do how? -- slide down leftmost in right subtree (with larger values), and attach
             left subtree (all values smaller) to leftmost, bottom-most and thus
             smallest value in right subtree;
*/

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
