//da6.h
//Cameron Showalter
//CS 311
// 11-15-16

#ifndef DA6_H_INCLUDED
#define DA6_H_INCLUDED

#include "llnode.h"
#include <iostream>
#include <cstddef>   //for std::size_t
using std::pair;
using std::make_pair;


//----Exercise A----

//Pre:
//    n/a
//Post:
//    basically makes all pointers point backwards,
//    head now points to "last" element, now first
//Requirements on type:
//    default ctor
//No-Throw  Guarantee

template<typename T>
void reverseList(shared_ptr<LLNode<T> > & head)
{
    if(head == nullptr) return;

    shared_ptr<LLNode<T> > prev;
    shared_ptr<LLNode<T> > curr;
    shared_ptr<LLNode<T> > next;
    prev = nullptr;
    curr = head;
    next = curr -> _next;

    while(true)
    {
        curr -> _next = prev;
        prev = curr;
        curr = next;

        if(curr == nullptr)
        {
            head = prev;
            return;
        }
        next = curr->_next;
    }
}

//----Exercise B----

//Class Invariants:
//    info_ points to front of queue
//    curr_ points to back of queue
//    size_ >= 0
//Requirements on type:
//    copy constructor

template<typename T>
class SLQueue
{
public:

    //Pre:
    //    n/a
    //Post:
    //    size_ = 0
    //    info_ = nullptr
    //    curr_ = info_
    //No-Throw Guarantee
    SLQueue():info_(nullptr),size_(0)
    {
        curr_ = info_;
    }

public:
    ~SLQueue() = default;
    SLQueue(const SLQueue & copy) = delete;
    SLQueue(SLQueue && copy) = delete;
    SLQueue operator=(const SLQueue & copy) = delete;
    SLQueue operator=(SLQueue && copy) = delete;

    //Pre:
    //	n/a
    //Post:
    //    returns true if "first" element is nullptr
    //No-Throw Guarantee
    bool empty()
    {
        return info_ == nullptr;
    }
    bool empty() const
    {
        return info_ == nullptr;
    }

    //Pre:
    //    n/a
    //Post:
    //    returns size of queue
    //No-Throw Guarantee
    std::size_t size()
    {
        return size_;
    }
    std::size_t size() const
    {
        return size_;
    }


    //Pre:
    //    info_ != nullptr
    //Post:
    //    returns data of first node
    //No-Throw Guarantee

    T & front()
    {
        return info_->_data;
    }
    T & front() const
    {
        return info_->_data;
    }

    //Pre:
    //    n/a
    //Post:
    //    node with data item is at back of queue
    //    curr_ points to back of queue
    //    size_++
    //Strong Guarantee
    //Throw:
    //    make_shared may throw bad_alloc
    void push(const T & item)
    {
        shared_ptr<LLNode<T> > valptr = make_shared<LLNode<T> >(item);
        if (info_)
        {
            curr_->_next = valptr;
            curr_ = curr_->_next;
        }
        else
        {
            info_ = valptr;
            curr_ = info_;
        }
        size_++;
    }

    //Pre:
    //    n/a
    //Post:
    //    info_ points to node after head
    //    size_--
    //No Throw Guarantee
	void pop()
	{
		if (info_)
		{
			info_ = info_->_next;
			--size_;
		}
	}

private:
	shared_ptr<LLNode<T> > info_;
	shared_ptr<LLNode<T> > curr_;
	size_t size_;
};

//----Exercise C----

    //Class Invariants:
    //    map_ is either nullptr for map of size 0 or points to
    //        first node of the map
    //    curr_ points to last inserted key-value pair
    //    size_ >= 0 and represents number of nodes in map
    //Requirements on type:
    //    copy constructors
    //    == for P
    //    & for T

template<typename P, typename T>
class SLMap
{
public:

    //Pre:
    //    n/a
    //Post:
    //    map_ = nullptr
    //    curr_ = map_
    //    size_ = 0
    //No-Throw  Guarantee
	SLMap():map_(nullptr),size_(0)
	{
		curr_ = map_;
	}

	~SLMap() = default;
	SLMap(const SLMap & copy) = delete;
	SLMap(SLMap && copy) = delete;
	SLMap operator=(const SLMap & copy) = delete;
	SLMap operator=(SLMap && copy) = delete;

    //Pre:
    //    n/a
    //Post:
    //    returns true if no nodes in map_ otherwise returns false
    //No-Throw  Guarantee
	bool empty()
	{
		return map_ == nullptr;
	}
	bool empty() const
	{
		return map_ == nullptr;
	}

    //Pre:
    //	n/a
    //Post:
    //	return size_
    //No-Throw  Guarantee
	size_t size()
	{
		return size_;
	}
	size_t size() const
	{
		return size_;
	}

    //Pre:
    //	n/a
    //Post:
    //	returns the reference to value of the node
    //    with the given key 'k'
    //No-Throw  Guarantee
	const T * find(const P & k) const
	{
		shared_ptr<LLNode<pair<P,T> > > curr;
		for (curr = map_; curr; curr = curr->_next)
		{
			if (curr->_data.first == k)
			{
				return &(curr->_data.second);
			}
		}
		//else
		return nullptr;
	}
	T * find(const P & k)
	{
		shared_ptr<LLNode<pair<P,T> > > curr;
		for (curr = map_; curr; curr = curr->_next)
		{
			if (curr->_data.first == k)
			{
				return &(curr->_data.second);
			}
		}
		//else
		return nullptr;
	}

    //Pre:
    //    n/a
    //Post:
    //    inserts node with std::pair(k,d) at curr_->_next
    //    size_++
    //Strong Guarantee
    //Throw:
    //    make_shared can throw bad_alloc
	void insert(const P & k, const T & d)
	{
		if (!curr_)
		{
			map_ = make_shared<LLNode<pair<P,T> > >(make_pair(k,d));
			curr_ = map_;
		}
		else
		{
			curr_->_next = make_shared<LLNode<pair<P,T> > >(make_pair(k,d));
			curr_ = curr_->_next;
		}
		++size_;
	}

    //Pre:
    //    n/a
    //Post:
    //    removes node with key k
    //No-Throw  Guarantee
	void remove(const P & k)
	{
		shared_ptr<LLNode<pair<P,T> > > curr = map_;

		if (curr->_data.first == k)
		{
			map_ = map_->_next;
			--size_;
			return;
		}
		while (curr->_next)
		{
			if (curr->_next->_data.first == k)
			{
				curr->_next = curr->_next->_next;
				--size_;
				return;
			}
			curr = curr->_next;
		}
	}

    //Pre:
    //    n/a
    //Post:
    //    f is called on all key-value pairs in the map
    //Strong Guarantee
    //Throws:
    //    throws if f throws
	void traverse(std::function<void(P,T)> f)
	{
		shared_ptr<LLNode<pair<P,T> > > curr = map_;

		while (curr)
		{
			f(curr->_data.first,curr->_data.second);
			curr = curr->_next;
		}
	}
private:
	shared_ptr<LLNode<pair<P,T> > > map_;
	shared_ptr<LLNode<pair<P,T> > > curr_;
	size_t size_;

};




#endif // DA6_H_INCLUDED
