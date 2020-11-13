# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
private:
    stack<T> _stack;
    stack<T> _stackMin;
public:
	StackExt();
	bool empty() const; 
	T &top();
	void pop();
	void push(const T & val);
	T &findMin();
};

template <class T>
StackExt<T>::StackExt() : _stack(stack<T>()), _stackMin(stack<T>()){}

template <class T> 
bool StackExt<T>::empty() const{
    return _stack.empty();
}

//a alterar
template <class T> 
T& StackExt<T>::top(){
    /*T *novo = new T();
    return *novo;*/
    return _stack.top();
}

//a alterar
template <class T> 
void StackExt<T>::pop(){
    if(_stack.top() == _stackMin.top()) _stackMin.pop();
    _stack.pop();
}

//a alterar
template <class T> 
void StackExt<T>::push(const T & val){
    if(_stack.empty() || val < _stackMin.top()) _stackMin.push(val);
    _stack.push(val);
}

//a alterar
template <class T> 
T& StackExt<T>::findMin(){
    return _stackMin.top();
}

