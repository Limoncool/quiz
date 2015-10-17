#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 52

typedef struct {
	char suit[6];
	char symbol[3];
} Card;

void shuffle(Card*);
//void card(int, char*);
void suit(int, char*);
void symbol(int, char*);

int main(void) {
Card cards[N];
int i;

srand(time(NULL));


shuffle(cards);
printf("洗好牌了！這副牌由牌頂至牌底依序為\n");
for(i = 0; i < N; i++) {
	printf("%s\n", cards[i].suit);
}

return 0;
} 


void shuffle(Card* cards) {
int a,b,c;
Card tmp;

for(a = 0; a < N; a++) {
	suit(a + 1, cards[a].suit);
        symbol(a + 1, cards[a].symbol);
}

for(b = 0; b < N; b++) {
	c = rand() % 52;
        tmp = cards[b];
        cards[b] = cards[c];
        cards[c] = tmp;
}

}


void suit(int number, char* suit) {
switch((number - 1) / 13) { 
	case 0: 
		strcpy(suit, "黑桃"); 
		break;
	case 1: 
		strcpy(suit, "紅心"); 
		break;
	case 2: 
		strcpy(suit, "方塊"); 
		break;
	case 3: 
		strcpy(suit, "梅花"); 
		break;
	default: 
		break;
}

}

void symbol(int number, char* symbol) {
int alpha = number % 13;
switch(alpha) { 
	case 0:  
		sprintf(symbol, "%s ", "K"); 
		break;
	case 1:  
		sprintf(symbol, "%s ", "A"); 
		break;
	case 11: 
		sprintf(symbol, "%s ", "J"); 
		break;
	case 12: 
		sprintf(symbol, "%s ", "Q"); 
		break;
        default: 
		sprintf(symbol, "%-2d", alpha);
		break;
}
     
}
