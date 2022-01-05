# video_streaming

Example of streaming compressed video using RTI Connext, over a local or wide area network such as the Internet.  
This example uses an external application to encode ([FFMPEG](https://www.ffmpeg.org/)) and decode/display
([FFPLAY](https://www.ffmpeg.org/)) video and audio, in this case from a pre-recorded file.  

FFMPEG and FFPLAY are available as buildable source code or as pre-built binary executables, and are used
here to encode video and audio using h.264 compression into an [MPEG-TS](https://en.wikipedia.org/wiki/MPEG_transport_stream) 
stream of 188-byte 'packets', which are then grouped and sent over a Connext DDS topic to one or more subscribers for presentation.
Note that this example could be made to work with other streaming video codecs.  

This example offers control over the grouping of packets in a DDS sample, with a means of measuring its effect on latency and sample loss using a companion application and set of topics for monitoring and control.

# Building the application

Ensure that your build environment is configured for RTI Connext and for your C++ build toolchain.
The `rtisetenv_<arch>.[bash/bat]` script in the RTI installation folder for resources/scripts may be used to 
configure the environment for RTI Connext.  

To build the application:

    mkdir build
    cd build
    cmake ..
    make

This will build the example applications for streaming video and measuring its performance.  

## 1. Streaming using an external 'ffmpeg' and 'ffplay'

This example uses the `ffmpeg` and `ffplay` video codec and display applications; 
these must be installed in available in your system PATH.  
For convenience, a launcher script `run_demo` has been provided.  This script will
launch the 4 applications in separate command terminals to demonstrate video streaming
on a common PC host. The commands within this script may be used separately to stream 
video between different machines.

To launch with the `run_demo` script:

    run_demo

To launch as separate applications: Two pairs of terminals will be needed: 2 for publish, 2 for subscribe

Publisher terminal 1:

   build/streamvid.exe -p PubMachine

Publisher terminal 2:

   ffmpeg -re -i RTI-vehicles-captioned-480.mp4 -g 15 -pix_fmt yuv420p -vcodec libx264 -preset ultrafast -tune zerolatency -f mpegts udp://127.0.0.1:2277

Subscriber terminal 1:

   build/streamvid.exe -s PubMachine

Subscriber terminal 2:

   ffplay -fflags nobuffer -i udp://127.0.0.1:2278



EOF.
