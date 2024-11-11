//
// Created by Mahmoud Elshafei on 10/26/2024.
//

#ifndef SLL_SINGLYLINKEDLIST_H
#define SLL_SINGLYLINKEDLIST_H

#endif //SLL_SINGLYLINKEDLIST_H

#include <iostream>

template<typename T>
class LinkedList {
    struct Node {
        T data{};
        Node *next{};

        Node(T data) : data(data), next(nullptr) {}
    };

    Node *head, *tail;

    void black_box_debugging() const { // o(1) time - o(1) memory
        if (!head && tail)
            throw std::runtime_error("head is null and tail is not null..\n");
        if (head && !tail)
            throw std::runtime_error("head is not null and tail is null..\n");
        if (tail && tail->next != nullptr)
            throw std::runtime_error("tail's next pointer not null..\n");
    }

    void printList(Node *cur) const { // o(n) time - o(n) memory
        if (!cur)
            return;
        std::cout << cur->data << ' ';
        printList(cur->next);
    }

    void clearList(Node *cur) { // o(n) time - o(n) memory
        if (!cur)
            return;
        clearList(cur->next);
        delete cur;
    }

public:
    LinkedList() : head(nullptr), tail(nullptr) {} // o(1) time - o(1) memory
    LinkedList(const LinkedList &other)  : head(nullptr), tail(nullptr) { // o(n) time - o(1) memory
        if (this != &other && other.head) {
            Node *cur = other.head;
            while (cur) {
                insert_back(cur->data);
                cur = cur->next;
            }
        }
        black_box_debugging();
    }
    LinkedList& operator=(const LinkedList &other) {
        if(this != &other) {
            clear();
            Node* cur = other.head;
            while(cur) {
                insert_back(cur->data);
                cur = cur->next;
            }
        }
        return *this;
    }
    void insert_front(T val) { // o(1) time - o(1) memory
        Node *newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        black_box_debugging();
    }

    void insert_back(T val) { // o(1) time - o(1) memory
        Node *newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        black_box_debugging();
    }

    T delete_front() { // o(1) time - o(1) memory
        if (!head)
            throw std::runtime_error("the list is empty..\n");
        Node *deleted = head;
        head = head->next;
        T val = deleted->data;
        delete deleted;
        black_box_debugging();
        return val;
    }

    void insert(T val, size_t idx) { // o(n) time - o(1) memory
        if (!idx)
            return insert_front(val), void();
        size_t length = 0;
        for (Node *cur = head, *prev = nullptr; cur; prev = cur, cur = cur->next) {
            if (idx == length++) {
                Node *newNode = new Node(val);
                newNode->next = cur;
                prev->next = newNode;
                black_box_debugging();
                return;
            }
        }
        if (idx == length)
            return insert_back(val), void();
        std::cerr << "index out of range..\n";
    }

    T remove(T val) { // o(n) time - o(1) memory
        if (!head)
            throw std::runtime_error("the list is empty..\n");
        if (head->data == val)
            return delete_front();
        Node *cur = head;
        Node *prev = nullptr;
        Node *deleted = nullptr;
        while (cur) {
            if (cur->data == val) {
                deleted = cur;
                cur = cur->next;
                prev->next = cur;
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        T ele = deleted->data;
        delete deleted;
        black_box_debugging();
        if (deleted != nullptr)
            return ele;
        else
            return std::cerr << "No Such Value..\n", T();
    }

    T middleElement() const { // o(n) time - o(1) memory
        if (!head)
            throw std::runtime_error("the list is empty..\n");
        Node *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->data;
    }

    void reverse() { // o(n) time - o(1) memory
        if (!head)
            throw std::runtime_error("the list is empty..\n");
        if(head == tail)
            return;
        tail = head;
        Node *prev = head;
        head = head->next;
        while (head) {
            Node *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;
        tail->next = nullptr;
        black_box_debugging();
    }

    size_t get_length() { // o(n) time - o(1) memory
        size_t length = 0;
        for (Node *cur = head; cur; length++, cur = cur->next) {}

        return length;
    }

    void clear() {
        clearList(head);
        head = tail = nullptr;
    }

    ~LinkedList() { // o(n) time - o(n) memory
        clearList(head);
        head = tail = nullptr;
    }

    void display() const { // o(n) time - o(n) memory
        if (!head)
            std::cerr << "the list is empty..\n";
        printList(head);
        std::cout << std::endl;
    }
};