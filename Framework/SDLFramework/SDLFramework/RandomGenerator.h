#pragma once

#include <ctime>
#include <random>

class RandomGenerator
{
private:

	RandomGenerator(int seed)
	{
		generator.seed(seed);
	};

	std::default_random_engine generator;


public:

	static RandomGenerator& getInstance()
	{
		static RandomGenerator instance((unsigned int)time(NULL));
		return instance;
	}
	RandomGenerator(RandomGenerator const&) = delete;
	void operator=(RandomGenerator const&) = delete;

	int generate(int min, int max);

private:


};
