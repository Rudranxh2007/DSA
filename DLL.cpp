#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

  public:
    Node(int data1, Node* next1,Node* back1){
          data=data1;
          next=next1;
          back=back1;
    }
    Node(int data1){
          data=data1;
          next=nullptr;
          back=nullptr;
    }
};
Node* ConvertArr2DLL(vector<int>&arr){
     Node* head=new Node(arr[0]);
     Node* prev=head;
     for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
     }
     return head;

}
void traversal(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* deleteHead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
   Node* prev=head;
   head=head->next;
   head->back=nullptr;
   prev->next=NULL;
   free(prev);
   return head;

}
Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    
    Node* prev=head;
    
    while(prev->next!=NULL) {
        prev=prev->next;
    }
    Node* temp=prev->back;
    temp->next=nullptr;
    prev->back=nullptr;
    free(prev);
    return head;
}

Node* deleteKthelement(Node* head,int val){

     if(head==NULL)  return nullptr;
     int count=0;
     Node* temp=head;
        
 while(temp!=NULL){
      count++;
      if(count==val) break;
      temp=temp->next;
    }

    Node* prev= temp->back;
    Node* front= temp->next;

    if(prev==NULL && temp==NULL) return NULL;
    else if(prev==NULL) return  deleteHead(head);
    else if(front==NULL) deleteTail(head);

   prev->next=front;
   front->back=prev;
   temp->next=NULL;
   temp->back=NULL;
   free(temp);
    return head;
}

void deleteNode(Node* temp){
    Node* prev=temp->back;
    Node* front=temp->next;
    if(front==NULL) {
        prev->next=nullptr;
        temp->back=nullptr;
        free(temp);
        return;
    }
    prev->next=front;
    front->back=prev;
    temp->next=temp->back=nullptr;
    free(temp);
}
Node* insertAthead(Node* head,int el){
    Node* temp=new Node(el,head,nullptr);
    head->back=temp;
    head=temp;
    return head;
}
Node* insertAtTail(Node* head,int el){
    if(head->next==NULL){
        return insertAthead(head,el);
    }
    Node* tail= head;
    while(tail->next!=NULL) tail=tail->next;
    Node* prev=tail->back;
    Node* newNode=new Node(el,tail,prev);
    prev->next=newNode;
    tail->back=newNode;
    return head;
}
Node* insertBeforeKthElement(Node* head,int val ,int el){
    if(val==1) return insertAthead(head,el);
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==val) break;
        temp=temp->next;
    } 
    Node* prev=temp->back;
    Node* newNode= new Node(el,temp,prev);
    temp->back=newNode;
    prev->next=newNode;
    return head;

}
void insertBeforeNode(Node* temp,int val){
      Node* prev=temp->back;
      Node* newNode=new Node(val,temp,prev);
      prev->next=newNode;
      temp->back=newNode;
      

}
Node* reverseDLL(Node* head){
    if(head==NULL || head->next==nullptr) return head;
    Node* curr=head;
    Node* last=NULL;
    while(curr!=NULL){
        last=curr->back;
        curr->back=curr->next;
        curr->next=last;
        curr=curr->back;
    }
    head=last->back;
    return head;
}
int main(){
    vector<int>arr={3,2,5,7};
    Node* head=ConvertArr2DLL(arr);
    head=reverseDLL(head);
    traversal(head);
}