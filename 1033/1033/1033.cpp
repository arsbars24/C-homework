#include <iostream>
#include <vector>

struct cell {
	int x;
	int y;

};

using namespace std;
vector<char> labyrinth;
vector<bool> mask;

int s = 0;
int WallsCount = 0;
int CountingWall(cell next);



int main() {
	const int wallSquare = 9;
	char in;

	cin >> s;

	cell EntryOne = { 0,0 };
	cell EntryTwo = { s - 1, s - 1 };

	for (int i = 0; i < s * s; i++)
	{
		mask.push_back(false);
	}

	while (std::cin >> in)
	{
		labyrinth.push_back(in);
	}

	WallsCount += CountingWall(EntryOne);
	WallsCount += CountingWall(EntryTwo);

	WallsCount -= 4;

	std::cout << WallsCount * wallSquare;

	return 0;
	

	

};

int CountingWall(cell next) {
	if (next.x < 0 || next.x >= s ||
		next.y < 0 || next.y >= s ||
		labyrinth[s * next.y + next.x] == '#') {
		return 1;
	}
	else if (!mask[s * next.y + next.x]) {
		mask[s * next.y + next.x] = true;
		return
			CountingWall({ next.x - 1, next.y }) +
			CountingWall({ next.x + 1, next.y }) +
			CountingWall({ next.x,     next.y - 1 }) +
			CountingWall({ next.x,     next.y + 1 });
	}
	else
	{
		return 0;
	}
}