#include <iostream>
#include <vector>
#include <memory>
#include <exception>
#include <thread>
#include <algorithm>
#include <chrono>

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

template <class T>
class Chunk{
private:
    int _size;
    bool _is_used;
    T* _memory = NULL;
public:
    Chunk(int size)
    :   _size(size)
    ,   _is_used(false)
    {
        _memory =  (T*) malloc(sizeof(T) * size);
        if(_memory == NULL){
            throw std::bad_alloc();
        }
    }

    Chunk(const Chunk<T>& other){
        _size = other._size;
        _is_used = other._is_used;
        _memory = (T*)malloc(sizeof(T) * _size);
        if(_memory == NULL){
            throw std::bad_alloc();
        }
    }

    bool isUsed(){
        return _is_used;
    }

    T* getPointer(){
        return _memory;
    }

    void setUsed(bool u){
        _is_used = u;
    }

    ~Chunk(){
        free(_memory);
    }
};


template<class T>
class GroupOfChunks{
private:
    vector<Chunk<T> > _chunks;
    int _max_size;
    int _used_count;
public:
    GroupOfChunks(int size, int count){
        _chunks =  vector<Chunk<T>>(count, Chunk<T>(size));
        _max_size = size;
        _used_count = 0;
    }


    int numOfUnusedChunks(){
        return _chunks.size() - _used_count;
    }

    int getMaxSize(){
        return _max_size;
    }

    T* getPointer(){
        for(int i = 0; i < _chunks.size(); i++){
            if(!_chunks[i].isUsed()){
                _chunks[i].setUsed(true);
                _used_count++;
                return _chunks[i].getPointer();
            }
        }

        return nullptr;
    }

    bool freePointer(T* p){
        for(int i = 0; i < _chunks.size(); ++i){
            if(_chunks[i].getPointer() == p){
                _used_count--;
                _chunks[i].setUsed(false);
                return true;
            }
        }

        return false;
    }

};


struct GOC{
    int size;
    int count;

    GOC(int _size, int _count){
        size = _size;
        count = _count;
    }
};


template <class T>
class Alloc
{
private:
    vector<GroupOfChunks<T> > _memory;

public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;


    Alloc(vector<GOC >& v)
    {
        sort(v.begin(), v.end(), [](GOC& left, GOC& right){return left.size < right.size;});
        for(GOC group : v){
            _memory.push_back(GroupOfChunks<T>(group.size, group.count));
        }
    }


    pointer allocate(size_type n){
        for(int i = 0; i < _memory.size(); ++i){
            if(_memory[i].getMaxSize() >= n && _memory[i].numOfUnusedChunks() > 0){
                return _memory[i].getPointer();
            }
        }
        
        throw std::bad_alloc();
    }

    void deallocate(pointer p, size_type n){
        for(int i = 0; i < _memory.size(); ++i){
            if(_memory[i].getMaxSize() < n){
                continue;
            }
            else{
                if(_memory[i].freePointer(p)){
                    break;
                }
            }
        }
    }



};


void measure
(
    function<void ()> func
)
{
    auto t1 = high_resolution_clock::now();
    func();
    auto t2 = high_resolution_clock::now();
    
    duration<double, std::milli> ms_double = t2 - t1;
    
    std::cout << ms_double.count() << "ms\n";
}


int main()
{
    vector<GOC> groups = {GOC(200000000, 2)};
 
    Alloc<int>* abob = new Alloc<int>(groups);   


    vector<int, Alloc<int>> v(*abob);

    measure([&]{
        for(int i = 0; i < 100000000; i++){
            v.push_back(i);
        }
    });


    vector<int> v2;

    measure([&]{
        for(int i = 0; i < 100000000; i++){
            v2.push_back(i);
        }
    });

    
    return 0;
}