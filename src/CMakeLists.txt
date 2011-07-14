CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )
    PROJECT( rtrt CXX )

# Make sure we can use opemMP
    FIND_PACKAGE(OpenMP REQUIRED )
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")



    SET( SRC  
            main.cpp
            )
    
    SET( BIN ../rtrt )
    
    SET( LIBS SIMDx86  )

    ADD_EXECUTABLE( ${BIN} ${SRC} )
    TARGET_LINK_LIBRARIES( ${BIN} ${LIBS} )


