##########################################################################################################
# Server library
##########################################################################################################

set(stuntmanserver_headers
    server.h
    stunconnection.h
    stunsocketthread.h
    tcpserver.h
    sampleauthprovider.h
)

add_library(stuntmanserver
    ${stuntmanserver_headers}
    server.cpp
    sampleauthprovider.cpp
    stunconnection.cpp
    stunsocketthread.cpp
    tcpserver.cpp
)

set_target_properties(stuntmanserver PROPERTIES
    OUTPUT_NAME stunserver)

target_include_directories(stuntmanserver PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/>)

target_link_libraries(stuntmanserver PUBLIC stuntmancommon stuntmancore stuntmannetworkutils Threads::Threads)

install(FILES ${stuntmanserver_headers} DESTINATION include/)

install(TARGETS stuntmanserver EXPORT StuntmanTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include)

##########################################################################################################
# Server executable
##########################################################################################################

add_executable(stunserver
    main.cpp
)

target_link_libraries(stunserver stuntmanserver resources)

if (with_configfile_support)
    target_link_libraries(stunserver Boost::headers)
    target_compile_definitions(stunserver PUBLIC WITH_CONFIGFILE_SUPPORT)
endif()

install(TARGETS stunserver EXPORT StuntmanTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include)
