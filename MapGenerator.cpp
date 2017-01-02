// MapGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "World.h"
#include <iostream>

int main()
{
	World one;
	one.genRandomLocations();
	one.genOceans();
	one.genMap();
	one.printMap();
    return 0;
}

