CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )
    PROJECT( rtrt_test CXX )

# Make sure we can use opemMP
    FIND_PACKAGE(OpenMP REQUIRED )
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS} -sse sse2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} -sse -sse2")

    set(CMAKE_BUILD_TYPE Debug)

    SET( SRC  
            main.cpp
            
            test_math_vec4.cpp
            test_math_vec_func.cpp

            ../util/math/vec_func.cpp
            )
    
    SET( BIN ../../test_rtrt )
    
    SET( LIBS UnitTest++ )

    ADD_EXECUTABLE( ${BIN} ${SRC} )
    TARGET_LINK_LIBRARIES( ${BIN} ${LIBS} )


