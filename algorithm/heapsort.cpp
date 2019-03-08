#include <iostream>

/*
	힙은 정리되어 있는 것은 아니다. 루트에 최고 큰 수가 와 있는 것일 뿐!!!

	가장 큰 값을 우물에서 퍼올린다는 기분으로 보자!

	부모와 자식을 구하는 공식은 반복이 반복문이 1부터 시작했을 때다. 따라서 힙 길이는 1부터로 하되, 실제 배열 접근은 0부터로 한다.
	힙소트는 일단 힙을 만든다.
	힙을 만들 때는 힙의 절반 부분(바로 밑에 자식이 아무런 자식이 존재하지 않는 부분) 부터 루트까지 heapify해준다.
	루트는 최고 큰 수이므로 최고 작은 수인 heapsize 부분에 있는 수와 바꿔준 뒤 최상단 노드를 heapify 해준다.
	이를 반복. build max heap이 O(n), 각 heapify가 log n 이 n 번이므로 시간복잡도는 nlog n;
*/

using namespace std;

class MaxHeap
{
public:
	MaxHeap(int size, int _length) {
		length = _length;
		heap = new int[10000];
		heap_size = size;
	}

	~MaxHeap() {
		
	}

	int parent(int i){
		return i / 2;
	}
	int left(int i) {
		return 2 * i;
	}
	int right(int i) {
		return 2 * i + 1;
	}

	void max_heapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int largest;
		if (l <= heap_size && heap[l - 1] > heap[i - 1])
		{
			largest = l;
		}
		else
		{
			largest = i;
		}
		if (r <= heap_size && heap[r - 1] > heap[largest - 1])
		{
			largest = r;
		}
		if (largest != i)
		{
			int container = heap[largest - 1];
			heap[largest - 1] = heap[i - 1];
			heap[i - 1] = container;
			max_heapify(largest);
		}
	}

	void build_max_heap() {
		heap_size = length;
		for (int i = length / 2; i >= 1; --i)
		{
			max_heapify(i);
		}
	}

	void heap_sort()
	{
		build_max_heap();
		for (int i = length; i >= 2; --i)
		{
			int container = heap[0];
			heap[0] = heap[i - 1];
			heap[i - 1] = container;
			heap_size = heap_size - 1;
			max_heapify(1);
		}
	}

	int heap_maximum() {
		return heap[0];
	}
	//log n 소요
	int heap_extract_max() {
		if (heap_size < 1) {
			cout << "error : heap underflow" << endl;
			return 0;
		}
		int max = heap[0];
		heap[0] = heap[heap_size - 1];
		max_heapify(1);
		return max;
	}

	void heap_increase_key(int i, int key) {
		if (key < heap[i - 1])
		{
			cout << "error : new key is smaller than current key" << endl;
		}
		heap[i - 1] = key;
		while (i > 1 && heap[parent(i) - 1] < heap[i - 1])
		{
			int container = heap[i - 1];
			heap[i - 1] = heap[parent(i) - 1];
			heap[parent(i) - 1] = container;
			i = parent(i);
		}
	}

	void max_heap_insert(int key) {
		heap_size = heap_size + 1;
		heap[heap_size - 1] = INT_MIN;
		heap_increase_key(heap_size, key);
	}

	int length;
	int *heap;
	int heap_size;
private:
	
};

int main()
{
	int size = 5, length = 5;

	MaxHeap test_heap(size, length);
	for (int i = 0; i < length; i++)
	{
		
	}

	test_heap.heap[0] = 3;
	test_heap.heap[1] = 1;
	test_heap.heap[2] = 2;
	test_heap.heap[3] = 7;
	test_heap.heap[4] = 4;

	test_heap.heap_sort();
	for (int i = 0; i < test_heap.length; i++)
	{
		cout << test_heap.heap[i] << endl;
	}

	MaxHeap test_priority_queue(0, 10);
	test_priority_queue.max_heap_insert(3);
	test_priority_queue.max_heap_insert(1);
	test_priority_queue.max_heap_insert(5);
	test_priority_queue.max_heap_insert(8);
	for (int i = 0; i < 4; i++)
	{
		cout << test_priority_queue.heap_extract_max() << endl;
	}
	return 0;
}