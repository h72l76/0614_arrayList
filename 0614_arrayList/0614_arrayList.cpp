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

    void doubleCapacity() {
        // create new space;
        T* temp = new T[_capacity * 2];
        if (!temp) {
            std::cerr << "fail to obtain space. program exit. \n";
            exit(1);
        }

        // copy elements over from old space to new space
        for (auto i = 0; i < _capacity; ++i) {
            temp[i] = _arr[i];
        }

        // delete old space 
        delete[] _arr; 
        _arr = temp; 

        // one last and most important step
        _capacity *= 2; 
    }

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
             doubleCapacity(); 
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
            doubleCapacity(); 
            add_at_index(index, t); 
            return;
        } 
        
        for (size_t i = _size - 1; i >= index; --i) {
            _arr[i + 1] = _arr[i];

            if (i == 0) {
                break; 
            }
        }

        _arr[index] = t; 

        _size++; 

    }

    void del_at_Index(int index) {
        // invalid index 
        if (!goodIndex(index)) {
            std::cerr << "invalid index. \n";
            exit(1);
        }

        for (auto i = index; i < _size - 1; i++) {
            _arr[i] = _arr[i + 1]; 
        }

        _size--; 
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

    for (auto i : { 10, 20, 30, 40, 50, 60, 70 })
        v.push_back(i);

    v.add_at_index(0, 5); 
    v.add_at_index(0, 0);

    for (int i = 0; i < v.size(); ++i) {
        std::cout << v.at(i) << " ";
    }

    std::cout << std::endl;

    // delete number 10 at index 2 
    v.del_at_Index(2); 

    for (int i = 0; i < v.size(); ++i) {
        std::cout << v.at(i) << " ";
    }


    

    //testFunction(v);

    
}

