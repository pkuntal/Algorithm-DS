
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
T **AllocateDynamicArray(int nRows, int nCols)
{
	T **dynamicArray;

	dynamicArray = new T*[nRows];
	for (int i = 0; i < nRows; i++)
		dynamicArray[i] = new T[nCols];

	return dynamicArray;
}

template <typename T>
void FreeDynamicArray(int64_t** dArray)
{
	
	delete[] * dArray;
	delete[] dArray;
}


int64_t getWays(const int64_t n, const int r, vector<int64_t> c)
{
	int64_t **A = AllocateDynamicArray<int64_t>(r, n);


	for (int i = 0; i < r; i++)
	{
		for (int64_t j = 0; j <= n; j++)
		{
			A[i][j] = 0;
		}
	}
	
	for (int i = 0; i < r; i++)
	{
		int64_t val = c[i];
		for (int64_t j = 0; j <= n; j++)
		{
			int64_t sum = j;
			if (j == 0)
			{
				A[i][j] = 0;
			}
			else
			{
				if ((sum > val))
				{
					if (sum % val == 0)
					{
						A[i][j] = A[i][j] + 1;
					}

					if (i != 0)
					{

						int64_t k = 1;
						A[i][j] = A[i][j] + A[i - 1][j];
						while (sum >= k * val)
						{
							int ttt = sum - (k*val);
							A[i][j] = A[i][j] + A[i - 1][sum - (k * val)];
							k++;
						}
					}


				}
				else if (sum == val)
				{
					if (i == 0)
					{
						A[i][j] = 1;
					}
					else
					{
						A[i][j] = A[i - 1][j] + 1;
					}
				}
				else
				{
					if (i != 0) {
						A[i][j] = A[i - 1][j];
					}
					else
					{
						A[i][j] = 0;
					}
				}
			}

		}

	}
	int64_t ret = A[r-1][n];
	FreeDynamicArray<int64_t>(A);

	return ret;


}

void main()
{
	const int64_t n = 219;
	vector<int64_t> c{ 36, 10, 42, 7, 50, 1, 49, 24, 37, 12, 34, 13, 39, 18, 8, 29, 19, 43, 5, 44, 28, 23, 35, 26 };
	vector<int64_t>::iterator itr_b = c.begin();
	vector<int64_t>::iterator itr_e = c.end();
	sort(itr_b, itr_e);
	const int r = c.size();
	int64_t ways = getWays(n, r, c );
	cout << ways;
	return;
}