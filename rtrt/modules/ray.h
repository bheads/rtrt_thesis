#ifndef RAY_H
#define RAY_H

/*
#include <armadillo>
typedef arma::fvec::fixed<3> vec;
*/

#include <eigen3/Eigen/Dense>
typedef Eigen::Vector3f vec;

class Ray
{
public:
    Ray();
    Ray(const vec &o, const vec &d);
    Ray(const Ray &r);

    vec _o, _d;
};

#endif // RAY_H
