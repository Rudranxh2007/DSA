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
Node* Sort012(Node* head){
  if(head==NULL || head->next==NULL) return head;

  Node* temp=head;
  Node* Zerohead = new Node(-1,nullptr);
  Node* Onehead = new Node(-1,nullptr);
  Node* Twohead = new Node(-1,nullptr);
  Node* one=Onehead;
  Node* two=Twohead;
  Node* zero=Zerohead;
     while(temp!=NULL){
        if(temp->data==0){
            zero->next=temp;
            zero=zero->next;
        }
        else if(temp->data==1){
            one->next=temp;
            one=one->next;
        }
        else{
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
     }
     zero->next=(Onehead->next)?Onehead->next:Twohead->next;
     one->next=Twohead->next;
     two->next=NULL;

     Node* newHead=Zerohead->next;

     free(Zerohead);
     free(Onehead);
     free(Twohead);
     return newHead;
     
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
    vector<int>arr={1,2,0,1,2,2,1,0};
    
    Node* head=ConvertArr2LL(arr);
     head= Sort012(head);
Traversal(head);
}