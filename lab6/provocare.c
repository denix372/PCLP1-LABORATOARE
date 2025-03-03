#include <stdio.h>
int main()
{
    /*int *p,i,n,v[101];
    p=v;
    //p++;
    // *p este valoarea; *p=v[0] si &v[i] este referentierea; p=&v;

    // declarati un vector cu elemente de tip intreg, 
    //int v[]={10,20,30,40,50,60,70,80,90};
    */
    int v[101],i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&v[i]);
        
    int *p;
    for(p=v;p<v+n;p++)
        printf("%d ",*p);
    return 0;
}