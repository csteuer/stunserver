add_executable(stunclient clientmain.cpp)

target_link_libraries(stunclient common stuncore networkutils resources)

install(TARGETS stunclient
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib)
