#include <stdio.h>
#include <stdlib.h>
/*  Modified card counting file from Head First C page 37
	
	Modified by: Deniz Celik
*/

/* Prompts the user for input and puts the reply in the given buffer.

User input is truncated to the first two characters.

prompt: string prompt to display 
card_name: buffer where result is stored 
*/ 
void get_card_name(char *prompt, char *card_name){
	puts(prompt);
	scanf("%2s", card_name);
}

/* Returns a value based on the card name

Returns 10 for K,Q,or J
Returns 11 for A
Returne -1 for X
Returns 0 if value is not valid
Returns value if valid integer (2,3,4,5,6,7,8,9,10)

card_name: buffer where input is stored 
*/
int getValue(char * card_name){
	char cn0 = card_name[0];
	/*If val is not here, it throws declaration-after-statement warning */
	int val = 0;
	
	if (cn0 == 'K' || cn0 == 'Q' || cn0 == 'J') {
		return 10;
	}
	if (cn0 == 'A') {
		return 11;
	}
	if (cn0 == 'X') {
		return -1;
	}
	val = atoi(card_name);
	if( (val<1) || (val>10) ){
		puts("I don't understand that value!");
		return 0;
	}
	return val;
}

/* Takes in a card value and returns flag for modifying count

Returns 1 if the card value is between 2 and 7
Returne -1 if the card value is 10
Returns 0 if none of the above is satisfied

val: value to be tested
*/
int testValue(int val){
	if ((val > 2) && (val < 7)){
		return 1;
	} else if (val == 10){
		return -1;
	}
	return 0;
}


/* Entry point for entering counting code */
int main(){
	char card_name[3];
	int count = 0;
	/*If val is not here, it throws declaration-after-statement warning */
	int val = 0;
	
	while (card_name[0] != 'X'){
		get_card_name("Enter the card_name: ", card_name);
		val = 0;
		val = getValue(card_name);
		if (val != -1){
			count += testValue(val);
			printf("Current count: %i\n", count);
		}
	}
	return 0;
}