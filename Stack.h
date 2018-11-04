#include<cstring>
#include<malloc.h>
#include<iostream>

using namespace std;

#define STACK_ADD_LEN 50
#define STACK_MAX_LEN 10000

template <class T>
class Stack {
	public:
		Stack();
		void ShowStack();
		bool FullStack();
		bool EmptyStack();
		bool ClearStack();
		bool Push(T item);
		void addStackLength();
		bool isSame(T item);
		int Size();
		T Pop();
		T Top();
	private:
	 	T *stack;
	 	int stackLength;
	 	int stackSize;
};

template <class T>
Stack<T>::Stack(){
	stackSize = 50;
	stack = new T[stackSize];
	stackLength = 0;
}

template <class T>
bool Stack<T>::FullStack(){
	return stackSize == STACK_MAX_LEN ? true : false;
}

template <class T>
bool Stack<T>::EmptyStack(){
	return stackLength == 0 ? true : false;	
}

template <class T>
int Stack<T>::Size(){
	return stackLength;
}

template <class T>
void Stack<T>::addStackLength(){
	T *tmp = new T[STACK_ADD_LEN + stackSize];
	for(int i = 1; i <= stackLength; i++){
		tmp[i] = stack[i];	
	}
	stack = tmp;	
	stackSize += STACK_ADD_LEN;
}

template<class T>
bool Stack<T>::Push(T item){
	if(stackLength + 1 > stackSize && stackSize <= STACK_MAX_LEN)
		addStackLength();
	else if(stackLength + 1 > STACK_MAX_LEN)
		return false;
	stackLength++;
	stack[stackLength] = item;
	return true;
}

template<class T>
T Stack<T>::Pop(){
	if(stackLength > 0)
		return stack[stackLength--];
}

template<class T>
T Stack<T>:: Top(){
	if(stackLength > 0)
		return stack[stackLength];
}

template<class T>
bool Stack<T>::isSame(T item){
	for(int i = 0; i < stackLength; i++){
		if(stack[i] == item)
			return true;
	}
	return false;
}

template<class T>
void Stack<T>::ShowStack(){
	for(int i = stackLength; i > 0; i--){
		cout << stack[i];
		std::cout << std::endl;
	}
}

template<class T>
bool Stack<T>::ClearStack(){
	while(stackLength)
		Pop();
	Stack();
	return true;
}