class dynamicArray{
    private:
    int *data;
    int nextIndex;
    int capacity;
    public:
    dynamicArray(){
        nextIndex = 0;
        data = new int[5];
        int size = 5;
    }

    dynamicArray(dynamicArray const& d){
       this -> data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++){
            this -> data[i] = d.data[i];
        }
        this -> nextIndex = d.nextIndex;
        this -> capacity = d.capacity;
    }

    void operator=(dynamicArray const &d){
        this -> data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++){
            this -> data[i] = d.data[i];
        }
        this -> nextIndex = d.nextIndex;
        this -> capacity = d.capacity;
    }
    void add(int element){
        if (nextIndex == capacity){
            int *newData = new int[2 * capacity];
            for(int i = 0; i < capacity; i++){
                newData[i] = data[i];
            }
            delete []data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int get(int index) const{
        if (index >= nextIndex){
            return -1;
        }
        return data[index];
    }

    void add(int element, int i){
        if (i > nextIndex){
            return;
        }
        else if(i < nextIndex){
            data[i] = element;
        }
        else{
            add(element);
        }
    }
    void print() const{
        for(int i = 0; i < nextIndex; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};