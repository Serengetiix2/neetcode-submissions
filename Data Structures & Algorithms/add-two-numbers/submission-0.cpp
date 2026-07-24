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
    void sumList(ListNode* l1, ListNode* l2,ListNode* l3, int carryOver){
        if(l1 == nullptr && l2 == nullptr){
            if(carryOver != 0){
            ListNode* newNode = new ListNode(carryOver);
            l3->next = newNode;
            }
            return;
        }
        int c1V;
        int c2V;
        int sum;
        if(l2 == nullptr){
            c1V = l1->val;
            l1 = l1->next;
            c2V = 0;
        }else if(l1 == nullptr){
            c2V = l2->val;
            l2 = l2->next;
            c1V = 0;
        }else{
            c1V = l1->val;
            c2V = l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }

        int total = (c1V + c2V + carryOver);
        int digit = total % 10;
        int carry = total /10;
        ListNode* newNode = new ListNode(digit);
        l3->next = newNode;
        l3 = l3->next;
        sumList(l1,l2,l3,carry);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        sumList(l1, l2,l3,0);
        return l3->next;

    }
};