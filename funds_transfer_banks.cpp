

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{
		return lhs < rhs;
	}
};

typedef std::multimap<int, int>::iterator mapiter;
std::multimap<int, int> first;
bool found = false;

int find_key(int val)
{
	std::multimap <int, int> ::iterator iter = first.begin();

	while (iter != first.end()) {
		if (iter->second == val)
		{
			return iter->first;
		}
		iter++;
	}
	return -1;

}


void search(int src, int dest, int max, std::vector<int> &path)
{
	if (std::find(path.begin(), path.end(), dest) != path.end()) {
		found = true;
		if (path.size() <= max) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
		return;
	}
	std::vector<int>::const_iterator f = path.begin();
	std::vector<int>::const_iterator l = path.end();
	std::vector<int> p_path(f, l);

	int p = find_key(src); // up 14
	if (p != -1) { // if p is -1, reached to root.
		if (std::find(p_path.begin(), p_path.end(), p) == p_path.end()){
			p_path.push_back(p); // 16->14
			search(p, dest, max,p_path);
		}
	}
	if (first.count(src) > 0) { // if node has child.
		//std::cout << "val count for " << src << " is" << first.count(src) << std::endl;
		std::pair<mapiter, mapiter> result = first.equal_range(src); // 20 21
		for (mapiter it = result.first; it != result.second; ++it) {
			std::vector<int> p_child(f, l); // 16
			if (std::find(p_child.begin(), p_child.end(), it->second) == p_child.end())
			{
				p_child.push_back(it->second); // 16->20 16->21
				search(it->second, dest, max, p_child);
			}
		}
	}
}

int main() {

	first.insert(std::pair<int, int>(1, 2));
	first.insert(std::pair<int, int>(1, 3));
	first.insert(std::pair<int, int>(1, 4));
	first.insert(std::pair<int, int>(2, 5));
	first.insert(std::pair<int, int>(2, 6));
	first.insert(std::pair<int, int>(5, 7));
	first.insert(std::pair<int, int>(6, 8));	
	first.insert(std::pair<int, int>(3, 9));
	first.insert(std::pair<int, int>(3, 10));
	first.insert(std::pair<int, int>(9, 12));
	first.insert(std::pair<int, int>(9, 11));
	first.insert(std::pair<int, int>(4, 13));
	first.insert(std::pair<int, int>(4, 14));
	first.insert(std::pair<int, int>(14, 15));
	first.insert(std::pair<int, int>(14, 16));
	first.insert(std::pair<int, int>(16, 21));
	first.insert(std::pair<int, int>(16, 20));
	first.insert(std::pair<int, int>(21, 23));
	first.insert(std::pair<int, int>(21, 24));

	std::vector<int>path;
	path.push_back(16);
	search(16, 6, 4, path);

	found = false;

	std::vector<int> p;
	p.push_back(9);
	search(9, 21, 7, p);	

	return 0;
}

