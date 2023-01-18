#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gradebook.h"

// This is the (somewhat famous) djb2 hash
unsigned hash(const char *str) {
    unsigned hash_val = 5381;
    int i = 0;
    while (str[i] != '\0') {
        hash_val = ((hash_val << 5) + hash_val) + str[i];
        i++;
    }
    return hash_val % NUM_BUCKETS;
}

gradebook_t *create_gradebook(const char *class_name) {
    gradebook_t *new_book = malloc(sizeof(gradebook_t));
    if (new_book == NULL) {
        return NULL;
    }

    strcpy(new_book->class_name, class_name);
    for (int i = 0; i < NUM_BUCKETS; i++) {
        new_book->buckets[i] = NULL;
    }
    new_book->size = 0;

    return new_book;
}

const char *get_gradebook_name(const gradebook_t *book) {
  
    return book->class_name;
}

int add_score(gradebook_t *book, const char *name, int score) {
	int index = hash(name);
	node_t *n = malloc(sizeof(node_t));
	strcpy(n->name, name);
	n->score = score;
	n->next = NULL;
		
	if (book->buckets[index] != NULL) {
		node_t *cur = book->buckets[index];
		node_t *next;
		
		if(strcmp(cur->name,name) == 0) {
				cur->score = n->score;
				return 0;
			}
		
		while (cur->next != NULL) {
			if(strcmp(cur->name,name) == 0) {
				cur->score = n->score;
				return 0;
			}
            		next = cur->next;
            		cur = next;
        	}
        	cur->next = n;
	} else {
		book->buckets[index]= n;
	}
		
	book->size++;
	return 0;	
}

int find_score(const gradebook_t *book, const char *name) {
    	int index = hash(name);
    	if (book->buckets[index] == NULL) {
    		return -1;
    	}
    	
    	node_t *cur = book->buckets[index];
	node_t *next;
	
    	while (strcmp(cur->name, name) != 0 && cur != NULL) {
    			next = cur->next;
    			cur = next;
    		}
    		
    	if (strlen(cur->name) == 0) {
    		return -1;
    	} else {
    		return cur->score;
    	}
}

void print_gradebook(const gradebook_t *book) {
    	for (int i = 0; i < NUM_BUCKETS; i++) {
    		node_t *n = book->buckets[i];
    		while (n != NULL) {
    			printf("%s: %d\n", n->name, n->score);
    			n = n->next;
    		}
   	}
    	
}

void free_gradebook(gradebook_t *book) {
	for (int i = 0; i < NUM_BUCKETS; i++) {
		node_t *cur = book->buckets[i];
		node_t *next;
        	while (cur != NULL) {
    			next = cur->next;
    			free(cur);
    			cur = next;
    		}
        	
    	}
	free(book);
}

int write_gradebook_to_text(const gradebook_t *book) {
    char file_name[MAX_NAME_LEN + strlen(".txt")];
    strcpy(file_name, book->class_name);
    strcat(file_name, ".txt");
    FILE *f = fopen(file_name, "w");
    if (f == NULL) {
        return -1;
    }

    fprintf(f, "%u\n", book->size);
    for (int i = 0; i < NUM_BUCKETS; i++) {
        node_t *current = book->buckets[i];
        while (current != NULL) {
            fprintf(f, "%s %d\n", current->name, current->score);
            current = current->next;
        }
    }
    fclose(f);
    return 0;
}

gradebook_t *read_gradebook_from_text(const char *file_name) {	//am I doing the reading/writing right
    FILE *f = fopen(file_name, "r");
    if (f == NULL) { 
    	return NULL;
    }
    
    char name[MAX_NAME_LEN];
    strcpy(name, file_name);
    name[strlen(name) - 4] = '\0';
    
    gradebook_t *book = create_gradebook(name);
    fscanf(f, "%u\n", &book->size);
    unsigned size = book->size;
    for (int i = 0; i < size; i++) {
    	int score;
    	char name[MAX_NAME_LEN];
    	fscanf(f, "%s %d\n", name, &score);
    	add_score(book, name, score); 
    }
    book->size = size;
    fclose(f);
    return book;
    
}

int write_gradebook_to_binary(const gradebook_t *book) {
    char file_name[MAX_NAME_LEN + strlen(".bin")];
    strcpy(file_name, book->class_name);
    strcat(file_name, ".bin");
    FILE *f = fopen(file_name, "w");
    if (f == NULL) {
        return -1;
    }
    
    fwrite(&book->size, sizeof(unsigned), 1, f);
    for (int i = 0; i < NUM_BUCKETS; i++) {
        node_t *current = book->buckets[i];
        while (current != NULL) {
            unsigned name_size = strlen(current->name);
            fwrite(&name_size, sizeof(name_size), 1, f);
            fwrite(&current->name, sizeof(char), name_size, f);
            fwrite(&current->score, sizeof(current->score), 1, f);
            current = current->next;
        }
    }
    fclose(f);
    return 0;
}

gradebook_t *read_gradebook_from_binary(const char *file_name) {
    FILE *f = fopen(file_name, "r");
    if (f == NULL) { 
    	return NULL;
    }
    
    char name[MAX_NAME_LEN];
    strcpy(name, file_name);
    name[strlen(name) - 4] = '\0';
    
    gradebook_t *book = create_gradebook(name);
    fread(&book->size, sizeof(book->size), 1 , f);
    unsigned size = book->size;
    
    for (int i = 0; i < size; i++) {
    	int score;
    	char name[MAX_NAME_LEN] = {};
    	unsigned name_size;
    	fread(&name_size, sizeof(name_size), 1, f);
    	fread(&name, sizeof(char), name_size, f);
    	fread(&score, sizeof(score), 1, f);
    	add_score(book, name, score);
    }
    book->size = size;
    fclose(f);
    return book;
}
