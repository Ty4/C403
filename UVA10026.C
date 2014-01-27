/* by Tyler Davidson
 *
 * Shoemaker's Problem: 	NONTRIVIAL	(Sorting)
 *
*/

#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

typedef struct Job
{
	unsigned int name;
	float timeReq;
	float finePerDay;

	Job(int _name, int _time, int _fine) :
		name(_name), timeReq(_time), finePerDay(_fine){}

	// const void print() const
	// {
	// 	printf("Name: %2d\tTime Needed: %10.0f\tDaily Fine: %10.0f\n",
	// 		name, timeReq, finePerDay);
	// }

	const bool operator<(const Job & rhs) const
	{
		double rhsCPD = rhs.timeReq / rhs.finePerDay;
		double myCPD = timeReq / finePerDay;

		if (myCPD < rhsCPD) return true;
		else if (myCPD == rhsCPD)
			return name < rhs.name;

		return false;
	}
} Job;

int main()
{
	int cases;

	scanf("%d", &cases);
	while (cases > 0){
		int N;
		int time, fine;
		set<Job> jobSet;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i){
			scanf("%d %d", &time, &fine);
			Job job(i+1, time, fine);
			jobSet.insert(job);
		}


		for (set<Job>::iterator it = jobSet.begin(); it != jobSet.end(); ++it)
			cout << (*it).name << " ";
		if (cases > 1)
			cout << "\n\n";
		else
			cout << endl;

		jobSet.clear();
		--cases;
	}

	return 0;
}