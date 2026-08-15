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
bool CheckPalindrome(Node* head){
    Node* fast=head;
    Node* slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    Node*newhead=recursiveReverse(slow->next);
    Node* first=head;
    Node* second=newhead;
    while(second!=NULL){
        if(second->data!=first->data){
            recursiveReverse(newhead);
             return false;
            }
            first=first->next;
            second=second->next;
    }
    recursiveReverse(newhead);
    return true;
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
    vector<int>arr={1,2,3,3,2,1};
    
    Node* head=ConvertArr2LL(arr);
    bool ans = CheckPalindrome(head);
    cout<<ans<<" ";
Traversal(head);
}