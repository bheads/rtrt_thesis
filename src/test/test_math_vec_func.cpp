

#include <UnitTest++/UnitTest++.h>

#include "../util/math/math.h"

SUITE( VecFuncTests )
{
    TEST( Vec4Addition )
    {
        rt::vec4 a( 1, 2, 3, 4 ), b( 5, 5, 5, 5 );
        rt::vec4 c = a + b;
        CHECK_CLOSE( c.x, a.x + b.x, 0.00001 );
        CHECK_CLOSE( c.y, a.y + b.y, 0.00001 );
        CHECK_CLOSE( c.z, a.z + b.z, 0.00001 );
        CHECK_CLOSE( c.w, a.w + b.w, 0.00001 );

        c = a + 10;
        CHECK_CLOSE( c.x, a.x + 10, 0.00001 );
        CHECK_CLOSE( c.y, a.y + 10, 0.00001 );
        CHECK_CLOSE( c.z, a.z + 10, 0.00001 );
        CHECK_CLOSE( c.w, a.w + 10, 0.00001 );

        c = 10 + b;
        CHECK_CLOSE( c.x, 10 + b.x, 0.00001 );
        CHECK_CLOSE( c.y, 10 + b.y, 0.00001 );
        CHECK_CLOSE( c.z, 10 + b.z, 0.00001 );
        CHECK_CLOSE( c.w, 10 + b.w, 0.00001 );

        rt::vec4 d = +a;
        CHECK_CLOSE( d.x, +a.x, 0.00001 );
        CHECK_CLOSE( d.y, +a.y, 0.00001 );
        CHECK_CLOSE( d.z, +a.z, 0.00001 );
        CHECK_CLOSE( d.w, +a.w, 0.00001 );

        rt::vec4 e( 1, 2, 3, 4 );
        e += a;
        CHECK_CLOSE( e.x, 2, 0.00001 );
        CHECK_CLOSE( e.y, 4, 0.00001 );
        CHECK_CLOSE( e.z, 6, 0.00001 );
        CHECK_CLOSE( e.w, 8, 0.00001 );

        rt::vec4 f( 1, 2, 3, 4 );
        f += 2;
        CHECK_CLOSE( f.x, 1+2.0f, 0.00001 );
        CHECK_CLOSE( f.y, 2+2.0f, 0.00001 );
        CHECK_CLOSE( f.z, 3+2.0f, 0.00001 );
        CHECK_CLOSE( f.w, 4+2.0f, 0.00001 );


    }

    TEST( Vec4Subtraction )
    {
        rt::vec4 a( 1, 2, 3, 4 ), b( 5, 5, 5, 5 );
        rt::vec4 c = a - b;
        CHECK_CLOSE( c.x, a.x - b.x, 0.00001 );
        CHECK_CLOSE( c.y, a.y - b.y, 0.00001 );
        CHECK_CLOSE( c.z, a.z - b.z, 0.00001 );
        CHECK_CLOSE( c.w, a.w - b.w, 0.00001 );

        c = a - 10;
        CHECK_CLOSE( c.x, a.x - 10, 0.00001 );
        CHECK_CLOSE( c.y, a.y - 10, 0.00001 );
        CHECK_CLOSE( c.z, a.z - 10, 0.00001 );
        CHECK_CLOSE( c.w, a.w - 10, 0.00001 );

        c = 10 - b;
        CHECK_CLOSE( c.x, 10 - b.x, 0.00001 );
        CHECK_CLOSE( c.y, 10 - b.y, 0.00001 );
        CHECK_CLOSE( c.z, 10 - b.z, 0.00001 );
        CHECK_CLOSE( c.w, 10 - b.w, 0.00001 );
                
        rt::vec4 d = -a;
        CHECK_CLOSE( d.x, -a.x, 0.00001 );
        CHECK_CLOSE( d.y, -a.y, 0.00001 );
        CHECK_CLOSE( d.z, -a.z, 0.00001 );
        CHECK_CLOSE( d.w, -a.w, 0.00001 );

        rt::vec4 e( 1, 2, 3, 6 );
        e -= a;
        CHECK_CLOSE( e.x, 0, 0.00001 );
        CHECK_CLOSE( e.y, 0, 0.00001 );
        CHECK_CLOSE( e.z, 0, 0.00001 );
        CHECK_CLOSE( e.w, 2, 0.00001 );

        rt::vec4 f( 1, 2, 3, 4 );
        f -= 2;
        CHECK_CLOSE( f.x, 1-2.0f, 0.00001 );
        CHECK_CLOSE( f.y, 2-2.0f, 0.00001 );
        CHECK_CLOSE( f.z, 3-2.0f, 0.00001 );
        CHECK_CLOSE( f.w, 4-2.0f, 0.00001 );
    }

    TEST( Vec4Multiplication )
    {
        rt::vec4 a( 1, 2, 3, 4 ), b( 5, 5, 5, 5 );
        rt::vec4 c = a * b;
        CHECK_CLOSE( c.x, a.x * b.x, 0.00001 );
        CHECK_CLOSE( c.y, a.y * b.y, 0.00001 );
        CHECK_CLOSE( c.z, a.z * b.z, 0.00001 );
        CHECK_CLOSE( c.w, a.w * b.w, 0.00001 );

        c = a * 10;
        CHECK_CLOSE( c.x, a.x * 10, 0.00001 );
        CHECK_CLOSE( c.y, a.y * 10, 0.00001 );
        CHECK_CLOSE( c.z, a.z * 10, 0.00001 );
        CHECK_CLOSE( c.w, a.w * 10, 0.00001 );

        c = 10 * b;
        CHECK_CLOSE( c.x, 10 * b.x, 0.00001 );
        CHECK_CLOSE( c.y, 10 * b.y, 0.00001 );
        CHECK_CLOSE( c.z, 10 * b.z, 0.00001 );
        CHECK_CLOSE( c.w, 10 * b.w, 0.00001 );

        rt::vec4 e( 1, 2, 3, 4 );
        e *= a;
        CHECK_CLOSE( e.x, 1, 0.00001 );
        CHECK_CLOSE( e.y, 4, 0.00001 );
        CHECK_CLOSE( e.z, 9, 0.00001 );
        CHECK_CLOSE( e.w, 16, 0.00001 );

        rt::vec4 f( 1, 2, 3, 4 );
        f *= 2;
        CHECK_CLOSE( f.x, 2.0f, 0.00001 );
        CHECK_CLOSE( f.y, 4.0f, 0.00001 );
        CHECK_CLOSE( f.z, 6.0f, 0.00001 );
        CHECK_CLOSE( f.w, 8.0f, 0.00001 );
    }


    TEST( Vec4Diviaion )
    {
        rt::vec4 a( 1, 2, 3, 4 ), b( 5, 5, 5, 5 );
        rt::vec4 c = a / b;
        CHECK_CLOSE( c.x, a.x / b.x, 0.00001 );
        CHECK_CLOSE( c.y, a.y / b.y, 0.00001 );
        CHECK_CLOSE( c.z, a.z / b.z, 0.00001 );
        CHECK_CLOSE( c.w, a.w / b.w, 0.00001 );

        c = a / 10;
        CHECK_CLOSE( c.x, a.x / 10, 0.00001 );
        CHECK_CLOSE( c.y, a.y / 10, 0.00001 );
        CHECK_CLOSE( c.z, a.z / 10, 0.00001 );
        CHECK_CLOSE( c.w, a.w / 10, 0.00001 );

        c = 10 / b;
        CHECK_CLOSE( c.x, 10 / b.x, 0.00001 );
        CHECK_CLOSE( c.y, 10 / b.y, 0.00001 );
        CHECK_CLOSE( c.z, 10 / b.z, 0.00001 );
        CHECK_CLOSE( c.w, 10 / b.w, 0.00001 );

        rt::vec4 e( 1, 2, 3, 8 );
        e /= a;
        CHECK_CLOSE( e.x, 1, 0.00001 );
        CHECK_CLOSE( e.y, 1, 0.00001 );
        CHECK_CLOSE( e.z, 1, 0.00001 );
        CHECK_CLOSE( e.w, 2, 0.00001 );

        rt::vec4 f( 1, 2, 3, 4 );
        f /= 2;
        CHECK_CLOSE( f.x, 1/2.0f, 0.00001 );
        CHECK_CLOSE( f.y, 2/2.0f, 0.00001 );
        CHECK_CLOSE( f.z, 3/2.0f, 0.00001 );
        CHECK_CLOSE( f.w, 4/2.0f, 0.00001 );

    }

    TEST( DotProduct )
    {
        CHECK_CLOSE( rt::dot( rt::vec4( 2.0f, 4.0f ), 
                    rt::vec4( 1.0f, 5.0f )), 22, 0.001 );
        CHECK_CLOSE( rt::dot( rt::vec4( 10.0f, 2.0f, 30.0f ), 
                    rt::vec4( 3.0f, 9.0f, 4.0f )), 168, 0.001 );
        CHECK_CLOSE( rt::dot( rt::vec4( 1.0f, 2.0f, 3.0f, 4 ), 
                    rt::vec4( 9, 8, 7, 6 )), 70, 0.001 );
    }

    TEST( CrossProduct )
    {
        /*b.set = [1,2,3,0];
            a.set = [9,8,7,0];
                assert( cross(a,b).cell == [10,-20,10,0], "Bad Cross Product" );
                            c.set = 0;
        */
        rt::vec4 a( 3, -3, 1 ), b( 4, 9, 2 );
        rt::vec4 c = cross( a, b );
        CHECK_CLOSE( c.x, -15, 0.00001 );
        CHECK_CLOSE( c.y, -2, 0.00001 );
        CHECK_CLOSE( c.z, 39, 0.00001 );
        CHECK_CLOSE( c.w, 0, 0.00001 );

        rt::vec4 d( 3, -2, -2 ), e( -1, 0, 5 );
        rt::vec4 f = cross( d, e );
        CHECK_CLOSE( f.x, -10, 0.00001 );
        CHECK_CLOSE( f.y, -13, 0.00001 );
        CHECK_CLOSE( f.z, -2, 0.00001 );
        CHECK_CLOSE( f.w, 0, 0.00001 );
    }

    TEST( ColorClamp )
    {
        rt::color a( 5.0, 6.0, -4.5, 1.9 ), b( 0.0, 1.0, 0.5, 3.00 );

        rt::color ca = clamped( a );
        CHECK_CLOSE( ca.x, 1.0000, 0.00001 );
        CHECK_CLOSE( ca.y, 1.0000, 0.00001 );
        CHECK_CLOSE( ca.z, 0.0000, 0.00001 );
        CHECK_CLOSE( ca.w, 1.0000, 0.00001 );
        CHECK_CLOSE( a.x, 5.0, 0.00001 );
        CHECK_CLOSE( a.y, 6.0, 0.00001 );
        CHECK_CLOSE( a.z, -4.5, 0.00001 );
        CHECK_CLOSE( a.w, 1.9, 0.00001 );

        rt::color cb = clamped( b, 1.0, 2.0 );
        CHECK_CLOSE( cb.x, 1.0000, 0.00001 );
        CHECK_CLOSE( cb.y, 1.0000, 0.00001 );
        CHECK_CLOSE( cb.z, 1.0000, 0.00001 );
        CHECK_CLOSE( cb.w, 2.0000, 0.00001 );
        CHECK_CLOSE( b.x, 0.0, 0.00001 );
        CHECK_CLOSE( b.y, 1.0, 0.00001 );
        CHECK_CLOSE( b.z, 0.5, 0.00001 );
        CHECK_CLOSE( b.w, 3.00, 0.00001 );


        clamp( a );
        CHECK_CLOSE( a.x, 1.0000, 0.00001 );
        CHECK_CLOSE( a.y, 1.0000, 0.00001 );
        CHECK_CLOSE( a.z, 0.0000, 0.00001 );
        CHECK_CLOSE( a.w, 1.0000, 0.00001 );

        clamp( b );
        CHECK_CLOSE( b.x, 0.0000, 0.00001 );
        CHECK_CLOSE( b.y, 1.0000, 0.00001 );
        CHECK_CLOSE( b.z, 0.5, 0.00001 );
        CHECK_CLOSE( b.w, 1.0, 0.00001 );
    }
}

