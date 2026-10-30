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
    ListNode* reverseLL(ListNode* head){
        
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;

        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp=reverseLL(head);
        head=temp;
        int carry=0;
        ListNode* last=nullptr;
        while(temp!=NULL){
            int digit=temp->val*2+carry;
            
            carry=digit/10;
            digit%=10;
            temp->val=digit;
            last=temp;
            temp=temp->next;


        }
        if(carry>0){
            ListNode* newNode= new ListNode(carry);
            last->next=newNode;

        }
        return reverseLL(head);
        
    }
};