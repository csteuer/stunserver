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
    commonincludes.hpp
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
)

set_target_properties(stuntmancommon PROPERTIES
    OUTPUT_NAME common)

target_include_directories(stuntmancommon PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/>)

target_compile_definitions(stuntmancommon PUBLIC $<$<CONFIG:Debug>:DEBUG_MODE>)

install(FILES ${common_headers} DESTINATION include/)

install(TARGETS stuntmancommon EXPORT StuntmanTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include)
