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

set(SOURCES_TYPSUPT
  src/idl/cctypes.cxx
  src/idl/cctypesPlugin.cxx
)

# - Executables to build ----------------------------------------------------------------------------
# vsffmpeg_ext : video streaming with FFMPEG (external)
add_executable(vsffmpeg_ext 
  src/1_ffmpeg_ext/ffmpeg_stdio.cxx
  src/0_common/rti_comms.cxx
  src/0_common/murmurhash3.cpp
  ${SOURCES_TYPSUPT})
target_link_libraries(vsffmpeg_ext PUBLIC RTIConnextDDS::cpp2_api)

# vstream_mon : performance monitoring of video streaming example
add_executable(vstream_mon 
  src/1_ffmpeg_ext/vstream_mon.cxx
  src/0_common/rti_comms.cxx
  src/0_common/murmurhash3.cpp
  ${SOURCES_TYPSUPT})
target_link_libraries(vstream_mon PUBLIC RTIConnextDDS::cpp2_api)
