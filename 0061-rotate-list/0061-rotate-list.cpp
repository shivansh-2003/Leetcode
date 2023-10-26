/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head || k == 0) {
        return head; // No rotation needed.
    }

    // Step 1: Find the length of the linked list.
    int length = 1;
    ListNode* current = head;
    while (current->next) {
        current = current->next;
        length++;
    }

    // Step 2: Calculate effective rotation.
    k = k % length;

    if (k == 0) {
        return head; // No change needed.
    }

    // Step 3: Identify new head and tail positions.
    int newHeadPos = length - k;
    int newTailPos = newHeadPos - 1;

    // Step 4: Adjust the pointers to perform rotation.
    current->next = head; // Make the list circular.
    current = head;
    for (int i = 0; i < newTailPos; i++) {
        current = current->next;
    }
    ListNode* newHead = current->next;
    current->next = nullptr;

    return newHead;

    }
};