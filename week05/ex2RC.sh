N=5

if [ $# -eq 1 ]; then
    N=$1;
elif [ $# -gt 1 ]; then
    echo "Usage: ${0} [execution count]"
    exit
fi

echo 1 > ex2RC.txt 

for (( i = 1; i <= $N; i++ ))
do
	./increaseFile.sh ex2RC.txt&
	./increaseFile.sh ex2RC.txt
done

