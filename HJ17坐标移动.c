/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-09-21 22:25:05
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-09-21 22:32:43
 * @FilePath: /CCODE/华为刷题/1.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() 
{
    char str[10000] = "A10;S20;W10;D30;X;A1A;B10A11;;A10;";
    char p[]  = ";";
    // gets(str);
    char* ret= NULL;
    int x = 0;
    int y = 0;
    
    for(ret = strtok(str,p);ret != NULL;ret = strtok(NULL,p))
    {
        int sum = 0;
        if(*ret == 'A' || *ret == 'D' || *ret == 'W'|| *ret == 'S')
        {
            char* cp = ret;
            //计算方向后的数值大小
            ret++;
            while(*ret && *ret >= '0' && *ret <= '9')
            {
                sum = sum*10 + ((*ret)-'0');
                ret++;
            }
            //改变坐标
            if(*ret == '\0')
            {
                if(*cp == 'A')
                    x -= sum;
                else if (*cp == 'D')
                    x += sum;
                else if (*cp == 'W')
                    y += sum;
                else if (*cp == 'S')
                    y -= sum;
            }
        }
    }
    printf("%d,%d\n",x,y);
    return 0;
}