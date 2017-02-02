#include <stdlib.h>
#include "MainController.h"
#include <functional>
#include <map>
#include <unordered_map>
#include <memory>
#include <queue>
#include <iostream>

int main(int argc, char *argv[])
{
	auto cmp = [](std::pair<double, int> left, std::pair<double, int> right) { return left.first > right.first; };
	std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, decltype(cmp)> frontier(cmp);
	frontier.push(std::make_pair(0, 0));

	frontier.push(std::make_pair(5, 0));
	frontier.push(std::make_pair(1, 0));
	frontier.push(std::make_pair(8, 0));

	while (!frontier.empty())
	{
		auto item = frontier.top();
		frontier.pop();
		cout << item.first << " " << item.second << "\n";
	}

	MainController mController;

	mController.start();

	return 0;
}