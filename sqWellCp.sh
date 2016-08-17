#!/bin/bash

#Check correct numnber of command line arguments
if (( $# != 2 )); then
  echo "Usage:  sqWellCp.sh [orginal input file] [copied inputfile]" >&2
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
cat $1 | sed -e "s/$old\//$new\//" > $2
