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

target_link_libraries(stunserver stuntmancommon stuntmancore stuntmannetworkutils resources Threads::Threads)

if (with_configfile_support)
    target_link_libraries(stunserver Boost::headers)
    target_compile_definitions(stunserver PUBLIC WITH_CONFIGFILE_SUPPORT)
endif()

install(TARGETS stunserver EXPORT StuntmanTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include)
