// 0614_arrayList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <class T> 
class MyArrayList {
private: 
    T* _arr; 
    size_t _size; 
    size_t _capacity; 

    bool goodIndex(int index) const { return 0 <= index and index < _size;  }
    
    bool isFull() const { return _size == _capacity; }

    bool isEmpty() const { return _size == 0; }

public: 
    MyArrayList() :
        _arr{ new T[8] }, _size{ 0 }, _capacity{ 8 } {} 

    // rule-of-three functions will be added later. 

    size_t size() const { return _size; }

    T& at(int index) { 
        if (!goodIndex(index)) { std::cerr << "invalid index.\n"; exit(1); }
        return _arr[index]; 
    }

    const T& at(int index) const {
        if (!goodIndex(index)) { std::cerr << "invalid index.\n"; exit(1); }
        return _arr[index];
    }

    void push_back(T t) {
        if (isFull())
        {
            // doubleCapacity(); 
            push_back(t); 
        }
        _arr[_size] = t; 
        _size++; 
    }

    void pop_back() {
        if (isEmpty()) {
            std::cerr << "empty arraylist. Cannot call pop.\n";
            exit(1);
        }
        _size--; 
    }

    T& front() {
        if (isEmpty()) {
            std::cerr << "empty arraylist. Cannot call front.\n";
            exit(1);
        }

        return _arr[0];
    }

    const T& front() const {
        if (isEmpty()) {
            std::cerr << "empty arraylist. Cannot call front.\n";
            exit(1);
        }

        return _arr[0];
    }

    T& back() {
        if (isEmpty()) {
            std::cerr << "empty arraylist. Cannot call back.\n";
            exit(1);
        }

        return _arr[_size - 1]; 
    }

    const T& back() const {
        if (isEmpty()) {
            std::cerr << "empty arraylist. Cannot call back.\n";
            exit(1);
        }

        return _arr[_size - 1];
    }

    // allow user to insert a value at valid index.
    // when array is emtpy and index is 0, call push_back
    void add_at_index(int index, T t) {
        if (isEmpty() && index == 0) {
            push_back(t); 
            return; 
        }
        
        if (!goodIndex(index)) { std::cerr << "invalid index.\n"; exit(1); }
        if (isFull()) {
            //doubleCapacity(); 
            add_at_index(index, t); 
        } 
        
        for (int i = _size - 1; i >= index; --i) {
            _arr[i + 1] = _arr[i]; 
        }
        _arr[index] = t; 

        _size++; 

    }

};

template <class T> 
void testFunction(const MyArrayList<T>& v) {

    std::cout << v.at(0) << std::endl;

    //v.front() == v.back(); 
    //v.front() = v.back();
}



int main()
{
    MyArrayList<int> v; 
    v.push_back(10); 
    v.push_back(20); 
    v.push_back(10);

    std::cout << v.front() << std::endl;

    v.back() = 30; 

    for (auto i = 0; i < v.size(); ++i) {
        v.at(i) *= 2; 
        std::cout << v.at(i) << std::endl;
    }

    //testFunction(v);


    int s = 0 - 1; 
    std::cout << s << std::endl;
    
}

