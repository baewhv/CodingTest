#include <iostream>
#include <string>

using namespace std;

struct Node
{
    Node(int n) : data(n) {}
    ~Node() {}

    int data;
    Node* prev;
};

class Queue
{
public:
    void push(int n)
    {
        Node* N = new Node(n);
        if (_back == nullptr)
        {
            _front = N;
            _back = N;
        }
        else
        {
            _back->prev = N;
            _back = N;
        }
        _size++;
    }
    int pop()
    {
        if (_size == 0) return -1;

        Node* temp = _front;
        int num = temp->data;

        if (_back == _front)
        {
            _front = nullptr;
            _back = nullptr;
        }
        else _front = _front->prev;
        
        delete(temp);
        _size--;
        
        return num;
    }

    int size() { return _size; }
    int empty() { return _size == 0 ? 1 : 0; }
    int front()
    {
        if (_size == 0) return -1;
        return _front->data;
    }
    int back()
    {
        if (_size == 0) return -1;
        return _back->data;
    }
private:
    Node* _front = nullptr;
    Node* _back = nullptr;
    int _size = 0;
};

int main()
{
    int n, tempNum;
    cin >> n;
    Queue q;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if (temp == "push")
        {
            cin >> tempNum;
            q.push(tempNum);
        }
        else if (temp == "pop")
        {
            cout << q.pop() << '\n';
        }
        else if (temp == "size")
        {
            cout << q.size() << '\n';
        }
        else if (temp == "empty")
        {
            cout << q.empty() << '\n';
        }
        else if (temp == "front")
        {
            cout << q.front() << '\n';
        }
        else if (temp == "back")
        {
            cout << q.back() << '\n';
        }

    }

    return 0;
}