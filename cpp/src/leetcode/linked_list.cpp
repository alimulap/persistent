#include "../../include/leetcode/linked_list.hpp"


ListNode::ListNode()
    : val(0), next(nullptr)
{ }
ListNode::ListNode(int x)
    : val(x), next(nullptr)
{ }
ListNode::ListNode(int x, ListNode *next) 
    : val(x), next(next)
{ }


ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;  
    ListNode* current = head;

    while(current != nullptr) { 
        ListNode* next = current->next; 
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; 
}

