
#include <random>
#include <chrono>
#include "rand.h"

float ZTORf()
{
	static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
	static std::mt19937 mgen(ss);
	static std::uniform_real_distribution<float> unif(0, 1);
	return unif(mgen);
}

double ZTOR()
{
	static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
	static std::mt19937 mgen(ss);
	static std::uniform_real_distribution<double> unif(0, 1);
	return unif(mgen);
}

int ZOOR()
{
	static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
	static std::mt19937 mgen(ss);
	static std::uniform_int_distribution<std::mt19937::result_type> dist2(0, 1);
	return dist2(mgen);
}

int NTKR(int n, int k)
{
	static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
	static std::mt19937 mgen(ss);

	if (n <= k)
	{
		std::uniform_int_distribution<std::mt19937::result_type> ntkd(n, k);
		return ntkd(mgen);
	}
	else
	{
		std::uniform_int_distribution<std::mt19937::result_type> ntkd(k, n);
		return ntkd(mgen);
	}
}

double NTKR(double n, double k)
{
	static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
	static std::mt19937 mgen(ss);

	if (n <= k)
	{
		std::uniform_real_distribution<double> ntkd(n, k);
		return ntkd(mgen);
	}
	else
	{
		std::uniform_real_distribution<double> ntkd(k, n);
		return ntkd(mgen);
	}
}