#!/bin/bash

for file in *.cpp *.hpp *.h
do 
	if [ -a "$file" ] && [ "`basename $file`" != "main.cpp" ] 
	then  
		mv $file ./$1
		echo -e " > $file moved up" 
	fi
	
done


