//
//  my_vector.cpp
//  homework
//
//  Created by Serzh Galoyan on 28.05.24.
//
#include "my_vector.hpp"

template <class T>
myvector<T>::myvector():m_size(0),m_capacity(0),ptr(nullptr){}

template <class T>
myvector<T>::myvector(int size):m_size(size),m_capacity(size*2),ptr(new T[size*2]){}

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
