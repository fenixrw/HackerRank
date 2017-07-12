#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Point
{
public:
	int x, y;
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

bool operator < (const Point &a, const Point &b)
{
	if (a.x != b.x)
	{
		return (a.x < b.x);
	}
	else
	{
		return (a.y < b.y);
	}
}

bool operator == (const Point &a, const Point &b)
{
	return ((a.x == b.x) && (a.y == b.y));
}

long moveQueen(int r, int c, int dirR, int dirC, set<Point> &obstacles, int n)
{
	int pR = r + dirR, pC = c + dirC;
	if ((pR < 0 || pR >= n) || (pC < 0 || pC >= n))
	{
		return 0;
	}
	else if (obstacles.find(Point(pR,pC)) != obstacles.end())
	{
		return 0;
	}
	else
	{
		return moveQueen(pR, pC, dirR, dirC, obstacles, n) + 1;
	}
}

long moveQueen(int r, int c, set<Point> &obstacles, int n)
{
	long count = 0;

	count += moveQueen(r, c, 0, 1, obstacles, n);
	count += moveQueen(r, c, 0, -1, obstacles, n);
	count += moveQueen(r, c, 1, 0, obstacles, n);
	count += moveQueen(r, c, -1, 0, obstacles, n);
	count += moveQueen(r, c, -1, 1, obstacles, n);
	count += moveQueen(r, c, 1, -1, obstacles, n);
	count += moveQueen(r, c, 1, 1, obstacles, n);
	count += moveQueen(r, c, -1, -1, obstacles, n);

	return count;
}


int main() {

	int n, k, rq, cq;

	cin >> n >> k >> rq >> cq;

	set<Point> obstacles;

	for (int i = 0; i<k; i++)
	{
		int r, c;
		cin >> r >> c;
		obstacles.emplace(Point(r - 1, c - 1));
	}

	cout << moveQueen(rq - 1, cq - 1, obstacles, n);
    
	return 0;
}
