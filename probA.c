#include <stdio.h>
 
void print(char *str,int i){
	int j;
	
	for(j = 0;j < i;j++){
		putchar(str[j]);
	}
	printf("HAGIXILE");
	for(j = j+6;str[j] != '\0';j++){
		putchar(str[j]);
	}
	putchar('\n');
}
 
int main(void) {
	int i,j;
	char str[1001],tmp[7] = "HAGIYA";
	
	scanf("%s",str);
	
	for(i = 0;i < 1000-6;i++){
		if(str[i] == 'H'){
			for(j = 0;j < 6;j++){
				if(str[i+j] != tmp[j]){
					goto bad;
				}
			}
			print(str,i);
			break;
		}
		bad:;
	}
	return 0;
}
