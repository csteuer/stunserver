set(networkutils_headers
    adapters.h
    polling.h
    ratelimiter.h
    recvfromex.h
    resolvehostname.h
    stunsocket.h
)

add_library(networkutils
    ${networkutils_headers}
    adapters.cpp
    polling.cpp
    ratelimiter.cpp
    recvfromex.cpp
    resolvehostname.cpp
    stunsocket.cpp
)

target_include_directories(networkutils PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/>)

target_link_libraries(networkutils PUBLIC common stuncore)

install(FILES ${networkutils_headers} DESTINATION include/)

install(TARGETS networkutils EXPORT StuntmanTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include)
