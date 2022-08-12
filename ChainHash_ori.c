#include <stdio.h>
#include <stdlib.h> 

struct data{
    int value;
    struct data *next;
};

struct data *datalist[2];

int Hash(int value){
    return value%2;
}

int search(int value){
    int index = Hash(value);
    struct data *q;
    for(q = datalist[index]; q != NULL; q = q->next){
        if(value == q->value){
            return 1;
        }
    }
    return 0;
}

void insert(int value){
    struct data *p, *q;
    int index;
    if(!search(value)){
        p = (struct data *)malloc(sizeof(struct data));
        p->value = value;
        p->next = NULL;
        index = Hash(value);
        q = datalist[index];

        if(q != NULL){
            while(q->next != NULL){
                q = q->next;
            }
            q->next = p;
        }else{
            datalist[index] = p;
        }
    }
}

void delete(int value){
    int index = Hash(value);
    struct data *q, *previous;
    
    //該当indexを線形探索
    for(q = datalist[index]; q != NULL; q = q->next){
        if(value == q->value){
            q->value = 0;
            previous->next = q->next;
            free(q);
        }
        previous = q;
    }

    printf("delete succeed\n");
}


int main(void){
    
    insert(6);
    insert(8);
    insert(9);
    insert(1);

    printf("\n value: %d, at %d\n",(*datalist[0]).value, index);
    printf("\n value: %d, at %d\n",(datalist[0]->next)->value, index);
    printf("\n value: %d, at %d\n",(*datalist[1]).value, index);
    printf("\n value: %d, at %d\n",(datalist[1]->next)->value, index);

    delete(6);
    delete(8);
    delete(9);
    delete(1);
    
    return 0;
}

