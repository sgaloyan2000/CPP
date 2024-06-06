#include <iostream>
template <class T>
void bubble_sort(T* arr, int size){
    for(int i=0; i<size;i++){
        for(int j=i; j<size; j++){
            if(arr[i]>arr[j]){
                std::swap(arr[i],arr[j]);
            }
        }
    }
}
template<typename T>
void print(T* arr, int size){
    for(int i = 0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}
int main() {
    int arr[] = {4,5,2,3,6,7,1};
    print(arr, 7);
    bubble_sort(arr, 7);
    print(arr,7);
    return 0;
}
