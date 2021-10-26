#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_FILES 10

struct file
{
	unsigned long inode;
	char filenames[MAX_FILES][MAX_NAME];
	int file_count;
};

int main()
{
	DIR *dir = opendir("./tmp");
	if(dir == NULL)
	{
		printf("Error occurred opening folder\n");
		return 1;
	}
	struct dirent *entry;
	
	struct file files[MAX_FILES];
	int file_count = 0;
	for(int i=0; i<MAX_FILES; i++)
	{
		files[i].inode = 0;
		files[i].file_count = 0;
	}
	
	while((entry = readdir(dir)) != NULL)
	{
		if(entry->d_name[0] == '.') continue;
		
		struct stat s = {};
		char dirname[4+MAX_NAME] = "tmp/";
		if(stat(strcat(dirname, entry->d_name), &s) != 0)
		{
			printf("Error reading file stat\n");
			break;
		}
		if(s.st_nlink <= 1)
			continue;
		
		//printf("%s: %lu\n", entry->d_name, s.st_nlink);
		int found = 0;
		for(int i=0; i<MAX_FILES; i++)
		{
			if(files[i].inode == s.st_ino)
			{
				strncpy(files[i].filenames[files[i].file_count], entry->d_name, MAX_NAME);
				files[i].inode = s.st_ino;
				files[i].file_count++;
				found = 1;
				break;
			}
		}
		if(found == 0)
		{
			files[file_count].inode = s.st_ino;
			strncpy(files[file_count].filenames[0], entry->d_name, MAX_NAME);
			files[file_count].file_count++;
			file_count++;
		}
	}
	closedir(dir);
	
	printf("Found %d files with more than 2 hard links:\n", file_count);
	for(int i=0; i<file_count; i++)
	{
		printf("The I-node: %lu (%d files)\n", files[i].inode, files[i].file_count);
		for(int j=0; j<files[i].file_count; j++)
		{
			printf("\t%s\n", files[i].filenames[j]);
		}
		printf("\n");
	}
	
	return 0;
}
