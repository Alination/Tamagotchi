#include <iostream>


int FlipCoin()
{
	if (rand() % 2 + 1 == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
