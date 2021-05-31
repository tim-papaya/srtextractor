#!/bin/sh
if [ -n "$1" ]
then
path="$1"
else
path=$(pwd)
fi
subd="subtitles"
if [ ! -d "$path/$subd" ]
then
mkdir "$path/$subd"
fi
trans="translate"

for file in $path/*.mkv
do 
echo "$file"
base=${file##*/}
ffmpeg -i "$file"  "$path/$subd/${base%.*}.srt"
done
for file in $path/$subd/*.srt
do 
readsrc read "$file"
done

if [ ! -d "$path/$subd/$trans" ]
then
mkdir "$path/$subd/$trans"
fi
for file in $path/$subd/*.temp
do
mv "$file" "$path/$subd/$trans"
done
