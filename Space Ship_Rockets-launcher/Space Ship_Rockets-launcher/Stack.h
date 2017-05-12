#pragma once
/////////////////////////////////////////////////////////////////////////
template<typename T> class Node{
	/////////////////////////////////////////////////////////////////////
public:
	T info;
	//Node* next;
	Node* prev;
	/////////////////////////////////////////////////////////////////////
};
/////////////////////////////////////////////////////////////////////////
template<class type> class Stack{
	/////////////////////////////////////////////////////////////////////////
private:
	Node<type> *Top;
	unsigned int Size;
	/////////////////////////////////////////////////////////////////////
public:
	Stack<type>(){
		Top = nullptr;
		Size = 0;
	}
	/////////////////////////////////////////////////////////////////////
	void push(type obj){
		//
		Node<type>* tmpn = new Node<type>;
		tmpn->info = obj;
		//
		if (!this->Top)
		{
			tmpn->prev = nullptr;
			this->Top = tmpn;
		}
		else
		{
			tmpn->prev = this->Top;
			this->Top = tmpn;
		}
		this->Size++;
	}
	/////////////////////////////////////////////////////////////////////
	void push(type obj, int index){
		//
		Node<type>* tmpn = new Node<type>;
		tmpn->info = obj;
		//
		if (!this->Top)
		{
			tmpn->prev = nullptr;
			this->Top = tmpn;
		}
		else
		{
			Node<type>* target = this->Top;
			int i;
			for (i = (this->Size - 1) - index; i > 0; i--) target = target->prev;
			tmpn->prev = target->prev;
			target->prev = tmpn;
		}
		this->Size++;
	}
	/////////////////////////////////////////////////////////////////////
	void assign(type obj, int index){
		Node<type>* tmpn = this->Top;
		int i;
		for (i = (this->Size - 1) - index; i > 0; i--) tmpn = tmpn->prev;
		tmpn->info = obj;
	}
	/////////////////////////////////////////////////////////////////////
	void pop(){
		Node<type>* tmpn = this->Top;
		this->Top = this->Top->prev;
		delete tmpn;
		this->Size--;
	}
	/////////////////////////////////////////////////////////////////////
	type top(){
		return this->Top->info;
	}
	/////////////////////////////////////////////////////////////////////
	type at(unsigned int index)
	{
		Node<type>* tmpn = this->Top;
		unsigned int i;
		for (i = (this->Size - 1) - index; i > 0; i--) tmpn = tmpn->prev;
		return tmpn->info;
	}
	/////////////////////////////////////////////////////////////////////
	void swap(unsigned fromIndex, unsigned ToIndex){
		type tmp = this->at(ToIndex);
		this->assign(this->at(fromIndex), ToIndex);
		this->assign(tmp, fromIndex);
	}
	/////////////////////////////////////////////////////////////////////
	bool empty(){
		return (this->Top == nullptr);
	}
	/////////////////////////////////////////////////////////////////////
	unsigned int size(){
		return this->Size;
	}
	/////////////////////////////////////////////////////////////////////
	void remove(unsigned int index){
		Node<type>* before = this->Top;
		if (index == this->Size - 1){
			this->Top = this->Top->prev;
			delete before;
		}
		else
		{
			Node<type>* eraser;
			unsigned int i;
			for (i = (this->Size - 1) - index; i > 1; i--) before = before->prev;
			eraser = before->prev;
			before->prev = before->prev->prev;
			delete eraser;
		}
		this->Size--;
	}
	/////////////////////////////////////////////////////////////////////
	void clear(){
		while (this->Top){
			Node<type>* tmpn = this->Top;
			this->Top = this->Top->prev;
			delete tmpn;
		}
		this->Size = 0;
	}
	/////////////////////////////////////////////////////////////////////////
};
/////////////////////////////////////////////////////////////////////////
