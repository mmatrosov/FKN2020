#include <iostream>
#include <stack>
#include <vector>

struct MinStackItem
{
    int value;
    int min;
};
/// Stack with O(1) min() queries
class MinStack
{
    std::stack<MinStackItem> items;

public:
    MinStack() {}

    bool empty() const { return items.empty(); }

    int min() const
    {
        if (empty())
        {
            std::cerr << "trying to find min, but stack is empty" << std::endl;
            abort();
        }
        return items.top().min;
    }

    void push(int value)
    {
        MinStackItem item;
        item.value = value;
        if (empty())
        {
            item.min = value;
        }
        else
        {
            MinStackItem const &prev_top = items.top();
            item.min = std::min(value, prev_top.min);
        }
        items.push(item);
    }

    int pop()
    {
        if (empty())
        {
            std::cerr << "trying to pop from empty stack" << std::endl;
            abort();
        }
        int x = items.top().value;
        items.pop();
        return x;
    }
};

/// Queue with O(1) min() queries
class MinQueue
{
    MinStack head;
    MinStack tail;
    void transfer()
    {
        while (!head.empty())
        {
            tail.push(head.pop());
        }
    }
    bool empty() const { return head.empty() && tail.empty(); }

public:
    MinQueue() {}

    int min() const
    {
        if (empty())
        {
            std::cerr << "trying to find min in empty queue" << std::endl;
            abort();
        }
        if (head.empty())
        {
            return tail.min();
        }
        if (tail.empty())
        {
            return head.min();
        }
        return std::min(head.min(), tail.min());
    }

    void push(int val) { head.push(val); }

    void pop()
    {
        if (empty())
        {
            std::cerr << "trying to pop from empty queue" << std::endl;
            abort();
        }
        if (tail.empty())
        {
            transfer();
        }
        tail.pop();
    }
};

int main()
{
    size_t n, k;
    std::cin >> n >> k;
    std::vector<int> data(n);
    for (int &x : data)
    {
        std::cin >> x;
    }
    MinQueue q;
    for (size_t i = 0; i < k; ++i)
    {
        q.push(data[i]);
    }
    std::cout << q.min() << "\n";
    for (size_t i = k; i < n; ++i)
    {
        q.push(data[i]);
        q.pop();
        std::cout << q.min() << "\n";
    }
}