old=${1%.*}
new=${2%.*}
echo $old $new
cat $1 | sed -e "s/$old\//$new\//" > $2
