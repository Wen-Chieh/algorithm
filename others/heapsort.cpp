/*Heap sort pseudo code:
HeapSort(A)
1 build-max-heap(A)
2 for i = A.length to 2
3   exchange A[1] with A[i]
4   A.heapsize -= 1
5   Max-HEAPIFY(A, 1)*/
class Solution{
private:
    int findParent(int idx){    return (idx - 1) >> 1;}

    void heapify_top_down(int size, vector<int>& heap, int rootIdx){
        int leftIdx = (rootIdx << 1) + 1, rightIdx = (rootIdx << 1) + 2;
        int maxIdx = rootIdx;
        
        if(leftIdx >= size)  return;
        maxIdx = (heap[leftIdx] > heap[maxIdx]) ? leftIdx : maxIdx;
        if(rightIdx < size){
            maxIdx = (heap[rightIdx] > heap[maxIdx]) ? rightIdx : maxIdx;
        }
        
        if(maxIdx == rootIdx)   return;
        
        swap(heap[rootIdx], heap[maxIdx]);
        heapify_top_down(size, heap, maxIdx);
    }

    void buildHeap(vector<int>& heap){
        int size = heap.size();
        for(int i = 1; i < size; i++){
            int idx = i;
            while(idx > 0){
                int parIdx = findParent(idx);
                if(heap[parIdx] < heap[idx])   swap(heap[parIdx], heap[idx]);
                idx = parIdx;
            }
        }
    }
    
public:
    void heapSort(vector<int>& inputVec){
        buildHeap(inputVec);
        int size = inputVec.size();
        for(int i = size - 1; i > 0; i--){
            swap(inputVec[0], inputVec[i]);
            size -= 1;
            heapify_top_down(size, inputVec, 0);
        }
    }    
};
