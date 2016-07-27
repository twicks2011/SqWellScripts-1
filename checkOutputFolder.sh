filename=${1%.*}
s=$(sed '34q;d' $1)
foldername=$(echo $s | awk -F[//] '{print $2}')
echo "Testing if file and folder name match..."
echo $foldername " (Folder)"
echo $filename " (Input file name)"

if [ "$foldername" == "$filename" ];
        then
            echo "...they are the same."
else
    echo ""
    echo "**********************************************************************"
    echo "!!!!!!!!!!!!!File and folder names do not match!!!!!!!!!!!!!!!!!!!!!!!"
        echo "**********************************************************************"
fi

	
#sed 's/.*"s\/"\(.*\):.*/\1/' <<< "$s"
#cat $1 | sed -e "s/$old\//$new\//" >> $2
