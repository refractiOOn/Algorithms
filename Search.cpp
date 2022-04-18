#include "search.h"

bool SequentialSearch(std::vector<int>& pVec, int pTarget)
{
	for (auto el : pVec)
	{
		if (el == pTarget) return true;
	}
	return false;
}

bool BinarySearch(std::vector<int>& pVec, int pTarget)
{
	int low = 0, high = pVec.size() - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (pTarget < pVec[mid]) high = mid - 1;
		else if (pTarget > pVec[mid]) low = mid + 1;
		else return true;
	}
	return false;
}