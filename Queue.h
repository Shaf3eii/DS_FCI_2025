

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <iostream>

template <typename T>
class Queue {
    struct Node {
        T data { };
        Node* next = nullptr;
        Node() = default;
        Node(T data) : data(data) {};
    };

    Node* head{ };
    Node* tail{ };
    size_t length { };

public:
    Queue() = default; // O(1) time - O(1) memory
    Queue(T val) { // O(1) time - O(1) memory
        Node* newNode = new Node(val);
        head = tail = newNode;
        length++;
    }
    ~Queue() { // O(1) time - O(1) memory
        Node *cur = head;
        while(cur)
        {
            Node* deleted = cur;
            cur = cur->next;
            delete deleted;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }


    void enqueue(T val) { // O(1) time - O(1) memory
        Node* new_node = new Node(val);
        if(!length)
        {
            head = tail = new_node;
            length++;
            return;
        }
        tail->next = new_node;
        tail = new_node;
        tail->next = nullptr;
        length++;
    }

    T dequeue() { // O(1) time - O(1) memory
        if(is_Empty())
            throw std::out_of_range("The Queue is Empty.\n");
        Node* deleted = head;
        head = head->next;
        if (not head)
            tail = nullptr;
        length--;
        T ret = deleted->data;
        delete deleted;
        return ret;
    }

    bool is_Empty() const { // O(1) time - O(1) memory
        return not length;
    }

    size_t size() const { // O(1) time - O(1) memory
        return length;
    }

    void print() const { // O(n) time - O(1) memory
        for(Node* cur = head ; cur ; cur = cur->next)
            std::cout << cur->data << " \n"[cur->next == nullptr];
    }

    T front() const { // O(1) time - O(1) memory
        if(is_Empty())
            throw std::out_of_range("The Queue is Empty.\n");
        return head->data;
    }
};



#endif //QUEUE_QUEUE_H
