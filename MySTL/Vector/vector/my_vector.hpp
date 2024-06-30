#ifndef my_vector_hpp
#define my_vector_hpp

template <class T>
class myvector{
    int m_size;
    int m_capacity;
    T* ptr;
public:
    myvector();
    myvector(int size);
    myvector(std::initializer_list<T> initlist);
    myvector(const myvector& obj);
    myvector(myvector&& obj);
    myvector& operator=(myvector&& obj) noexcept;
    myvector& operator = (const myvector& obj);
    T& operator [] (int index);
    void print();
    void push_back(const T& obj);
    void push_front(const T& obj);
    void insert(const T& obj, const int& index);
    void pop_back();
    void pop_front();
    int get_size();
    int get_capacity();
    void resize(const int&);
    void reserve(const int&);
    bool empty();
    ~myvector();
};
#include "my_vector.tpp"
#endif /* my_vector_hpp */
