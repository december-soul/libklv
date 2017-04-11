#!/bin/sh


wget http://samples.ffmpeg.org/MPEG2/mpegts-klv/Day%20Flight.mpg -O Day_Flight.mpg
ffmpeg -i Day_Flight.mpg -map data-re -codec copy -f data Day_Flight.klv


echo "now run ./klv Day_Flight.klv"
