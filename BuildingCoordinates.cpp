#include <iostream>
#include <stdio.h>
#include <string>
#define STR_SIZE 1000
using namespace std;
struct data{
    int l;
    int h;
    int b;
};

int main()
{
	int n;
	char outstr[STR_SIZE]={0};
    scanf("%d",&n);
    struct data d[n];

    for(int i=0;i<n;i++)
    scanf("%d%*c%d%*c%d",&d[i].l,&d[i].h,&d[i].b);
    for (int i=0;i<n;i++)
    {
        int min=i;
        for (int j=i+1;j<n;j++)
        {
            if(d[j].l<d[min].l)
                min=j;
        }
        struct data temp=d[i];
        d[i]=d[min];
        d[min]=temp;
    }
    //include initial ordinate 
    sprintf(outstr, "%d%c%d", d[0].l,'#', 0);
    //initial height ordinate will  be of building with least left ordinate   
    sprintf(outstr, "%s\n%d%c%d", outstr,d[0].l,'#', d[0].h);
    int r_edges[n], r_edges_inter[n];
    for (int ll=0;ll<n;ll++)
    {   r_edges[ll]=0;
    }
    int top=0;
    r_edges[0]=1;
    int r_edges_count=1;
    for(int i=1;i<n;i++)
    {
        int left_curr=d[i].l;
        int right_curr=d[i].b;
        int height_curr=d[i].h;
        int m_height=0;
        int add_left_flag=1;
        int add_right_flag=1;
        int prev=0;
        if((height_curr==0)||(left_curr==right_curr))
            continue;
        for (int ll=0;ll<n;ll++)
        {   
            r_edges_inter[ll]=0;
            top=0;
        }    
        for (int j=0;j<i;j++)
        {
            if((d[j].h==0)||(d[j].l==d[j].b))
            continue;
            if(left_curr <= d[j].b)
            {  
                if(height_curr<=d[j].h)
                    add_left_flag=0;
                else
                {
                    (d[j].h > m_height)?(m_height=d[j].h):0;
                    if (right_curr>=d[j].b)
                        {
                            r_edges[j]=0;
                            r_edges_count--;
                        }
                }
            }
            else if((r_edges[j]==1)&&(d[j].b>=prev))
            {  
                
                    r_edges_inter[top]=j;
                    top++;
                
            }
            if((right_curr<=d[j].b) && (height_curr<=d[j].h))
                add_right_flag=0;
        }
        for (int i=0;i<top;i++)
        {
            int min=i;
            for (int j=i+1;j<top;j++)
            {
                if(d[r_edges_inter[j]].b<d[r_edges_inter[min]].b)
                min=j;
            }
            int temp=r_edges_inter[i];
            r_edges_inter[i]=r_edges_inter[min];
            r_edges_inter[min]=temp;
        }
        for (int k=0;k<top;k++)
        {   
            sprintf(outstr, "%s\n%d%c%d", outstr,d[r_edges_inter[k]].b,'#', d[r_edges_inter[k]].h);
             r_edges[r_edges_inter[k]]=0;
             r_edges_count-=1;
        }
        if(add_left_flag)
        {
             if(top!=0)
             {
                sprintf(outstr, "%s\n%d%c%d",outstr, d[i].l,'#',m_height);
                prev=d[i].b;
             }
            sprintf(outstr,"%s\n%d%c%d", outstr,d[i].l,'#',d[i].h);
        }
        
        if(add_right_flag)
            {
                r_edges[i]=1;
                r_edges_count+=1;
            }
    }
    do
    {
        int min;
        for (int m=0;m<n;m++)
        {
            if(r_edges[m]==0)
                continue;
            else
            {
                min=m;
                for (int k=m+1;k<n;k++)
                {   
                    if(r_edges[k]==0)
                        continue;
                    else
                        {
                            if (d[k].b<d[min].b)
                            min=k;
                        }
                }
                break;
            }
        }
    if(r_edges_count==1)
    {
        sprintf(outstr, "%s\n%d%c%d",outstr, d[min].b,'#',d[min].h);
        sprintf(outstr, "%s\n%d%c%d",outstr, d[min].b,'#',0);
    }
    else 
        sprintf(outstr, "%s\n%d%c%d",outstr, d[min].b,'#',d[min].h);
    r_edges[min]=0;
    r_edges_count--;
    }while(r_edges_count!=0);
    
    cout<<outstr;
    return 0;
}
