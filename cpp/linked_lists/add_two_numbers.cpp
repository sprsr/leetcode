// https://leetcode.com/problems/add-two-numbers/
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

#include <iostream>
#include <algorithm>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = nullptr, *cur = nullptr;
        ListNode *l1_mark = l1;
        ListNode *l2_mark = l2;
        int sum, count, max_cnt; 
        int l1_cnt = 0, l2_cnt = 0;

        while (l1_mark->next != nullptr) {
            l1_cnt++;
            l1_mark = l1_mark->next;
        }
        while (l2_mark->next != nullptr) {
            l2_cnt++;
            l2_mark = l2_mark->next;
        }

        count = 0;
        max_cnt = std::max(l1_cnt,l2_cnt);
        cout << "Max Cnt: " << max_cnt << endl;
        while (count<=max_cnt) {
            sum = 0;
            if (l1_cnt >= count) {
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if (l2_cnt >= count) {
                sum = sum + l2->val;
                l2 = l2->next;
            }
            count++;
            if (cur == nullptr) {
                cur = new ListNode();
            }
            cur->val = cur->val+sum;
             cout << "Current: " << cur->val << endl;
            if (cur->val >= 10) {
                if (cur->next == nullptr) {
                    cur->next = new ListNode();
                }
                cur->next->val = cur->next->val + 1;
                cur->val = (cur->val)%10;
            }
            if (count == 1) {
                ret = cur;
            }
            if (cur->next == nullptr && count<=max_cnt) {
                cur->next = new ListNode();
            }
            cur = cur->next;
        }   
        return ret;
    }
};
