#pragma once

#define MAP_WIDTH 40
#define MAP_HEIGHT 20

struct Block {
	int environment;
	unsigned int life;
	Block() : environment(0), life(0) {}
};

class Map {
private:
	Block _map[MAP_HEIGHT][MAP_WIDTH];
	char* _display;

	void _UpdateMapString(int i, int j, char c);
	int _IndexTranslate(int i, int j);
public:
	Map();
	~Map();

	int SpotLife(int i, int j);

	unsigned int Spawn(int i, int j, unsigned int life = 1);

	void Kill(int i, int j);

	Block* GetBlock(int i, int j);

	int GetAdjacentLifeCount(int i, int j);

	char* GetString();
};