#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

int main(){
	StrList *list = StrList_alloc();
	int a=0;
	
	while(1){
	    scanf("%d",&a);	
	    if(a==1){
		    int x;
		    scanf("%d",&x);

		    while(1){
			char *c = malloc(sizeof (char)*100);
			scanf("%s",c);
			StrList_insertLast(list,c);
			x--;
			if(x<=0) break;
			free(c);
		    }
		   
	     }
	     else if(a==2){
	     	int x = 0;
	     	scanf("%d",&x);
	     	char *c = malloc(sizeof (char)*100);
	     	scanf("%s",c);
	     	StrList_insertAt(list,c,x);
	     	free(c);
	     	
	     
	     }
	     
	     else if(a==3){
	     	StrList_print(list);
	     	printf("\n");
	   
	     }
		
	     else if(a==4){
	     	printf("%ld",StrList_size(list));
	     	printf("\n");
	     	
	     
	     
	     }	
	     else if(a==5){
	     	int x;
	     	scanf("%d",&x);
	     	StrList_printAt(list,x);
	     	printf("\n");
	     
	     }
	     
	     else if(a==6){
	     	printf("%d",StrList_printLen(list));
	     	printf("\n");
	     
	     }
	     else if(a==7){
	     	char *c = malloc(sizeof (char)*100);
	     	scanf("%s",c);
	     	
	     	printf("%d",StrList_count(list,c));
	     	
	     	free(c);
	     	printf("\n");
	     }
	     
	     else if(a==8){
	     	char *c = malloc(sizeof (char)*100);
	     	scanf("%s",c);
	     	StrList_remove(list,c);
	     	free(c);
	     	
	     }
	     else if(a==9){
	     	int x;
	     	scanf("%d",&x);
	     	StrList_removeAt(list,x);
	     	
	     }
	     else if(a==10){
	     	StrList_reverse(list);
	     	
	     }
	     else if(a==11){
	     	StrList_free(list);
	     	
	     }
	     else if(a==12){
	     	StrList_sort(list);
	     	
	     }
	     else if(a==13){
	     	if(StrList_isSorted(list)) printf("true");
	     	else printf("false");
	     	printf("\n");
	     }
	     else if(a==0){
	     	break;
	     }
	     
		
	
	}
	if(list!=NULL){
		StrList_free(list);
	}

	return 0;
}
