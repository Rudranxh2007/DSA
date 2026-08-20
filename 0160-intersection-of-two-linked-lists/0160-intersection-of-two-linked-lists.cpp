/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp=headA;
        unordered_map<ListNode*,int>store;
        while(temp!=NULL){
            store[temp]++;
            temp=temp->next;
        }
        ListNode* temp2=headB;
        while(temp2!=NULL){
            if(store.count(temp2)){
                return temp2;
            }
            else{
                temp2=temp2->next;
            }
        }
       return NULL; 
    }
};