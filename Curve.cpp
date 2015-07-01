#include "Curve.h"
#include "PixelList.h"
#include "Variables.h"

#include <vector>

#ifndef _WIN32
#include <math.h>
#endif


Curve::Curve()
{
}


Curve::~Curve()
{
}


void Curve::generate(PixelList* pixelList)
{
	_pixelList = pixelList;

	// Prime generation
	int currentN = 3;
	std::vector<int> primes = { 2, 3 };

	step();
	add(); // 2
	step();
	add(); // 3

	while (currentN < GRAPHLIMIT)
	{
		step();
		step();

		currentN += 2;

		int n_sqrt = (int)sqrt(currentN);
		bool isPrime = true;

		for (size_t i = 0; i < primes.size(); i++)
		{
			if (primes[i] > n_sqrt)
			{
				break;
			}
			if (currentN % primes[i] == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			primes.push_back(currentN);
			add();
		}
	}

	_pixelList = nullptr;
}

void Curve::step()
{
	position.x += TURNS[_currentTurn].x;
	position.y += TURNS[_currentTurn].y;

	_currentStep++;
	if (_currentStep > _turnLength)
	{
		_currentStep = 0;
		_currentTurn = (_currentTurn + 1) % 4;

		_turnLengthStep++;

		if (_turnLengthStep > 1)
		{
			_turnLength++;
			_turnLengthStep = 0;
		}
	}
}

void Curve::add()
{
	_pixelList->add(position.x * PIXEL_SIZE, position.y * PIXEL_SIZE);
}
