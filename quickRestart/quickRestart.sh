#!/bin/bash

#Check correct numnber of command line arguments
if (( $# != 2 )); then
  echo "Usage:  quickRestart.sh [orginal input file] [restart inputfile]" >&2
  exit 1
fi

if [  -f $2 ]; then
    echo "File $2 already exists: refusing to overwrite!!!! "
    exit 1
fi

if [ ! -f $1 ]; then
    echo "File $1 does not exist: can't continue!!! "
    exit 1
fi


old=${1%.*}
new=${2%.*}
echo $old $new

#change the output filename
cat $1 | sed -e "s/$old\//$new\//" > $2


cat $2 | sed "s~.*CONFIGS_FILE (File containing initial configs)*~outputFiles/$old/restartInfo/configs.dat	: CONFIGS_FILE (File containing initial configs)~" > temp.dat



cat temp.dat | sed "s~.*MSIZE_DIR (Directory containing initial move sizes)*~outputFiles/$old/restartInfo/ 	: MSIZE_DIR (Directory containing initial move sizes)~" > $2

cat $2 | sed "s~.*fileInput (0=Off (planar zig-zag), 1=On)*~1	: fileInput (0=Off (planar zig-zag), 1=On)~" > temp.dat



cp temp.dat $2
rm temp.dat