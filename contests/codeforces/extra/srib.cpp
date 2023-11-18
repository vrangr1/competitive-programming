#include <stdio.h>
#include <stdlib.h>
typedef struct toy {
    int model, s_no, used;
    struct toy *next, *previous;
} toy;

toy *root;
void init(int N){
    root = (toy*) malloc(sizeof(toy));
    root->next = NULL;
    root->previous = NULL;
    root->used = 0;
    root->model = 0;
    root->s_no = 0;
    toy *iter;
    iter = root;
    for (int i = 0; i < N - 1; ++i){
        toy *temp = (toy*)malloc(sizeof(toy));
        iter->next = temp;
        (temp)->previous = iter;
        iter = temp;
        // iter->rank = i + 2;
        iter->next = NULL;
        iter->model = 0;
        iter->s_no = 0;
        // iter->previous = NULL;
        iter->used = 0;
    }
}

void acceptGift(int model, int s_no){
    toy *iter = root, *move = NULL;
    while(iter->used == 1){
        printf("One iter\n");
        if(model == iter->model){
            move = iter;
            break;
        }
        if(iter->next != NULL){
            printf("This one\n");
            iter = iter->next;
        }
            
        else{
            printf("Or this\n");
            move = iter;
            break;
        }
    }
    if(move == NULL){
        iter->model = model;
        iter->s_no = s_no;
        iter->used = 1;
        print();
    }
    else{
        if(move->next != NULL && move->previous != NULL){
            move->previous->next = move->next;
            move->next->previous = move->previous;
            move->previous = NULL;
            move->next = root;
            root->previous = move;
        }
        else if(move->previous != NULL){
            move->previous->next = NULL;
            move->previous = NULL;
            move->next = root;
            root->previous = move;
        }
        
        root = move;
        root->model = model;
        root->s_no = s_no;
    }
}

void play(int model){
    toy *iter = root;
    while (iter!=NULL){
        if (iter->model == model){
            printf("%d\n", iter->s_no);
            if(iter->next != NULL && iter->previous != NULL){
                iter->previous->next = iter->next;
                iter->next->previous = iter->previous;
                root->previous = iter;
                iter->next = root;
                iter->previous = NULL;
                root = iter;
            }
            else if(iter->previous != NULL){
                iter->previous->next = NULL;
                iter->next = root;
                iter->previous = NULL;
                root->previous = iter;
            }
            return;
        }
        if(iter->next != NULL)
            iter = iter->next;
        else
            break;
    }
    printf("-1\n");
}

void print(){
    printf("Print function called:\n");
    while(root!=NULL){
        printf("%d %d\n", root->model, root->s_no);
        if(root->next != NULL){
            root = root->next;
        }
        else
            break;
    }
    printf("Print function ended.\n");
}

void free_list(){
    while(root!=NULL){
        if(root->next != NULL){
            root = root->next;
            free(root->previous);
            root->previous = NULL;
        }
    }
    free(root);
}

int main(void) {
    // printf("Checkpoint 0\n");
	// your code goes here
	int T, Q, choice, model, s_no, N;
// 	toy *boxes;
	scanf("%d", &T);
// 	printf("Checkpoint 1\n");
	for(int test = 0; test < T; ++test){
	    scanf("%d %d", &N, &Q);
	    init(N);
	    printf("N, Q input: %d, %d\n", N, Q);
	    print();
	    for(int i = 0; i < Q; ++i){
	        scanf("%d", &choice);
	        printf("choice input: %d\n", choice);
	        if(choice == 0){
	            scanf("%d %d", &model, &s_no);
	            printf("model and s_no input: %d, %d\n", model, s_no);
	            acceptGift(model, s_no);
	            print();
	        }
	        else{
	            scanf("%d", &model);
	            play(model);
	            print();
	        }
	    }
	   // free_list();
	}
	return 0;
}


