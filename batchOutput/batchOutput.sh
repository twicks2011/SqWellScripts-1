arr1=( $( cut -d' ' -f1 $1 ) )
arr2=( $( cut -d' ' -f2 $1 ) )


for i in $(seq 1 $(expr ${#arr1[@]} - 1))
do
   :
   echo ${arr1[$i]} ${arr2[$i]}
   all="$all ${arr1[$i]}"
done

echo $all
xmgrace $all


