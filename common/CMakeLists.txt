set(common_headers
    atomichelpers.h
    chkmacros.h
    cmdlineparser.h
    fasthash.h
    hresult.h
    logger.h
    objectfactory.h
    oshelper.h
    prettyprint.h
    refcountobject.h
    stringhelper.h
)

add_library(stuntmancommon
    ${common_headers}
    atomichelpers.cpp
    cmdlineparser.cpp
    common.cpp
    fasthash.cpp
    getconsolewidth.cpp
    getmillisecondcounter.cpp
    logger.cpp
    prettyprint.cpp
    refcountobject.cpp
    stringhelper.cpp
    internal_definitions.hpp
)

if (ANDROID)
    target_link_libraries(stuntmancommon log)
endif()

set_target_properties(stuntmancommon PROPERTIES
    OUTPUT_NAME common)

target_include_directories(stuntmancommon PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/>)

install(FILES ${common_headers} DESTINATION include/)

install(TARGETS stuntmancommon EXPORT StuntmanTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    INCLUDES DESTINATION include)
