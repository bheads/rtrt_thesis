#include "performancecounter.h"

PerformanceCounter::PerformanceCounter(std::string name)
    : _count(0),
      _rate(0.0f),
      _average_rate(0.0f),
      _update_time(glfwGetTime()),
      _name(name)
{
}

void PerformanceCounter::update()
{
    float now = glfwGetTime();
    if(now - _update_time >= 1.0f)
    {
        _rate = (float)_count / (now - _update_time);
        _average_rate += _rate;
        _average_rate /= 2.0f;
        _update_time = now;
        _count = 0;
    }
}

std::ostream &operator<<(std::ostream &out, PerformanceCounter &pc)
{
    out << "PC: " << pc._name << "  Rate: " << pc._rate
        << "  Avg: " <<  pc._average_rate;
    return(out);
}
