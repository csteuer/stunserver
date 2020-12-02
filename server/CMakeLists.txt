add_executable(stunserver
    main.cpp
    sampleauthprovider.cpp
    sampleauthprovider.h
    server.cpp
    server.h
    stunconnection.cpp
    stunconnection.h
    stunsocketthread.cpp
    stunsocketthread.h
    tcpserver.cpp
    tcpserver.h
)

target_link_libraries(stunserver common stuncore networkutils resources Threads::Threads)

option(with_configfile_support "The server can be configured with a json file (requires boost)" OFF)
if (with_configfile_support)
    find_package(Boost REQUIRED)
    target_link_libraries(stunserver Boost::headers)
    target_compile_definitions(stunserver PUBLIC WITH_CONFIGFILE_SUPPORT)
endif()

install(TARGETS stunserver
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib)
