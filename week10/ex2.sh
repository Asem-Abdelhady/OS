touch ../week01/file.txt
link ../week01/file.txt _ex2.txt
inode=$(ls -i _ex2.txt | cut -d ' ' -f 1)
find .. -inum "$inode"
find .. -inum "$inode" -exec rm {} \;
