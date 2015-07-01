#pragma once

class PixelList;

namespace
{
	// Actually direction
	struct Turn
	{
		char x, y;
	}

	static const TURNS[] =
	{
		Turn{ 0, 1 },  // up
		Turn{ -1, 0 }, // left
		Turn{ 0, -1 }, // down
		Turn{ 1, 0 }   // right
	};
}

class Curve
{
public:
	Curve();
	~Curve();

	void generate(PixelList* pixelList);

private:
	void step();
	void add();

	int _currentTurn = 0, _turnLength = 0, _turnLengthStep = 0, _currentStep = 0;
	PixelList* _pixelList = nullptr;
	Turn position = {};
};

