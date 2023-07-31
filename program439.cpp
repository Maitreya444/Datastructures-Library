#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for singly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for doubly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
    public:
        struct NodeS<T> * first;
        int iCount;

    SinglyLL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyLL <T>::SinglyLL()
{
    first = NULL;
}

template <class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements of Singly Linear Linked list are : "<<"\n";

    NodeS<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp= temp -> next;
        }
        temp->next = newn;
    }
    iCount++;

}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp ->next -> next!= NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{
    int iCount = Count();

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;

        newn-> data = no;
        newn-> next = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp -> next = newn;
        
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int iCount = Count();

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;
        
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly circular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public:
        struct NodeS<T> * first;
        struct NodeS<T> * last;
        int iCount;

    SinglyCL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyCL <T>::SinglyCL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    NodeS<T> * temp = first;

    if(first != NULL && last != NULL)
    {   
        cout<<"Elements of singly circular linked list are"<< "\n";
        for(int iCnt =1; iCnt <= iCount; iCnt++)
        {
            cout<<"| "<<temp -> data<<" |->";
            temp = temp -> next;
        }
        cout<<"NULL"<<"\n";
    }
    else
    {
        cout<<"Linked List is empty\n";
    }
    iCount++;
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;
    
    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))  // LL is empty
    {
        first = newn;
        last = newn;
    }
    else        // LL contains atleast one node
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if ((first == NULL) && (last == NULL)) // LL is empty
    {
        first = newn;
        last = newn;
    }
    else // LL contains at least one node
    {
        last->next = newn;
        last = newn;
        last->next = first; // Update last node's next to point back to the first node for circular behavior
    }
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
        int iLength = 0;
    NodeS<T> *temp = first;
    int iCnt = 0;

    //PNODE newn = NULL;

    iLength = Count();

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }

        //NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;

        newn->data = no;
        newn->next = NULL;

        newn->next = temp->next;
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if((first == NULL) && (last == NULL))        // A
    {
        return;
    }
    else if(first == last)       // B
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else        // C
    {
        first = first -> next;
        delete last ->next;
        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if ((first == NULL) && (last == NULL)) // List is empty
    {
        return;
    }
    else if (first == last && first != NULL) // Only one node in the list
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeS<T> *temp = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }

        delete last;
        last = temp;
        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int iLength = 0;
    NodeS<T> * temp = first;
    int iCnt = 0;

    NodeS<T> * tempX= NULL;

    iLength = Count();

    if((iPos < 1) || (iPos > iCount))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }

        tempX = temp->next;

        temp->next = temp->next->next;
        delete tempX;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    public:
        struct NodeD<T> * first;
        int iCount;

    DoublyLL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int); 
};

template <class T>
DoublyLL <T>::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    NodeD<T> * temp = first;

    cout<<"Elements of Doubly Linear Linked List are : "<<"\n";

    cout<<"NULL <=> ";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"  |<=>";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    //PNODE newn = NULL;

    NodeD<T> * newn = new NodeD<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;      // #

    if(first == NULL)       // LL is empty
    {
        first = newn;
    }
    else                    // LL contains atleast one node in it
    {
        first->prev = newn;       // #
        newn->next = first;
        first = newn;
    }
     iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    NodeD<T> * newn = new NodeD<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;      // #

    if(first == NULL)       // LL is empty
    {
        first = newn;
    }
    else                    // LL contains atleast one node in it
    {   
        NodeD<T> * temp = first;
        while(temp->next != NULL)   // type 2
        {
            temp = temp -> next;
        }

        temp->next = newn;
        newn->prev = temp;      // #
    }
     iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {   
        NodeD<T> * temp = first;
        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }

        NodeD<T> * newn = new NodeD<T>;;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;      // #

        newn->next = temp->next;        //      1
        temp->next->prev = newn;        // #    2
        temp->next = newn;              //      3
        newn->prev = temp;              // #    4
        
        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(first == NULL)                   // LL is empty
    {
        return;
    }
    else if(first->next == NULL)      // LL contains 1 node
    {
        delete first;
        first = NULL; 
    }
    else                                // LL contains more than one node
    {  
        NodeD<T> * temp = first;

        first = first -> next;
        delete temp->prev;        // #
        temp -> prev = NULL;       // #
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{   
    NodeD<T> * temp = first;

    if(first == NULL)                   // LL is empty
    {
        return;
    }
    else if(first->next == NULL)      // LL contains 1 node
    {
        delete first;
        first = NULL; 
    }
    else                                // LL contains more than one node
    {
        while(temp -> next -> next != NULL)     // Type 3
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount --;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {   NodeD<T> * newn = new NodeD<T>;
        NodeD<T> * temp = first;
        NodeD<T> * tempX = NULL; 

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }
        tempX = temp -> next;
        temp -> next = temp -> next -> next;

        delete tempX;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly cicular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    public:
        struct NodeD<T> * first;
        struct NodeD<T> * last;
        int iCount;

    DoublyCL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int );
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int );
};

