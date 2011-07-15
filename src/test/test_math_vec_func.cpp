

#include <UnitTest++/UnitTest++.h>

#include "../math/math.h"

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
    }
}

