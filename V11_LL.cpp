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
/*
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data,Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
// we have to return a pointer of type head
Node *convertVecToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0],nullptr);
    // head pointer holding the address of the newly created Node
    Node *mover = head;
    // mover holds the value of head which was and address

    for (int i = 1; i < arr.size(); i++)
    {
        // cout<<arr[i]<<" "; // For debugging
        Node *temp = new Node(arr[i],nullptr);
        mover->next = temp;
        // Putting the value of temp which was an address into mover was pointing to head initially and it went inside the node and chose next which was basically holding an address and now it holds the value temp holded(that is an address);
        // (*mover).next=temp;
        mover = temp;
        // temp was holding an address now mover has that value
    }
    return head;
} // TC : O(n)

int lenOfLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }
} // TC : O(n)

bool searchInLL(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
} // O(n), O(1), O(n/2)

Node *deleteHead(Node *head)
{
    if (head == NULL)
        return head;   // If head has NULL value then return head only
    Node *temp = head; // head has an address storing it in temp
    head = head->next; // head-> next has address of the next node putting it in head
    delete temp;       // deleting temp node
    return head;       // returning head address
}

Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *deleteAny(Node *head, int k)
{
    if (head == nullptr)
        return head;
    Node *temp = head;
    Node *prev = nullptr;
    if (k == 1)
    {
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *deleteEle(Node *head, int ele)
{
    if (head == nullptr)
        return head;
    Node *temp = head;
    Node *prev = nullptr;
    if (head->data == ele)
    {
        head = head->next;
        delete temp;
        return head;
    }
    while (temp != nullptr)
    {
        if (temp->data == ele)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertHead(Node *head, int val)
{
    Node *temp = new Node(val,head); // temp->next will be pointing to head
    return temp;                      // temp will become the new head
}

Node* insertTail(Node* head,int val){
    if(head==nullptr) return new Node(val,nullptr);
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* newNode= new Node(val,nullptr);
    temp->next=newNode;
    return head;
}

Node* insertAny(Node* head,int val,int k){
    if(head==NULL){
        if(k==1){
            return new Node(val,nullptr);
        }else return head;
    }
    if(k==1) return new Node(val,head);
    int cnt=0;
    Node*temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* newNode= new Node(val,temp->next);
            temp->next=newNode;
            break;
        }temp=temp->next;
    }return head;
}

Node* insertBeforeVal(Node* head,int val,int val2){
    if(head==NULL){
        return NULL; // cant insert value if no Node is present
    }
    if(head->data==val2) return new Node(val,head);
    int cnt=0;
    Node*temp=head;
    bool found=false;
    while(temp->next!=NULL){
        cnt++;
        if(head->data==val2){
            Node* newNode= new Node(val,temp->next);
            temp->next=newNode;
            found=1;
            break;
        }temp=temp->next;
    }
    if(found=false) cout<<"Not Found "<<endl;
    return head;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    Node *head = convertVecToLL(vec);
    cout << "head->data : ";
    cout << head->data << endl; // 1

    Node *temp = head;
    // head held an address and now temp has it
    cout << "Traversing in the LL : ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        // Printing the value of the data temp was holding
        temp = temp->next;
        // temp->next was the address of the Node2 which Node1 was holding when temp was pointing to it, not temp->next is basically an address so now temp has that value as temp is basically a pointer for holding address
    }
    cout << endl;

    cout << "Length of the LL : " << lenOfLL(head); // we are passing head as it holds the address of the first node

    cout << endl;
    cout << "Searching in LL : " << searchInLL(head, 3);

    cout << endl
         << "Deleting Head : ";
    head = deleteHead(head);
    cout << head->data << endl; // 2

    cout << "Deleting Tail : ";
    head = deleteTail(head);
    Node *temp2 = head;
    cout << "Traversing in the LL : ";
    while (temp2 != nullptr)
    {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    cout << endl;

    cout << "Deleting Any : ";
    head = deleteAny(head, 2);
    cout << "Traversing in the LL : ";
    Node *temp3 = head;
    while (temp3 != nullptr)
    {
        cout << temp3->data << " ";
        temp3 = temp3->next;
    }
    cout << endl;

    head = deleteEle(head, 4);
    cout << "Traversing in the LL : ";
    Node *temp4 = head;
    while (temp4 != nullptr)
    {
        cout << temp4->data << " ";
        temp4 = temp4->next;
    }
    cout << endl;

    cout << "Inserting at Head : ";
    head = insertHead(head, 4);
    // Or
    // head= insetHead(head,100);
    cout << "Traversing in the LL : ";
    Node *temp5 = head;
    while (temp5 != nullptr)
    {
        cout << temp5->data << " ";
        temp5 = temp5->next;
    }
    cout << endl;

    cout<<"Inserting at Tail :";
    head=insertTail(head,100);
    cout << "Traversing in the LL : ";
    Node *temp6 = head;
    while (temp6 != nullptr){
        cout << temp6->data << " ";
        temp6 =
        temp6->next;
    }cout<<endl;

    cout<<"Inserting Any : ";
    head = insertAny(head,1310,3);
    cout << "Traversing in the LL : ";
    Node *temp7 = head;
    while (temp7 != nullptr){
        cout << temp7->data << " ";
        temp7 = temp7->next;
    }cout<<endl;

    cout<<"Insert Before Val : ";
    head=insertBeforeVal(head,13,1310);
        cout << "Traversing in the LL : ";
    Node *temp8 = head;
    while (temp8 != nullptr){
        cout << temp8->data << " ";
        temp8 = temp8->next;
    }cout<<endl;


    return 0;
}
*/
/*
head->data : 1
Traversing in the LL : 1 2 3 4 5
Length of the LL : 0
Searching in LL : 1
Deleting Head : 2
Deleting Tail : Traversing in the LL : 2 3 4
Deleting Any : Traversing in the LL : 2 4
Traversing in the LL : 2
Inserting at Head : Traversing in the LL : 4 2
Inserting at Tail :Traversing in the LL : 4 2 100
Inserting Any : Traversing in the LL : 4 2 1310 100
Insert Before Val : Traversing in the LL : 4 2 1310 100
*/

