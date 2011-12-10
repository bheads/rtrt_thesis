#ifndef LIGHT_H
#define LIGHT_H

#include <modules/objects/sphere.h>
#include <modules/vec4.h>.h>
#include <modules/random.h>

class Light : public Sphere
{
public:
    Light();
    Light(const vec &pos, float r, const color &c);

    virtual bool is_light() { return true; }
private:
};

#endif // LIGHT_H
