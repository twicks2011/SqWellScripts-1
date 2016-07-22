d=$(sed -n '34s/ .*//p' $1)
t=$(sed -n '3s/ .*//p' $1)
echo $d/collated/occW_chain$t.dat &
echo $t
echo title \"$d\" > p.dat
xmgrace -barebones -fixed 1880 500 -pexec "ARRANGE(1, 4, 0.1, 0.15, 0.2)" -g 2500x720 -nxy $d/Range$t.dat -graph 1  $d/collated/occW_chain$t.dat -graph 2 $d/collated/occW_chain*.dat -graph 3  $d/collated/FE_chain$t.dat -param p.dat   &
#xmgrace  -g 1250x900 -nxy $d/Range$t.dat -param p.dat &
#xmgrace  -g 1300x900 $d/collated/occW_chain$t.dat -param p.dat &
#xmgrace  -g 1300x900 $d/collated/occW_chain*.dat -param p.dat &


