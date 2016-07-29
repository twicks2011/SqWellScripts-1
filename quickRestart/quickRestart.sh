#!/bin/bash

#Check correct numnber of command line arguments
if (( $# != 2 )); then
  echo "Usage:  quickRestart.sh [orginal input file] [restart inputfile]" >&2
  exit 1
fi


old=${1%.*}
new=${2%.*}
echo $old $new

#change the output filename
cat $1 | sed -e "s/$old\//$new\//" > $2


#cat $2 | sed "s~.*CONFIGS_FILE (File containing initial configs)*~outputFiles/$old/restartInfo/configs.dat	: CONFIGS_FILE (File containing initial configs)~" > $2

