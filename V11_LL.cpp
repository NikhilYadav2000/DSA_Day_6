/*
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data,Node* next){
        this->data=data;
        this->next=next;
    }
};
int main(){
    vector<int> arr={2,5,8,7};
    Node* y=new Node(arr[0],nullptr);
    cout<<y->data<<endl; // 2
    cout<<y; // The address y is pointing to
// new returns ref and y is holding it
// Node x=node(arr[0],nullptr);
// Node* y=&x

    Node x=Node(arr[1],nullptr);
    cout<<x.data<<endl; // 5

    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data,Node* next){
            this->data=data;
            this->next=nullptr;
        }
};
// we have to return a pointer of type head
Node* convertVecToLL(vector<int> &arr){
    Node* head=new Node(arr[0],nullptr); 
    // head pointer holding the address of the newly created Node
    Node* mover=head;
    // mover holds the value of head which was and address

    for(int i=1;i<arr.size();i++){
        // cout<<arr[i]<<" "; // For debugging
        Node* temp=new Node(arr[i],nullptr);
        mover->next=temp;
        // Putting the value of temp which was an address into mover was pointing to head initially and it went inside the node and chose next which was basically holding an address and now it holds the value temp holded(that is an address);
        // (*mover).next=temp;
        mover=temp;
        // temp was holding an address now mover has that value
    }
    return head;
} // TC : O(n)

int lenOfLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        temp=temp->next;
        cnt++;
    }
} // TC : O(n)

bool searchInLL(Node* head,int val){
    Node* temp=head;
    while(temp){
        if(temp->data==val) return true;
        temp=temp->next;
    }return false;
} // O(n), O(1), O(n/2)

int main(){
    vector<int> vec={1,2,3,4,5};
    Node* head=convertVecToLL(vec);
    cout<<"head->data : ";
    cout<<head->data<<endl; // 1

    Node* temp=head;
    // head held an address and now temp has it
    cout<<"Traversing in the LL : ";
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        // Printing the value of the data temp was holding
        temp=temp->next;
        // temp->next was the address of the Node2 which Node1 was holding when temp was pointing to it, not temp->next is basically an address so now temp has that value as temp is basically a pointer for holding address
    }cout<<endl;

    cout<<"Length of the LL : "<<lenOfLL(head); // we are passing head as it holds the address of the first node

    cout<<"Searching in LL"<<searchInLL(head,3);

    return 0;
}