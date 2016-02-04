// PlanetOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "Engine.h"

int main()
{
	Map m;
	Engine e(&m);
	char* str = e.ShowMap();
	printf("Map:\n%s\n", str);
	std::string line;
	std::cin >> line;
	while (line != "exit") {
		if (line == "map") {
			printf("Map:\n%s\n", str);
		}
		else if (line == "spawn") {
			int i, j;
			std::cin >> i >> j;
			e.GetMap()->Spawn(i, j, 1);
		}
		else if (line == "next") {
			e.Update();
		}
		else if (line == "after") {
			unsigned int time;
			std::cin >> time;
			e.UpdateMore(time);
		}
		else if (line == "showtime") {
			while (1) {
				e.Update();
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				printf("Map:\n%s\n", str);
			}
		}
		std::cin >> line;
	}
    return 0;
}

