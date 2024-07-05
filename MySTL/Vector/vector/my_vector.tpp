#include "my_vector.hpp"

template <class T>
myvector<T>::myvector():m_size(0),m_capacity(0),ptr(nullptr){}

template <class T>
myvector<T>::myvector(int size):m_size(size),m_capacity(size*2),ptr(new T[size*2]){}

template <class T>
myvector<T>::myvector(std::initializer_list<T> initlist):m_size(initlist.size()),m_capacity(2*m_size),ptr(new T[m_capacity])
{
    for(int i=0; i<m_size ;i++)
        ptr[i] = initlist.begin()[i];
}

template <class T>
myvector<T>::myvector(const myvector& obj){
    m_size = obj.m_size;
    m_capacity = obj.m_capacity;
    ptr = new T[m_capacity];
    for (int i=0; i<m_size; ++i){
        ptr[i] = obj.ptr[i];
    }
}
template <class T>
myvector<T>::myvector(myvector&& obj){
    m_size = obj.m_size;
    m_capacity = obj.m_capacity;
    ptr = obj.ptr;
    obj.ptr = nullptr;
    obj.m_size = 0;
    obj.m_capacity = 0;
}

template <class T>
myvector<T>& myvector<T>::operator=(myvector&& obj) noexcept {
    if (this != &obj) {
        delete[] ptr;
        ptr = obj.ptr;
        m_size = obj.m_size;
        m_capacity = obj.m_capacity;
        obj.ptr = nullptr;
        obj.m_size = 0;
        obj.m_capacity = 0;
    }
    return *this;
}

template <class T>
myvector<T>& myvector<T>::operator = (const myvector& obj){
    if(this != &obj){
        delete [] ptr;
        m_size = obj.m_size;
        m_capacity = obj.m_capacity;
        ptr = new T[m_capacity];
        for (int i=0; i<m_size; ++i){
            ptr[i] = obj.ptr[i];
        }
    }
    return *this;
}
template <class T>
T& myvector<T>::operator [] (int index){
    return ptr[index];
}
template <class T>
void myvector<T>::resize(const int& size){
    if(size == m_size){
        return;
    }
    if(size < m_size){
        std::cerr<<"input size is smaller than existing one"<<std::endl;
        return;
    }
    T* temp = new T[size*2];
    for (int i = 0; i < size; ++i)
    {
        if(i<m_size)
            temp[i] = ptr[i];
        else
            temp[i] = T();
    }
    delete[] ptr;
    ptr = temp;
    m_size = size;
    m_capacity = size*2;
    
}
template <class T>
void myvector<T>::reserve(const int& capacity){
    if (capacity <= m_capacity) {
        return;
    }

    T* temp = new T[capacity];
    for (int i = 0; i < m_size; ++i) {
        temp[i] = ptr[i];
    }

    delete[] ptr;
    ptr = temp;
    m_capacity = capacity;
}
template <class T>
void myvector<T>::push_back(const T& obj) {
    if (m_size == m_capacity) {
        m_capacity = (m_capacity == 0) ? 1 : 2 * m_capacity;
        T* temp = new T[m_capacity];
        for (int i = 0; i < m_size; ++i) {
            temp[i] = ptr[i];
        }
        delete[] ptr;
        ptr = temp;
    }
    ptr[m_size++] = obj;
}
template <class T>
int myvector<T>::get_size(){
    return m_size;
}
template <class T>
int myvector<T>::get_capacity(){
    return m_capacity;
}
template <class T>
bool myvector<T>::empty(){
    return (m_size == 0);
}
template <class T>
myvector<T>::~myvector()
{
    delete[] ptr;
    ptr = nullptr;
}
template <class T>
void myvector<T>::pop_back()
{
    if (m_size > 0) {
        --m_size;
        ptr[m_size].~T();
    }
    else
        std::cout<<"Vector is empty"<<std::endl;
}
template <class T>
void myvector<T>::pop_front()
{
    if(m_size > 0){
        ptr[0].~T();
        for(int i=1; i<m_size;i++)
            ptr[i-1] = ptr[i];
        --m_size;
    }
    else
        std::cout<<"Vector is empty"<<std::endl;
}
template <class T>
void myvector<T>::push_front(const T& obj)
{
    if (m_size == m_capacity)
        m_capacity = (m_capacity == 0) ? 1 : 2 * m_capacity;
    
    T* temp = new T[m_capacity];
    for (int i = 1; i <= m_size; ++i)
        temp[i] = ptr[i-1];
    
    temp[0] = obj;
    delete[] ptr;
    ptr = temp;
    ++m_size;
    
}
template <class T>
void myvector<T>::insert(const T& obj, const int& index)
{
    if(index > 0 && index < m_size){
        if (m_size == m_capacity)
            m_capacity = (m_capacity == 0) ? 1 : 2 * m_capacity;
        
        T* temp = new T[m_capacity];
        for (int i = 0; i < index; ++i)
            temp[i] = ptr[i];
        
        temp[index] = obj;
        for (int i = index+1; i<=m_size; i++)
            temp[i] = ptr[i-1];
        
        delete[] ptr;
        ptr = temp;
        ++m_size;
    }
    else if(index == 0){
        this->push_front(obj);
    }
    else if(index == m_size){
        this->push_back(obj);
    }
    else
        std::cout<<"Index is out of range "<<std::endl;
}
template <class T>
void myvector<T>::print(){
    for(int i=0; i<m_size; i++){
        std::cout<<ptr[i]<<" ";
    }
    std::cout<<std::endl;
}
template <class T>
T& myvector<T>::at(const int& index){
    if(index >= m_size){
        throw std::out_of_range("Index is out of range");
    }
    return ptr[index];
}
