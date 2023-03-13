#ifndef __PROJ5_PRIORITY_QUEUE_HPP
#define __PROJ5_PRIORITY_QUEUE_HPP

#include "runtimeexcept.hpp"

class PriorityQueueEmptyException : public RuntimeException 
{
public:
	PriorityQueueEmptyException(const std::string & err) : RuntimeException(err) {}
};




template<typename Object>
class MyPriorityQueue
{
private:
	// fill in private member data here
	std::vector<Object> p_queue;
	size_t p_size;

public:

	// You also need a constructor and a destructor.
	MyPriorityQueue();
	~MyPriorityQueue();

 	size_t size() const noexcept;
	bool isEmpty() const noexcept;

	void insert(const Object & elem);


	// Note:  no non-const version of this one.  This is on purpose because
	// the interior contents should not be able to be modified due to the
	// heap property.  This isn't true of all priority queues but 
	// for this project, we will do this.
	// min and extractMin should throw PriorityQueueEmptyException if the queue is empty.
	const Object & min() const; 

	void extractMin(); 

};


template<typename Object>
MyPriorityQueue<Object>::MyPriorityQueue()
{
	this->p_size = 0;
}


template<typename Object>
MyPriorityQueue<Object>::~MyPriorityQueue()
{
	
}

template<typename Object>
size_t MyPriorityQueue<Object>::size() const noexcept
{
	return p_size;
}



template<typename Object>
bool MyPriorityQueue<Object>::isEmpty() const noexcept
{
	if(this->p_size == 0){
		return true;
	}
	return false;
}

template<typename Object>
void MyPriorityQueue<Object>::insert(const Object & elem) 
{
	p_queue.push_back(elem);
	p_size++;
	unsigned index = p_size-1;
	while(index > 0){
		unsigned par_index = (index - 1) / 2;
		if(p_queue[index] < p_queue[par_index]){
				std::swap(p_queue[index], p_queue[par_index]);
				index = par_index;
			}
		else{
			break;
		}
	}
}




template<typename Object>
const Object & MyPriorityQueue<Object>::min() const
{
	if(this->p_size == 0){
		throw PriorityQueueEmptyException("priority queue has no min. it is empty");
	}
	return p_queue[0];
}



template<typename Object>
void MyPriorityQueue<Object>::extractMin() 
{
	if(this->p_size == 0){
		throw PriorityQueueEmptyException("priority queue is empty");
	}
	// swap whats at root and pop that from the end of the vector then make a while loop that checks left and right (2i + 1 and 2i + 2 to make a comparison and swap)
	std::swap(p_queue[0], p_queue[this->p_size-1]);
	p_queue.pop_back();
	this->p_size --;
	int index = 0;
	int child = 2 * 0 + 1;
	Object val = this->p_queue[0];
	while(child < this->p_size){
		Object minValue = val;
		int minIndex = -1;
		for(int i = 0; i < 2 && i + child < p_size; i++){
			if(p_queue[i + child] < minValue){
				minValue = p_queue[i + child];
				minIndex = i + child;
			}
		}
		if(minValue == val){
			return;
		}
		else{
			std::swap(p_queue[index], p_queue[minIndex]);
			index = minIndex;
			child = 2 * index + 1;
		}
	}
}


#endif 
