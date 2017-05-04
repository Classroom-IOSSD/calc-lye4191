#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	int line = 0;
	double result = 0;
	fp = fopen("read.txt","r");
	double (*calc_function) (int,int);

	if(fp!=NULL){
		fscanf(fp, "%d", &line);	
		for(int i=0; i<line-1; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				//result = add(operand1, operand2);
				calc_function = add;
				break;
				case '-':
				//result = minus(operand1, operand2);
				calc_function = minus;
				break;
				case '*':
				//result = mul(operand1, operand2);
				calc_function = mul;
				break;	
				case '/':
				calc_function = div;
				//result = div(operand1, operand2);
				break;
			}	
			result = calc_function(operand1, operand2);	
			printf("%d %c %d = %.6f\n",
				 operand1, operator, operand2, result);

		}
	}
	return 0;
}

