#ifndef LIGHT_H
#define LIGHT_H

#include <modules/objects/sphere.h>
#include <modules/ray.h>
#include <modules/random.h>

class Light : public Sphere
{
public:
    Light();

    virtual bool is_light() { return true; }
private:
};

#endif // LIGHT_H
