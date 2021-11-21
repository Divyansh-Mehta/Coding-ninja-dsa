template <typename T>
class StackArrayT{
  private:
    T *data;
    int nextIndex;
    int capacity;

    public:
    StackArrayT(){
        data = new T[5];
        nextIndex = 0;
        capacity = 5;
    }

    // size of stack or number of elements in stack
    int size(){
        return nextIndex;
    }

    // To check if stack is empty
    bool isEmpty(){
        /*
        if (nextIndex == 0){
            return true;
        }
        return false;
          */
         return nextIndex == 0;  
    }

    // Insert element in stack
    void push(T element){
        if (nextIndex == capacity){
            T *newData = new T[capacity * 2];
            for (int i = 0; i < capacity; i++){
                newData[i] = data[i];
            }
            delete data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex++] = element;
    }

    // Remove element from stack
    T pop(){
        if (isEmpty()){
            cout << "Stack Empty" << "\n";
            return 0;
        }

        return data[--nextIndex];
    }

    // Return top element
    T top(){
        if(isEmpty()){
            cout << "Stack Empty" << "\n";
            return 0;
        }
        return data[nextIndex - 1];
    }
};