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
Node* oddEven(Node* head){
    if(head==NULL && head->next==NULL) return head;
    Node* odd=head;
    Node* even=head->next;
    Node* evenhead=head->next;
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;     
    }
    odd->next=evenhead;
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
    vector<int>arr={1,2,3,4,5,6,7,8};
    
    Node* head=ConvertArr2LL(arr);
     head= oddEven(head);
Traversal(head);
}