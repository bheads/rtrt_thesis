CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )
    PROJECT( rtrt CXX )

# Make sure we can use opemMP
    FIND_PACKAGE(OpenMP REQUIRED )
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS} -sse sse2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} -sse -sse2")

#    set(CMAKE_BUILD_TYPE Release)

    SET( SRC  
            main.cpp

            math/vec_func.cpp
            )
    
    SET( BIN ../rtrt )
    
    SET( LIBS )

    ADD_EXECUTABLE( ${BIN} ${SRC} )
    TARGET_LINK_LIBRARIES( ${BIN} ${LIBS} )


