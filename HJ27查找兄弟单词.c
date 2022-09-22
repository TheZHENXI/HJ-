/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-09-22 09:51:37
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-09-22 10:57:02
 * @FilePath: /CCODE/华为刷题/HJ27 查找兄弟单词.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <string.h>

int Isbrother(char s[11],char tar[11])
{

    if(strcmp(s,tar) == 0 || strlen(s) != strlen(tar))
    {
        return 0;
    }
    else
    {
        int hash[26] = {0};
        for(int i =0;i < strlen(s);i++)
        {
            hash[s[i]-'a']++;
            hash[tar[i]-'a']--;   
        }
        for(int i = 0;i < 26;i++)
        {
            if(hash[i] != 0)
                return 0;
        }    
        return 1;
    }
}

//6 cab ad abcd cba abc bca abc 1
int main() 
{
    //输入处理
    int n = 6;
    char str[1000][11] = {"cab","ad","abcd","cba","abc","bca"};//{"cab","ad","abcd","cba","abc","bca"}
    char cp[1000][11] ;
    char tar[11] = "abc";     //"abc"
    int k = 1;
    // scanf("%d",&n);
    // for(int i = 0;i < n;i++)
    // {
    //     scanf("%s",str[i]);
    // }
    // scanf("%s",tar);
    // scanf("%d",&k);
    //判断是否为兄弟单词
    int cnt = 0;
    for(int i = 0;i < n;i++)
    {
        if(Isbrother(str[i],tar))
        {
            strcpy(cp[cnt++],str[i]); 
        }
    }
    //排序兄弟单词
    for(int i =0;i < cnt - 1;i++)
    {
        for(int j = 0;j < cnt-1-i;j++)
        {
            if(strcmp(cp[j],cp[j+1]) > 0)
            {
                char tmp[11];
                strcpy(tmp,cp[j]);
                strcpy(cp[j],cp[j+1]);
                strcpy(cp[j+1],tmp);
            }
        }
    }
    printf("%d\n",cnt);
    printf("%s\n",cp[k-1]);
}