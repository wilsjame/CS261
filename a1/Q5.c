/* CS261- Assignment 1 - Q.5*/
/* Name: James Wilson
 * Date: 12 April 2017
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
	int index = 0;

	while(word[index] != '\0'){
		if(index % 2 == 0){
			if(word[index] >= 'A' && word[index] <= 'Z'){
				/*do nothing*/
			}
			else{
				word[index] = toUpperCase(word[index]);
			}
		}
		else{
			if(word[index] >= 'A' && word[index] <= 'Z'){
				word[index] = toLowerCase(word[index]);
			}
			else{
				/*do nothing*/
			}
		}

		index++;
	}

}

int main(){
    /*Read word from the keyboard using scanf*/
	char user_input[30];
	printf("Enter a word to modify with sticky caps: ");
	scanf("%s", user_input);
    
    /*Call sticky*/
	sticky(user_input);
    
    /*Print the new word*/
	printf("%s\n", user_input);
    
    return 0;
}
