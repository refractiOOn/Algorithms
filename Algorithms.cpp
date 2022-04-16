#include <iostream>
#include <vector>
#include <functional>

void QuickSort(std::vector<int>& vec)
{
	if (vec.size() < 2) return;

	std::function<int(std::vector<int>&, int, int)> ChoosePivot = [&](std::vector<int>& vec, int startIndex, int endIndex)
	{
		int midIndex = (startIndex + endIndex) / 2;
		std::vector<int> temp = { startIndex, midIndex, endIndex };
		int mean = (vec[startIndex] + vec[midIndex] + vec[endIndex]) / 3, median = midIndex;
		int minDeviation = INT_MAX;
		for (auto el : temp)
		{
			int curDeviation = abs(mean - vec[el]);
			if (curDeviation < minDeviation)
			{
				minDeviation = curDeviation;
				median = el;
			}
		}

		return median;
	};

	std::function<void(std::vector<int>&, int, int)> Sort = [&](std::vector<int>& vec, int startIndex, int endIndex)
	{
		int vecSize = vec.size();

		int a = startIndex, b = endIndex, pivot = vec[ChoosePivot(vec, startIndex, endIndex)];
		//int a = startIndex, b = endIndex, midIndex = (startIndex + endIndex) / 2, midValue = vec[midIndex];

		while (a <= b)
		{
			while (vec[a] < pivot) ++a;
			while (vec[b] > pivot) --b;

			if (a <= b)
			{
				std::swap(vec[a], vec[b]);
				++a;
				--b;
			}
		}

		if (a < endIndex) Sort(vec, a, endIndex);
		if (b > startIndex) Sort(vec, startIndex, b);
	};

	Sort(vec, 0, vec.size() - 1);
}

void HeapSort(std::vector<int>& vec)
{
	int size = vec.size();
	std::function<void(std::vector<int>&, int, int)> Heapify = [&](std::vector<int>& vec, int vecSize, int index)
	{
		int left = 2 * index + 1;
		if (vecSize - 1 < left) return; // if no children (no left means no right too)

		int right = 2 * index + 2, largest = index;

		// detecting largest number
		if (left < vecSize and vec[left] > vec[largest]) largest = left; // comparing left child with current largest
		if (right < vecSize and vec[right] > vec[largest]) largest = right; // comparing right child with current largest

		if (largest != index) // if root element is not largest
		{
			std::swap(vec[index], vec[largest]); // swapping root element with his largest child
			Heapify(vec, vecSize, largest); // sorting ex-largest child with it's new value
		}
	};

	for (int a = size / 2 - 1; a >= 0; --a) Heapify(vec, size, a); // beginning with latest element in penultimate level

	for (int a = size - 1; a >= 0; --a)
	{
		std::swap(vec[0], vec[a]); // sending root (cuz it's largest) element to the end of vector, last element is now a root of a tree
		Heapify(vec, a, 0); // sorting tree cuz of having a new root
	}
}

void SelectionSort(std::vector<int>& vec)
{
	int vecSize = vec.size();
	for (int pos = vecSize - 1; pos >= 0; --pos)
	{
		int maxElPos = 0;
		for (int i = 0; i <= pos; ++i) if (vec[i] > vec[maxElPos]) maxElPos = i;

		if (maxElPos != pos) std::swap(vec[pos], vec[maxElPos]);
	}
}

void InsertionSort(std::vector<int>& vec)
{
	int vecSize = vec.size();
	if (vecSize < 2) return;

	for (int pos = 1; pos < vecSize; ++pos)
	{
		int a = pos - 1, value = vec[pos];
		while (a >= 0 and vec[a] > value) --a;

		if (++a == pos) continue;

		std::copy(vec.begin() + a, vec.begin() + pos, vec.begin() + a + 1);
		vec[a] = value;
	}
}

void ShakerSort(std::vector<int>& vec)
{
	int endPos = vec.size() - 1;
	for (int startPos = 0; startPos < endPos; ++startPos)
	{
		for (int a = startPos; a < endPos; ++a)
		{
			if (vec[a] > vec[a + 1]) std::swap(vec[a], vec[a + 1]);
		}
		for (int a = endPos - 1; a > startPos; --a)
		{
			if (vec[a] < vec[a - 1]) std::swap(vec[a], vec[a - 1]);
		}
		--endPos;
	}
}

void BubbleSort(std::vector<int>& vec)
{
	int vecSize = vec.size();
	for (int a = vecSize - 1; a > 0; --a)
	{
		for (int b = 0; b < a; ++b)
		{
			if (vec[b] > vec[b + 1]) std::swap(vec[b], vec[b + 1]);
		}
	}
}

int main()
{
	std::vector<int> vec{ 6, 7, 4, 5, 9, 1, 2, 8, 3, 11, 19, 25, 12, 10, 16 };
	//BubbleSort(vec);
	//ShakerSort(vec);
	QuickSort(vec);
	//InsertionSort(vec);
	//SelectionSort(vec);
	//HeapSort(vec);
	for (auto el : vec) std::cout << el << std::endl;
}