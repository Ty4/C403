/* by Tyler Davidson
 *
 * Light and Transparencies:	(Sorting)
 *
*/

#include <cstdio>
#include <set>
#include <vector>

using namespace std;

typedef struct Point{
	double x;
	double y;

	Point() : x(0), y(0) {}
	Point(double _x, double _y) : x(_x), y(_y) {
		if (_x == -0) x = 0;
		if (_y == -0) y = 0;
	}
	Point(const Point &pt) : x(pt.x), y(pt.y) {}

	const bool operator<(const Point & rhs) const
	{
		return x < rhs.x;
	}
} Point;

typedef struct Film{
	double transCoeff;
	pair<Point, Point> endpoints;

	Film(const Point & p1, const Point & p2, double coeff) : transCoeff(coeff)
	{
		if (p2 < p1) endpoints = make_pair(p2, p1);
		else endpoints = make_pair(p1, p2);
	}

	const bool operator<(const Film & rhs) const
	{
		if (rhs.endpoints.first < endpoints.first) return false;
		return endpoints.second < rhs.endpoints.second;
	}

} Film;

int main()
{
	int cases;
	scanf("%d", &cases);

	while (cases-- > 0){
		int NL;
		set<Film> filmSet;
		set<Point> endpointSet;
		vector<Film> filmArray;
		vector<Point> pointArray;

		scanf("%d", &NL);
		while (NL-- > 0){
			double x1, y1, x2, y2, r;
			scanf("%f %f %f %f %f", &x1, &y1, &x2, &y2, &r);
			endpointSet.insert(Point(x1, y1));
			endpointSet.insert(Point(x2, y2));
			filmSet.insert(Film(Point(x1, y1), Point(x2, y2), r));
		}

		for (set<Film>::iterator it = filmSet.begin(); it != filmSet.end(); ++it)
			filmArray.push_back(*it);
		for (set<Point>::iterator it = endpointSet.begin(); it != endpointSet.end(); ++it)
			pointArray.push_back(*it);

		printf("%d\n", pointArray.size()+1);
		printf("-inf %.3f 1.000\n", pointArray[0].x);
		for (int i = 1; i < pointArray.size(); ++i){
			double result = 1.0;

			for (int j = 0; j < filmArray.size(); ++j){
				Point p1 = filmArray[j].endpoints.first;
				Point p2 = filmArray[j].endpoints.second;
				if ((p1.x <= pointArray[i-1].x) && (p2.x >= pointArray[i].x))
					result *= filmArray[j].transCoeff;
			}
			printf("%.3f %.3f %.3f\n", pointArray[i-1].x, pointArray[i].x, result);
			if (i == pointArray.size()-1)
				printf("%.3f +inf 1.000\n", pointArray[i].x);
		}
		if (cases)
			printf("\n");
	}

	return 0;
}