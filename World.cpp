#include "stdafx.h"
#include "World.h"


World::World() : water(true), grassLand(false)
{
	srand(time(NULL));
}


World::~World()
{
}

void World::genRandomLocations() {
	srand(time(NULL));
	int totalSeeds = rand() % totalSeedsPossible + smallestNumSeedsPossible;
	for (int i = 0; i < totalSeeds; i++) {
		std::pair<int, int> seed = std::pair<int, int>(rand() % width, rand() % height);
		rLocations.push_back(seed);
		waterSpaces.push_back(seed);
	}
}

void World::printMap() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (gameWorld[i][j] ->getIsWater() == true) {
				std::cout << "[x]";
			}
			else {
				std::cout << "[ ]";
			}
		}
		std::cout << std::endl;
	}
}

void World::genMap() {
	//Set all tiles to grassland default
	
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			gameWorld[i][j] = &grassLand;
		}
	}
	
	//Set chosen tiles to ocean
	for (int i = 0; i < waterSpaces.size(); i++) {
		std::pair <int, int> loc = waterSpaces.at(i);
		gameWorld[loc.first][loc.second] = &water; //Generates an exception
	}
	//Look into exception handling in C++ and write a try/catch block to handle values outside of the range of the "game board"
	//Also make sure that the program is "mistake proof," meaning the program can't access values outside of the "game board" anywhere in the program
}

/*
/ The idea behind this method is that, for each value we placed in the rLocations, the program will randomly generate an ocean shape
*/
void World::genOceans() {
	//srand(time(NULL));
	int currentBotLength = rand() % 6 + 1;
	int currentTopLength = rand() % 6 + 1;
	int topLength;
	int bottomLength;
	
	for (int i = 0; i < rLocations.size(); i++) {
		std::pair<int, int> center = rLocations.at(i);
		//Add more spaces to the rLocations list
		int oceanLength = rand() % width + 1 ;
		for (int i = 0; i < oceanLength; i++) {
			if (center.second + 1 != width - 1) { //Check out if this statement does what I want it to
				//Update the values the program works with
				topLength = generateTopLength(currentTopLength);
				bottomLength = generateBottomLength(currentBotLength);
				addSpaces(center, topLength, true);
				addSpaces(center, bottomLength, false);
				//Update the current values that will become the next iteration's "prev" values
				currentTopLength = topLength;
				currentBotLength = bottomLength;
				center.second++; //Update the value of the center tile - PROBLEM: center isn't updating
			}
			else break;
		}
		
	}
}

/**
/ For now, keep these two methods separate in case I want to change the parameters of one.
*/

int World::generateBottomLength(int prev) {
	if (prev == 0) prev = 1;
	return rand() % prev*1.5 + prev / 2;
}


int World::generateTopLength(int prev) {
	if (prev == 0) prev = 1;
	return rand() % prev*1.5 + prev/2;
}

void World::addSpaces(std::pair <int, int> location,int length, bool direction)
{	
	int current = location.first;
	if (direction == true) { //Add water spaces upwards
		//int current = location.first; //Update the current value in the for loop
		for (int i = 0; i < length; i++) {
			std::pair<int, int> newPair;
			if (current == 0) {
				break;
			}
			else {
				current--;
				std::pair<int, int> newPair(current,location.second);
				//std::pair<int, int> newPair(location.first, current);
				waterSpaces.push_back(newPair);
			}

		}
	}

	else { //Add water spaces downwards
		//int current = location.first; //Update the current value in the for loop

		for (int i = 0; i < length; i++) {
			std::pair<int, int> newPair;
			if (current == height-1) {
				break;
			}
			else {
				current++;
				std::pair<int, int> newPair(current, location.second);
				//std::pair<int, int> newPair(location.first, current);
				waterSpaces.push_back(newPair);
			}
		}

	}
}