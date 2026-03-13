#include <stdio.h>
#include <string.h>
int cmp(int*a,int*b)//不一样，返回0，一样，返回1
{
    int i;
    for(i=0;i<8;i++)
    {
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}
int judg_Palindrome(const int*a)//判断是不是回文数 是，返回1，不是，返回0
{
    if(a[0]==a[7]&&a[1]==a[6]&&a[2]==a[5]&&a[3]==a[4])
    return 1;
    else return 0;
}
int judg_year(int a)//判断是不是闰年，是 返回1  不是 返回0
{
    if(a%4==0&&a%100!=0||a%400==0)
    {
        return 1;
    }
    else return 0;
}
int main()
{
    int answer=0;
    int start[8],over[8];
    int current[8]={0};
    int i;
    int year,month,day;
    for(i=0;i<8;i++)
    {
        scanf("%1d",&start[i]);
        current[i]=start[i];
    }
    for(i=0;i<8;i++)
    {
        scanf("%1d",&over[i]);
    }
    while(!cmp(current,over))
    {
        if(judg_Palindrome(current)) answer++;
        year=current[0]*1000+current[1]*100+current[2]*10+current[3];
        month=current[4]*10+current[5];
        day=current[6]*10+current[7];
        if(day==28)
        {
            if(month==2)//是2月
            {
            if(!judg_year(year))//是平年
                {
                current[6]=0;current[7]=1;
                current[5]=3;
                }
                else//是闰年
                current[7]=9;
                continue;
            }
            else
            current[7]=9;
        }
        else if(day==29)//一定是闰年
        {
            if(month==2)
            {
                current[6]=0;current[7]=1;
                current[5]=3;
                continue;
            }
            else
            current[6]=3;current[7]=0; continue;
        }
        else if(day==30)
        {
            if(month==4||month==6||month==9||month==11)
            {
                current[6]=0;current[7]=1;
                if(month==4) current[5]=5;
                else if(month==6) current[5]=7;
                else if(month==9)
                {
                    current[4]=1;current[5]=0;
                }
                else if(month==11)
                {
                    current[5]=2;
                }
                continue;
            }
            else
            {
                current[7]=1;
                continue;
            }
        }
        else if(day==31)
        {
            current[6]=0;current[7]=1;
            month++;
            if(month==13)
            {
                current[4]=0;current[5]=1;
                year++;
                current[0]=year/1000;
                current[1]=year/100%10;
                current[2]=year/10%10;
                current[3]=year%10;
                continue;
            }
            else
            {
                current[4]=month/10;current[5]=month%10;
                continue;
            }
        }
        else
        {
            day++;
            current[6]=day/10;
            current[7]=day%10;
        }
        
    }
    if(judg_Palindrome(current)) answer++;
    printf("%d",answer);
}
