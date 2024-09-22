//Singly Linked List - All Operations
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *ptr, *start, *preptr;

Node *create(Node *start){
    int num;
    printf("Creating Linked List\n");
    printf("If Num != -1 then only Linked List will execute\n");
    printf("Enter The Number: ");
    scanf("%d", &num);
    
    while(num != -1){
        Node *newN = (Node*)malloc(sizeof(Node));
        newN->data = num;
        
        if(start == NULL){
            newN->next = NULL;
            start = newN;
        }
        else{
            ptr = start;
            while(ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newN;
            newN->next = NULL;
        }
        printf("Enter The Number: ");
        scanf("%d", &num);
    }
    return start;
}

Node *display(Node *start){
    if(start == NULL){
        printf("----- LINKED LIST IS EMPTY----\n");
    }
    else{
        ptr = start;
        while(ptr->next != NULL){
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
    return start;
}

Node *InsBeg(Node *start){
    int num;
    printf("Enter The Number: ");
    scanf("%d", &num);
    
    Node *newN = (Node*)malloc(sizeof(Node));
    newN->data = num; 
    
    newN->next = start;
    start = newN;

return start;
}

Node *InsEnd(Node *start){
    int num;
    printf("Enter The Number: ");
    scanf("%d", &num);
    
    Node *newN = (Node*)malloc(sizeof(Node));
    newN->data = num;
    
    ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newN;
    newN->next = NULL;
    
return start;    
}

Node *InsMid(Node *start){
    int num, loc;
    printf("Enter the Node Value: ");
    scanf("%d", &loc);
    printf("Enter The Number: ");
    scanf("%d", &num);
    
    Node *newN = (Node*)malloc(sizeof(Node));
    newN->data = num;
    
    ptr = start->next;
    preptr = start;
    
    while(preptr->data != loc){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newN;
    newN->next = ptr;
    
return start;    
}

Node *delBeg(Node *start){
    if(start == NULL){
        printf("----- LINKED LIST IS EMPTY----\n");
    }
    else{
        ptr = start->next;
        start = ptr;
    }
return start;  
}

Node *delEnd(Node *start){
    if(start == NULL){
        printf("----- LINKED LIST IS EMPTY----\n");
    }
    else{
        ptr = start;
        while(ptr->next != NULL) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
    }
return start;
}

Node *delMid(Node *start){
    if(start == NULL){
        printf("----- LINKED LIST IS EMPTY----\n");
    }
    else{
        int num;
        printf("Enter The Node to be deleted in Middle: ");
        scanf("%d", &num);
        
        ptr = start;
        while(ptr->data != num){
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
    }
    return start;
}

Node *update (Node *start){
    int num, upNum;
    Node  *pr;
    printf("Enter The Old Node Value: ");
    scanf("%d", &num);
    printf("Enter Your Updated Node Value: ");
    scanf("%d", &upNum);
    
    Node *upN = (Node*)malloc(sizeof(Node));
    upN->data = upNum;
    
    ptr = start;
    while(ptr->data != num){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    
    ptr = start->next;
    pr = start;
    while(pr->data != preptr->data){
        pr = ptr;
        ptr = ptr->next;
    }
    pr->next = upN;
    upN->next = ptr;
    return start;
}

Node *reverse (Node *start){
    ptr = start;
    preptr = NULL;
    Node *postptr = ptr->next;
    
    while(ptr != NULL){
        ptr->next = preptr;
        preptr = ptr;
        ptr = postptr;
        
        if(postptr != NULL){
        postptr = postptr->next;
        }
    }

return preptr;    
}

Node *Traverse (Node *start){
    ptr = start;
    int count = 1;
    while(ptr->next != NULL){
        count++;
        ptr = ptr->next;
    }
    printf("%d Nodes are successfully accessed\n", count);
return start;    
}

void main(){
    int opt, insOpt, delOpt;
    do{
       printf("--\nCreate Menu--\n");
       printf("(1)\tCreating Linked List\n");
       printf("(2)\tInsertion of Node\n");
       printf("(3)\tDeletion of Node\n");
       printf("(4)\tUpdate Node at LL\n");
       printf("(5)\tReversal of Nodes\n");
       printf("(6)\tCounting Nodes\n");
       printf("(7)\tEXIT\n");
       printf("Enter the option: ");
       scanf("%d", &opt);
       
       switch(opt){
            case 1:
                start = create(start);
                start = display(start);
                break;
            
            case 2: 
            do{
                printf("---Create Menu-----\n");
                printf("(1)Insertion at Beginning\n");
                printf("(2)Insertion at End\n");
                printf("(3)Insertion after a given Node\n");
                printf("(4) EXIT\n");
                printf("Enter Option: ");
                scanf("%d", &insOpt);
                
                switch(insOpt){
                    case 1:
                        start = InsBeg(start);
                        start = display(start);
                        break;
                    case 2:
                        start = InsEnd(start);
                        start = display(start);
                        break;
                    case 3:
                        start = InsMid(start);
                        start = display(start);
                        break;
                    case 4:
                        break;
                    default:
                        printf("Invalid Number! Try Again\n");
                }
            }while(insOpt != 4);  
            break;
            
            case 3: 
            do{
                printf("---Create Menu-----\n");
                printf("(1)Deletion at Beginning\n");
                printf("(2)Deletion at End\n");
                printf("(3)Deletion of a given Node\n");
                printf("(4) EXIT\n");
                printf("Enter Option: ");
                scanf("%d", &delOpt);
                
                switch(delOpt){
                    case 1:
                        start = delBeg(start);
                        start = display(start);
                        break;
                    case 2:
                        start = delEnd(start);
                        start = display(start);
                        break;
                    case 3:
                        start = delMid(start);
                        start = display(start);
                        break;
                    case 4:
                        break;
                    default:
                        printf("Invalid Number! Try Again\n");
                }
            }while(delOpt != 4);  
            break;
        
        case 4:
            start = update(start);
            start = display(start);
            break;
            
        case 5:
            start = reverse(start);
            display(start);
            break;
        
        case 6:
            start = Traverse(start);
            break;
            
        case 7:
            break;

        default:
          printf("Invalid Number! Try Again\n");
       }
    }while(opt != 7);
}