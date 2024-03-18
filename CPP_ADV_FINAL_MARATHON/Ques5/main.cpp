#include "Stack.hpp"

int main()
{
    Stack<int, 5> st;
    cout << st.isEmpty() << "\n";
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);
    st.Push(50);

    cout << st.Peek() << "\n";
    cout << st.isFull() << "\n";
    cout << st.Pop() << "\n";
    cout << st.Pop() << "\n";
    line();
    Stack<float, 5> stk;
    stk.Push(10.01f);
    stk.Push(20.02f);
    stk.Push(30.03f);
    stk.Push(40.04f);
    stk.Push(50.05f);

    cout << stk.Peek() << "\n";
    cout << stk.Pop() << "\n";
    cout << stk.Pop() << "\n";
    line();

    Stack<float *, 5> stk1;
    float f1 = 10.01f;
    float f2 = 20.02f;
    float f3 = 30.03f;
    float f4 = 40.04f;
    float f5 = 50.05f;
    stk1.Push(&f1);
    stk1.Push(&f2);
    stk1.Push(&f3);
    stk1.Push(&f4);
    stk1.Push(&f5);

    cout << stk1.Peek() << "\n";
    cout << stk1.Pop() << "\n";
    cout << stk1.Pop() << "\n";

    return 0;
}