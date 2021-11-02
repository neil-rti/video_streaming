# video_streaming

Examples for video streaming using RTI Connext

In brief:

    mkdir build
    cd build
    (run rtisetenv_arch.bash script)
    cmake ..
    make

This will build a series of demonstration applications for streaming video and measuring its performance.  

## 1. Streaming using an external 'ffmpeg' and 'ffplay'

This example uses the `ffmpeg` and `ffplay` video codec and display applications.

Launch the subscriber:

    ./build/vsffmpeg_ext -p sub -n BeTheSub -f BeThePub | ffplay -fflags nobuffer -i pipe:0

Then the publisher:

    ffmpeg -re -i <your-video-file>.mp4 -g 15 -pix_fmt yuv420p -vcodec libx264 -preset ultrafast -tune zerolatency -f mpegts pipe:1 | ./build/vsffmpeg_ext -p pub -n BeThePub -f BeTheSub


(this is a starter README)  EOF.
