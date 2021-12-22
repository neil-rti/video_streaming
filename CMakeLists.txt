cmake_minimum_required(VERSION 3.3.2)
project (cc_wanstream)

if(DEFINED ENV{NDDSHOME})
  set(NDDSHOME $ENV{NDDSHOME})
else()
  message(FATAL_ERROR "NDDSHOME (env var) is not set")
endif()

# this helps if multiple Connext target libraries are installed.
if(DEFINED ENV{CONNEXTDDS_ARCH})
  set(CONNEXTDDS_ARCH $ENV{CONNEXTDDS_ARCH})
  message(STATUS "Building for RTI target: ${CONNEXTDDS_ARCH}")  
endif()

set(CMAKE_MODULE_PATH ${NDDSHOME}/resource/cmake)

find_package(RTIConnextDDS)

# - Point to the source dirs and files ----------
include_directories("src" "src/idl" "src/common" ${CONNEXTDDS_INCLUDE_DIRS})

# - Executables to build ----------------------------------------------------------------------------
# streamvid : video streaming with FFMPEG (external using udp)
add_executable(streamvid 
  src/streamvid/stream_vid.cxx
  src/streamvid/rti_comms.cxx
  src/common/murmurhash3.cpp
  src/common/property_util.cxx
  src/idl/cc_str_com_types.cxx
  src/idl/cc_str_com_typesPlugin.cxx)
target_link_libraries(streamvid PUBLIC RTIConnextDDS::cpp2_api)

# streamtest : performance monitoring of video streaming example
add_executable(streamtest 
  src/streamtest/stream_test.cxx
  src/streamtest/rti_comm_test.cxx
  src/common/murmurhash3.cpp
  src/common/property_util.cxx
  src/idl/cc_str_test_types.cxx
  src/idl/cc_str_test_typesPlugin.cxx)
target_link_libraries(streamtest PUBLIC RTIConnextDDS::cpp2_api)
