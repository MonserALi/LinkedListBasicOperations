#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

struct Position
{
    int position_number[10000];
};


/// Declaration of functions
int CountTheSize(Node *&head);
void DisplayTheList(Node *&head);
void InsertionAtHead(Node *&head, int val);
void InsertionAtTail(Node *&head, int val);
void InsertionAtSpecificPosition(Node *&head,int val, int pos);
int SearchValueAtUniqueList(Node *&head,int val);
Position SearchValueAtDuplicateList(Node *&head,int val);
void InsertionAfterSpecificValueDuplicateList(Node *&head,int searchValue,int val);
void DeletionAtHead(Node *&head);
void DeletionAtTail(Node *&head);
void DeletionAtSpecificPosition(Node *&head,int pos);
void DeletionByValueUniqueList(Node *&head,int searchValue);
void MoveTail(Node *&head);
int FindMid(Node *&head);
void MakeCycle(Node *&head,int pos);
bool CycleDetection(Node *&head);
void DeletionOfCycle(Node *&head);
void ReplaceEvenIndex(Node *&head);
void RemoveDuplicate(Node *&head);
Node* ReveresEveryKNodes(Node* &head, int k);


/// Implementation of functions
int CountTheSize(Node *&head)
{
    int i = 0;
    Node *temp = head;
    while(temp!=NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

void DisplayTheList(Node *&head)
{
    Node *temp = head;
    if(temp==NULL)
    {
        cout<<"The List Is Empty!"<<endl;
    }
    else
    {
        cout<<"The List Is: ";
        while(temp!=NULL)
        {
            cout<<temp->value;
            if(temp->next!=NULL)
            {
                cout<<" -> ";
            }
            temp=temp->next;
        }
        cout<<endl;
    }
}
void InsertionAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
void InsertionAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    if(temp==NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;

    }
}
void InsertionAtSpecificPosition(Node *&head,int val, int pos)
{
    Node *temp = head;
    Node *newNode = new Node(val);
    int siz = CountTheSize(head);
    if(pos<1 || pos>siz+1)
    {
        cout<<"You enter invalid index...!\n";
        return;
    }
    int i = 1;
    if(pos==1)
    {
        InsertionAtHead(head,val);
    }
    else
    {
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;

        temp->next = newNode;
    }

}
int SearchValueAtUniqueList(Node *&head,int val)
{
    int pos = 1;
    int flag = 0;
    Node *temp = head;

    while(temp!=NULL)
    {
        if(temp->value == val)
        {
            flag = 1;
            return pos;
            break;
        }
        pos++;
        temp = temp->next;
    }
    if(flag==0)
    {
        return -1;
    }
}
Position SearchValueAtDuplicateList(Node *&head,int val)
{
    Position position;
    int k = 1;
    int j = 1;
    Node *temp = head;
    while(temp!=NULL)
    {
        if(temp->value == val)
        {
            position.position_number[j] = k;
            j++;
        }
        k++;
        temp = temp->next;
    }
    position.position_number[0] = j-1;

    return position;
}
void InsertionAfterSpecificValueUniqueList(Node *&head,int searchValue,int ins)
{
    int pos;
    pos = SearchValueAtUniqueList(head,searchValue);
    InsertionAtSpecificPosition(head,ins,pos+1);
}
void InsertionAfterSpecificValueDuplicateList(Node *&head,int searchValue,int val)
{
    Position pos;
    pos = SearchValueAtDuplicateList(head,searchValue);
    if(pos.position_number[0]==0)
    {
        cout<<"The value you enter not yet at the list";
    }
    else
    {
        for(int i=1,j=1; i<=pos.position_number[0]; j++,i++)
        {
            InsertionAtSpecificPosition(head,val,pos.position_number[i]+j);
        }
    }

}

void DeletionAtHead(Node *&head)
{
    Node *temp = head;
    if(temp==NULL)
    {
        cout<<"The List is already empty\n";
    }
    else
    {
        head = temp->next;
        delete temp;
    }
}

void DeletionAtTail(Node *&head)
{
    Node *temp = head;
    int sz = CountTheSize(head);
    if(temp==NULL)
    {
        cout<<"The List is already empty\n";
    }
    else if(sz==1)
    {
        DeletionAtHead(head);
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = NULL;
        delete delNode;
    }
}

void DeletionAtSpecificPosition(Node *&head,int pos)
{
    Node *temp = head;
    int sz = CountTheSize(head);
    if(pos<1 || pos>sz)
    {
        cout<<"Invalid input...!\n";
        return;
    }
    if(pos==1)
    {
        DeletionAtHead(head);
    }
    else if(sz==pos)
    {
        DeletionAtTail(head);
    }
    else
    {
        int i = 1;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        Node *delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }
}

void DeletionByValueUniqueList(Node *&head,int searchValue)
{
    int pos =  SearchValueAtUniqueList(head,searchValue);
    DeletionAtSpecificPosition(head,pos);
}

void DeletionByValueDuplicateList(Node *&head,int val)
{
    Node *temp = head;
    Position pos  = SearchValueAtDuplicateList(head,val);
    if(pos.position_number[0]<1)
    {
        cout<<"The List is Already Empty\n";
        return;
    }
    for(int i=1,j=0; i<=pos.position_number[0]; i++,j++)
    {
        DeletionAtSpecificPosition(head,pos.position_number[i]-j);
    }
}

/// non recursive
Node *ReverseNonRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;

    if(head == NULL)
    {
        cout<<"The List is Empty \n";
        return head;
    }
    Node *Next = head->next;
    while(true)
    {
        current->next = prev;
        prev = current;
        current=Next;
        if(current==NULL)
        {
            break;
        }
        Next = Next->next;

    }
    return prev;
}
// Recursive

