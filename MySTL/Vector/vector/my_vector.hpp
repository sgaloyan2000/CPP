//
//  my_vector.hpp
//  homework
//
//  Created by Serzh Galoyan on 28.05.24.
//

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
    myvector(const myvector& obj);
    myvector(myvector&& obj);
    myvector& operator=(myvector&& obj) noexcept;
    myvector& operator = (const myvector& obj);
    T& operator [] (int index);

    void push_back(const T& obj);
    int get_size();
    int get_capacity();
    bool empty();
    ~myvector();
};
#include "my_vector.tpp"
#endif /* my_vector_hpp */
