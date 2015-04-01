
#include <fstream>
#include <assert.h>
#include<iostream>
#include <cassert>

using namespace std;


template<class xtype>
struct node{
    
    xtype info;
    node *next;
    node *back;
    
};

template<class xtype>
class Queue
{
private:
    
    node<xtype> *rear;
    node<xtype> *front;
    int length;
    
public:
    Queue();
    bool isEmpty();
    bool isFull();
    void enQueue(xtype queueElement);
    void deQueue(xtype &queueElement);
    void makeEmpty();
    void printQueue();
};

template<class xtype>
Queue<xtype>::Queue()
{
    rear = NULL;
    front = NULL;
    length=0;
}

template<class xtype>
bool Queue<xtype>::isEmpty()
{
    return (front == NULL);
}

template<class xtype>
bool Queue<xtype>::isFull()
{
    
    node<xtype> *p = new node<xtype>;
    
    if ( p == NULL )
        return true;
    else{
        delete p;
        return false;
    };
}

template<class xtype>
void Queue<xtype>::enQueue(xtype data)
{
    
    node<xtype> *temp = new node<xtype>;
    
    temp->info = data;
    
    temp->next = NULL;
    
    if(front == NULL){
        
        front = temp;
        
    }else{
        
        node<xtype> *p = front;
        
        while ( p->next != NULL)
            p = p->next;
        
            p->next=temp;
        
    }
    rear = temp;
    length++;
    
}

template<class xtype>
void Queue<xtype>::deQueue(xtype &element)
{
    
    node<xtype> *temp;
    
    if(front == NULL)
    {
        cout<<"\nQueue is Emtpty\n";
        
    }
    else
    {
        element=front->info;
        temp = front;
        front = front->next;
        
        delete temp;
        
    }
    length--;
}

template<class xtype>
void Queue<xtype>::printQueue()
{

    
    node<xtype> *p;
    
    p = front;
    
    if(front == NULL){
        
        cout<<"\nNothing to Display\n";
        
    }else{
        
        while(p!=NULL){
            
            cout<<p->info<<" ";
            
            p = p->next;
            
        }
        
    }
    cout<<endl;
}

template <class xtype>
void Queue<xtype> :: makeEmpty()
{
    
    node<xtype> *p;
    
    while ( front != NULL )
    {
        p = front;
        front = front->next;
        delete p;
    }
    length=0;
}
template<class xtype>
class stack
{
private:
    int length; // hold the length of the stack
    int max;    // maximum elements in the stack
    xtype *info;    // will hold the elements of the stack
public:
    stack(int);     // constructor intialize the stack to the maximum of elements
    ~stack();       // destructor to destroy the stack
    bool isFull();  // return true if the stack is full otherwise return false
    bool isEmpty(); // return true if the stack is empty otherwise return false
    void pop(xtype &item);     // delete the top element from the stack
    void push(xtype);   // add a new element to the stack
    void print();       // print the stack, need for debug
    
};

template <class xtype>
stack<xtype>::stack(int m)
{
    length=-1;
    max=m;
    info=new xtype [max];
}

template <class xtype>
stack<xtype>::~stack()
{
    delete [] info;
}

template <class xtype>
bool stack<xtype>::isFull()
{
    return (length+1)==max;
}

template <class xtype>
bool stack<xtype>::isEmpty()
{
    return (length==-1);
}

template <class xtype>
void stack <xtype>::pop(xtype &item)
{
    assert(!isEmpty());
    item = info[length];
    length--;
}

template <class xtype>
void stack<xtype>::push(xtype item)
{
    if (!isFull())
        info[++length]=item;
}


template <class xtype>
void stack<xtype>::print()
{
    for(int i=0;i<=length;i++)
    {
        std::cout<<info[i]<<" ";
    }
}


