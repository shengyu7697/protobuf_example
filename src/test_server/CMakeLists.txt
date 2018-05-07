set(FILES
    server.cpp
)

list(APPEND FILES SocketPoseService.h SocketPoseService.cpp)
list(APPEND INCLUDE_DIRS tinytcp)
list(APPEND LIBRARIES tinytcp)

if(USE_PROTOBUF)
    find_package(Protobuf REQUIRED)
    PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS pose.proto)
    list(APPEND FILES ${PROTO_SRCS})
    list(APPEND INCLUDE_DIRS ${PROTOBUF_INCLUDE_DIRS})
    list(APPEND LIBRARIES ${PROTOBUF_LIBRARIES})
endif()

if (WIN32)
else() # Linux
    list(APPEND LIBRARIES pthread)
endif()

add_executable(test_server ${FILES})

target_include_directories(test_server PUBLIC ${INCLUDE_DIRS})
target_link_libraries(test_server ${LIBRARIES})
