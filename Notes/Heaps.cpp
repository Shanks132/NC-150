#include <iostream>
#include <queue>
#include <queue>
using namespace std;

class Heap{
    int arr[100];
    int size;
    public :
    Heap(){
        arr[0] = -1;
        size = 0;
    }
    public :
    void insert(int value){
        size ++;
        int index = size;
        arr[index] = value;

        while(index > 1){
            int parent = index/2;
            
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                break;
            }
        }
    }
    void deleteRootNode(){
        arr[1] = arr[size];
        size = size -1;
        int index = 1;
        print();
        while(index < size){
            int larger=index;
            if(arr[index*2] > arr[larger]){
                larger = index*2;
            }
            if(arr[index*2 +1] > arr[larger]){
                larger = index*2 +1;
            }
            if(larger==index){break;}
            swap(arr[index],arr[larger]);
            index = larger;
            print();
            
        
            
        }
    }
    void print(){
        for(int i =0 ; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout  << endl;
    }
};
void heapify(int arr[], int n, int i){
    int largest = i;    
    int left = 2*i;
    int right = 2*i + 1;

    //base case 
    if(left < n && arr[largest] < arr[left] ){
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest!=i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n){
    int size = n;

    swap(arr[size], arr[1]);
    size--;

    heapify(arr,size,1);

}
int main (){
    Heap h ;
    h.insert(50);
    h.insert(60);
    h.insert(80);
    h.insert(22);
    h.insert(10);
    h.insert(250);
    h.insert(2);
    h.print();
    h.deleteRootNode();
    h.print();

    int arr[6] = {-1,22,9,90,30,20};
    int n =5;
    cout << "input : \n";
    for(int i =0 ; i < n; i++){
        cout << arr[i] << " ";
    }
    for(int i = n/2 ; i > 0; i--){
        heapify(arr,n,i);
    }
    cout << "\nheapified : \n";
    for(int i =0 ; i < n; i++){
        cout << arr[i] << " ";
    }
    cout  << endl;

    cout << "priority_queue";
    priority_queue<int> pq;
    pq.push(1);
    pq.push(4);
    pq.push(6);
    pq.push(8);
    pq.push(2);
    pq.push(42);
    cout << "\n"<< "top - "<< pq.top() 
    <<" size -"<<pq.size();
    pq.pop();
    cout <<" popping an element - new top -"<< pq.top();
    

    priority_queue<int,vector<int>,greater<int>> minHeap;

}