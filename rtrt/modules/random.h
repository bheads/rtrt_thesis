#ifndef RANDOM_H
#define RANDOM_H

#include <cstddef>
#include <ctime>

#include <boost/random/uniform_real.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>

class Random
{
	public:

		static float getf();
		static float getf (float min, float max);
		static Random *instance();

	private:
		static Random *_instance;

		boost::mt19937 igen;
		boost::variate_generator<boost::mt19937, boost::uniform_real<> > gen;

		Random();
};

#endif // RANDOM_H
