#include <iostream>

template <typename T>
void merge(T* arr, int const left, int const mid, int const right){
    
    int arr1 = mid-left+1;
    int arr2 = right - mid;
    
    T* left_arr = new T[arr1];
    T* right_arr = new T[arr2];
    
    for(int i=0; i<arr1; i++){
        left_arr[i] = arr[left + i];
    }
    for(int j=0; j<arr2; j++){
        right_arr[j] = arr[mid + j + 1];
    }
    
    int index_of_left = 0;
    int index_of_right = 0;
    int index_of_merged = left;
    
    while (index_of_left < arr1 && index_of_right < arr2){
        if(left_arr[index_of_left] <= right_arr[index_of_right]){
            arr[index_of_merged] = left_arr[index_of_left];
            index_of_left++;
        }
        else{
            arr[index_of_merged] = right_arr[index_of_right];
            index_of_right++;
        }
        index_of_merged++;
    }
    while(index_of_left < arr1){
        arr[index_of_merged] = left_arr[index_of_left];
        index_of_merged++;
        index_of_left++;
    }
    while(index_of_right < arr2){
        arr[index_of_merged] = right_arr[index_of_right];
        index_of_merged++;
        index_of_right++;
    }
}
template <typename T>
void merge_sort(T* arr, int start, int end){
    if(start >= end){
        return;
    }
    int mid = start + (end-start)/2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);
    merge(arr, start, mid, end);
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
    merge_sort(arr, 0, 6);
    print(arr,7);
    
    return 0;
}