template <class xtype>
class dlist
{
public:
    node<xtype> *head; //head of the link list
    node<xtype> *last;  // tail of the likn list
    node<xtype> *temp;  // a pointer used to step through the list
    node<xtype> *current; // // another pointer used to step through the list needed for the LargeInt class
    int length;         //length of the list
public:
    dlist(); // constructor
    ~dlist(); // destructor
    dlist ( const dlist<xtype> & other); //copy constructor
    dlist<xtype>& operator= ( const dlist<xtype> & other); ///assignment operator overloading
    void copyList( const dlist<xtype> & other); // copy function called by the copy constructor and the assignment operator overloading
    bool isFull();  // return true if the list is full else return false
    bool isEmpty(); // return true if the list is empty else return false
    void makeEmpty();   // function to destroy the list called by the destructor
    void insertItem ( xtype ); // insert a the front of the list
    int getlength();        //return the length of the list
    void printList ();  // print the list
    void deleteItem(xtype); // delete item in the list
    bool searchItem(xtype); // look the item and return true if find else return true
};



template <class xtype>
dlist<xtype> :: dlist()
{
    head = last=NULL;
    length=0;
}

template <class xtype>
dlist<xtype> :: ~dlist()
{
    makeEmpty();
}

template <class xtype>
void dlist<xtype> :: makeEmpty()
{
    
    node<xtype> *p;
    
    while ( head != NULL )
    {
        p = head;
        head = head->next;
        delete p;
    }
    length=0;
}

template <class xtype>
bool dlist<xtype> :: isEmpty()
{
    return head == NULL;
}

template <class xtype>
bool dlist<xtype> :: isFull()
{
    node<xtype> *p = new node<xtype>;
    
    if ( p == NULL )
        return true;
    else{
        delete p;
        return false;
    }
}

template <class xtype>
dlist<xtype> :: dlist ( const dlist<xtype> & other )
{
    head = NULL;
    copyList (other);
}

template <class xtype>
dlist<xtype>& dlist<xtype>:: operator= ( const dlist<xtype> & other )
{
    copyList (other);
    return *this;
}

template <class xtype>
void dlist<xtype>:: copyList ( const dlist<xtype> & other )
{
    node<xtype> *temp;
    node<xtype> *p;
    
    if ( head != NULL )
        makeEmpty();
    
    if ( other.head == NULL )
        head = NULL;
    else
    {
        length=other.length;
        p = other.head;
        head = new node<xtype>;
        
        head->info = p->info;
        head->next = head->back = NULL;
        
        temp = head;
        p = p->next;
        
        while ( p != NULL )
        {
            temp->next = new node<xtype>;
            temp->next->info = p->info;
            temp->next->next = NULL;
            temp->next->back = temp;
            temp = temp->next;
            p = p->next;
        }
        last=temp;
    }
}

template <class xtype>
void dlist<xtype> :: printList()
{
    if ( head == NULL )
        cout<<"LIST IS EMPTY";
    else
    {
        node<xtype> *p = head;
        
        while ( p != NULL )
        {
            cout<<p->info<<"  ";
            p = p->next;
        }
    }
}


template <class xtype>
void dlist<xtype> :: insertItem( xtype item )
{
    if ( isFull() )
        cout<<"\nLIST IS FULL";
    else
    {
        node<xtype> *temp = new node<xtype>;
        temp->info = item;
        
        if ( head == NULL )
        {
            temp->next =temp->back = NULL;
            head=last=temp;
        }
        else
        {
            node<xtype> *p = head;
            
            while ( p->next != NULL)
                p = p->next;
            
            temp->next = NULL;
            p->next=temp;
            temp->back = p;
            last=temp;
        }
        length++;
    }
    
}

template <class xtype>
bool dlist<xtype> :: searchItem( xtype item )
{
    if ( head == NULL )
        cout<<"LIST IS EMPTY";
    else
    {
        node<xtype> *p = head;
        
        while ( p != NULL && p->info <= item )
        {
            if ( p->info == item )
                return true;
            p = p->next;
        }
    }
    return false;
}

