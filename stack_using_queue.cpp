// 22-04-2024
// Leetcode
// Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

// Implement the MyStack class:

//     void push(int x) Pushes element x to the top of the stack.
//     int pop() Removes the element on the top of the stack and returns it.
//     int top() Returns the element on the top of the stack.
//     boolean empty() Returns true if the stack is empty, false otherwise.

// Notes:

//     You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
//     Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

class MyStack
{
public:
    queue<int> que;

    MyStack()
    {
    }

    void push(int x)
    {
        que.push(x);
        int n = que.size();

        for (int i = 0; i < n - 1; i++)
        {
            que.push(que.front());
            que.pop();
        }
    }

    int pop()
    {
        int result = que.front();
        que.pop();

        return result;
    }

    int top()
    {
        return que.front();
    }

    bool empty()
    {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */