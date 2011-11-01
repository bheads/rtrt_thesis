

#include <UnitTest++/UnitTest++.h>

#include <modules/vec4.h>
#include <modules/vec_func.h>

SUITE( Vec4Tests )
{
    TEST( Construction )
    {
        vec4 a;
        CHECK_EQUAL( a.x, 0 );
        CHECK_EQUAL( a.y, 0 );
        CHECK_EQUAL( a.z, 0 );
        CHECK_EQUAL( a.w, 0 );

        vec4 b( 1, 2, 3, 4 );
        CHECK_EQUAL( b.x, 1 );
        CHECK_EQUAL( b.y, 2 );
        CHECK_EQUAL( b.z, 3 );
        CHECK_EQUAL( b.w, 4 );

        float data[4] = { 8,9,10,11};
        vec4 c( data );
        CHECK_EQUAL( c.x, 8 );
        CHECK_EQUAL( c.y, 9 );
        CHECK_EQUAL( c.z, 10 );
        CHECK_EQUAL( c.w, 11 );

        vec4 d( 33, false );
        CHECK_EQUAL( d.x, 33 );
        CHECK_EQUAL( d.y, 33 );
        CHECK_EQUAL( d.z, 33 );
        CHECK_EQUAL( d.w, 0 );

        vec4 e( 45, true );
        CHECK_EQUAL( e.x, 45 );
        CHECK_EQUAL( e.y, 45 );
        CHECK_EQUAL( e.z, 45 );
        CHECK_EQUAL( e.w, 45 );

        vec4 f( e );
        CHECK_EQUAL( f.x, e.x );
        CHECK_EQUAL( f.y, e.y );
        CHECK_EQUAL( f.z, e.z );
        CHECK_EQUAL( f.w, e.w );
    }

    TEST( Assignment )
    {
        vec4 a( 1, 2, 3, 4 ), b;
        CHECK_EQUAL( b.x, 0 );
        CHECK_EQUAL( b.y, 0 );
        CHECK_EQUAL( b.z, 0 );
        CHECK_EQUAL( b.w, 0 );
        b = a;
        CHECK_EQUAL( b.x, a.x );
        CHECK_EQUAL( b.y, a.y );
        CHECK_EQUAL( b.z, a.z );
        CHECK_EQUAL( b.w, a.w );
        b = 3.14;
        CHECK_CLOSE( b.x, 3.14, 0.001 );
        CHECK_CLOSE( b.y, 3.14, 0.001 );
        CHECK_CLOSE( b.z, 3.14, 0.001 );
        CHECK_CLOSE( b.w, 3.14, 0.001 );
    }
}


