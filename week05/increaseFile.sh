#!/bin/bash

if [ $# -eq 1 ]; then
    FileName="$1";
else
    echo "Usage: ${0} <file name>"
    exit
fi

# Critical region:
last=$( tail -n 1 "$FileName" )

((last++))

echo $last >> $FileName
