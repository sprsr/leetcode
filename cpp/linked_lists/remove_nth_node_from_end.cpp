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
            ListNode* removeNthFromEnd(ListNode* head, int n) {
                
                int distance = 0;
                
                ListNode *target_node = head, *search_node = head;
                while (search_node->next != nullptr) {
                    search_node = search_node->next;
                    distance++;
                    if (distance > n) {
                        target_node = target_node->next;
                        std::cout << target_node->val << std::endl;
                        distance--;
                    }
                }
                if (distance > 0) {
                    target_node->next = target_node->next->next;
                }
                else {
                    head = nullptr;
                }
                return head;
            }
        };
