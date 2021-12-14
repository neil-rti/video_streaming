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
include_directories("src" "src/idl" "src/toml" "src/0_common" ${CONNEXTDDS_INCLUDE_DIRS})

# - Executables to build ----------------------------------------------------------------------------
# streamvid : video streaming with FFMPEG (external using udp)
add_executable(streamvid 
  src/1_ffmpeg_ext/stream_vid.cxx
  src/0_common/rti_comms.cxx
  src/0_common/murmurhash3.cpp
  src/idl/cc_str_com_types.cxx
  src/idl/cc_str_com_typesPlugin.cxx)
target_link_libraries(streamvid PUBLIC RTIConnextDDS::cpp2_api)

# streamperf : performance monitoring of video streaming example
add_executable(streamperf 
  src/1_ffmpeg_ext/stream_test.cxx
  src/0_common/rti_comm_test.cxx
  src/0_common/murmurhash3.cpp
  src/idl/cc_str_test_types.cxx
  src/idl/cc_str_test_typesPlugin.cxx)
target_link_libraries(streamperf PUBLIC RTIConnextDDS::cpp2_api)
