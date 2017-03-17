/* Duff's device Copies int arrays -- blocks of memory*/
#include <stdio.h>

void        send(int *to, int *from,int count) 
         
         { 
                 int n=(count+7)/8; 
                 switch(count%8){ 
                 case 0: do{     *to++ = *from++; 
                 case 7:         *to++ = *from++; 
                 case 6:         *to++ = *from++; 
                 case 5:         *to++ = *from++; 
                 case 4:         *to++ = *from++; 
                 case 3:         *to++ = *from++; 
                 case 2:         *to++ = *from++; 
                 case 1:         *to++ = *from++; 
                         }while(--n>0); 
                 } 
         } 
 

int main()
{
	int i;
	int a[5]={1,2,3,4,5};
	int b[]={0,0,0,0,0};

	/*output each a[i] and b[i] in decimal separated by a Tab on one line*/
	for(i=0; i<5; i++)
		printf("%d\t%d\n", a[i], b[i]); 

	printf("----------------\n");

	send(b, a, 5);

	for(i=0; i<5; i++)
		printf("%d\t%d\n", a[i], b[i]);
}

