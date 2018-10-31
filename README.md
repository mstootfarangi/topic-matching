## topic-matching

this code try to create a trie from strings then find matched string for given sample


# data structure : 
each node is a struct and will have a key and a pointer to child and next node

child is next word of existing node, ie in `foo.bar`, `bar` is a child for `foo`.

next is other possible choice for matching, ie in `foo.baz`, `baz` is next node for `bar` which already exist in trie


# add : 

void trie_add(Trie **trie, const char *str)

# match :

search_trie(int v,Trie **trie, const char* str)

# tokenize :

char** tokenize (const char* str)

## RUN

 download main.c from project and run `gcc -g -Wall -o main main.c`
 
 note : current code just try to tokenize a string and output is nothing! other function was commented so they could work as recursive 
        one if tokenize done in right way.