template <class xtype>
void dlist<xtype> :: deleteItem( xtype item )
{
    if ( head == NULL )
        cout<<"\nLIST IS EMPTY";
    else
    {
        node<xtype> * r = head;
        
        if ( head->info == item )
        {
            delete r;
            head = head->next;
            length--;
        }
        else
        {
            while ( r != NULL  && r->info < item )
                r = r->next;
            
            if ( r != NULL && r->info == item )
            {
                r->back->next = r->next;
                if ( r->next != NULL )
                    r->next->back = r->back;
                if(r->next==NULL)
                    last=r->back;
                delete r;
                length--;
            }
            else  cout <<"\nITEM NOT IN THE LIST";
        }
    }
}

template <class xtype>
int dlist<xtype>::getlength()
{
    return length;
}


template <class xtype>
class Graph
{
    
    private :
    dlist<xtype> * graph;
    int numVertices;
    int maxSize;
    bool *visited;
    xtype *vertices;
    
public:
    Graph(int size);
    void makeEmptyGraph();   // function to destroy the list called by the destructor
    bool isEmpty();
    bool isFull();
    void addVertex(xtype v);
    void addEdge(xtype v1, xtype v2);
    void deleteVertex(xtype v);
    void deleteEdge(xtype v1, xtype v2);
    bool isVisited(xtype v);
    void resetVisited();
    void setVertexVisited(xtype v);
    void getVertices(xtype v, Queue<xtype> &q);
    void dfs(xtype starv);
    void bfs(xtype starv);
    
};
template<class xtype>
Graph<xtype>::Graph(int size)
{
    maxSize = size;
    numVertices = 0;
    graph = new dlist<xtype> [maxSize];
    vertices = new xtype[maxSize];
    visited =new bool [maxSize];
    for (int i =0; i<maxSize; i++)
        visited[i]=false;
    
}
template<class xtype>
void Graph<xtype>::makeEmptyGraph()
{
    
    for (int i =0; i<numVertices; i++)
        graph[i].makeEmpty();
    delete [] graph;
    delete [] visited;
    delete [] vertices;
    numVertices= 0;
    
    
}
template<class xtype>
bool Graph<xtype>::isEmpty()
{
    return numVertices==0;
}
template<class xtype>
bool Graph<xtype>::isFull()
{
    return numVertices==maxSize;
}
template<class xtype>
void Graph<xtype>::addVertex(xtype v)
{
    
    for (int i =0; i<numVertices; i++)
    {
        if(vertices[i]==v)
        {
            cout<<"The vertex is already in the tree";
            return;
        }
    }
    vertices[numVertices]= v;
    numVertices++;
}

template<class xtype>
void Graph<xtype>::deleteVertex(xtype v)
{
    int position = -1;
    if(isEmpty())
        cout<<" The graph is Empty";
    else
    {
        for (int i= 0; i<numVertices; i++)
        {
            if(vertices[i]==v)
                position=i;
        }
        if(position==-1)
        {
            cout<<" The edge is not the in the tree";
            return;
        }
        else
        {
            for (int i= 0; i<numVertices; i++)
            {
                node<xtype> *p= graph[i].head;
                while(p!=NULL)
                {
                    if(p->info==v)
                        graph[i].deleteItem(v);
                    p=p->next;
                }
                
                graph[position].makeEmpty();
                graph[position]=graph[numVertices];
                numVertices--;
                
            }
        }
        
        
    }
    
}

template<class xtype>
void Graph<xtype>::setVertexVisited(xtype v)
{
    int position;
    for (int i =0; i<numVertices; i++)
    {
        if(vertices[i]==v)
            position=i;
    }
    visited[position]=true;
    
}

template<class xtype>
void Graph<xtype>::resetVisited()
{
    for (int i =0; i<numVertices; i++)
        visited[i]=false;
    
}
template<class xtype>
bool Graph<xtype>::isVisited(xtype v)
{
    int position;
    for (int i =0; i<numVertices; i++)
    {
        if(vertices[i]==v)
            position=i;
    }
    return visited[position]==true;
}


template<class xtype>
void Graph<xtype>::addEdge(xtype v1, xtype v2)
{
    int position1 = -1;
    int position2  = -1;
    if(!isFull())
    {
        for (int i= 0; i<numVertices; i++)
        {
            if(vertices[i]==v1)
                position1=i;
            
            if(vertices[i]==v2)
                position2=i;
        }
        if(position1==-1)
        {
            cout<<v1<<" is not the in the tree";
            return;
        }
        else if(position2==-1)
        {
            cout<<v2<<" is not the in the tree";
            return;
        }
        else
            graph[position1].insertItem(v2);
    }
    
}

