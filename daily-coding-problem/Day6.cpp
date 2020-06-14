#include <iostream>
#include <stdexcept>

using namespace std
struct Node
Node* XOR(Node* prev, Node* next) {
    return (Node *)((uintptr_t)(prev) ^ (uintptr_t)(next));
}

struct Node {
    int data;
    Node* npx;
    Node(int data, Node* prev, Node * next): data(data), npx(XOR(prev, next))
    {

    }
    
    Node * GetNext(Node * prev)
    {
        return XOR(prev, npx);
    }
    };


void Add(Node * &head, int data) { 
    if (head == nullptr) { 
        head = new Node(data, nullptr, nullptr); 
    }
    else {
                Node * prev = nullptr
		Node * cur = head; 
        Node * next = XOR(prev, cur->npx); 
        while (next != nullptr) { 
            prev = cur;
            cur = next;
            next = XOR(prev, cur->npx);
        }

        Node * newNode = new Node(data, cur, nullptr); 
                                                       
        cur->npx = XOR(prev, newNode); 
                                       
    }
}


int Get(int index, Node* cur) {
    Node * prev = nullptr; 
    while (index && 
            cur != nullptr) { 
        Node * next =  XOR(prev, cur->npx); 
        prev = cur; 
        cur = next;
        index--; 
    }
    if (index != 0) 
    {
        throw std::out_of_range("index out of range");
    }
    return cur->data;
}


int main()
{
    Node* head = nullptr; 

    Add(head, 10); 
    Add(head, 2);
    Add(head, 42); 
    cout << Get(0, head) << '\n'; 
    cout << Get(1, head) << '\n';
    cout << Get(2, head) << '\n';

return 0;