void ReverseRecursive(Node *&head)
{


    if(head==NULL)
    {
        return;
    }
    ReverseRecursive(head->next);
    cout<<head->value<<"  ";
}

void MoveTail(Node *&head)
{
    // 1. find tail

    Node *temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }

    //2. insert tail at head
    InsertionAtHead(head,temp->value);
    //3. delete tail

    DeletionAtTail(head);
}

int FindMid(Node *&head)
{
    int mid;
    Node *fast = head;
    Node *slow = head;

    if(head==NULL)
    {
        return -1;
    }
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->value;

}


/// function about cycle
void MakeCycle(Node *&head,int pos)
{
    Node *startNode;
    Node *temp = head;

    int i = 1;

    if(head==NULL)
    {
        cout<<"The list is empty\n";
        return;
    }
    while(temp->next !=NULL)
    {
        if(i==pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        i++;
    }
    temp->next = startNode;
}

bool CycleDetection(Node *&head)
{
    Node *fast = head;
    Node *slow = head;
    if(head==NULL)
    {
        return false;
    }
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast->next == slow->next)
        {
            return true;
        }
    }

    return false;
}

void DeletionOfCycle(Node *&head)
{
    Node *fast = head;
    Node *slow = head;

    do
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    while(slow!=fast);

    fast = head;

    while(fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}

/// remove duplicate


void RemoveDuplicate(Node *&head)
{
    Node *slow, *first, *dup;
    slow = head;

    while (slow != NULL && slow->next != NULL) {
        first = slow;

        while (first->next != NULL) {
            if (slow->value == first->next->value) {
                dup = first->next;
                first->next = first->next->next;
                delete (dup);
            }
            else
                first = first->next;
        }
        slow = slow->next;
    }
}

void ReplaceEvenIndex(Node *&head){
    int i=1;
    Node *temp = head;
    while(temp!=NULL){
        if(i%2==0){
            temp->value = -1;
        }
        temp = temp->next;
        i++;
    }
}

Node* ReveresEveryKNodes(Node* &head, int k)
{
    if(head==NULL){
        return NULL;
    }
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int cnt = 0;

    while (current != NULL && cnt < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        cnt++;
    }
    if (next != NULL)
        head->next = ReveresEveryKNodes(next, k);

    return prev;
}
int main()
{
    Node *head = NULL;
    Position position;
    cout<<"Choice 1: Counting The Size"<<endl
        <<"Choice 2: Display The List"<<endl
        <<"Choice 3: Insertion At Head"<<endl
        <<"Choice 4: Insertion At Tail"<<endl
        <<"Choice 5: Insertion At Specific Position"<<endl
        <<"Choice 6: Search A Value (Unique List)"<<endl
        <<"Choice 7: Search A Value (Duplication Enable List)"<<endl
        <<"Choice 8: Insertion After A Specific Value (Unique List)"<<endl
        <<"Choice 9: Insertion After A Specific Value (Duplication Enable List)"<<endl
        <<"Choice 10: Deletion At Head "<<endl
        <<"Choice 11: Deletion At Tail"<<endl
        <<"Choice 12: Deletion At Specific Position"<<endl
        <<"Choice 13: Deletion By specific value (Unique List)"<<endl
        <<"Choice 14: Deletion By specific value (Duplicate List)"<<endl
        <<"Choice 15: Reverse List"<<endl
        <<"Choice 16: Display List In Reverse Order "<<endl
        <<"Choice 17: Move Tail To The Head"<<endl
        <<"Choice 18: Find The Mid Node (Slow-Fast Method)"<<endl
        <<"Choice 19: Create A Cycle At Specific Position"<<endl
        <<"Choice 20: Cycle Detection "<<endl
        <<"Choice 21: Remove Cycle From The List"<<endl
        <<"Choice 22: Remove Duplication"<<endl
        <<"Choice 23: Replace Even Index "<<endl
        <<"Choice 24: Reveres Every Kth Nodes "<<endl
        <<"Choice 0: Exit"<<endl;


    int choice = 1,len,pos,val,searchValue;
    while(choice!=0)
    {
        cout<<"\nEnter Next Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            len  = CountTheSize(head);
            cout<<"Size of the list is: "<<len<<endl;
            break;
        case 2:
            DisplayTheList(head);
            break;
        case 3:
            cout<<"Enter the value you want to insert at head: ";
            cin>>val;
            InsertionAtHead(head,val);
            break;
        case 4:
            cout<<"Enter the value you want to insert at tail: ";
            cin>>val;
            InsertionAtTail(head,val);
            break;
        case 5:
            cout<<"Enter the desire position: ";
            cin>>pos;
            cout<<"Enter the value you want to insert: ";
            cin>>val;
            InsertionAtSpecificPosition(head,val,pos);
            break;
        case 6:
            cout<<"Enter the value you want to search (UL): ";
            cin>>val;
            pos = SearchValueAtUniqueList(head,val);
            if(pos==-1) cout<<"The value you search not yet at the list..!\n";
            else cout<<"The value found at position: "<<pos<<endl;
            break;
        case 7:
            cout<<"Enter the value you want to search (DL): ";
            cin>>val;
            position = SearchValueAtDuplicateList(head,val);
            if(position.position_number[0]<1) cout<<"The value you search not yet at the list..!\n";
            else
            {
                cout<<"The value found at position: ";
                for(int i=1; i<=position.position_number[0]; i++)
                {
                    cout<<position.position_number[i];
                    if(i<position.position_number[0]) cout<<", ";
                }
            }
            break;
        case 8:
            cout<<"Enter the desire value (UL): ";
            cin>>searchValue;
            cout<<"Enter the value you want to insert: ";
            cin>>val;
            InsertionAfterSpecificValueUniqueList(head,searchValue,val);
            break;
        case 9:
            cout<<"Enter the desire value (DL): ";
            cin>>searchValue;
            cout<<"Enter the value you want to insert: ";
            cin>>val;
            InsertionAfterSpecificValueDuplicateList(head,searchValue,val);
            break;
        case 10:
            DeletionAtHead(head);
            break;
        case 11:
            DeletionAtTail(head);
            break;
        case 12:
            cout<<"Enter the position you want to delete from: ";
            cin>>pos;
            DeletionAtSpecificPosition(head,pos);
            break;
        case 13:
            cout<<"Enter the value you want to delete (UL): ";
            cin>>val;
            DeletionByValueUniqueList(head,val);
            break;
        case 14:
            cout<<"Enter the value you want to delete (DL): ";
            cin>>val;
            DeletionByValueDuplicateList(head,val);
            break;
        case 15:
            head = ReverseNonRecursive(head);
            break;
        case 16:
            if(head==NULL)
            {
                cout<<"The List is empty";
            }
            else
            {
                cout<<"The Reverse List is: ";
                ReverseRecursive(head);
            }
            break;
        case 17:
            MoveTail(head);
            break;
        case 18:
            int mid;
            mid = FindMid(head);
            if(mid==-1)
            {
                cout<<"The list empty\n";
            }
            else
            {
                cout<<"Mid node of the list is: ";
                cout<<mid<<endl;
            }
            break;
        case 19:
            cout<<"Enter the desire position to make cycle: ";
            cin>>pos;
            MakeCycle(head,pos);
            break;
        case 20:
            int isDetect;
            isDetect =  CycleDetection(head);
            if(isDetect>0)
            {
                cout<<"There is a cycle in the list\n";
            }
            else
            {
                cout<<"There is no cycle in the list\n";
            }
            break;
        case 21:
            isDetect = CycleDetection(head);
            if(isDetect)
            {
                DeletionOfCycle(head);
            }
            else
            {
                cout<<"There is no cycle in the list\n";
            }
            break;
        case 22:
            RemoveDuplicate(head);
            break;
        case 23:
            ReplaceEvenIndex(head);
            break;
        case 24:
            cout<<"Enter the value of K: ";
            cin>>val;
            head = ReveresEveryKNodes(head,val);
            break;
        default:
            break;
        }

    }

    return 0;
}
