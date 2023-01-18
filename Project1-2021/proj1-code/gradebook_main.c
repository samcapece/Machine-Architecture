#include <stdio.h>
#include <string.h>

#include "gradebook.h"

#define MAX_CMD_LEN 128

/*
 * This is in general *very* similar to the list_main file seen in lab
 * One big difference is the notion of switching between gradebooks in one
 * run of the program.
 * You have to create or load a gradebook from a file before you can do things
 * like add, lookup, or write.
 * The code below has to check if gradebook is NULL before the operations
 * occur. Also, the user has to explicitly clear the current gradebook before
 * they can create or load in a new one.
 */
int main(int argc, char **argv) {
    gradebook_t *book = NULL;
    
    if (argc > 1) {
    	char *file_name = argv[1];
    	char *ext = strchr(file_name, '.');
    	if (strcmp(ext, ".txt") == 0) {
        	printf("Gradebook loaded from text file\n");
        	book = read_gradebook_from_text(file_name);
        	if(book == NULL) {
        		printf("Failed to read gradebook from text file\n");
        	}
    	} else if (strcmp(ext, ".bin") == 0){ 
       	printf("Gradebook loaded from binary file\n");
        	book = read_gradebook_from_binary(file_name);
        	if(book == NULL) {
        		printf("Failed to read gradebook from binary file\n");
        	}
   	} else {
   		printf("Error: Unknown gradebook file extension\n");
   		}
   }
    
    
    printf("CSCI 2021 Gradebook System\n");
    printf("Commands:\n");
    printf("  create <name>:          creates a new class with specified name\n");
    printf("  class:                  shows the name of the class\n");
    printf("  add <name> <score>:     adds a new score\n");
    printf("  lookup <name>:          searches for a score by student name\n");
    printf("  clear:                  resets current gradebook\n");
    printf("  print:                  shows all scores, sorted by student name\n");
    printf("  write_text:             saves all scores to text file\n");
    printf("  read_text <file_name>:  loads scores from text file\n");
    printf("  write_bin:              saves all scores to binary file\n");
    printf("  read_bin <file_name>:   loads scores from binary file\n");
    printf("  exit:                   exits the program\n");

    char cmd[MAX_CMD_LEN];
    while (1) {
        printf("gradebook> ");
        if (scanf("%s", cmd) == EOF) {
            printf("\n");
            break;
        }

        if (strcmp("exit", cmd) == 0) {
            break;
        }

        else if (strcmp("create", cmd) == 0) {
            scanf("%s", cmd); // Read in class name
            if (book != NULL) {
                printf("Error: You already have a gradebook.\n");
                printf("You can remove it with the \'clear\' command\n");
            } else {
                book = create_gradebook(cmd);
                if (book == NULL) {
                    printf("Gradebook creation failed\n");
                }
            }
        }
	
	else if (strcmp("class", cmd) == 0) {
		if (book != NULL) {
			const char *p = get_gradebook_name(book);
			printf("%s\n", p);
				
		} else {
			printf("Error: You must create or load a gradebook first\n");
		}
	}
	
	else if (strcmp("add", cmd) == 0) {
		char name[MAX_CMD_LEN];
		int score;
		scanf("%s", name);
		scanf("%d", &score);
		if(book != NULL) {
			if (score < 0) {
				printf("Error: You must enter a score in the valid range (0 <= score)\n");
			} else {
				add_score(book, name, score);
			}
		} else {
			printf("Error: You must create or load a gradebook first\n");
		}
	}
	
	else if (strcmp("lookup", cmd) == 0) {
		char name[MAX_CMD_LEN];
		scanf("%s", name);
		if(book != NULL) {
			int score = find_score(book, name);
		  	if (score != -1) {
				printf("%s: %d\n", name, score);
			} else {
				printf("No score for '%s' found\n", name);
			}
		} else {
			printf("Error: You must create or load a gradebook first\n");
		}
	}
	
	else if (strcmp("print", cmd) == 0) {
		if(book != NULL) {
			printf("Scores for all students in %s:\n", book->class_name);
			print_gradebook(book);
		} else {
			printf("Error: You must create or load a gradebook first\n");
		}
	}
	
	else if (strcmp("clear", cmd) == 0) {
		if(book != NULL) {
			free_gradebook(book);
			book = NULL;
		} else {
			printf("Error: No gradebook to clear\n");
		}
	}
	
	else if (strcmp("write_text", cmd) == 0) {
		if(book != NULL) {
			write_gradebook_to_text(book);
			if(write_gradebook_to_text(book) == 0) {
				printf("Gradebook successfully written to %s.txt\n", book->class_name);
			} else {
				printf("Failed to write gradebook to text file\n");
			}
		} else {
			printf("Error: You must create or load a gradebook first\n");
			
		}
	}
	
	else if (strcmp("read_text", cmd) == 0) {
            scanf("%s", cmd);
            if (book != NULL) {
                printf("Error: You must clear current gradebook first\n");
            } else {
                book = read_gradebook_from_text(cmd);
                if (book == NULL) {
                    	printf("Failed to read gradebook from text file\n");
                } else {
                	printf("Gradebook loaded from text file\n");
                }
            }
        }
        
        else if (strcmp("write_bin", cmd) == 0) {
		if(book != NULL) {
			write_gradebook_to_binary(book);
			if(write_gradebook_to_text(book) == 0) {
				printf("Gradebook successfully written to %s.bin\n", book->class_name);
			} else {
				printf("Failed to write gradebook to binary file\n");
			}
		} else {
			printf("Error: You must create or load a gradebook first\n");
		}
	}
	
	else if (strcmp("read_bin", cmd) == 0) {
            scanf("%s", cmd);
            if (book != NULL) {
                printf("Error: You must clear current gradebook first\n");
            } else {
                book = read_gradebook_from_binary(cmd);
                if (book == NULL) {
                    	printf("Failed to read gradebook from binary file\n");
                } else {
                	printf("Gradebook loaded from binary file\n");
                }
            }
        }	
		

        else {
            printf("Unknown command %s\n", cmd);
        }
    }

    if (book != NULL) {
        free_gradebook(book);
    }
    return 0;
}
