#include <stdio.h>
// 
int main(int argc, char *argv[])
{
    // 建立两个数组
    int ages[] = {88, 43, 12, 89, 2};
    char *names[] = {
        "小T", "PCH",
        "cleanery", "hello-world", "鲁迅"
    };

    // 安全得到个数
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // 第一种方法得到
    for(i = 0; i < count; i++) {
        printf("%s 吃了 %d 次火锅\a.\n",
                names[i], ages[i]);
    }

    printf("---\n");

    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;

    // second way using pointers
    for(i = 0; i < count; i++) {
        printf("is %s\n",(cur_name+i));
        printf("%s 吃了 %d 次火锅.\n",
                *(cur_name+i), *(cur_age+i));
    }

    printf("---\n");

    // third way, pointers are just arrays
    for(i = 0; i < count; i++) {
        printf("%s 吃了 %d 次火锅.\n",
                cur_name[i], cur_age[i]);
    }

    printf("---\n");

    // fourth way with pointers in a stupid complex way
    for(cur_name = names, cur_age = ages;
            (cur_age - ages) < count;
            cur_name++, cur_age++)
    {
        printf("%s lived %d years so far.\n",
                *cur_name, *cur_age);
    }

    return 0;
}
