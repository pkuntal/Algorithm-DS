//#include <iostream>
//#include <map>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//void main()
//{
//	int64_t n = 250;
//	vector<int64_t> c{ 41, 34, 46, 9, 37, 32, 42, 21, 7, 13, 1, 24, 3, 43, 2, 23, 8 ,45, 19, 30, 29, 18, 35, 11 };
//	vector<int64_t>::iterator itr_b = c.begin();
//	vector<int64_t>::iterator itr_e = c.end();
//
//	sort(itr_b, itr_e);
//
//	map<pair<int, int>, vector<vector<int64_t>>> store;
//	for (int i = 0; i < c.size(); i++)
//	{
//
//		for (int j = 0; j <= n; j++)
//		{
//			vector<vector<int64_t>> prev;
//
//			if (i > 0)
//			{
//				pair<int, int> p;
//				p = make_pair(i - 1, j);
//				prev = store[p];
//				
//			}
//
//			int sum = j;
//			if (sum >= c[i])
//			{
//				if (i > 0) {
//					int h = 1;
//
//					while (sum > 0)
//					{
//						vector<int64_t>t;
//						for (int l = 0; l < h; l++) {
//							t.push_back(c[i]);
//						}
//							pair<int, int> p = make_pair(i - 1, j -h*c[i]);
//							vector<vector<int64_t>> temp = store[p];
//							for (auto k : temp)
//							{
//								for (auto j : k)
//								{
//									if (j != 0 && j != -1)
//									{
//										t.push_back(j);
//									}
//								}
//							}
//							int s = 0;
//							for (auto g : t)
//							{
//								s = s + g;
//							}
//							if (s == j)
//							{
//								prev.push_back(t);
//							}
//						//}
//						
//						sum = sum - c[i];
//						h++;
//					}
//					
//				}
//				else
//				{
//					if (sum % c[i] == 0)
//					{
//						vector<int64_t>t;
//						for (int k = 0; k< (sum / c[i]); k++)
//						{
//							t.push_back(c[i]);
//						}
//						prev.push_back(t);						
//					}
//					else
//					{
//						vector<int64_t> w;
//						w.push_back(0);
//						prev.push_back(w);
//
//					}
//
//				}
//			}
//			else
//			{
//				vector<int64_t> w;
//				if (j == 0 && prev.size() == 0)
//				{
//					w.push_back(-1);
//					prev.push_back(w);
//				}
//				if (prev.size() == 0 && j != 0)
//				{
//					w.push_back(0);
//					prev.push_back(w);
//				}
//
//			}
//			store[pair<int, int>(i, j)] = prev;
//		}
//
//	}
//	pair<int, int>p;
//	p = make_pair(c.size() - 1, n);
//	//store
//	for (auto i : store[p])
//	{
//		cout << endl;
//		for (auto j : i) 
//		{
//
//			cout << j << ",";
//		}
//	}
//
//}

#include <iostream>
#include <map>
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
	
	//delete[] * dArray;
	delete[] dArray;
}


int64_t getWays(const int64_t n, const int r, vector<int64_t> c)
{
	//int64_t **A = AllocateDynamicArray<int64_t>(r, n);
	int64_t A[52][251] = { 0 };
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
	return A[r-1][n];
	//FreeDynamicArray<int64_t>(A);


}

void main()
{
	const int64_t n = 219;

	//vector<long> c{ 5 ,37, 8, 39, 33, 17, 22, 32, 13, 7, 10, 35, 40, 2, 43, 49, 46, 19, 41, 1, 12, 11, 28 };
	vector<int64_t> c{ 36, 10, 42, 7, 50, 1, 49, 24, 37, 12, 34, 13, 39, 18, 8, 29, 19, 43, 5, 44, 28, 23, 35, 26 };

	vector<int64_t>::iterator itr_b = c.begin();
	vector<int64_t>::iterator itr_e = c.end();
	sort(itr_b, itr_e);
	const int r = c.size();
	int64_t ways = getWays(n, r, c );
	cout << ways;
}