#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int input(int *, int *, double *, char *);
int calculation(int *, int *, double *, char *);
int print(int *, int *, double *, char *);
int again(int *, int *, double *, char *);

int main() {

	int num1, num2, check ,i;
	double res;
	char mark;
	int (*func[4])(int *, int *, double *, char *) = {input, calculation, print, again};

	while(1){

		for(i = 0; i < 4 ; i++){

			check = func[i](&num1, &num2, &res, &mark);

			if( (check == 0) && (i == 3) ) return 0;
			else if( check && (i == 3) ) printf("\n\n==========================================\n\n\n");
		}
	}

	return 0;
}

int input(int *num1, int *num2, double *temp, char *mark){ //Receive expression

	int check;

	while(1){

		printf("Input Mathmatical Expression (Ex:2+3) : ");
		check = scanf("%d%c%d", num1, mark, num2);

		if(check != 3){
			while(getchar() != '\n');
			printf("\n<<Wrong Expression>>\n");
			continue;
		}
		if( (*mark != '+') && (*mark != '-') && (*mark != '*') && (*mark != '/') ) {
			printf("\n<<Choose mark among +, -, *, />>\n");	
			continue;
		}
		if( (*mark == '/') && (*num2 == 0) ) {
			printf("\n<<When you divide, don't put Zero in second number>>\n");
			continue;
		}
		
		break;
	}

	return 0;
}

int calculation(int *num1, int *num2, double *res, char *mark){ //calculate num1, num2

	switch(*mark){

	case '+':
		*res = *num1 + *num2;
		break;

	case '-':
		*res = *num1 - *num2;
		break;

	case '*':
		*res = *num1 * (*num2);
		break;

	case '/':
		*res = (double)*num1 / *num2;
		break;

	default:
		break;
	}

	return 0;
}

int print(int *num1, int *num2, double *res, char *mark){ //printing Result

	printf("Calculation Result : %.2lf\n\n", *res);

	return 0;
}

int again(int *num1, int *num2, double *res, char *mark){ //Asking if they want to do it again

	char word[80];
	char *retry;
	int size, i = 0;

	while(1){
		printf("Do you want to make a calculation more? (Yes or No)\n¡æ ");
		scanf("%s",word);

		retry = (char *)malloc(strlen(word) + 1);
		strcpy(retry, word);

		if(retry == NULL) {
			printf("line 100, memory error\n");
			return 0;
		}

		while( *(retry + i) ){

			if( ( *(retry + i) >= 'A') && ( *(retry + i) <= 'Z') ) *(retry + i) += 32;
			i++;
		}

		if( strcmp(retry, "yes") == 0 ) {
			free(retry);
			return 1;
		}
		else if( strcmp(retry, "no") == 0) {
			free(retry);
			return 0;
		}
		else printf("<<Input only Yes or No>>\n");
		free(retry);
	}

}