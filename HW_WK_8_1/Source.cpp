#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Init_dice();
void Rotate_Front();
void Rotate_Back();
void Rotate_Left();
void Rotate_Right();
void Rotate_Clockwise();
void Rotate_CounterClockwise();

struct Dice {
	int top;
	int front;
	int left;
	int back;
	int right;
	int under;
}dice;

int temp1,temp2,i=0;

int main() {
	char rotate[50];
	printf("This program allow you to rotate dice and program will show you the front side of the dice.\n\n");
	printf("Initial side of the dice is\n\n\tTop : 1\n\tFront : 2\n\tLeft : 3\n\tRight : 4\n\tBack : 5\n\tUnder : 6\n\n");
	printf("Input meaning\n\n");
	printf("\tF : Rotate front\n");
	printf("\tB : Rotate back\n");
	printf("\tL : Rotate left\n");
	printf("\tR : Rotate right\n");
	printf("\tC : Rotate clockwise\n");
	printf("\tD : Rotate counterclockwise\n\n");
	printf("Enter your rotation : ");
	scanf("%s",rotate);
	Init_dice();
	while (rotate[i] != NULL) {
		if (rotate[i] == 'f' || rotate[i] == 'F') {
			Rotate_Front();
		}
		else if (rotate[i] == 'b' || rotate[i] == 'B') {
			Rotate_Back();
		}
		else if (rotate[i] == 'l' || rotate[i] == 'L') {
			Rotate_Left();
		}
		else if (rotate[i] == 'r' || rotate[i] == 'R') {
			Rotate_Right();
		}
		else if (rotate[i] == 'c' || rotate[i] == 'C') {
			Rotate_Clockwise();
		}
		else if (rotate[i] == 'd' || rotate[i] == 'D') {
			Rotate_CounterClockwise();
		}
		else {
			printf("ERROR! character %c is undefine in this program.\n",rotate[i]);
			break;
		}
		i++;
	}
	if (rotate[i] == NULL) {
		printf("The front side is %d\n", dice.front);
	}
	return 0;
}
void Init_dice() {
	dice.top = 1;
	dice.front = 2;
	dice.left = 3;
	dice.back = 5;
	dice.right = 4;
	dice.under = 6;
}
void Rotate_Front() {
	temp1 = dice.top;
	temp2 = dice.under;
	dice.top = dice.back;
	dice.under = dice.front;
	dice.front = temp1;
	dice.back = temp2;
}
void Rotate_Back() {
	temp1 = dice.back;
	temp2 = dice.front;
	dice.back = dice.top;
	dice.front = dice.under;
	dice.top = temp2;
	dice.under = temp1;
}
void Rotate_Left() {
	temp1 = dice.left;
	temp2 = dice.right;
	dice.left = dice.top;
	dice.right = dice.under;
	dice.top = temp2;
	dice.under = temp1;
}
void Rotate_Right() {
	temp1 = dice.left;
	temp2 = dice.right;
	dice.left = dice.under;
	dice.right = dice.top;
	dice.top = temp1;
	dice.under = temp2;
}
void Rotate_Clockwise() {
	temp1 = dice.left;
	temp2 = dice.right;
	dice.left = dice.front;
	dice.right = dice.back;
	dice.front = temp2;
	dice.back = temp1;
}
void Rotate_CounterClockwise() {
	temp1 = dice.left;
	temp2 = dice.right;
	dice.left = dice.back;
	dice.right = dice.front;
	dice.front = temp1;
	dice.back = temp2;
}
