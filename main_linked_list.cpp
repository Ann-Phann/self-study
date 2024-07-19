#include "linked_list.cpp"
#include <iostream>

int main(void)
{
    //check if we can create a node and access the data
    Node* N1 = new Node(10); // Equivalent to N1 = Node(10) in Python
    Node* N2 = new Node(20); // Equivalent to N2 = Node(20) in Python

    N1->next = N2;
    std::cout << "Create a node, link N1-->N2: " <<N1->next->to_Str() << std::endl; 

    //check if we can create a linked list and access the head node
    LinkedList* list = new LinkedList();
    list->head = N1;
    std::cout << "See the size of link list" <<list->size() << std::endl;
    for (Node* current = list->head; current != nullptr; current = current->next)
    {
        std::cout << "Create link list: " << current->to_Str() << std::endl;
    }

    //check if we can add a node to the head of the linked list
    list->addToHead(5);
    std::cout << "Size after using add method: " << list->size() << std::endl;
    for (Node* current = list->head; current != nullptr; current = current->next)
    {
        std::cout << "Data after using add: " << current->to_Str() << std::endl;
    }

    //check if we can search for a node in the linked list
    Node* search_result = list->search(10);
    if (search_result != nullptr)
    {
        std::cout << "Search result: " << search_result->to_Str() << std::endl;
    } else {
        std::cout << "Search result: " << "Not found" << std::endl;
    }

    //check if we can insert a node at a specific position in the linked list
    list->insert(9, 2);
    std::cout << "Size after using insert method: " << list->size() << std::endl;
    for (Node* current = list->head; current != nullptr; current = current->next)
    {
        std::cout << "Data after using insert: " << current->to_Str() << std::endl;
    }
    // Clean up the allocated memory
    delete N1;
    delete N2;
    delete list;

    return 0;
}