add_library(networkutils
    adapters.cpp
    adapters.h
    polling.cpp
    polling.h
    ratelimiter.cpp
    ratelimiter.h
    recvfromex.cpp
    recvfromex.h
    resolvehostname.cpp
    resolvehostname.h
    stunsocket.cpp
    stunsocket.h
)

target_include_directories(networkutils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(networkutils PUBLIC common stuncore)

install(TARGETS networkutils
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib)
