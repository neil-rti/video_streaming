# video_streaming

Example of streaming compressed video using RTI Connext.  
This example uses an external video codec: [FFMPEG](https://www.ffmpeg.org/), which is available as buildable source or as pre-built binary executables.  This external codec (and its companion player, `FFPLAY`) to encode video and audio using h.264 into an [MPEG-TS](https://en.wikipedia.org/wiki/MPEG_transport_stream) stream of 188-byte 'packets', which are then grouped and sent over a Connext DDS topic to one or more subscribers.  

This example offers control over the grouping of packets in a DDS sample, with a means of measuring its effect on latency and sample loss using a companion application and set of topics for monitoring and control.

# Building the application

In brief:

    mkdir build
    cd build
    (run rtisetenv_<arch>.bash script to configure environment for Connext)
    cmake ..
    make

This will build the example applications for streaming video and measuring its performance.  

## 1. Streaming using an external 'ffmpeg' and 'ffplay'

This example uses the `ffmpeg` and `ffplay` video codec and display applications.

Launch the subscriber:

    ./build/vsffmpeg_ext -p sub -n BeTheSub -f BeThePub | ffplay -fflags nobuffer -i pipe:0

Then the publisher:

    ffmpeg -re -i RTI-vehicles-captioned.mp4 -g 15 -pix_fmt yuv420p -vcodec libx264 -preset ultrafast -tune zerolatency -f mpegts pipe:1 | ./build/vsffmpeg_ext -p pub -n BeThePub -f BeTheSub


(this is a starter README)  
EOF.
