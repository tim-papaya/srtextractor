 #!/bin/sh
if [ -n "$1" ]
then
path="$1"
else
path=$(pwd)
fi
subd="subtitles"
trans="translate"
for file in $path/$subd/$trans/*.temp
do
mv "$file" "$path/$subd/"
done
rm -r "$path/$subd/$trans"

for file in $path/$subd/*.srt
do 
readsrc write "$file"
base=${file##*/}
fname=${file%.*}
# 
# need to find the way to add subtitles to the video
# the exmpl below doesn`t work
# 
# ffmpeg -i "$path/${base%.*}.mkv" -i ""$fname"_rus.srt" -c copy -c:s mov_text "$path/${base%.*}_added.mkv"
done

# rm "$path/subtitles/*.temp"
