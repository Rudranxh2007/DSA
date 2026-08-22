class Solution {
private:
ListNode* reverseLL(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* temp=head;
    ListNode* prev=NULL;
    ListNode*  front=NULL;
    while(temp!=NULL){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
        
    }
    return prev;
}
ListNode* findkthNode(ListNode* temp,int k){
   k-=1;
   while(temp!=NULL && k>0){
   k--;
   temp=temp->next;
   }
   return temp;
}
public:
 ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode * kthNode=findkthNode(temp,k);

             if(kthNode==NULL){

                if(prev){ prev->next=temp;
                 break;
                 }
        }
        
            ListNode* nextNode= kthNode->next;
            kthNode->next=NULL;
           ListNode* newhead   =reverseLL(temp);
            if(temp==head){
               head=kthNode;
            }
            else {
           
            prev->next=newhead;
              }
             prev= temp;
             temp=nextNode;
        }
   return head;
        
       

    }
};