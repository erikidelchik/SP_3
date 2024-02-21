#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"


typedef struct _Node{
    char *p;
    struct _Node *next;


}Node;

Node* Node_alloc(const char *data,Node *next){
    Node* n = (Node*) malloc(sizeof (Node));
    n->p = strcpy((char*) malloc(sizeof (data)+1),data);
    n->next = next;
    return n;
}

struct _StrList{
    Node *head;
    int listSize;

};



StrList* StrList_alloc(){
    StrList *p = (StrList*) malloc(sizeof(StrList));
    p->head = NULL;
    p->listSize = 0;
    return p;

}

void StrList_free(StrList* StrList){
    if (StrList==NULL) return;
    Node* p1= StrList->head;
    Node* p2;
    while(p1) {
        p2 = p1;
        p1 = p1->next;
        free(p2->p);
        free(p2);
    }
    StrList->head = NULL;
    StrList->listSize = 0;
}

size_t StrList_size(const StrList* StrList){
    if(StrList!=NULL)
    	return StrList->listSize;
    return 0;
    	
}

void StrList_insertLast(StrList* StrList,const char* data){
    Node *currpointer = StrList->head;
    if(currpointer==NULL){
        StrList->head = Node_alloc(data,NULL);
        StrList->listSize++;
        return;
    }
    while (currpointer->next!=NULL){
        currpointer=currpointer->next;
    }

    currpointer->next = Node_alloc(data,NULL);
    ++(StrList->listSize);
}

/*
* Inserts an element at given index
*/
void StrList_insertAt(StrList* StrList, const char* data,int index){
    if(StrList_size(StrList)<=index || index<0) return;
    int c = 0;
    Node *currpointer = StrList->head;

    if(index==0){
        StrList->head = Node_alloc(data,StrList->head);
        return;
    }

    while(c!=index-1){
        c++;
        currpointer=currpointer->next;
    }
    Node *new = Node_alloc(data,currpointer->next);
    currpointer->next = new;
    StrList->listSize++;
}

/*
 * Returns the StrList first data.
 */
char* StrList_firstData(const StrList* StrList){
    return StrList->head->p;
}

/*
 * Prints the StrList to the standard output.
 */
void StrList_print(const StrList* StrList){
    if(StrList==NULL) return;
    const Node *currpointer = StrList->head;
    while(currpointer){
    	if(currpointer->next==NULL) printf("%s",currpointer->p);
        else printf("%s ",currpointer->p);
        currpointer= currpointer->next;
    }
}

/*
 Prints the word at the given index to the standard output.
*/
void StrList_printAt(const StrList* StrList,int index){
    const Node *currpointer = StrList->head;
    if(StrList_size(StrList)<index+1) return;
    int c=0;
    while (c!=index){
        c++;
        currpointer = currpointer->next;
    }
    printf("%s",currpointer->p);
}

/*
 * Return the amount of chars in the list.
*/
int StrList_printLen(const StrList* StrList){
    const Node *currpointer = StrList->head;
    int c = 0;
    while (currpointer){
        c += (int) strlen(currpointer->p);
        currpointer = currpointer->next;
    }
    return c;
}

/*
Given a string, return the number of times it exists in the list.
*/
int StrList_count(StrList* StrList, const char* data){
    const Node *currpointer = StrList->head;
    int c = 0;
    while (currpointer){
        if(!strcmp(currpointer->p,data)) c++;
        currpointer = currpointer->next;
    }
    return c;
}



/*
	Given an index and a list, remove the string at that index.
*/
void StrList_removeAt(StrList* StrList, int index){
    if(StrList->listSize<=index || index<0) return; // if index is greater or eq to list size, do nothing
    Node *currpointer = StrList->head;
    int c=0;
    if(index==0){
        if(currpointer->next==NULL)   //if list size is 1
            StrList->head=NULL;
        else
            StrList->head = StrList->head->next;

        StrList->listSize--;
        return;
    }

    while (c!=index-1){
        currpointer=currpointer->next;
        c++;
    }
    if(currpointer->next->next!=NULL){   //if it's not the last index of the list
        currpointer->next = currpointer->next->next;
    }
    else currpointer->next=NULL;
    StrList->listSize--;

}

/*
	Given a string and a list, remove all the appearances of this string in the list.
*/
void StrList_remove(StrList* StrList, const char* data){
    Node *currpointer = StrList->head;
    int i = 0;
    while (currpointer){
        if(!strcmp(currpointer->p,data)){  //start from beginning of the list
            StrList_removeAt(StrList,i);
            currpointer = StrList->head;
            i=0;
        }
        else {
            currpointer = currpointer->next;
            i++;
        }
    }



}

/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if(StrList1==NULL || StrList2==NULL || StrList1->listSize!=StrList2->listSize) return 0;
    Node* p1 = StrList1->head;
    Node* p2 = StrList2->head;
    while (p1 && p2){
        int result = strcmp(p1->p,p2->p);
        if(!result){
            p1 = p1->next;
            p2 = p2->next;
        }
        else return 0;
    }
    return 1;


}


/*
 * Clones the given StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* Strlist){
    StrList *newlist = StrList_alloc();
    newlist->listSize = Strlist->listSize;
    Node *old = Strlist->head;
    Node **copy = &newlist->head;

    while (old){
        *copy = Node_alloc(old->p,NULL);
        old = old->next;
        copy = &(*copy)->next;


    }

    return newlist;
}

/*
 * Reverses the given StrList.
 */
void StrList_reverse(StrList* StrList){
    int size = (int) StrList_size(StrList);
    if(size<=1) return;

    Node** arr = (Node **) malloc(size* sizeof(Node*));
    Node *p = StrList->head;
    int k = 0;
    while(p){
        arr[k] = p;
        p = p->next;
        k++;
    }
    while (k-1){
        arr[k-1]->next = arr[k-2];
        k--;
    }
    StrList->head = arr[size-1];
    arr[0]->next = NULL;

    free(arr);

}

/*
 * Sort the given list in lexicographical order
 */
void StrList_sort( StrList* StrList){
    Node *currpointer = StrList->head;
    int size = (int) StrList_size(StrList);
    char** arr = (char **) malloc(size* sizeof(char*));
    int k=0;
    while (currpointer){
        arr[k] = currpointer->p;
        currpointer = currpointer->next;
        k++;
    }

    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            int result = strcasecmp(arr[j],arr[j+1]);
            if(result>0){
                char *temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
    }
    Node *cp = StrList->head;

    for(int i=0;i<size;i++){
        cp->p = strcpy((char*) malloc(sizeof (arr[i])+1),arr[i]);
        cp = cp->next;
    }

    free(arr);
}

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* StrList){
    int size = (int) StrList->listSize;
    if(size<=1) return 1;
    Node *currnode = StrList->head->next;
    Node *prev = StrList->head;

    while (currnode){
        int result = strcasecmp(prev->p,currnode->p);
        if(result>0) return 0;
        currnode = currnode->next;
        prev = prev->next;
    }
    return 1;

}


