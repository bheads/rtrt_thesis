CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )

#   rtrt build
    ADD_SUBDIRECTORY( src )

#   Document Build System
    find_package(Doxygen)

    if(DOXYGEN_FOUND)
    configure_file( Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc
            ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen" VERBATIM
            )
    endif(DOXYGEN_FOUND)


