#include "performancemonitor.h"

PerformanceMonitor *PerformanceMonitor::_instance = NULL;


PerformanceMonitor::PerformanceMonitor()
    : GL_FPS("GL Frame Rate"),
      RT_FPS("Ray Trace Frame Rate"),
      RPS("Rays/Sec")
{
}

/*
PerformanceMonitor &PerformanceMonitor::instance()
{
    if(_instance == NULL)
    {
        _instance = new PerformanceMonitor();
    }

    return(*_instance);
}
*/

void PerformanceMonitor::update()
{
    GL_FPS.update();
    RT_FPS.update();
    RPS.update();
}


std::ostream &operator <<(std::ostream &out, PerformanceMonitor &pm)
{
    return(out << pm.GL_FPS << std::endl << pm.RT_FPS << std::endl << pm.RPS << std::endl);
}
