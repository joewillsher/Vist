#!/bin/bash

x="$1"
cat $1 > ${x%.*}.c
gcc -E ${x%.*}.c -o ${x%.*}.i
cat ${x%.*}.i | sed '/^#/ d' > $1.previst
rm ${x%.*}.c
rm ${x%.*}.i