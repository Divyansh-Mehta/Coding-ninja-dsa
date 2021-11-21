#include <climits>
#include <iostream>
using namespace std;

class StackUsingArray{
    private:
    int *data;
    int nextIndex;
    int capacity;

    public:
    StackUsingArray(int totalSize){
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
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
    void push(int element){
        if (nextIndex == capacity){
            cout << "Stack Full" << "\n";
            return;
        }
        data[nextIndex++] = element;
    }

    // Remove element from stack
    int pop(){
        if (isEmpty()){
            cout << "Stack Empty" << "\n";
            return INT_MIN;
        }

        return data[--nextIndex];
    }

    // Return top element
    int top(){
        if(isEmpty()){
            cout << "Stack Empty" << "\n";
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};

class StackUsingArrayDynamic{
    private:
    int *data;
    int nextIndex;
    int capacity;

    public:
    StackUsingArrayDynamic(){
        data = new int[5];
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
    void push(int element){
        if (nextIndex == capacity){
            int *newData = new int[capacity * 2];
            for (int i = 0; i < capacity; i++){
                newData[i] = data[i];
            }
            delete []data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex++] = element;
    }

    // Remove element from stack
    int pop(){
        if (isEmpty()){
            cout << "Stack Empty" << "\n";
            return INT_MIN;
        }

        return data[--nextIndex];
    }

    // Return top element
    int top(){
        if(isEmpty()){
            cout << "Stack Empty" << "\n";
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};