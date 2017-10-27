#!/bin/bash


for file in $1/*.cpp $1/*.hpp *.h 
do
	if [ -a "$file" ]
	then
		mv $file $2
		echo -e " > $file moved to $2"
	fi
done

