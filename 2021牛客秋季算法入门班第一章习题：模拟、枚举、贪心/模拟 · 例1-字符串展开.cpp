#include <stdio.h>
#include <string.h>
int main()
{
    int p1,p2,p3;
    scanf("%d %d %d",&p1,&p2,&p3);
    char s[105];
    scanf("%s",s);
    int i,u,k;
    int poor;
    int len=strlen(s);//长度为len，最后一位是s[len-1]
    for(i=0;i<len;i++)
    {
        if(s[i]!='-')
        {
            printf("%c",s[i]);
        }
        else
        {
            if(i==0||i==len-1)
            {
                printf("-");
                continue;
            }
            else if(s[i+1]=='-'||s[i-1]=='-')
            {
                printf("-");
            }
            else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='a'&&s[i+1]<='z')
            {
                printf("-");
                continue;
            }
            else if(s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]>='a'&&s[i-1]<='z')
            {
                printf("-");
                continue;
            }
            else
            {
                poor=s[i+1]-s[i-1];
                if(poor<=0)
                {
                    printf("-");
                    continue;
                }
                else if(poor==1)
                {
                    continue;
                }
                else if (poor>1)
                {
                    if(p1==1)//小写
                    {
                        if(p3==1)//正序
                        {
                            for(u=1;u<=poor-1;u++)
                            {
                                for(k=1;k<=p2;k++)
                                {
                                    printf("%c",s[i-1]+u);
                                }
                            }
                        }
                        else//倒序
                        {
                            for(u=1;u<=poor-1;u++)
                            {
                                for(k=1;k<=p2;k++)
                                {
                                    printf("%c",s[i+1]-u);
                                }
                            }
                        }
                    }
                    else if (p1==2)//大写 
                    {
                        if(p3==1)//正序
                        {
                            for(u=1;u<=poor-1;u++)
                            {
                                for(k=1;k<=p2;k++)
                                {
                                    if(s[i-1]>='a'&&s[i-1]<='z')
                                    {
                                        printf("%c",s[i-1]+u-32);
                                    }
                                    else
                                    {
                                        printf("%c",s[i-1]+u);
                                    }
                                }
                            }
                        }
                        else//倒序
                        {
                            for(u=1;u<=poor-1;u++)
                            {
                                for(k=1;k<=p2;k++)
                                {
                                    if(s[i-1]>='a'&&s[i-1]<='z')
                                    {
                                        printf("%c",s[i+1]-u-32);
                                    }
                                    else
                                    {
                                        printf("%c",s[i+1]-u);
                                    }
                                }
                            }
                        }
                    }
                    else //p1==3   用*号
                    {
                        for(u=1;u<=poor-1;u++)
                        {
                            for(k=1;k<=p2;k++)
                            {
                                printf("*");
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
