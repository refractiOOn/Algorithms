#include "sortings.h"
#include "search.h"

#include <iostream>

int main()
{
	std::vector<int> vec{ 6, 16, 4, 5, 9, 1, 2, 8, 3, 11, 19, 25, 12, 10, 7 };
	//BubbleSort(vec);
	//ShakerSort(vec);
	//QuickSort(vec);
	//InsertionSort(vec);
	//SelectionSort(vec);
	//HeapSort(vec);
	MergeSort(vec);
	//for (auto el : vec) std::cout << el << std::endl;
	std::cout << BinarySearch(vec, 16) << std::endl;
}