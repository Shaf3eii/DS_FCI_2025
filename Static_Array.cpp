#include <iostream>

template <typename T,int capacity>
class Array {
    int size { };
    T arr[capacity];
public:
    Array() : size(0) {}; // o(1) time - o(1) memory

    Array (T init_val) : size(capacity) { // o(1) time - o(1) memory
        arr[capacity];
        for(int i = 0 ; i < capacity ; ++i)
            arr[i] = init_val;
        size = capacity;
    }
    // Add an element at the end
    void append(T val) { // o(1) time - o(1) memory
        if(size >= capacity)
            throw std::out_of_range("The Array is Full..\n");

        arr[size++] = val;
    }
    // insert an element at specific location
    void insert(T val, int idx) { // o(n) time - o(1) memory
        if(size >= capacity)
            throw std::out_of_range("The Array is Full..\n");
        if (idx < 0 || idx > size)
            throw std::out_of_range("Index out of range.");

        for(int i = size ; i > idx ; --i)
            arr[i] = arr[i - 1];

        arr[idx] = val;
        size++;
    }
    // remove an element from the end
    void remove() { // o(1) time - o(1) memory
        if(size == 0)
            throw std::runtime_error("The Array is Empty..\n");

        --size;
    }
    // delete an element from specific location
    void delete_(int idx) { // o(n) time - o(1) memory
        if(size == 0)
            throw std::runtime_error("The Array is Empty..\n");

        for(int i = idx ; i < size - 1 ; ++i)
            arr[i] = arr[i + 1];

        --size;
    }
    // get an element at specific location
    T get(int idx) const { // o(1) time - o(1) memory
        if(idx >= size || idx < 0)
            throw std::out_of_range("This index is not valid..\n");

        return arr[idx];
    }
    // return the current size
    int get_size() const { // o(1) time - o(1) memory
        return size;
    }
    // return the max size
    int get_capacity() const { // o(1) time - o(1) memory
        return capacity;
    }
    // reverse array element
    void reverse(int from = 0, int to = 0) { // o(n) time - o(1) memory
        if(size == 0)
            throw std::runtime_error("The Array is Empty..\n");

        if(!to)
            to = get_size() - 1;
        for(int st = from , nd = to ; st < nd ; ++st , --nd) {
            T temp = arr[st];
            arr[st] = arr[nd];
            arr[nd] = temp;
        }
    }
    // look for element --> return it's idx   (Linear Search)
    // We can use binary search --> cons -> arr should be sorted
    int search(T val) const { // o(n) time - o(1) memory
        if(size == 0)
            throw std::runtime_error("The Array is Empty..\n");
        for(int i = 0 ; i < size ; ++i)
            if(arr[i] == val)
                return i; // founded

        return -1; //  does not exist
    }
    // return the max element in the arr
    T max_element() const {
        T Max_soFar = INT_MIN;
        for(int i = 0 ; i < size ; ++i)
            if(Max_soFar < arr[i])
                Max_soFar = arr[i];

        return Max_soFar;
    }
    // return the max element in the arr
    T min_element() const {
        T Min_soFar = INT_MAX;
        for(int i = 0 ; i < size ; ++i)
            if(Min_soFar > arr[i])
                Min_soFar = arr[i];

        return Min_soFar;
    }
    // sort array elements in ascending order
    void sort() {
        if(size == 0)
            throw std::runtime_error("The Array is Empty..\n");
        // we can sort using different algorithms
        // I implemented 3 Algorithms and will explain the pros and cons of each one

        // bubble sort is an efficient algorithm with memory o(1) but it's time is o(n^2)
        // bubble sort is inefficient for large datasets.
        auto bubble_sort = [&](){
            for(int i = 0 ; i < (size - 1) ; ++i) {
                for(int j = 0 ; j < (size - i - 1) ; ++j) {
                    if(arr[j] > arr[j + 1]) {
                        T temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        };
        bubble_sort();

//        // insertion sort is an efficient algorithm with memory o(1) but it's time is o(n^2)
//        // insertion sort is efficient for small datasets or nearly sorted arrays.
//        auto insertion_sort = [&]() {
//            for(int i = 0 ; i < (size - 1) ; ++i) {
//                for(int j = i + 1 ; j > 0 ; --j) {
//                    while(arr[j - 1] > arr[j]) {
//                        T temp = arr[j];
//                        arr[j] = arr[j - 1];
//                        arr[j - 1] = temp;
//                    }
//                }
//            }
//        };
//        insertion_sort();

//        // count sort is an efficient algorithm with time o(n) but it would using o(n) memory
//        // if the range of the elements is big, this algorithm wouldn't work efficiently
//        auto count_sort = [&](){
//            // Assuming T is int and values are in a small known range
//            if constexpr (std::is_integral<T>::value) {
//                int min_val = min_element();
//                int max_val = max_element();
//                std::vector<int> freq[max_val - min_val + 1];
//
//                int idx = 0;
//                for (int i = 0 ; i < (int)freq.size() ; ++i)
//                    while(freq[i]--)
//                        arr[idx++] = i + min_val;
//            }
//        };
//        count_sort();
    }
    // display all elements in the array
    void display() const {
        for(int i = 0 ; i < size ; ++i)
            std::cout << arr[i] << " \n"[i == size - 1];
    }
};

int main() {
    Array<int,10> arr;
    arr.append(5);
    arr.append(1);
    arr.append(12);
    arr.append(45);
    arr.append(31);
    arr.display(); // 5 1 12 45 31
    arr.insert(7,3);
    arr.display(); // 5 1 12 7 45 31
    arr.delete_(1);
    arr.display(); // 5 12 7 45 31
    arr.sort();
    arr.display(); // 5 7 12 31 45
    std::cout << arr.search(7) << '\n'; // 1
    std::cout << arr.search(8) << '\n'; // -1
    std::cout << arr.max_element() << '\n'; // 45
    std::cout << arr.min_element() << '\n'; // 5
    std::cout << arr.get(2) << '\n';   // 12
    arr.reverse();
    arr.display(); // 45 31 12 7 5
    arr.remove();
    arr.display(); // 45 31 12 7

    Array<std::string,5> str;
    str.append("Mahmoud");
    str.append("Salah");
    str.append("ElShafei");
    str.display(); // Mahmoud Salah ElShafei
    str.insert("ElSayed",2);
    str.display(); // Mahmoud Salah ElSayed ElShafei
    str.delete_(2);
    str.display(); // Mahmoud Salah ElShafei
    return 0;
}
