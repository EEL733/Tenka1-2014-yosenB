#include <stdio.h>
#include <string.h>
 
int data[750][750],ans[750][750];
 
int main(){
	int N,i,j,tmp;
	char c;
	
	scanf("%d",&N);
 
	for(i = 0;i < N;i++){
		getchar();
		for(j = 0;j < N;j++){
			c = getchar();
			if(c == '.'){
				data[i][j] = 0;
			}else{
				data[i][j] = 1;
			}
		}
	}
 
	memset(ans,0,sizeof(ans));
 
	for(i = 0;i < N;i++){
		for(j = 0;j < N;j++){
			tmp = 0;
			if(i > 0){
				tmp += ans[i-1][j];
			}
			if(i < N-1){
				tmp += ans[i+1][j];
			}
			if(j > 0){
				tmp += ans[i][j-1];
			}
			if(j < N-1){
				tmp += ans[i][j+1];
			}
			if(tmp%2 == data[i][j]){
				if(i > 0){
					if(!ans[i-1][j]){
						ans[i-1][j] = 2;
					}
				}
				if(i < N-1){
					if(!ans[i+1][j]){
						ans[i+1][j] = 2;
					}
				}
				if(j > 0){
					if(!ans[i][j-1]){
						ans[i][j-1] = 2;
					}
				}
				if(j < N-1){
					if(!ans[i][j+1]){
						ans[i][j+1] = 2;
					}
				}
			}else{
				if(j > 0 && !ans[i][j-1]){
					ans[i][j-1] = 1;
					if(j < N-1 && !ans[i][j+1]){
						ans[i][j+1] = 2;
					}
					if(i < N-1 && !ans[i+1][j]){
						ans[i+1][j] = 2;
					}
				}else if(j < N-1 && !ans[i][j+1]){
					ans[i][j+1] = 1;
					if(j > 0 && !ans[i][j-1]){
						ans[i][j-1] = 2;
					}
					if(i < N-1 && !ans[i+1][j]){
						ans[i+1][j] = 2;
					}
				}else if(i < N-1 && !ans[i+1][j]){
					ans[i+1][j] = 1;
					if(j > 0 && !ans[i][j-1]){
						ans[i][j-1] = 2;
					}
					if(j < N-1 && !ans[i][j+1]){
						ans[i][j+1] = 2;
					}
				}
			}
		}
	}
 
	for(i = 0;i < N;i++){
		for(j = 0;j < N;j++){
			if(ans[i][j] == 1){
				putchar('#');
			}else{
				putchar('.');
			}
		}
		putchar('\n');
	}
 
	return 0;
}
