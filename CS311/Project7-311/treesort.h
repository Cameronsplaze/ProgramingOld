// treesort.h
//Cameron Showalter

// Glenn G. Chappell
// 15 Nov 2016
//
// For CS 311 Fall 2016
// Header for function template treesort
// There is no associated source file.

#ifndef FILE_TREESORT_H_INCLUDED
#define FILE_TREESORT_H_INCLUDED

#include <type_traits>
using std::remove_reference;
#include <algorithm>
using std::stable_sort;
using std::copy;
#include <vector>
using std::vector;
#include <iterator>
using std::distance;

#include <memory>
using std::shared_ptr;
using std::make_shared;


// Class Invariants:
//		data = Value
//		left == nullptr || left points to another node
//		right == nullptr || right points to another node
// Requirements on type:
//		copy ctor
template<typename Value>
class BTNode
{
public:
	Value data;
	shared_ptr<BTNode> left;
	shared_ptr<BTNode> right;
public:
	explicit BTNode(Value & d):data(d),left(nullptr),right(nullptr)
	{

	}

	~BTNode() = default;
	BTNode(BTNode && copy) = delete;
	BTNode(const BTNode & copy) = delete;
	BTNode operator=(BTNode && copy) = delete;
    BTNode operator=(const BTNode & copy) = delete;

};

// Pre:
//		n/a
// Post:
//		iter = curr->data
// 		++iter
// Requirements on Types:
//      Value has operator< and copy assignment operator
//		T has operator* and pre-increment operator
// Safety guarantee:
// 		No-Throw Guarantee
template<typename Value,typename T>
void inOrderTraverse(shared_ptr<BTNode<Value> > curr, T & iter)

{
	if (curr->left)
	{
		inOrderTraverse(curr->left,iter);
	}

	*iter++ = curr->data;
	if (curr->right)
	{
		inOrderTraverse(curr->right,iter);
	}
}

// Pre:
//		n/a
// Post:
//		new node in BST at appropriate place
// Safety guarantee:
// 		Strong Guarantee
// Throws:
//		make_shared may throw bad_malloc
template<typename Value>
void addNode(shared_ptr<BTNode<Value> > & curr, Value & v)
{
	if (!curr)
	{
		curr = make_shared<BTNode<Value> >(v);
		return;
	}

	if (v < curr->data)
	{
		if (curr->left)
		{
			addNode(curr->left,v);
		}
		else
		{
			curr->left = make_shared<BTNode<Value> >(v);
			return;
		}
	}
	else
	{
		if (curr->right)
		{
			addNode(curr->right,v);
		}
		else
		{
			curr->right = make_shared<BTNode<Value> >(v);
			return;
		}
	}
}

// Pre:
//		n/a
// Post:
//		data from begin to end is sorted
// Requirements on Types:
//		T has operator* and pre-increment operator
//      *T has operator< and copy assignment operator
// Safety guarantee:
//		Strong Guarantee
template<typename T>
void treesort(T begin, T end)
{
	if (begin == end)
	{
		return;
	}
    using Value = typename remove_reference< decltype(*begin )>::type;
	shared_ptr< BTNode<Value> > head;

	T tempValue = begin;
    while ( tempValue != end )
    {
    	addNode<Value>( head,*tempValue );
    	++tempValue;
    }
    inOrderTraverse<Value,T>( head,begin );
}
#endif //#ifndef FILE_TREESORT_H_INCLUDED

