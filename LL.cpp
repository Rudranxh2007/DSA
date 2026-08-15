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
Node* DeleteFromBegin(Node* head){
    if(head==NULL) return head;
    Node* temp =head;
    head=head->next;
    free(temp);
    return head;
}
Node* deleteFromTail(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    Node* cur=temp->next;
    temp->next=nullptr;
    free(cur);
    return head;
}
int length(Node* head){
    if(head==NULL) return 0;
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
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

Node* RemoveKth(Node* head , int k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp= head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node * prev=NULL;
    while(temp != NULL){
        cnt++;
        if(cnt==k){
          prev->next=prev->next->next;
          free(temp);
          break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* RemoveEl(Node* head , int el){
    if(head==NULL) return head;
    if(head->data==el){
        Node* temp= head;
        head=head->next;
        free(temp);
        return head;
    }
 
    Node* temp=head;
    Node * prev=NULL;
    while(temp != NULL){
        
        if(temp->data==el){
          prev->next=prev->next->next;
          free(temp);
          break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
 
Node* insertAtHead(Node* head,int val){
    Node* temp= new Node(val);
    temp->next=head;
    head=temp;
    return head;

}

Node* insertAtEnd(Node* head,int val){
    if(head==NULL){
         head=new Node(val);
         return head;
        
    } 
    Node* temp= head;
    while(temp->next!=NULL)
    temp=temp->next;
    
    Node* newNode= new Node(val);
    temp->next=newNode;
    return head;
}
Node* InsertAtKth(Node* head,int val,int el){
   if(head==NULL){
    if(val==1){
      return new Node(el);
    }
    else return nullptr;
   }
    if(val==1){
        Node* temp=new Node(el);
        temp->next=head;
        head=temp;
        return head;
    }
    int cnt=0;
    Node* temp=head;
    
    while(temp->next!=NULL){
        cnt++;
        if(cnt==val-1){
        Node* newNode=new Node(el,temp->next);
       temp->next=newNode;
       break;

        }
      
        temp=temp->next;
    }
    return head;
}

Node* InsertBeforeValue(Node* head,int val,int el){
   if(head==NULL){
    return NULL;
    }
    
   
    if(head->data==val){
        Node* temp=new Node(el);
        temp->next=head;
        head=temp;
        return head;
    }
    
    Node* temp=head;
    
    while(temp->next!=NULL){
       
        if(temp->next->data==val){
        Node* newNode=new Node(el,temp->next);
       temp->next=newNode;
       break;

        }
      
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int>arr={2,5,7,8};
    Node* head=ConvertArr2LL(arr);
Traversal(head);
}