project(ofx)

set (VERSION_MAJOR 0)
set (VERSION_MINOR 9)
set (VERSION_PATCH 13)

cmake_minimum_required(VERSION 2.6)

list(APPEND CMAKE_MODULE_PATH  ${CMAKE_SOURCE_DIR})
find_package(OpenSP REQUIRED)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

include_directories(
    inc
    ${OPENSP_INCLUDES}
    ${CMAKE_INSTALL_PREFIX}/include
    "C:\\vcpkg\\installed\\x64-windows\\include"
)

add_definitions(
    -D__WIN32__
    -DMAKEFILE_DTD_PATH="${CMAKE_PREFIX_PATH}/share/libofx/dtd/"
)

set (COEFF_HDRS 
        inc/libofx.h
        lib/messages.hh
        lib/ofx_preproc.hh
        lib/file_preproc.hh
        lib/context.hh
        lib/ofx_sgml.hh
        lib/ofc_sgml.hh
        lib/ofx_aggregate.hh
        lib/ofx_error_msg.hh
        lib/ofx_containers.hh
        lib/ofx_request.hh
        lib/ofx_request_accountinfo.hh
        lib/ofx_request_statement.hh
        lib/ofx_utilities.hh
        lib/tree.hh
        lib/win32.hh
        )

set (SRC_SOURCES
         lib/messages.cpp
         lib/ofx_utilities.cpp
         lib/file_preproc.cpp
         lib/context.cpp
         lib/ofx_preproc.cpp
         lib/ofx_container_generic.cpp
         lib/ofx_container_main.cpp
         lib/ofx_container_security.cpp
         lib/ofx_container_statement.cpp
         lib/ofx_container_account.cpp
         lib/ofx_container_position.cpp
         lib/ofx_container_transaction.cpp
         lib/ofx_containers_misc.cpp
         lib/ofx_request.cpp
         lib/ofx_request_accountinfo.cpp
         lib/ofx_request_statement.cpp
         lib/ofx_sgml.cpp
         lib/ofc_sgml.cpp
         lib/win32.cpp
         ${COEFF_HDRS}
)

# We would like it to be shared, but libofx does not export symbols manually
# thus it causes troubles on MSVC
#add_library(ofx SHARED ${SRC_SOURCES})
add_library(ofx ${SRC_SOURCES})

FIND_LIBRARY( ICONV_LIBRARIES iconv )
if(MSVC)
    set_target_properties(ofx PROPERTIES OUTPUT_NAME "libofx")
endif(MSVC)
target_link_libraries(ofx ${OPENSP_LIBRARIES} ${ICONV_LIBRARIES})

######### add a utility function so that we can test ofx files ##########
set(ofxdump_SRCS
    ofxdump/cmdline.c
    ofxdump/ofxdump.cpp 
)

if(MSVC)
    set(ofxdump_SRCS ${ofxdump_SRCS} lib/messages.cpp lib/getopt.c lib/getopt1.c)
endif(MSVC)

add_definitions(-DCMDLINE_PARSER_PACKAGE=\"ofxdump\" -DCMDLINE_PARSER_PACKAGE_NAME=\"ofxdump\" -DCMDLINE_PARSER_VERSION=\"0.9.13\")
add_executable(ofxdump ${ofxdump_SRCS})
target_link_libraries(ofxdump ofx)

configure_file("libofx.pc.in" "${CMAKE_CURRENT_BINARY_DIR}/libofx.pc")

install(TARGETS ofx ofxdump RUNTIME DESTINATION bin ARCHIVE DESTINATION lib LIBRARY DESTINATION lib)
install(FILES inc/libofx.h DESTINATION include/libofx)
install(FILES dtd/opensp.dcl DESTINATION ${CMAKE_PREFIX_PATH}/share/libofx/dtd)
install(FILES dtd/ofx160.dtd DESTINATION ${CMAKE_PREFIX_PATH}/share/libofx/dtd)
install(FILES dtd/ofx201.dtd DESTINATION ${CMAKE_PREFIX_PATH}/share/libofx/dtd)
install(FILES dtd/ofc.dtd DESTINATION ${CMAKE_PREFIX_PATH}/share/libofx/dtd)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libofx.pc DESTINATION ${CMAKE_PREFIX_PATH}/lib/pkgconfig)
