#include <stdio.h>
#include <stdlib.h>
int main()
{
        char **planets;
        planets=malloc(40);
        *(planets+0)="MERCURY";
        *(planets+1)="VENUS";
        *(planets+2)="EARTH";
        *(planets+3)="ASTEROIDS";
        *(planets+4)="MARS";
        *(planets+5)=" ";
        printf("\n%p",planets);
        printf("\n%p",planets+1);
        printf("\n%p",planets+2);
        printf("\n%p",planets+3);
        printf("\n%p",planets+4);
        printf("\n%u",(*(planets+1)-*planets));
        printf("\n%u",(*(planets+2)-*(planets+1)));
        printf("\n%u",(*(planets+3)-*(planets+2)));
        printf("\n%u",(*(planets+4)-*(planets+3)));
        printf("\n%u",(*(planets+5)-*(planets+4)));
        return(0);
}