template<class xtype>
void Graph<xtype>::deleteEdge(xtype v1, xtype v2)
{
    int position = -1;
    if(isEmpty())
        cout<<" The graph is Empty";
    else
    {
        for (int i= 0; i<numVertices; i++)
        {
            if(vertices[i]==v1)
                position=i;
        }
        if(position==-1)
        {
            cout<<" The edge is not the in the tree";
            return;
        }
        else
            graph[position].deleteItem(v2);
        
    }
    
}

template<class xtype>
void Graph<xtype>::getVertices(xtype v, Queue<xtype> &qu)
{
    int position = -1;
    if(isEmpty())
        cout<<" The graph is Empty";
    else
    {
        for (int i= 0; i<numVertices; i++)
        {
            if(vertices[i]==v)
                position=i;
        }
        if(position==-1)
        {
            cout<<" The vertices is not the in the tree";
            return;
        }
        else
        {
            node<xtype> *p= graph[position].head;
            while(p!=NULL)
            {
                qu.enQueue(p->info);
                p=p->next;
            }
        }
    }
    
}


template<class xtype>
void Graph<xtype>::dfs(xtype starv)
{
    Queue<xtype> q;
    stack<xtype> s(20);
    xtype v1, v2;
    resetVisited();
    s.push(starv);
    
    do
    {
        s.pop(v1);
        if(!(isVisited(v1)))
        {
            setVertexVisited(v1);
            cout<<v1<<" ";
            getVertices(v1, q);
            while (!(q.isEmpty()))
            {
                q.deQueue(v2);
                if(!(isVisited(v2)))
                    s.push(v2);
            }
        }
        //cout<<" -> ";s.print();cout<<"<-   ";
    }while(!(s.isEmpty()));
    cout<<endl;
} //end breadthFirstTraversal

template<class xtype>
void Graph<xtype>::bfs(xtype starv)
{
    Queue<xtype> q1;
    Queue<xtype> q2;
    xtype v1, v2;
    resetVisited();
    q1.enQueue(starv);
    
    do
    {
        q1.deQueue(v1);
        if(!isVisited(v1))
        {
            setVertexVisited(v1);
            cout<<v1<<" ";
            getVertices(v1, q2);
            while (!(q2.isEmpty()))
            {
                q2.deQueue(v2);
                if(!isVisited(v2))
                    q1.enQueue(v2);
            }
        }
    }while(!(q1.isEmpty()));
    cout<<endl;
} //end breadthFirstTraversal


int main()
{
    

/*** Create the graph g***/
    Graph<char> g(10);
    
 /*** Adding Vertices in the graph g***/
    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');
    g.addVertex('E');
    g.addVertex('F');
    g.addVertex('G');

 /*** Adding Edges in the graph g***/
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('A', 'G');
    g.addEdge('G', 'F');
    g.addEdge('F', 'C');
    g.addEdge('B', 'D');
    g.addEdge('D', 'E');
    g.addEdge('E', 'D');
    g.addEdge('F', 'D');
   
    cout<<" This is the Death First Search : ";
    g.dfs('A');                                 // Death First Search
    cout<<endl<<" This is the Breadth First Search : ";
    g.bfs('A');                                 // Breadth First Search
    
    cout<<endl<<" These are the vertices adjacent to A: ";
    Queue<char> qu;                             // the queue will hold the adjacent vertices
    g.getVertices('A', qu);                     // get adjacent vertices
    qu.printQueue();                            // print adjacent vertices
    
    cout<<endl<<" These are the vertices adjacent to A after deletion of the vertex G: ";
    g.deleteVertex('G');                        // delete the vertex G
    qu.makeEmpty();                             // empty the queue before using it again
    g.getVertices('A', qu);
    qu.printQueue();
    
    return 0;
    
}




