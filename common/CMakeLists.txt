add_library(common
    atomichelpers.cpp
    atomichelpers.h
    chkmacros.h
    cmdlineparser.cpp
    cmdlineparser.h
    common.cpp
    commonincludes.hpp
    fasthash.cpp
    fasthash.h
    getconsolewidth.cpp
    getmillisecondcounter.cpp
    hresult.h
    logger.cpp
    logger.h
    objectfactory.h
    oshelper.h
    prettyprint.cpp
    prettyprint.h
    refcountobject.cpp
    refcountobject.h
    stringhelper.cpp
    stringhelper.h
)

target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(common PUBLIC $<$<CONFIG:Debug>:DEBUG_MODE>)

install(TARGETS common
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib)
