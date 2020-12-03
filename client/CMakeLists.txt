add_executable(stunclient clientmain.cpp)

target_link_libraries(stunclient common stuncore networkutils resources)

install(TARGETS stunclient EXPORT StuntmanTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib)
