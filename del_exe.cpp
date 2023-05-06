#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

void remove_exe_files(const char *path)
{
    DIR *dir = opendir(path);
    if (!dir)
    {
        perror("opendir failed");
        return;
    }

    struct dirent *entry;
    struct stat st;

    while ((entry = readdir(dir)))
    {
        char filename[1024];
        snprintf(filename, sizeof(filename), "%s/%s", path, entry->d_name);
        if (stat(filename, &st) == -1)
        {
            perror("stat failed");
            continue;
        }

        if (S_ISDIR(st.st_mode))
        {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }
            remove_exe_files(filename);
        }
        else if (S_ISREG(st.st_mode))
        {
            const char *extension = strrchr(entry->d_name, '.');
            if (extension && strcmp(extension, ".exe") == 0)
            {
                if (remove(filename) == -1)
                {
                    char str[300];
                    sprintf(str, "Remove %s failed", filename);
                    perror(str);
                    continue;
                }
                printf("Removed file: %s\n", filename);
            }
        }
    }

    closedir(dir);
}

/**
 * 该函数删除当前目录下的所有可执行文件，并在退出前等待用户输入。
 * 
 * @return 主函数返回一个整数值 0。
 */
int main()
{
    remove_exe_files("./");
    system("pause");
    return 0;
}