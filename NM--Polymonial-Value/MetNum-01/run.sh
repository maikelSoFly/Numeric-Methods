#!/bin/bash

bash ../moveDown.sh .. .

for file in *.cpp
do
	if [ -a "$file" ]
	then
		args+="$file "
	fi
done

echo -e " > Linking:  $args\n\n"

g++ $args -o prog
./prog $1 $2 $3 $4 $5 $6 $7 $8 $9

echo -e "\n•••••••••••••••••••••••••••••"
bash moveUp.sh ..

echo -e "\n > Script done\n"
