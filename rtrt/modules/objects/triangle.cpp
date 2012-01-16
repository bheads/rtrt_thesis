#include "triangle.h"

Triangle::Triangle()
    : Object(),
      _a(),
      _b(),
      _c(),
      _N(),
      _color(),
      _diffuse(0),
      _specular(0),
      _reflection(0)
{
    _color.x = Random::getf();
    _color.y = Random::getf();
    _color.z = Random::getf();

    _a.x = Random::getf(-105, 105);
    _a.y = Random::getf(-105, 105);
    _a.z = Random::getf(-200, 200);

    _b.x = Random::getf(-105, 105);
    _b.y = Random::getf(-105, 105);
    _b.z = Random::getf(-200, 200);

    _c.x = Random::getf(-105, 105);
    _c.y = Random::getf(-105, 105);
    _c.z = Random::getf(-200, 200);

    _N = cross(_b - _a, _c - _a);

    _diffuse = Random::getf();
    _specular = Random::getf();
    _reflection = Random::getf();
    // LOG(INFO) << _pos << "  " << _c;
}


Triangle::Triangle(const vec &a, const vec &b, const vec &c, const color &col)
    : Object(),
      _a(a),
      _b(b),
      _c(c),
      _N(cross(_b - _a, _c - _a)),
      _color(col),
      _diffuse(1),
      _specular(0.5),
      _reflection(0)
{
}

Triangle::~Triangle()
{

}

float Triangle::collision(const Ray &ray, float max)
{
    vec4 q, qp, ap; // the max distance
    at(ray, max, q); // q = ray._o + max * ray._d;
    sub(ray._o, q, qp); // qp = ray._o - q

    float d = dot(qp, _N);
    if( d <= 0.0f) return -1.0f;

    sub(ray._o, _a, ap); // ap = ray._o - _a;
    float t = dot(ap, _N);
    if(t < 0.0f | d < t) return -1.0f;



    /*
        vector p = r.o;
        vector q = r.at( tmax );
        vector qp = p - q;

        float d = dot( qp, N );
        if( d <= 0.0f ) return -1.0f;

        vector ap = p - a;
        float t = dot( ap, N );
        if( t < 0.0f || d < t ) return -1.0f;

        vector e = cross( qp, ap );
        float v = dot( ac, e );
        if( v < 0.0f || d < v ) return -1.0f;
        float w = -dot( ab, e );
        if( w < 0.0f || d < v + w ) return -1.0f;

        return qp.length * (t / d);


      */

    return(-1);
}

vec &Triangle::at(const Ray &ray, float dist, vec &v)
{
    v = ray._o + (dist * ray._d);
    return(v);
}


float Triangle::vec_to(const vec &from, const vec &to, vec &v)
{
    sub(to, from, v);
    //v = to - from;
    return(v.length());
}


vec &Triangle::normal(const vec &at, vec &N)
{
    N = _N;
    return N;
}
