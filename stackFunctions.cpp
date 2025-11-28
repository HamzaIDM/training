#include  <stdio.h>
#include  <stdlib.h>

typedef struct link {
    int v;
    struct link *next;
}Link;

typedef Link *Stack;

Stack initStack() {
    return NULL;
}

int EmptyStack(Stack p) {
    return (p == NULL);
}

int StackSummit(Stack p , int* x) {
    if (!EmptyStack(p)) {
        *x = p -> v;
        return 1;
    }
    return 0;
}

Link* creeatLink(int v) {
    Link* ppt = (Link*)malloc(sizeof(Link));
    if (ppt == NULL) {
        printf("Allocation ERROR!!\n");
        exit(1);
    }
    ppt -> v = v;
    ppt -> next = NULL;
    return ppt;
}

int stackADD(Stack *p, int v) {
    Link* ppt = creeatLink(v);
    if (ppt != NULL) {
        ppt->next = *p;
        *p = ppt;
        return 1;
    }
    return 0;
}
int stackPop(Stack *p) {
    if (!EmptyStack(*p)) {
        Stack temp = *p;
        *p = (*p)->next;
        free(temp);
        return 1;
    }
    return 0;
}

void displayStack(Stack *p) {
    Stack temp = initStack();
    int x;
    while (!EmptyStack(*p)) {
        StackSummit(*p,&x);
        stackPop(p);
        stackADD(&temp,x);
        printf("%d\n",x);
    }
    while (!EmptyStack(temp)) {
        StackSummit(temp,&x);
        stackPop(&temp);
        stackADD(p,x);
    }
}

int main() {
    Stack p = initStack();


    stackADD(&p,4);
    stackADD(&p,-1);
    stackADD(&p,5);
    stackADD(&p,9);
    stackADD(&p,0);

    displayStack(&p);
    return 0;
}