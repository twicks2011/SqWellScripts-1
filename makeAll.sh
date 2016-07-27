#!/bin/sh
cp doBoth.sh ~/bin/
cp showAll.sh ~/bin/
cp sqWellCp.sh ~/bin/
cp batchOutput/batchOutput.sh ~/bin/

echo ""
for f in blockVary clipQuad collateClip dosMapping; do
    echo $f
    cd $f
    make
    cd ..
    echo ""
done

#Minor hpc edit
