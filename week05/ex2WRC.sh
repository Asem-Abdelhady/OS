#!/bin/bash

N=6

if [ $# -eq 1 ]; then
    N=$1;
elif [ $# -gt 1 ]; then
    echo "Usage: ${0} [execution count]"
    exit
fi

echo 1 > ex2WithoutRaceCondition.txt

for (( i = 1; i <= $N; i++ ))
do
	./lockIncreaseFile.sh ex2WithoutRaceCondition.txt&
	./lockIncreaseFile.sh ex2WithoutRaceCondition.txt
done
