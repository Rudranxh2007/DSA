#include<bits/stdc++.h>
using namespace std;
// struct Node {
//     int data;
//     Node* next;

//     Node(int data1, Node* next1){
//           data=data1;
//           next=next1;
//     }
// };
class Node {
public:
    int data;
    Node* next;

  public:
    Node(int data1, Node* next1){
          data=data1;
          next=next1;
    }
    Node(int data1){
          data=data1;
          next=nullptr;
    }
};
Node* recursiveReverse(Node* head){
    if(head==NULL || head->next==NULL) return head;
     
    Node* newhead=recursiveReverse(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;

}
Node* reverseLL(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* temp=head;
    Node* prev=NULL;
    Node*  front=NULL;
    while(temp!=NULL){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
        
    }
    return prev;
}
void Traversal(Node* head){
   if(head->next==nullptr){
    cout<<head->data<<" ";
    return ;
   }
   Node* temp=head;
   while(temp!=nullptr){
    cout<<temp->data<<" ";
    temp=temp->next;
   }
   cout<<endl;
}
Node* ConvertArr2LL(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;

}

int main(){
    vector<int>arr={1,2,3,4,5,6};
    
    Node* head=ConvertArr2LL(arr);
     head= reverseLL(head);
Traversal(head);
}