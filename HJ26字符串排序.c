/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-09-22 11:00:17
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-09-22 11:00:37
 * @FilePath: /CCODE/华为刷题/HJ26字符串排序.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char str[1000] = "";
    gets(str);
    int len = strlen(str);
    int ch[1000] = {0};
    int k = 0;
    //把A-Z 依次存到ch
    for(int i = 0 ;i < 26;i++)//每趟收集一个字符到ch数组(A-Z)
    {
        for(int j = 0;j < len;j++)
        {
            if(toupper(str[j]) == 'A'+i) 
            {
                ch[k++] = str[j];
            }
        }
    }
    //打印输出
    k = 0;
    for(int i = 0;i < len;i++)
    {
        if(isalpha(str[i]))
            str[i] = ch[k++];
    }
    printf("%s\n",str);
    return 0;
}
  