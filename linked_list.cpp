/*
Regardless of any data structures that we use, all data structures are expected to carry out:
- Access and read values
- Search for an arbitrary values
- Insert values at any point into the structure
- Delete values in the structure

Array is bad at insert and delete.

Linked list: linear data structure where each element in the list is contained a separate object called a node. 
Each node contains two fields: a data field to store the element and a reference field to store the address of the next node.
- First node: head, last node: tail
- Nodes are called self referential objects
- There are two kind of linked list: singly linked list and doubly linked list.
    + Singly linked list: each node has a reference to the next node in the sequence.
    + Doubly linked list: each node has a reference to the next and previous node in the sequence.

A linked list is called a dynamic data structure because it can be used with a data collection that grows and shrinks during program 
execution. The major advantage of using linked list over arrays is in implementing any data structure like stack or queue.

*Note: not many place we can use linked list in real life
*/

//single linked list
#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr){}

    //method to represent node as a string
    std::string to_Str ()
    {
        return "Node value: " + std::to_string(data);
    }
};


class LinkedList {
    //singly linked list
    //a common operation to the data structure is to check if the data structure contains any data
public:
    Node* head;
    LinkedList() : head(nullptr){}

    bool is_empty() {
        return head == nullptr;
    }
    
    //not like default method size()/len(), we have to loop through the list to count the number of nodes --> O(n)
    int  size() 
    {
        //return the number of nodes in the linked list
        int count = 0;
        Node* current = head; //reference to the head node
        while (current != nullptr)
        {
            count++; //increment the count every time we visit a node until we hit the tail
            current = current->next;
        }
        return count;
    }

    //add data to the linked list, inserting data into the linked list is more efficient than array
    //but if we want to insert at the tail--> need reference to the tail node, ortherwise we have to start at the head and walk down the length/size of the linked list to find the tail
    //this method will accept some dataadded to the list inside of a node
    //this is just reassign the new_node to th head--> constant time O(1)
    void addToHead(int data) //prepend
    {
        //create a new node
        Node* new_node = new Node(data);

        //before setting the new_node as the head, we need to point the new_node to whatever at head--> so we don't lose any reference of the linked list
        //e.g:new_node(5) -------->[old linked list]N1-->N2-->...
        new_node->next = head;

        //if there is no node at the head --> this will set next_node to nullptr
        //so we have to have the line below: set new_node as the head
        head = new_node;
    }

    //search for the first node contains the key data in the linked list
    //check if the data on that node matches the key
    //take O(n) time complexity
    Node* search(int key)
    {
        Node* current = head;

        while (current != nullptr)
        {
            if(current->data == key)
            {
                return current;
            } else {
                current = current->next;
            }
        }
        return nullptr;
    }

    //insert at specific position
    //unlike array when we insert we have to move all index after the inserted data to the right
    //in linked list, we just have to change the reference of the previous node to the new node and the new node to the next node
    //take O(1) constant time complexity because we just need to change the reference
    //while insering is fast, finding the position we want to insert is not (linear time)
    void insert (int data, int index)
    {
        //even though linked list don't have index position, we can mimic that behavior by just counting the number of times we access next node
        //insert a new node containing data at index position
        //-->e.g: if we passed into index = 0, we want to insert the new node at the head of the list
        if (index == 0)
        {
            addToHead(data);
            return;
        }
        //if index > 0, we have to walk down the list to find the current node at the index position
        if (index > 0)
        {
            //creat new node that we want to insert data into
            Node* new_node = new Node(data);
            int position = index;
            Node* current = head;

            //every time we move to the next node, we will decrease the position by 1-->when position = 0, we found the node at the position we want to insert
            //but we don't want to insert the new node at the position, we want to insert it before the position
            while (position > 1)
            {
                current = current->next;
                position--;
                //when the loop exit, current will refer to the node at the position before the insert point
            }
            Node* prev = current;
            Node* next_node = current->next;

            //insert bewteen prev and next_node
            prev->next = new_node;
            new_node->next = next_node;

            /*
            prev = 2, next_node = 3
            prev->next = new_node = 9 => 2 --> 9
            new_node->next = next_node = 3 => 2 --> 9 --> 3

            1 2       3 4 5

            1 2   9   3 4 5

            want to put 9 in index=2
            */
        }
    }

    //for remove we have 2 ways to do: remove by key or remove by index
    //remove the node containing data that matches the key
    //take O(n) time complexity
    Node* remove_key(int key)
    {
        Node* current = head;

        //keep track of the previous node as we walk down the list
        Node* previous = nullptr;

        //serve as a stopping condition
        bool found = false;

        //when the current = nullptr, we've gone past the tail and we haven't found the key
        //when we find the key, we set found = true
        //we need both conditions to run --> when 1 condition evaluate to false, terminate the loop
        while (current != nullptr && found == false)
        {
            //3 situations that we can run into

            //key matches the current node's data and the current node is the head-->special because the head don't have previous node. this is the only node being referneced by the list
            if (current->data == key && current == head)
            {
                found == true;

                //remove the current node by setting the head to the next node
                //This operation updates the head of the linked list to point to the next node after the current node. It effectively removes the current head node from the list and makes the next node the new head.
                head == current->next;
            } else if (current->data == key) // current node contains the key that not the head
            {
                //to remove the current node, we need to go to the previous node and  modify its reference to point to the node after current
                found = true;
                previous->next = current->next;
                /*
                1 2    3     4 5 
                1 2          4 5
                previous = 2, current = 3
                previous-> next = current->next = 4
                */
            } else {
                //this mean the current node we are evaluating doesn't contain data that matches the key
                previous = current;
                current = current->next;
            }

        }
        //return the value being removed
        return current;
    }
};  
#endif

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