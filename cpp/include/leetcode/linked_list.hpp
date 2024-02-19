struct ListNode 
{
    int val;
    ListNode *next;
    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode *next);
};

ListNode* reverseList(ListNode* head);

