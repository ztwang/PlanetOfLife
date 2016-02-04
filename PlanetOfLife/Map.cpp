#include "stdafx.h"

#include "Map.h"

Map::Map() {
	int displayWidth = MAP_WIDTH + 2;
	int displayHeight = MAP_HEIGHT + 2;
	int size = (displayWidth + 2) * (displayHeight + 1);
	_display = new char[size];
	memset(_display, '.', size);
	int lastRow = (displayHeight - 1) * (displayWidth + 2);
	for (int i = displayWidth + 1; i < size; i += displayWidth + 2) {
		_display[i] = '\n';
	}
	_display[size - 1] = 0;
	for (int i = 0; i < displayWidth; ++i) {
		_display[i] = '#';
		_display[lastRow + i] = '#';
	}
	for (int i = 1; i < displayHeight - 1; ++i) {
		_display[i * (displayWidth + 2)] = '#';
		_display[(i + 1) * (displayWidth + 2) - 3] = '#';
	}
}

Map::~Map() {
	delete[] _display;
}

Block* Map::GetBlock (int i, int j) {
	if (
		i >= MAP_HEIGHT || i < 0 ||
		j >= MAP_WIDTH || j < 0)
		return nullptr;
	return &(_map[i][j]);
}

unsigned int Map::Spawn(int i, int j, unsigned int life) {
	int result;
	if (result = SpotLife(i, j)) return result;
	_map[i][j].life = life;
	_UpdateMapString(i, j, 'X');
	return life;
}

void Map::Kill(int i, int j) {
	if (SpotLife(i, j) > 0) {
		_map[i][j].life = 0;
	}
	_UpdateMapString(i, j, '.');
}

int Map::SpotLife(int i, int j) {
	if (
		i >= MAP_HEIGHT || i < 0 ||
		j >= MAP_WIDTH || j < 0)
		return -1;
	else return _map[i][j].life;
}

int Map::GetAdjacentLifeCount(int i, int j) {
	if (
		i >= MAP_HEIGHT || i < 0 ||
		j >= MAP_WIDTH || j < 0)
		return -1;
	int count = 0;
	for (int m = i - 1; m < i + 2; ++m) {
		for (int n = j - 1; n < j + 2; ++n) {
			if (
				m >= MAP_HEIGHT || m < 0 ||
				n >= MAP_WIDTH || n < 0) continue;
			else if (_map[m][n].life > 0) ++count;
		}
	}
	return count;
}

char* Map::GetString() { return _display; }

void Map::_UpdateMapString(int i, int j, char c) {
	int index = _IndexTranslate(i, j);
	if (index >= 0) _display[index] = c;
}

int Map::_IndexTranslate(int i, int j) {
	if (i < 0 || i >= MAP_HEIGHT || j < 0 || j >= MAP_WIDTH) return -1;
	return (i + 1) * (MAP_WIDTH + 4) + j + 1;
}