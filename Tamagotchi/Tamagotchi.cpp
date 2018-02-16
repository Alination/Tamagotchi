#include "Tamagotchi.h"

Tamagotchi::Tamagotchi()
{
	std::cout << "You got a Tamagotchi, yay! Please take care of it. :)\n";
}


Tamagotchi::~Tamagotchi()
{
	std::cout << "Poor Tamagotchi passed away because of your awful care. You should feel bad. >:(";
}

void Tamagotchi::Play()
{
	PlayerInput();
}

bool Tamagotchi::IsAlive()
{
	return mAlive;
}

void Tamagotchi::Die(Death cause)
{
	switch (cause)
	{
	case stroked:
		std::cout << "Tamagotchi got so happy that it got a heart attack.\n";
		break;
	case exploded:
		std::cout << "Tamagotchi ate so much that it exploded.\n";
		break;
	case overdosed:
		std::cout << "Tamagotchi had so many medicines it overdosed.\n";
		break;
	case depressed:
		std::cout << "Tamagotchi was so depressed that it killed itself.\n";
		break;
	case starved:
		std::cout << "Tamagotchi starved to death.\n";
		break;
	case sick:
		std::cout << "Tamagotchi died of sickness.\n";
		break;
	}

	mAlive = false;
}

void Tamagotchi::PlayerInput()
{
	int input = 0;
	while (IsAlive())
	{
		std::cout << "Tamagotchi is " << GetHappinessStr() << ", " << GetHungerStr() << ", " << GetHealthStr() << ".\n" << "Enter 1 to pet, 2 to feed or 3 to give medicine:\n";
		std::cin >> input;

		switch (input)
		{
		case 1:
			AddHappiness();
			break;
		case 2:
			AddHunger();
			break;
		case 3:
			AddHealth();
			break;
		}
	}
	
}

void Tamagotchi::AddHappiness()
{
	mHappiness++;
	if (mHappiness == 5)
	{
		mCauseOfDeath = stroked;
		Die(mCauseOfDeath);
	}
	else
	{
		SubHunger();
		if (FlipCoin())
		{
			SubHealth();
		}
	}
}

void Tamagotchi::AddHunger()
{
	mHunger++;
	if (mHunger == 5)
	{
		mCauseOfDeath = exploded;
		Die(mCauseOfDeath);
	}
	else
	{
		SubHappiness();
		if (FlipCoin())
		{
			SubHealth();
		}
	}
}

void Tamagotchi::AddHealth()
{
	mHealth++;
	if (mHealth == 5)
	{
		mCauseOfDeath = overdosed;
		Die(mCauseOfDeath);
	}
	else
	{
		SubHunger();
	}
}

void Tamagotchi::SubHappiness()
{
	mHappiness--;
	if (mHappiness == 0)
	{
		mCauseOfDeath = depressed;
		Die(mCauseOfDeath);
	}
}

void Tamagotchi::SubHunger()
{
	mHunger--;
	if (mHunger == 0)
	{
		mCauseOfDeath = starved;
		Die(mCauseOfDeath);
	}
}

void Tamagotchi::SubHealth()
{
	mHealth--;
	if (mHealth == 0)
	{
		mCauseOfDeath = sick;
		Die(mCauseOfDeath);
	}
}

std::string Tamagotchi::GetHappinessStr()
{
	switch (mHappiness)
	{
	case 1:
		return "depressed";
	case 2:
		return "sad";
	case 3:
		return "happy";
	case 4:
		return "very happy";
	}
}

std::string Tamagotchi::GetHungerStr()
{
	switch (mHunger)
	{
	case 1:
		return "starving";
	case 2:
		return "hungry";
	case 3:
		return "full";
	case 4:
		return "very full";
	}
}

std::string Tamagotchi::GetHealthStr()
{
	switch (mHealth)
	{
	case 1:
		return "very sick";
	case 2:
		return "sick";
	case 3:
		return "healthy";
	case 4:
		return "drugged";
	}
}