template <class T>
DoublyCL <T>::DoublyCL()
{
    last = NULL;
}

template <class T>
void DoublyCL<T>::Display()
{
    NodeD<T> * temp = first;

    cout<<"Elements of Doubly Circular Linked List are : "<<"\n";

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    /*
        PNODE newn = new NODE;
        newn->data = ino;
        newn->next = NULL;
        newn->prev = NULL;
    */

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }

    last -> next = first;
    first -> prev = last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = last -> next;
    }

    last -> next = first;
    first -> prev = last;
    
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * temp = first;

        for(int icnt = 1; icnt < iPos -1; icnt++)
        {
            temp = temp->next;
        }

        NodeD<T> * newn = new NodeD<T>;;

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(iCount == 0)         // LL is empty
    {
        return; 
    }
    else if(iCount == 1)        // LL contains one node
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else        // LL contains more than one node
    {
        first = first->next;
        delete last->next;      // delete First->prev;

        first->prev = last;
        last->next = first;
    }

    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{   
    NodeD<T> * temp = first;
    if(iCount == 0)         // LL is empty
    {
        return; 
    }
    else if(iCount == 1)        // LL contains one node
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else        // LL contains more than one node
    {
        last = last -> prev;
        delete last->next;

        first->prev = last;
        last->next = first;
    }

    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> * newn = new NodeD<T>;
        NodeD<T> * temp = first;

        for(int icnt = 1; icnt < iPos -1; icnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// Entry Point function
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    //SinglyCL <int>obj5;
    SinglyLL <int>obj1;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.InsertLast(101);
    obj1.InsertLast(111);

    obj1.InsertAtPos(55,4);
    obj1.Display();
    cout<<"Number of elements are : "<<obj1.Count()<<"\n";

    obj1.DeleteAtPos(4);
    obj1.Display();
    cout<<"Number of elements are : "<<obj1.Count()<<"\n";

    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();
    cout<<"Number of elements are : "<<obj1.Count()<<"\n";

    SinglyLL <char>obj2;

    obj2.InsertFirst('C');
    obj2.InsertFirst('B');
    obj2.InsertFirst('A');

    obj2.InsertLast('D');
    obj2.InsertLast('E');

    obj2.Display();
    cout<<"Number of elements are : "<<obj2.Count()<<"\n";


    SinglyLL <double>obj3;

    obj3.InsertFirst(90.90);
    obj3.InsertFirst(80.80);
    obj3.InsertFirst(70.70);

    obj3.InsertLast(60.60);
    obj3.InsertLast(50.50);

    obj3.Display();
    cout<<"Number of elements are : "<<obj3.Count()<<"\n";

    DoublyLL <int>obj6;
    int iRet = 0;

    obj6.InsertFirst(51);
    obj6.InsertFirst(21);
    obj6.InsertFirst(11);
    obj6.InsertLast(101);
    obj6.InsertLast(111);

    obj6.Display();
    iRet = obj6.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
    
    obj6.DeleteFirst();
    obj6.DeleteLast();
    obj6.Display();
    iRet = obj6.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj6.InsertAtPos(55, 4);
    obj6.Display();
    iRet = obj6.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj6.DeleteAtPos(4);
    obj6.Display();
    iRet = obj6.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    DoublyCL <int>obj4;
    obj4.InsertFirst(5111);
    obj4.InsertFirst(2111);
    obj4.InsertFirst(1111);

    obj4.InsertLast(10111);
    obj4.InsertLast(11111);

    obj4.Display();
    cout<<"Length of Linked list is : "<<obj4.Count()<<"\n";

    obj4.InsertAtPos(554,4);
    obj4.Display();
    cout<<"Length of Linked list is : "<<obj4.Count()<<"\n";
  
    obj4.DeleteAtPos(4);
    obj4.Display();
    cout<<"Length of Linked list is : "<<obj4.Count()<<"\n";

    obj4.DeleteFirst();
    obj4.DeleteLast();
    
    obj4.Display();
    cout<<"Length of Linked list is : "<<obj4.Count()<<"\n";

    SinglyCL <int>obj5;
    
    obj5.InsertFirst(51);
    obj5.InsertFirst(21);
    obj5.InsertFirst(11);
    //obj5.InsertLast(101);
    //obj5.InsertLast(111);
    //obj5.DeleteLast();
    //obj5.DeleteFirst();
    //obj5.InsertAtPos(69,2);
    //obj5.DeleteAtPos(2);
    obj5.Display();

    cout<<"Number of elements are : "<<obj5.Count()<<"\n";
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
