

#include <UnitTest++/UnitTest++.h>

#include <modules/vec4.h>
#include <modules/vec_func.h>
#include <modules/random.h>

#include <eigen3/Eigen/Dense>
typedef Eigen::Vector3f tvec;

#include <cmath>

#define ACC 0.00001

SUITE( VecFuncTests )
{
    TEST( Vec4Addition )
    {
        vec4 a( 1, 2, 3, 4 ), b( 5, 5, 5, 5 );
        vec4 c = a + b;
        CHECK_CLOSE( c.x, a.x + b.x, ACC );
        CHECK_CLOSE( c.y, a.y + b.y, ACC );
        CHECK_CLOSE( c.z, a.z + b.z, ACC );
        CHECK_CLOSE( c.w, a.w + b.w, ACC );

        c = a + 10;
        CHECK_CLOSE( c.x, a.x + 10, ACC );
        CHECK_CLOSE( c.y, a.y + 10, ACC );
        CHECK_CLOSE( c.z, a.z + 10, ACC );
        CHECK_CLOSE( c.w, a.w + 10, ACC );

        c = 10 + b;
        CHECK_CLOSE( c.x, 10 + b.x, ACC );
        CHECK_CLOSE( c.y, 10 + b.y, ACC );
        CHECK_CLOSE( c.z, 10 + b.z, ACC );
        CHECK_CLOSE( c.w, 10 + b.w, ACC );

        vec4 d = +a;
        CHECK_CLOSE( d.x, +a.x, ACC );
        CHECK_CLOSE( d.y, +a.y, ACC );
        CHECK_CLOSE( d.z, +a.z, ACC );
        CHECK_CLOSE( d.w, +a.w, ACC );

        vec4 e( 1, 2, 3, 4 );
        e += a;
        CHECK_CLOSE( e.x, 2, ACC );
        CHECK_CLOSE( e.y, 4, ACC );
        CHECK_CLOSE( e.z, 6, ACC );
        CHECK_CLOSE( e.w, 8, ACC );

        vec4 f( 1, 2, 3, 4 );
        f += 2;
        CHECK_CLOSE( f.x, 1+2.0f, ACC );
        CHECK_CLOSE( f.y, 2+2.0f, ACC );
        CHECK_CLOSE( f.z, 3+2.0f, ACC );
        CHECK_CLOSE( f.w, 4+2.0f, ACC );

        tvec taa, tab, tac;
        vec tba, tbb, tbc;
        taa[0] = tba.x = Random::getf(-10000, 10000);
        taa[1] = tba.y = Random::getf(-10000, 10000);
        taa[2] = tba.z = Random::getf(-10000, 10000);

        tab[0] = tbb.x = Random::getf(-10000, 10000);
        tab[1] = tbb.y = Random::getf(-10000, 10000);
        tab[2] = tbb.z = Random::getf(-10000, 10000);

        tac = taa + tab;
        tbc = tba + tbb;

        CHECK_CLOSE( tac[0], tbc.x, ACC );
        CHECK_CLOSE( tac[1], tbc.y, ACC );
        CHECK_CLOSE( tac[2], tbc.z, ACC );
    }

    TEST( Vec4Subtraction )
    {
        vec4 a( 1, 2, 3, 4 ), b( 5, 5, 5, 5 );
        vec4 c = a - b;
        CHECK_CLOSE( c.x, a.x - b.x, ACC );
        CHECK_CLOSE( c.y, a.y - b.y, ACC );
        CHECK_CLOSE( c.z, a.z - b.z, ACC );
        CHECK_CLOSE( c.w, a.w - b.w, ACC );

        c = a - 10;
        CHECK_CLOSE( c.x, a.x - 10, ACC );
        CHECK_CLOSE( c.y, a.y - 10, ACC );
        CHECK_CLOSE( c.z, a.z - 10, ACC );
        CHECK_CLOSE( c.w, a.w - 10, ACC );

        c = 10 - b;
        CHECK_CLOSE( c.x, 10 - b.x, ACC );
        CHECK_CLOSE( c.y, 10 - b.y, ACC );
        CHECK_CLOSE( c.z, 10 - b.z, ACC );
        CHECK_CLOSE( c.w, 10 - b.w, ACC );
                
        vec4 d = -a;
        CHECK_CLOSE( d.x, -a.x, ACC );
        CHECK_CLOSE( d.y, -a.y, ACC );
        CHECK_CLOSE( d.z, -a.z, ACC );
        CHECK_CLOSE( d.w, -a.w, ACC );

        vec4 e( 1, 2, 3, 6 );
        e -= a;
        CHECK_CLOSE( e.x, 0, ACC );
        CHECK_CLOSE( e.y, 0, ACC );
        CHECK_CLOSE( e.z, 0, ACC );
        CHECK_CLOSE( e.w, 2, ACC );

        vec4 f( 1, 2, 3, 4 );
        f -= 2;
        CHECK_CLOSE( f.x, 1-2.0f, ACC );
        CHECK_CLOSE( f.y, 2-2.0f, ACC );
        CHECK_CLOSE( f.z, 3-2.0f, ACC );
        CHECK_CLOSE( f.w, 4-2.0f, ACC );

        tvec taa, tab, tac;
        vec tba, tbb, tbc;
        taa[0] = tba.x = Random::getf(-10000, 10000);
        taa[1] = tba.y = Random::getf(-10000, 10000);
        taa[2] = tba.z = Random::getf(-10000, 10000);

        tab[0] = tbb.x = Random::getf(-10000, 10000);
        tab[1] = tbb.y = Random::getf(-10000, 10000);
        tab[2] = tbb.z = Random::getf(-10000, 10000);

        tac = taa - tab;
        tbc = tba - tbb;

        CHECK_CLOSE( tac[0], tbc.x, ACC );
        CHECK_CLOSE( tac[1], tbc.y, ACC );
        CHECK_CLOSE( tac[2], tbc.z, ACC );
    }

    TEST( Vec4Multiplication )
    {
        vec4 a( 1, 2, 3, 4 ), b( 5, 5, 5, 5 );
        vec4 c = a * b;
        CHECK_CLOSE( c.x, a.x * b.x, ACC );
        CHECK_CLOSE( c.y, a.y * b.y, ACC );
        CHECK_CLOSE( c.z, a.z * b.z, ACC );
        CHECK_CLOSE( c.w, a.w * b.w, ACC );

        c = a * 10;
        CHECK_CLOSE( c.x, a.x * 10, ACC );
        CHECK_CLOSE( c.y, a.y * 10, ACC );
        CHECK_CLOSE( c.z, a.z * 10, ACC );
        CHECK_CLOSE( c.w, a.w * 10, ACC );

        c = 10 * b;
        CHECK_CLOSE( c.x, 10 * b.x, ACC );
        CHECK_CLOSE( c.y, 10 * b.y, ACC );
        CHECK_CLOSE( c.z, 10 * b.z, ACC );
        CHECK_CLOSE( c.w, 10 * b.w, ACC );

        vec4 e( 1, 2, 3, 4 );
        e *= a;
        CHECK_CLOSE( e.x, 1, ACC );
        CHECK_CLOSE( e.y, 4, ACC );
        CHECK_CLOSE( e.z, 9, ACC );
        CHECK_CLOSE( e.w, 16, ACC );

        vec4 f( 1, 2, 3, 4 );
        f *= 2;
        CHECK_CLOSE( f.x, 2.0f, ACC );
        CHECK_CLOSE( f.y, 4.0f, ACC );
        CHECK_CLOSE( f.z, 6.0f, ACC );
        CHECK_CLOSE( f.w, 8.0f, ACC );

        tvec taa, tab, tac;
        vec tba, tbb, tbc;
        taa[0] = tba.x = Random::getf(-10000, 10000);
        taa[1] = tba.y = Random::getf(-10000, 10000);
        taa[2] = tba.z = Random::getf(-10000, 10000);

        tab[0] = tbb.x = Random::getf(-10000, 10000);
        tab[1] = tbb.y = Random::getf(-10000, 10000);
        tab[2] = tbb.z = Random::getf(-10000, 10000);

        tac = taa.cwiseProduct(tab);
        tbc = tba * tbb;

        CHECK_CLOSE( tac[0], tbc.x, ACC );
        CHECK_CLOSE( tac[1], tbc.y, ACC );
        CHECK_CLOSE( tac[2], tbc.z, ACC );
    }


    TEST( Vec4Diviaion )
    {
        vec4 a( 1, 2, 3, 4 ), b( 5, 5, 5, 5 );
        vec4 c = a / b;
        CHECK_CLOSE( c.x, a.x / b.x, ACC );
        CHECK_CLOSE( c.y, a.y / b.y, ACC );
        CHECK_CLOSE( c.z, a.z / b.z, ACC );
        CHECK_CLOSE( c.w, a.w / b.w, ACC );

        c = a / 10;
        CHECK_CLOSE( c.x, a.x / 10, ACC );
        CHECK_CLOSE( c.y, a.y / 10, ACC );
        CHECK_CLOSE( c.z, a.z / 10, ACC );
        CHECK_CLOSE( c.w, a.w / 10, ACC );

        c = 10 / b;
        CHECK_CLOSE( c.x, 10 / b.x, ACC );
        CHECK_CLOSE( c.y, 10 / b.y, ACC );
        CHECK_CLOSE( c.z, 10 / b.z, ACC );
        CHECK_CLOSE( c.w, 10 / b.w, ACC );

        vec4 e( 1, 2, 3, 8 );
        e /= a;
        CHECK_CLOSE( e.x, 1, ACC );
        CHECK_CLOSE( e.y, 1, ACC );
        CHECK_CLOSE( e.z, 1, ACC );
        CHECK_CLOSE( e.w, 2, ACC );

        vec4 f( 1, 2, 3, 4 );
        f /= 2;
        CHECK_CLOSE( f.x, 1/2.0f, ACC );
        CHECK_CLOSE( f.y, 2/2.0f, ACC );
        CHECK_CLOSE( f.z, 3/2.0f, ACC );
        CHECK_CLOSE( f.w, 4/2.0f, ACC );
    }

    TEST( DotProduct )
    {
        CHECK_CLOSE( dot( vec4( 2.0f, 4.0f ),
                    vec4( 1.0f, 5.0f )), 22, 0.001 );
        CHECK_CLOSE( dot( vec4( 10.0f, 2.0f, 30.0f ),
                    vec4( 3.0f, 9.0f, 4.0f )), 168, 0.001 );
        CHECK_CLOSE( dot( vec4( 1.0f, 2.0f, 3.0f, 4 ),
                    vec4( 9, 8, 7, 6 )), 70, 0.001 );

        tvec taa, tab;
        vec tba, tbb;
        taa[0] = tba.x = Random::getf(-10000, 10000);
        taa[1] = tba.y = Random::getf(-10000, 10000);
        taa[2] = tba.z = Random::getf(-10000, 10000);

        tab[0] = tbb.x = Random::getf(-10000, 10000);
        tab[1] = tbb.y = Random::getf(-10000, 10000);
        tab[2] = tbb.z = Random::getf(-10000, 10000);

        CHECK_CLOSE( taa.dot(tab), dot(tba, tbb), ACC );
        CHECK_CLOSE( tab.dot(taa), dot(tbb, tba), ACC );
    }

    TEST( CrossProduct )
    {
        /*b.set = [1,2,3,0];
            a.set = [9,8,7,0];
                assert( cross(a,b).cell == [10,-20,10,0], "Bad Cross Product" );
                            c.set = 0;
        */
        vec4 a( 3, -3, 1 ), b( 4, 9, 2 );
        vec4 c = cross( a, b );
        CHECK_CLOSE( c.x, -15, ACC );
        CHECK_CLOSE( c.y, -2, ACC );
        CHECK_CLOSE( c.z, 39, ACC );
        CHECK_CLOSE( c.w, 0, ACC );

        vec4 d( 3, -2, -2 ), e( -1, 0, 5 );
        vec4 f = cross( d, e );
        CHECK_CLOSE( f.x, -10, ACC );
        CHECK_CLOSE( f.y, -13, ACC );
        CHECK_CLOSE( f.z, -2, ACC );
        CHECK_CLOSE( f.w, 0, ACC );

        tvec taa, tab, tac;
        vec tba, tbb, tbc;
        taa[0] = tba.x = Random::getf(-10000, 10000);
        taa[1] = tba.y = Random::getf(-10000, 10000);
        taa[2] = tba.z = Random::getf(-10000, 10000);

        tab[0] = tbb.x = Random::getf(-10000, 10000);
        tab[1] = tbb.y = Random::getf(-10000, 10000);
        tab[2] = tbb.z = Random::getf(-10000, 10000);

        tac = taa.cross(tab);
        tbc = cross(tba, tbb);

        CHECK_CLOSE( tac[0], tbc.x, ACC );
        CHECK_CLOSE( tac[1], tbc.y, ACC );
        CHECK_CLOSE( tac[2], tbc.z, ACC );
    }

    TEST( ColorClamp )
    {
        color a( 5.0, 6.0, -4.5, 1.9 ), b( 0.0, 1.0, 0.5, 3.00 );

        color ca = clamped( a );
        CHECK_CLOSE( ca.x, 1.0000, ACC );
        CHECK_CLOSE( ca.y, 1.0000, ACC );
        CHECK_CLOSE( ca.z, 0.0000, ACC );
        CHECK_CLOSE( ca.w, 1.0000, ACC );
        CHECK_CLOSE( a.x, 5.0, ACC );
        CHECK_CLOSE( a.y, 6.0, ACC );
        CHECK_CLOSE( a.z, -4.5, ACC );
        CHECK_CLOSE( a.w, 1.9, ACC );

        color cb = clamped( b, 1.0, 2.0 );
        CHECK_CLOSE( cb.x, 1.0000, ACC );
        CHECK_CLOSE( cb.y, 1.0000, ACC );
        CHECK_CLOSE( cb.z, 1.0000, ACC );
        CHECK_CLOSE( cb.w, 2.0000, ACC );
        CHECK_CLOSE( b.x, 0.0, ACC );
        CHECK_CLOSE( b.y, 1.0, ACC );
        CHECK_CLOSE( b.z, 0.5, ACC );
        CHECK_CLOSE( b.w, 3.00, ACC );


        clamp( a );
        CHECK_CLOSE( a.x, 1.0000, ACC );
        CHECK_CLOSE( a.y, 1.0000, ACC );
        CHECK_CLOSE( a.z, 0.0000, ACC );
        CHECK_CLOSE( a.w, 1.0000, ACC );

        clamp( b );
        CHECK_CLOSE( b.x, 0.0000, ACC );
        CHECK_CLOSE( b.y, 1.0000, ACC );
        CHECK_CLOSE( b.z, 0.5, ACC );
        CHECK_CLOSE( b.w, 1.0, ACC );
    }
}

