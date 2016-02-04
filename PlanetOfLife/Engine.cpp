#include "stdafx.h"
#include "Engine.h"
#include <cstdlib>

void Engine::Update() {
	++time;
	Map* copy = new Map(*_worldmap);
	Block* block = nullptr;
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			if ((block = _worldmap->GetBlock(i, j)) != nullptr) {
				int adjacent = _worldmap->GetAdjacentLifeCount(i, j);
				int life = _worldmap->SpotLife(i, j);
				if (!life && (adjacent == 3 || adjacent == 4)) copy->Spawn(i, j, 1);
				else if(!life && adjacent < 3 && rand() % 1000 < 1) copy->Spawn(i, j, 1);
				else if(life && adjacent > 4) copy->Kill(i, j);
			}
		}
	}
	_worldmap = copy;
}