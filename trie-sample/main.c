//
//  main.c
//  trie-sample
//
//  Created by Farzaneh on 10/28/18.
//  Copyright © 2018 Farzaneh. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct Trie Trie;

struct Trie {
    char key[16];
    int end;
    Trie *next;
    Trie *child;
};

static Trie *trie_create(const char *str)
{
    Trie *trie = malloc(sizeof(*trie));
    trie->next = NULL;
    trie->child = NULL;
    trie->end = 0;
    strcpy(trie->key, str);
    
    return trie;
}

void trie_add(Trie **trie, const char *str)
{
    char buf[strlen(str) + 1];
    char *tok;
    int *p = NULL;
    
    strcpy(buf, str);
    printf("string is %s \n",str);
    tok = strtok(buf, ".");
    
    
    while (tok) {
        while (*trie) {
            //printf("token is : %s and key is %s and next is : %d \n",tok,(*trie)->key,*(&(*trie)->next));
            if (strcmp((*trie)->key, tok) == 0) break;
            
            trie = &(*trie)->next;
        }
        
        if (*trie == NULL) {
            *trie = malloc(sizeof(**trie));
            
            (*trie)->next = NULL;
            (*trie)->child = NULL;
            (*trie)->end = 0;
            strcpy((*trie)->key, tok);
        }
        
        p = &(*trie)->end;
        trie = &(*trie)->child;
        
        tok = strtok(NULL, ".");
    }
    
    if (p) (*p)++;
}

char** tokenize (const char* str)
{
    int n_spaces = 0;
    char buf[strlen(str) + 1];
    char *tok;
    strcpy(buf, str);
    tok = strtok (buf, ".");
    char **words = NULL;
    words = realloc (words, sizeof (char*) * n_spaces);
    while(tok){
       words = realloc (words, sizeof (char*) * ++n_spaces);
        if (words == NULL)
            exit (-1);
        words[n_spaces] = tok;
        tok = strtok (NULL, ".");
    }
    words = realloc (words, sizeof (char*) * (++n_spaces));
    words[n_spaces] = 0;
    --n_spaces;
    words[0] = (char *)&n_spaces;
    //printf("n_spaces %d \n",(int)*words[0]);
    return words;
}

int search_trie(int v,int i,Trie **trie, char** words)
{
    // return 0 if Trie is empty
    if (*trie == NULL)
        return 0;
    int words_length = (int)*words[0];
    if(i == words_length){
        if((*trie)->end){
            v++;
        }
    }
    else{
        char *word = words[i];
        if(1){
           if (strcmp((*trie)->key, word) == 0){
               if((*trie)->child != NULL)
                   trie = &(*trie)->child;
               v = search_trie(v, i+1,trie, words);
           }
        }
    }
    /*while (tok)
    {
        while(*trie){
            if (strcmp((*trie)->key, tok) == 0){
                if((*trie)->end){
                    v++;
                    //break;
                }
                if((*trie)->child != NULL)
                   trie = &(*trie)->child;
               v = search_trie(v, trie, rest);
               //tok = strtok(NULL, ".");
            }
            else{
                while((*trie)->next){
                    if(strcmp((*trie)->key, tok) == 0){
                        v = search_trie(v, trie, rest);
                    }
                    
                }
            }
        }
        //if(*(&(*trie)->end))
//            return 1;
       
    }*/
    return v;
    // if current node is a leaf and we have reached the
    // end of the string, return 1
}
void trie_delete(Trie *trie)
{
    while (trie) {
        Trie *t = trie;
        
        trie_delete(trie->child);
        trie = trie->next;
        free(t);
    }
}

void trie_print(Trie *trie, int level)
{
    while (trie) {
        printf("%*s%s", level * 4, "", trie->key);
        if (trie->end) printf(" [%d]", trie->end);
        puts("");
        
        trie_print(trie->child, level + 1);
        trie = trie->next;
    }
}

int main()
{
    Trie *trie = NULL;
    char **words;
    words = tokenize("foo.bar.foo");
    printf("size of words is %d \n", (int)*words[0]);
    trie_add(&trie, "foo.bar.foo");
    //trie_add(&trie, "bar.bar.baz");
    int v=0;
    int a = search_trie(v, 1, &trie, words);
    if(a)
       printf("fooound\n");
    else
        printf("not found :(\n");
    /*trie_add(&trie, "foo.bar.foo.*");
     trie_add(&trie, "foo.baz.*");
     trie_add(&trie, "foo.*.bar");
     trie_add(&trie, "bar.foo.*.one");
     trie_add(&trie, "bar.foo.*.two");
     trie_add(&trie, "foo.foo");
     trie_add(&trie, "foo.foo");
     trie_add(&trie, "bar");*/
    
    //trie_print(trie, 0);
    
    //trie_delete(trie);
    
    return 0;
}

