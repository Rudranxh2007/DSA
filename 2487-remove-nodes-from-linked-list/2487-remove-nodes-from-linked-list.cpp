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
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr!=nullptr){
            ListNode* nextNode= curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode; 
        }
        return prev;

   }

    ListNode* removeNodes(ListNode* head) {
       if(head==NULL) return NULL;
       ListNode* head2=head;
        ListNode* temp=reverseLL(head2);
        
        ListNode* dup=temp;
        int maxi=temp->val;
        while( dup!=NULL && dup->next!=NULL){
            if(dup->next->val<maxi){
               
                dup->next=dup->next->next;
               
            }
            else{ 
                dup=dup->next;
                maxi=dup->val;
            }
        }
       
        
        return reverseLL(temp);
        
    }
};