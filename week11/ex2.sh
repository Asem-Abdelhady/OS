pth=`pwd`/lofsdisk
sudo echo ${pth}
sudo mkdir -p $pth/{bin,lib,lib64}
sudo cp -v /bin/{bash,ls,echo,cat} $pth/bin
list="$(ldd /bin/bash | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp -v --parents "$i" "${pth}"; done
list="$(ldd /bin/ls | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp -v --parents "$i" "${pth}"; done
list="$(ldd /bin/echo | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp -v --parents "$i" "${pth}"; done
list="$(ldd /bin/cat | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp -v --parents "$i" "${pth}"; done

gcc ex2.c -o ex2.out

sudo bash -c "echo 'Asem' >${pth}/file1"
sudo bash -c "echo 'Abdelhady' >${pth}/file2"
sudo cp ex2.out $pth/ex2.out

echo "The chroot">ex2.txt
sudo chroot $pth ./ex2.out >> ex2.txt
echo "Without chroot" >> ex2.txt
./ex2.out >> ex2.txt 




