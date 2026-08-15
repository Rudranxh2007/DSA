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
Node* Add2nums(Node* head1, Node* head2){
    Node* dummy=new Node(-1,nullptr);
    Node* curr=dummy;
    Node* temp1=head1;
    Node* temp2= head2;
     int sum=0,carry=0;
    while(temp1!=NULL && temp2!=NULL){
          sum=temp1->data+temp2->data+carry;
          carry=sum/10;
          sum%=10;
          Node* newNode= new Node(sum,nullptr);
          curr->next=newNode;
          curr=curr->next;
          temp1=temp1->next;
          temp2=temp2->next;
        }
        while(temp1!=NULL){
            sum=temp1->data+carry;
            carry=sum/10;
            sum%=10;
            Node* newNode= new Node(sum,nullptr);
            curr->next=newNode;
            curr=curr->next;
          temp1=temp1->next;
    }
    while(temp2!=NULL){
        sum=temp2->data+carry;
        carry=sum/10;
            sum%=10;
            Node* newNode= new Node(sum,nullptr);
            curr->next=newNode;
            curr=curr->next;
          temp2=temp2->next;
    }
    if(carry!=0){
         Node* newNode= new Node(carry,nullptr);
         curr->next=newNode;
         curr=curr->next;
    }
    return dummy->next;
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
    vector<int>arr={2,5,7,8};
    vector<int>arr2={2,5,7,8};
    Node* head=ConvertArr2LL(arr);
    Node* head2=ConvertArr2LL(arr2);
    Node* head3=Add2nums(head,head2);
Traversal(head3);
}