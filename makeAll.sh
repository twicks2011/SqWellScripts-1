#!/bin/sh
set -e
cp doBoth.sh ~/bin/
cp showAll.sh ~/bin/

for f in blockVary clipQuad collateClip dosMapping; do
    echo $f
    cd $f
    make
    cd ..
    echo ""
done


