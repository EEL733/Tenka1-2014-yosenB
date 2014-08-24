#include <stdio.h>
#include <string.h>
 
int main(){
	int i,j,N,ans,slen;
	int answer[1001],tlen[100];
	char s[1001],t[100][1001];
 
	scanf("%d %s",&N,s);
 
	slen = strlen(s);
	
	memset(answer,0,sizeof(answer));
 
	for(i = 0;i < N;i++){
		scanf("%s",t[i]);
		tlen[i] = strlen(t[i]);
		if(!strncmp(s,t[i],tlen[i])){
			answer[tlen[i]-1]++;
		}
	}
 
	for(i = 0;i < slen;i++){
		if(answer[i] != 0){
			for(j = 0;j < N;j++){
				if(!strncmp(s+i+1,t[j],tlen[j])){
					answer[i+tlen[j]] += answer[i];
					answer[i+tlen[j]] %= 1000000007;
				}
			}
		}
	}
 
	/*
	for(i = 0;i < slen;i++){
		printf("%d\n",answer[i]);
	}
	*/
 
	printf("%d\n",answer[slen-1]);
 
	return 0;
}