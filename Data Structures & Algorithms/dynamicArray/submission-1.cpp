class DynamicArray {
public:
    int *arr;
    int length;
    int capacity;

    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->length = 0;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (length == capacity) {
            resize();
        }

        arr[length] = n;
        length++;
    }

    int popback() {
        int temp = arr[length - 1];
        length--;
        return temp;
    }

    void resize() {
        capacity *= 2;

        int *new_arr = new int[capacity];

        for (int i = 0; i < length; i++) {
            new_arr[i] = arr[i];
        }

        delete[] arr;

        arr = new_arr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};
