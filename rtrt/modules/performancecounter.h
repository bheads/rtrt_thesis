#ifndef PERFORMANCECOUNTER_H
#define PERFORMANCECOUNTER_H

// STL
#include <iostream>
#include <iomanip>
#include <string>

// BOOST
#include <boost/cstdint.hpp>

// GLFW
#include <GL/glfw.h>

class PerformanceCounter
{
public:
    PerformanceCounter(std::string name);

    inline void count() { ++_count; } // use this quickly count
    void update(); // use this to update the rate

    inline float rate() { return _rate; }
    inline float aerage_rate() { return _average_rate; }

    friend std::ostream &operator<<(std::ostream &out, PerformanceCounter &pc);
private:
    boost::uint64_t _count;
    float _rate, _average_rate;
    float _update_time;
    std::string _name;
};

std::ostream &operator<<(std::ostream &out, PerformanceCounter &pc);

#endif // PERFORMANCECOUNTER_H
