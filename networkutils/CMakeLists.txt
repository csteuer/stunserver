set(networkutils_headers
    adapters.h
    polling.h
    ratelimiter.h
    recvfromex.h
    resolvehostname.h
    stunsocket.h
)

add_library(stuntmannetworkutils
    ${networkutils_headers}
    adapters.cpp
    polling.cpp
    ratelimiter.cpp
    recvfromex.cpp
    resolvehostname.cpp
    stunsocket.cpp
)

set_target_properties(stuntmannetworkutils PROPERTIES
    OUTPUT_NAME networkutils)

target_include_directories(stuntmannetworkutils PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/>)

target_link_libraries(stuntmannetworkutils PUBLIC stuntmancommon stuntmancore)

install(FILES ${networkutils_headers} DESTINATION include/)

install(TARGETS stuntmannetworkutils EXPORT StuntmanTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    INCLUDES DESTINATION include)
