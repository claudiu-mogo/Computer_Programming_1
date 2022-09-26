#include "mapst.h"

#define CAPACITY 	10
#define BUFFER_SIZE	100

// Funcţie ce compară 2 chei (în cazul de faţă, 2 şiruri de caractere). Funcţia va apela _strcmp_.
int compareKey( const void *key1, const void *key2) {
    char *pk1,*pk2;
    pk1= (char *)key1;
    pk2= (char *)key2;
    return(strcmp(pk1,pk2));
}

//  Funcţia ce compară între ele 2 structuri entry* ţinând cont de faptul că în acest caz particular cheia va fi char *. Funcţia de comparare nu trebuie să ţină cont şi de valorile asociate.
int compareEntry( const void *entry1, const void *entry2) {
    entry *x1, *x2;

    x1 = *(entry**) entry1;
    x2 = *(entry**) entry2;

    return strcmp((char*)x1->key, (char*)x2->key);  

}

// Funcţie ce afişează cheia şi valoarea asociată pe cazul particular când sunt şiruri de caractere.
void printEntry( const entry *ent) {
    if(ent!=NULL)
	    printf("%s : %s\n",ent->key,ent->value);
} 

int main() {
	map m;
	init(&m, CAPACITY);
	char buffer[BUFFER_SIZE];
	int operation, done;
	done = 0;
	while (!done) {
		printf("Introduceti codul operatiei pe care doriti sa o executati: ");
		fgets(buffer, BUFFER_SIZE, stdin);
		operation = atoi(buffer);
		if (operation == 1) {
			print(&m, printEntry);
		} else if (operation == 0) {
			done = 1;
		} else if (operation == 2) {
			printf("\tIntroduceti cuvantul pe care doriti sa il cautati: ");
			fgets(buffer, BUFFER_SIZE, stdin);
			char *word = strtok(buffer, "\n");
			entry *ent = (entry*) malloc(sizeof(entry));
			ent->key = strdup(word);
			char *result = (char*) find(&m, &ent, compareEntry);
	//		free(ent->key);
	//		free(ent);
            if(result!=NULL)
			    printf("[%s] = %s\n", word, result);
            else
                printf("Nu s-a gasit");
		} else if (operation == 3) {
			entry *ent = (entry*) malloc(sizeof(entry));
			printf("\tIntroduceti cuvantul si explicatia (sub forma cuvant=explicatie): ");
			fgets(buffer, BUFFER_SIZE, stdin);
			char *token = strtok(buffer, "=");
			ent->key = strdup(token);
			token = strtok(NULL, "=\n");
			ent->value = strdup(token);
			add(&m, ent);
		} else if (operation == 4) {
			printf("\tIntroduceti cuvantul pe care doriti sa il stergeti: ");
			fgets(buffer, BUFFER_SIZE, stdin);
			char *word = strtok(buffer, "\n");
			del(&m, word, compareKey);
		} else if (operation == 5) {
			sort(&m, compareEntry);
		} else {
			printf("\tAti introdus o valoare invalida!\n");
		}
		printf("__________________________________________________________\n");
	}
//	free_map(&m);
	return 0;
}
