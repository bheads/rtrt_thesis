

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
    }



    TEST( DotProduct )
    {
        CHECK_CLOSE( rt::dot( rt::vec4( 2.0f, 4.0f ), 
                    rt::vec4( 1.0f, 5.0f )), 22, 0.001 );
        CHECK_CLOSE( rt::dot( rt::vec4( 10.0f, 2.0f, 30.0f ), 
                    rt::vec4( 3.0f, 9.0f, 4.0f )), 168, 0.001 );
    }
}

