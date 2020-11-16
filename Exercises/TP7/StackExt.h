# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
private:
	stack<T> st;
	stack<T> min_val;

public:
	StackExt() {};
	bool empty() const;
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};

template <class T>
bool StackExt<T>::empty() const {
	if (st.empty()) {
		return true;
	}
	return false;
}

template <class T>
T& StackExt<T>::top() {

	return st.top();
}

template <class T>
void StackExt<T>::pop() {
	if (st.top() == min_val.top()) {
		st.pop();
		min_val.pop();
	}
	else {
		st.pop();
	}
}

template <class T>
void StackExt<T>::push(const T& val) {
	if (min_val.empty()) {
		min_val.push(val);
		st.push(val);
	}

	else if (val <= min_val.top()) {
		min_val.push(val);
		st.push(val);
	}
	else {
		st.push(val);
	}
}

template <class T>
T& StackExt<T>::findMin() {

	return min_val.top();
}
