#include <iostream>
template <typename T>
int partition(T* arr,int start,int end)
{
  T pivot=arr[end];
  int i = start-1;
  
  for(int j = start; j <= end; j++)
  {
    if(arr[j] < pivot)
    {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i+1], arr[end]);
  return (i+1);
}
template <typename T>
void quick_sort(T* arr, int start, int end)
{
  if(start < end)
  {
    int pi=partition(arr,start,end);
    quick_sort(arr,start,pi-1);
    quick_sort(arr,pi+1,end);
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
    int arr[] = {2,4,5,2,3,6,7,3,9};
    print(arr, 9);
    quick_sort(arr, 0, 8);
    print(arr, 9);
    return 0;
}
