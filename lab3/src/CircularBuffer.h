#ifndef CircularBuffer_H
#define CircularBuffer_H

#include <iostream>
#include <string>


using namespace std;


template<typename T>
class CircularBuffer{
private:
    int capacity;
    int size;
    int b_index;
    int e_index;
    T *arr;
public:
    class Iterator {
    public:
        using difference_type = int;
        using value_type = T;
        using pointer = const T*;
        using reference = const T&;
        using iterator_category = std::random_access_iterator_tag;

        Iterator(T* ptr) : m_ptr(ptr) {}

        Iterator(const Iterator& it){
            m_ptr = it.m_ptr;
        }

        Iterator operator=(const Iterator& it){
            m_ptr = it.m_ptr;
            return Iterator(m_ptr);
        }

        T& operator*() const { return *m_ptr; }

        T* operator->() { return m_ptr; }

        Iterator& operator++() {
            m_ptr++;
            return *this; 
        }

        Iterator operator++(int) { Iterator tmp(m_ptr); ++(*this); return tmp; }

        Iterator& operator--() {
            m_ptr--; 
            return *this; 
        }

        Iterator operator--(int) { Iterator tmp(m_ptr); --(*this); return tmp; }

        friend bool operator==(const Iterator& lhs, const Iterator& rhs) { return lhs.m_ptr == rhs.m_ptr; }

        friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { return lhs.m_ptr != rhs.m_ptr; }

        Iterator& operator+=(int n){
            m_ptr += n;
            return *this;
        }

        friend Iterator operator+(const Iterator& lhs, int n){
            Iterator tmp(lhs.m_ptr);
            return tmp += n;
        }

        friend Iterator operator+(int n, const Iterator& rhs){
            Iterator tmp(rhs.m_ptr);
            return tmp += n;
        }

        Iterator& operator-=(int n){
            m_ptr -= n;
            return *this;
        }

        friend Iterator operator-(const Iterator& lhs, int n){
            Iterator tmp = lhs;
            return tmp -= n;
        }

        friend int operator-(const Iterator& lhs, const Iterator& rhs){
            int n = lhs.m_ptr - rhs.m_ptr;
            return n;
        }

        T operator[](int index){
            return *(m_ptr + index);
        }

        friend bool operator<(const Iterator& lhs, const Iterator& rhs){
            return rhs - lhs > 0;
        }

        friend bool operator>(const Iterator& lhs, const Iterator& rhs){
            return rhs < lhs;
        }

        friend bool operator<=(const Iterator& lhs, const Iterator& rhs){
            return !(lhs > rhs);
        }

        friend bool operator>=(const Iterator& lhs, const Iterator& rhs){
            return !(lhs < rhs);
        }

    private:
        T* m_ptr;
    };


    ~CircularBuffer(){
        delete[] arr;
    }


    CircularBuffer(size_t n)
    :   capacity(n)
    ,   size(0)
    ,   arr(new T[n])
    {}


    void push_back(const T& e){
        if(size < capacity){
            arr[size] = e;
            size++;
        }
        else{
            for(int i = 0; i < capacity - 1; i++){
                arr[i] = arr[i + 1];
            }

            arr[capacity - 1] = e;
        }
    }


    void pop_back(){
        if(size == 0){
            cout << "Error, buffer is empty" << endl;
        }
        else{
            size--;
        }
    }


    void push_front(const T& e){
        if(size < capacity){
            for(int i = capacity - 1; i > 0; i--){
                arr[i] = arr[i - 1];
            }

            arr[0] = e;
            size++;
        }
        else{
            for(int i = capacity - 1; i > 0; i--){
                arr[i] = arr[i - 1];
            }

            arr[0] = e;
        }
    }


    void pop_front(){
        if(size == 0){
            cout << "Error, buffer is empty" << endl;
        }
        else{
            for(int i = 0; i < size - 1; i++){
                arr[i] = arr[i + 1];
            }

            size--;
        }
    }


    friend ostream& operator<<(ostream& os, CircularBuffer& cb){
        for(int i = 0; i < cb.size; i++){
            cout << cb.arr[i] << " ";
        }

        return os;
    }


    Iterator begin(){
        return arr;
    }


    Iterator end(){
        return arr + size;
    }


    T operator[](int index){
        if(index >= size){
            cout << "Error";
            return *(arr + index);
        }
        return *(arr + index);
    }


    void change_capacity(int new_capacity){
        if(new_capacity >= capacity){
            capacity = new_capacity;
        }
        else{
            capacity = new_capacity;
            if(size > capacity){
                size = capacity;
            }
        }
    }

    int get_size(){
        return size;
    }
};
#endif