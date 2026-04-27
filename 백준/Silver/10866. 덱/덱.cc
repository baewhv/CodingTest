#include <iostream>

using namespace std;

struct Node
{
    Node(int n) : data(n) {}
    ~Node(){}
    
    int data = 0;
    Node* prev = nullptr;
    Node* next = nullptr;
};

class Deque
{
public:
    void push_front(int n)
    {
        Node* N = new Node(n);
        if(_size == 0)
        {
            _front = N;
            _back = N;
        }
        else
        {
            N->prev = _front;
            _front->next = N;
            _front = N;
        }
        _size++;
    }
    void push_back(int n)
    {
        Node* N = new Node(n);
        if(_size == 0)
        {
            _front = N;
            _back = N;
        }
        else
        {
            N->next = _back;
            _back->prev = N;
            _back = N;
        }
        _size++;
    }
    int pop_front()
    {
        if(_size == 0) return -1;
        Node* temp = _front;
        int tempN = temp->data;
        if(_size - 1 == 0)
        {
            _front = nullptr;
            _back = nullptr;
        }
        else
        {
            _front->prev->next = nullptr;
            _front = _front->prev;    
        }
        delete(temp);
        _size--;
        return tempN;
    }
    int pop_back()
    {
        if(_size == 0) return -1;
        Node* temp = _back;
        int tempN = temp->data;
        if(_size -1 == 0)
        {
            _front = nullptr;
            _back = nullptr;
        }
        else
        {
            _back->next->prev = nullptr;
            _back = _back->next;
        }
        delete(temp);
        _size--;
        return tempN;
    }
    int size()  { return _size; }
    int empty() { return _size == 0 ? 1 : 0; }
    int front() { return _size == 0 ? -1 : _front->data; }
    int back()  { return _size == 0 ? -1 : _back->data; }
    
private:
    int _size = 0;
    Node* _front = nullptr;
    Node* _back = nullptr;
};

int main()
{
    int n, tempNum;
    cin >> n;
    Deque dq;
    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if(temp == "push_front")
        {
            cin >> tempNum;
            dq.push_front(tempNum);
        }
        else if(temp == "push_back")
        {
            cin >> tempNum;
            dq.push_back(tempNum);
        }
        else if(temp == "pop_front") cout << dq.pop_front() << '\n';
        else if(temp == "pop_back") cout << dq.pop_back() << '\n';
        else if(temp == "size") cout << dq.size() << '\n';
        else if(temp == "empty") cout << dq.empty() << '\n';
        else if(temp == "front") cout << dq.front() << '\n';
        else if(temp == "back") cout << dq.back() << '\n';
    }
    return 0;
}