// DoublyLinkedList
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
Node *MakingDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++) // start i from ` not 0
    {
        Node *temp = new Node(arr[i]);
        prev->next = temp;
        temp->prev = prev;
        prev = temp;
    }
    return head;
}
void printDLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *DeleteAtHead(Node *head)
{
    if (head == NULL || head->next == nullptr)
        return NULL;
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    return head;
}
Node *DeleteTail(Node *head)
{
    if (head == NULL || head->next == nullptr)
        return NULL;
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}
Node *DelelteKth(Node* head, int k){
    if(head==NULL) return NULL;
    // if(head->next==nullptr){
    //     if(k==1) return NULL;
    // }
    Node* temp=head;
    int cnt=0;
    // while(cnt!=(k-1)){ // why we are not doing this is bcoz if k's value is longer then temp's length 
    //     temp=temp->next;
    //     cnt++;
    // }
    while(temp!=nullptr){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    if(temp->next==nullptr) return DeleteTail(temp);
    if(temp->prev==nullptr) return DeleteAtHead(temp);
    if(temp->next==nullptr && temp->prev==nullptr){
        delete temp;
        return NULL;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    temp->next=nullptr;
    temp->prev=nullptr;
    return head;
}
Node* insertEle(Node* head, int pos, int val){
    Node* temp=head;
    Node* newNode = new Node(val);
    if(pos==1){
        newNode->next=head;
        // newNode->prev=nullptr; already it was pointing to nullptr during making of it in CTOR
        head=newNode;
        return head;
    } 
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==(pos-1)) break;
        temp=temp->next;
    }
    if(temp->next==nullptr){
        temp->next=newNode;
        newNode->prev=temp;
        return head;
    }
    newNode->prev=temp;
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    return head;

}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = MakingDLL(arr);
    cout << "Printing Head data -> ";
    cout << head->data;
    cout << endl;

    cout << "Printing DLL -> ";
    printDLL(head);
    cout << endl;

    cout << "Delete at Head ->";
    head = DeleteAtHead(head);
    printDLL(head);
    cout << endl;

    cout << "Delete at Tail ->";
    head = DeleteTail(head);
    printDLL(head);
    cout << endl;

    cout<<"Delete kth Element ->";
    head=DelelteKth(head,3);
    printDLL(head);
    cout << endl;

    cout<<"Insert Element in between ->";
    head=insertEle(head,3,13);
    printDLL(head);
    cout<<endl;
    cout<<"Insert Element at tail ->";
    head=insertEle(head,5,10);
    printDLL(head);
    cout<<endl;
    cout<<"Insert Element at head ->";
    head=insertEle(head,1,1310);
    printDLL(head);
    cout<<endl;

    return 0;
}
