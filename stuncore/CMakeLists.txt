add_library(stuncore 
    buffer.cpp
    buffer.h
    datastream.cpp
    datastream.h
    messagehandler.cpp
    messagehandler.h
    socketaddress.cpp
    socketaddress.h
    socketrole.h
    stunauth.h
    stunbuilder.cpp
    stunbuilder.h
    stunclientlogic.cpp
    stunclientlogic.h
    stunclienttests.cpp
    stunclienttests.h
    stuncore.h
    stunreader.cpp
    stunreader.h
    stuntypes.h
    stunutils.cpp
    stunutils.h
    crc32.cpp
    crc32.h
)

target_include_directories(stuncore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(stuncore common OpenSSL::Crypto)

install(TARGETS stuncore
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib)
