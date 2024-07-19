// linkedlist_merge_sort.cpp
#include "linked_list.cpp"  // Make sure to include the file with the LinkedList and Node classes

LinkedList merge_sort(LinkedList& linked_list);
void split(LinkedList& linked_list, LinkedList& left_half, LinkedList& right_half);
LinkedList merge(LinkedList& left, LinkedList& right);

LinkedList merge_sort(LinkedList& linked_list) {
    if (linked_list.size() <= 1) {
        return linked_list;
    }

    LinkedList left_half;
    LinkedList right_half;
    split(linked_list, left_half, right_half);

    LinkedList left = merge_sort(left_half);
    LinkedList right = merge_sort(right_half);

    return merge(left, right);
}

void split(LinkedList& linked_list, LinkedList& left_half, LinkedList& right_half) {
    int size = linked_list.size();
    int mid = size / 2;

    Node* mid_node = linked_list.node_at_index(mid - 1);

    left_half.head = linked_list.head;
    right_half.head = mid_node->next;
    mid_node->next = nullptr;
}

LinkedList merge(LinkedList& left, LinkedList& right) {
    LinkedList merged;

    Node* left_head = left.head;
    Node* right_head = right.head;

    Node* merged_tail = nullptr;

    while (left_head != nullptr || right_head != nullptr) {
        if (left_head == nullptr) {
            if (merged.head == nullptr) {
                merged.head = right_head;
            } else {
                merged_tail->next = right_head;
            }
            break;
        } else if (right_head == nullptr) {
            if (merged.head == nullptr) {
                merged.head = left_head;
            } else {
                merged_tail->next = left_head;
            }
            break;
        } else {
            if (left_head->data <= right_head->data) {
                if (merged.head == nullptr) {
                    merged.head = left_head;
                    merged_tail = left_head;
                } else {
                    merged_tail->next = left_head;
                    merged_tail = merged_tail->next;
                }
                left_head = left_head->next;
            } else {
                if (merged.head == nullptr) {
                    merged.head = right_head;
                    merged_tail = right_head;
                } else {
                    merged_tail->next = right_head;
                    merged_tail = merged_tail->next;
                }
                right_head = right_head->next;
            }
        }
    }

    return merged;
}

int main() {
    LinkedList l;
    l.addToHead(10);
    l.addToHead(2);
    l.addToHead(34);
    l.addToHead(23);
    l.addToHead(12);
    l.addToHead(1);

    std::cout << "Original List:" << std::endl;
    l.print();

    LinkedList sorted_linked_list = merge_sort(l);

    std::cout << "Sorted List:" << std::endl;
    sorted_linked_list.print();

    return 0;
}
