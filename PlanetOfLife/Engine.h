#pragma once

#include "Map.h"

class Engine {
private:
	long time;
	Map* _worldmap;
public:
	inline Engine() : time(0), _worldmap(nullptr) {};
	inline Engine(Map* map) : time(0), _worldmap(map) {};

	inline void SetMap(Map* map) { _worldmap = map; }
	inline Map* GetMap() { return _worldmap; }
	inline char* ShowMap() { return _worldmap->GetString(); }

	void Update();
	inline void UpdateMore(unsigned int time) { while (time--) Update(); }
};