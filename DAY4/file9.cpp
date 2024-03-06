#include <iostream>
using namespace std;
#define line(msg) cout << "----------------------" #msg "----------------\n"

// Implementing Stack data structure.
/* Template bloating is when a function is made again and again even though they are not of the template type.
All those that donot use the template factor are called bloating factors.
Corrected Code
*/
class BaseStack
{
protected:
    BaseStack() = default;
    int top = -1;

public:
    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == 4;
    }
};

template <typename T>
class Stack : public BaseStack
{
    T arr[5];
    // int size;
public:
    void push(T val)
    {
        arr[++top] = val;
    }

    T pop()
    {
        return arr[top--];
    }
    T peek()
    {
        return arr[top];
    }
};
int main()
{
    Stack<int> st1;
    st1.push(10);
    st1.pop();
    st1.peek();
    st1.isEmpty();
    st1.isFull();
    line();
    Stack<double> st2;
    st2.push(3.01);
    st2.pop();
    st2.peek();
    st2.isEmpty();
    st2.isFull();
    line();
    Stack<float> st3;
    st3.push(3.01f);
    st3.pop();
    st3.peek();
    st3.isEmpty();
    st3.isFull();
    return 0;
}