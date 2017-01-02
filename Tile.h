#pragma once
class Tile
{
private:
	bool isWater;
public:
	Tile(bool _isWater);
	~Tile();
	bool getIsWater();
};

