#include <string>
#include <vector>
#include <numeric>

using namespace std;

struct TruckInfo
{
	int l;
	int w;
};

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int time = 0;
	vector<TruckInfo> load;

	int current_weight = 0;
	auto t = truck_weights.begin();

	while (t != truck_weights.end() || !load.empty())
	{
		++time;

		for (auto& truck : load)
		{
			++truck.l;
		}


		if (!load.empty() && load.front().l > bridge_length)
		{
			current_weight -= load.front().w;
			load.erase(load.begin());
		}


		if (t != truck_weights.end())
		{

			if (current_weight + *t <= weight)
			{
				load.push_back({ 1, *t });
				current_weight += *t;
				++t;
			}
		}
	}

	return time;
}
