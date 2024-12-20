
#ifndef STACK_STACK_H
#define STACK_STACK_H

#endif //STACK_STACK_H

#include <iostream>

template<typename T>
class Stack {
    struct Node {
        T data{};
        Node *next{};

        Node(T data) : data(data), next(nullptr) {}
    };

    Node *head{};
    size_t length{};

public:
    Stack() = default; // O(1) time - O(1) memory
    Stack(T val) {  // O(1) time - O(1) memory
        Node* newNode = new Node(val);
        head = newNode;
        length++;
    }

    ~Stack() { // O(n) time - O(1) memory
        while(head)
        {
            Node* deleted = head;
            head = head->next;
            delete deleted;
        }
    }

    void push(T val) { // O(1) time - O(1) memory
        Node *new_node = new Node(val);
        new_node->next = head;
        head = new_node;
        length++;
    }

    T pop() {  // O(1) time - O(1) memory
        if (isEmpty())
            throw std::runtime_error("Stack is empty. Cannot pop.");

        T data = head->data;
        Node *deleted = head;
        head = head->next;
        length--;
        delete deleted;
        return data;
    }

    T top() {  // O(1) time - O(1) memory
        if (isEmpty())
            throw std::runtime_error("Stack is empty. Cannot peek.");

        return head->data;
    }

    bool isEmpty() const { // O(1) time - O(1) memory
        return not head;
    }

    size_t getSize() const {  // O(1) time - O(1) memory
        return length;
    }

    void print() const { // O(n) time - O(1) memory
        for (Node *cur = head; cur; cur = cur->next)
            std::cout << cur->data << " \n"[cur->next == nullptr];
    }

};