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

Node* removeNthNode(Node* head,int k){
    Node* fast=head;
    Node* slow=head;
    for(int i=0;i<k;i++) fast=fast->next;
     if(fast==NULL) return head->next;
     while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
     }
     Node* del=slow->next;
     slow->next=slow->next->next;
     delete del;
     return head;


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
     head= removeNthNode(head,3);
Traversal(head);
}