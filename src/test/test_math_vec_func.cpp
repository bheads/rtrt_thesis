

#include <UnitTest++/UnitTest++.h>

#include "../math/math.h"

SUITE( VecFuncTests )
{
    TEST( DotProduct )
    {
        CHECK_CLOSE( rt::dot( rt::vec4( 2.0f, 4.0f ), 
                    rt::vec4( 1.0f, 5.0f )), 22, 0.001 );
        CHECK_CLOSE( rt::dot( rt::vec4( 10.0f, 2.0f, 30.0f ), 
                    rt::vec4( 3.0f, 9.0f, 4.0f )), 168, 0.001 );
    }
}

