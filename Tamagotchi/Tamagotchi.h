#pragma once
#include "CoinFlip.h"
#include <iostream>
#include <string>

class Tamagotchi
{
	enum Death
	{
		stroked,
		exploded,
		overdosed,
		depressed,
		starved,
		sick
	};

	Death mCauseOfDeath;

	int mHappiness = 3;
	int mHunger = 2;
	int mHealth = 3;
	bool mAlive = true;

	void PlayerInput();
	bool IsAlive();
	void Die(Death cause);

	void AddHappiness();
	void AddHunger();
	void AddHealth();

	void SubHappiness();
	void SubHunger();
	void SubHealth();

	std::string GetHappinessStr();
	std::string GetHungerStr();
	std::string GetHealthStr();

public:
	Tamagotchi();
	~Tamagotchi();

	void Play();
};

