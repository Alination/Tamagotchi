#include "Tamagotchi.h"

int main()
{
	bool keepPlaying = true;

	while (keepPlaying)
	{
		{
			Tamagotchi tama;

			tama.Play();
		}

		std::cout << "Play again? 1 for yes, 0 to exit.\n";
		std::cin >> keepPlaying;
	}

	return 0;
}