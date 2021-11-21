template<typename T>
class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data){
        this -> data = data;
        next = NULL;
    }
};

template<typename T>
class Queue{
    private:
    Node<T> *head;
    Node<T> *tail;
    int size;    
    
    public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T data)
    {
        Node<T> *temp = new Node<T>(data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            size++;
            return;
        }
        tail->next = temp;
        tail = temp;
        size++;
    }

    T dequeue()
    {
        if (size == 0)
        {
            cout << "Queue empty" << endl;
            return 0;
        }
        Node<T> *temp = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        T ans = temp->data;
        delete temp;
        size--;
        return ans;
    }

    T front()
    {
        if (size == 0)
        {
            cout << "Queue Empty" << endl;
            return 0;
        }
        return head->data;
    }
};