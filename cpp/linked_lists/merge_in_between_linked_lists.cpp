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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode* mark1 = list1;
        ListNode* mark2 = list1;
        ListNode* mark3 = list2;

        for (int i = 0; i < b; i++) {
            // Setting to mark2 because mark2 is iterating each loop
            if (i<a-1) {
                mark1 = mark1->next;
            }
            mark2 = mark2->next;
        }
        mark2 = mark2->next;
        
        while (mark3->next != nullptr) {
            mark3 = mark3->next;
        }

        mark1->next = list2;
        mark3->next = mark2;
        return list1;
    }
};
