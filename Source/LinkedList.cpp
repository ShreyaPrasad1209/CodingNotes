#include <iostream>

using namespace std;

template<typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node* next = NULL;
    };
    void PrintElementsRecurssion(Node* curHead) const
    {
        if(curHead == NULL)
            return;
        
        cout << curHead -> data << " ";
        PrintElementsRecurssion(curHead -> next);
    }
    void PrintElementsReverseRecurssion(Node* curHead) const
    {
        if(curHead == NULL)
            return;
        
        PrintElementsReverseRecurssion(curHead -> next);
        cout << curHead -> data << " ";        
    }
    void ReverseListRecurssion(Node* curHead, Node* prevHead)
    {
        if(curHead -> next == NULL)
        {
            prevHead -> next = NULL;
            curHead -> next = prevHead;
            head = curHead;
            return;
        }
        
        ReverseListRecurssion(curHead -> next, curHead);
        if(prevHead == NULL)
            return;
        prevHead -> next = NULL;
        curHead -> next = prevHead;
    }
    Node* head;
    Node* tail;
    int size;
    
public:
    LinkedList() : head(NULL), size(0) { };

    void Insert(T value, int index)
    {
        Node* node = new Node;
        node -> data = value;

        if(head == NULL && index == 0)
        {
            head = node;
            tail = node;
            return;
        }

        Node* curHead = head;
        Node* changedHead = head;
        int i = 0;
        while(curHead != NULL)
        {
            if(i == index - 1)
            {
                changedHead = curHead -> next;
                curHead -> next = node;                
            }
            else if(i == index)
            {
                if(index == 0)
                    head = node;
                
                if(node -> next == NULL)
                    tail = changedHead;
                node -> next = changedHead;
                size++;
                break;
            }

            i++;
            curHead = curHead -> next;
        }
    }

    void PushFront(T value)
    {
        Node* node = new Node;
        node -> data = value;
        node -> next = head;

        if(head == NULL)
        {
            head = node;
            tail = node;
            return;
        }

        head = node;
    }

    T TopFront()
    {
        return head -> data;
    }

    void PopFront()
    {
        Node* delNode = head;
        head = head -> next;
        delNode -> next = NULL;
        delete delNode;
    }

    void PushBack(T value)
    {
        //For pop back we must implement doubly linked list
        //A doubly linked list will have reference of next and previous node
        //This will help in certain operations like push back, reverse, etc.
        //Here it will help in keeping track of tail once pop is performed
        Node* node = new Node;
        node -> data = value;
        node -> next = NULL;

        if(head == NULL)
        {
            head = node;
            tail = node;
            return;
        }

        tail -> next = node;
        tail = tail -> next;
        size++;
    }

    void Remove(int index)
    {
        Node* curHead = head;
        int i = 0;

        if(index == 0)
        {
            head = head -> next;
            curHead -> next = NULL;
            delete curHead;
            return;
        }

        while(curHead != NULL)
        {
            if (i == index - 1)
            {
                head = head -> next;
                curHead -> next = NULL;
                delete curHead;
                break;
            }
            i++;
            curHead = curHead -> next;
        }
    }

    void PrintElementsUsingItteration() const
    {
        Node* curHead = head;
        while(curHead != NULL)
        {
            cout << curHead -> data << " ";
            curHead = curHead -> next;
        }
        cout << endl;
    }

    void PrintElementsUsingRecurssion() const
    {
        PrintElementsRecurssion(head);
        cout << endl;
    }

    void PrintElementsReverseUsingRecurssion() const
    {
        PrintElementsReverseRecurssion(head);
        cout << endl;
    }

    void ReverseListUsingItteration()
    {
        Node* curNode = head;
        Node* nextNode = NULL;
        Node* prevNode = NULL;
        tail = head;

        while(curNode != NULL)
        {
            nextNode = curNode -> next;
            curNode -> next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        head = prevNode;
    }

    void ReverseListUsingRecurssion()
    {
        tail = head;
        ReverseListRecurssion(head, NULL);
    }

    ~LinkedList()
    {
        Node* curHead = head;
        while(curHead != NULL)
        {
            Node* tempNext = curHead -> next;
            curHead -> next = NULL;
            delete curHead;
            curHead = tempNext;
        }
    }
};

int main()
{
    {
        LinkedList<int> linkedList;
        linkedList.PushBack(5);
        linkedList.PushBack(9);
        linkedList.PushBack(7);
        linkedList.Insert(1, 2);
        linkedList.PrintElementsUsingRecurssion();
        linkedList.Remove(0);
        linkedList.PrintElementsUsingItteration();
        linkedList.PushBack(1);
        linkedList.PushBack(2);
        linkedList.PushBack(3);
        linkedList.PrintElementsUsingRecurssion();
        linkedList.Insert(4, 4);
        linkedList.PrintElementsUsingItteration();
        linkedList.ReverseListUsingItteration();        
        linkedList.PrintElementsUsingRecurssion();
        linkedList.PrintElementsReverseUsingRecurssion();
        cout << "--------" << endl;
        linkedList.PrintElementsUsingRecurssion();
        linkedList.ReverseListUsingRecurssion();
        linkedList.PrintElementsUsingRecurssion();
        cout << "--------" << endl;
        linkedList.PushFront(0);
        linkedList.PrintElementsUsingRecurssion();
        linkedList.PopFront();
        linkedList.PopFront();
        linkedList.PushFront(8);
        linkedList.PrintElementsUsingRecurssion();
        cout << linkedList.TopFront() << endl;
    }

    return 0;
}