#include "stdafx.h"
#include "Tile.h"


Tile::Tile(bool _isWater)
{
	isWater = _isWater;
}


Tile::~Tile()
{
}

bool Tile::getIsWater(){
	return isWater;
}