#include "random.h"

Random *Random::_instance = NULL;

Random::Random()
	: igen(),
	  gen (igen, boost::uniform_real<> (0, 1))
{
	gen.engine().seed (time (NULL));
}

float Random::getf()
{
	return (Random::instance()->gen());
}

float Random::getf (float min, float max)
{
	return ( (Random::instance()->gen() * (max - min)) + min);
}

Random *Random::instance()
{
	if (_instance == NULL)
	{
		_instance = new Random();
	}

	return (_instance);
}
