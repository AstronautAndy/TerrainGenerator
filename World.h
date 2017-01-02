#pragma once
#include "Tile.h"
#include <utility>
#include <vector>
#include <time.h>
#include <array>
#include <iostream>
class Tile;

class World
{
private:
	int width = 20;
	int height = 20;
	int totalSeedsPossible = 5;
	int smallestNumSeedsPossible = 1;

	int topLengthUBound = 8;
	int topLengthLBound = 3;

	int botLengthUBound = 7;
	int botLengthLBound = 1;

	float centerChangeFactor = 0.10;
	Tile water;
	Tile grassLand;
	Tile * gameWorld[20][20];
	std::vector< std::pair <int, int> > rLocations; //vector of starting locations
	std::vector< std::pair <int, int> > waterSpaces; 
public:
	World();
	~World();
	void genRandomLocations();
	void printMap();
	void genMap();
	void genOceans();
	int generateTopLength(int prev);
	int generateBottomLength(int prev);
	void addSpaces(std::pair <int,int> location , int length, bool direction); //In regards to direction, "True" will handle "up" and "false" will handle "down"
};

