CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )
    PROJECT( rtrt CXX )

# Make sure we can use opemMP
    FIND_PACKAGE(OpenMP REQUIRED )

# use -pg for debugging 
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS} -sse -sse2 -O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} -sse -sse2 -O3")

    IF( APPLE )
# cocoa lib
        FIND_LIBRARY(COCOA_LIBRARY Cocoa)
    ENDIF( APPLE )

# openGL
    FIND_LIBRARY(OpenGL_LIBRARY OpenGL OpenGLU )

#    set(CMAKE_BUILD_TYPE Release)

    SET( SRC  
            main.cpp
            util/handlers/close.cpp
            util/handlers/key.cpp

            util/gl/create_window.cpp
            util/gl/destroy_window.cpp
            util/gl/init.cpp

            util/fps/fps.cpp

            util/math/vec_func.cpp

            util/image/image.cpp
            )
    
    SET( BIN ../rtrt )
    
    SET( LIBS 
            gflags 
            glog 
            ${OpenGL_LIBRARY}
            ${OpenGLU_LIBRARY}
            glfw
            )

    IF( APPLE )
        SET( LIBS ${LIBS}
            ${COCOA_LIBRARY}
           )
    ENDIF( APPLE )

    ADD_EXECUTABLE( ${BIN} ${SRC} )
    TARGET_LINK_LIBRARIES( ${BIN} ${LIBS} )


