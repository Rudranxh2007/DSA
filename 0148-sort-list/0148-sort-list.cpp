
class Solution {
    private:
          ListNode* middleNode(ListNode* head) {
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=NULL){
            
            fast=fast->next;
            if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
            }
        }
        return slow;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=new ListNode(0);
        ListNode* newNode=head;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                newNode->next=list1;
                list1=list1->next;
            }
            else{
                 newNode->next=list2;
                list2=list2->next;
            }
            newNode=newNode->next;
        }
        if(list1!=NULL) newNode->next=list1;
        else newNode->next=list2;
        return head ->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid=middleNode(head);
        ListNode* leftHead=head,*rightHead=mid->next;
        mid->next=NULL;
        leftHead=sortList(leftHead);
        rightHead=sortList(rightHead);
        return mergeTwoLists(leftHead,rightHead);
    
        
    }
};