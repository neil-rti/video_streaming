# video_streaming

Examples for video streaming using RTI Connext

In brief:

    mkdir build
    cd build
    (run rtisetenv_arch.bash script)
    cmake ..
    make


Launch the subscriber:
    ./build/vsffmpeg_ext -p sub -n BeTheSub -f BeThePub | ffplay -fflags nobuffer -i pipe:0

Then the publisher:
    ffmpeg -re -i CES-demo-redux.mp4 -g 15 -pix_fmt yuv420p -vcodec libx264 -preset ultrafast -tune zerolatency -f mpegts pipe:1 | ./build/vsffmpeg_ext -p pub -n BeThePub -f BeTheSub

