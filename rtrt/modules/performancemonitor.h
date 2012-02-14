#ifndef PERFORMANCEMONITOR_H
#define PERFORMANCEMONITOR_H

#include <iostream>

#include <modules/performancecounter.h>

class PerformanceMonitor
{
	public:
		inline static PerformanceMonitor &instance()
		{
			if (_instance == NULL)
			{
				_instance = new PerformanceMonitor();
			}

			return (*_instance);
		}

		PerformanceCounter  GL_FPS;
		PerformanceCounter  RT_FPS;
		PerformanceCounter  RPS;

		void update();

		friend std::ostream &operator<< (std::ostream &out, PerformanceMonitor &pm);
	private:
		PerformanceMonitor();

		static PerformanceMonitor *_instance;
};

std::ostream &operator<< (std::ostream &out, PerformanceMonitor &pm);

#endif // PERFORMANCEMONITOR_H
