#include<bits/stdc++.h>
using namespace std;
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
Node* AddOne(Node* head){
   head=recursiveReverse(head);
   int carry=1;
   Node* temp=head;
   while(temp!=NULL){
        temp->data+=carry;
        if(temp->data<10){
            carry=0;
            break;
        }
        else{
            carry=1;
            temp->data=0;
        }
        temp=temp->next;
   }
    head=recursiveReverse(head);
    if(carry==1){
        Node* newNode=new Node(1,head);
        head=newNode;
    }
    return head;
    
}
int addHelper(Node* temp){

    if(temp==NULL){
        return  1;
    }
    int carry=addHelper(temp->next);
    temp->data+=carry;
    if(temp->data<10){
        return 0;
    }
    temp->data=0;
    return 1;
}
Node* addOne(Node* head){
    int carry=addHelper(head);
    if(carry==1){
        Node* newNode= new Node(1,head);
        head=newNode;

    }
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
    vector<int>arr={9,9,9,9};
    
    Node* head=ConvertArr2LL(arr);
     head = AddOne(head);
    // cout<<ans<<" ";
Traversal(head);
}