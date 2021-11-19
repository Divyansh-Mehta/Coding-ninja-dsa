template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data){
        this -> data = data;
        next = NULL;
    }
};

template <typename T>
class StackLLT{
    private:
    Node<T> *head;
    int size;

    public:
    StackLLT(){
        head = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return head == NULL;
    }

    void push(T element){
        Node<T> *temp = new Node<T>(element);
        temp -> next = head;
        head = temp;
        size++;
    }

    T pop(){
        if (head == NULL){
            return 0;
        }
        Node<T> *temp = head;
        head = head -> next;
        T tempData = temp -> data;
        delete temp;
        size--;
        return tempData;
    }

    T top(){
        if (head == NULL){
            return 0;
        }
        return head -> data;
    }
};