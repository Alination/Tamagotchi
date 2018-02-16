#include <iostream>


int FlipCoin()
{
	if (rand() % 10 + 1 == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
