for var in "$@"
do
    echo "$var"
    cp $var dum.arg
    echo $var".dat" >> dum.arg
    multiAverage_sqW  $(cat dum.arg)
    #multiAverage_sqW `< $var`
    all="$all $(tail -1 dum.arg)"
done

echo $all
xmgrace  -g 1200x900 $all &


