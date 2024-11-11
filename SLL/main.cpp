#include "SinglyLinkedList.h"


int main() {
    LinkedList<int> list;
    list.insert_front(4);
    list.insert_front(1);
    list.insert_back(6);
    list.insert_back(7);
    list.insert(5,2);
    list.insert(3,3);
    list.insert_back(8);
    list.insert_back(9);
    list.display();
    std::cout << "list length: " << list.get_length() << std::endl;
    int ele = list.middleElement();
    std::cout << "middle element: " << ele << std::endl;
    list.display();
    list.reverse();
    list.display();
    return 0;
}
