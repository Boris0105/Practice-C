#include <stdio.h>
#include <stdlib.h>

int main(){
	
	
	int* numbers =0;//表示空指標
	int length =0; //表示目前已經輸入的數字個數
	
	while (1) {
		int input;
		scanf("%d", &input);
		if (input ==0) break;//如果輸入字數為0 結束
		
		int* larger = malloc(sizeof(int)*(length + 1)); //產生一個大一格的新陣列
		
		for(int i =0; i<length;i++) larger[i]=numbers[i]; //複製就陣列到新陣列
		free(numbers);
		
		numbers =larger;
		numbers[length]=input;
		length++;
		
		
	}
	
	printf("Numbers:");
	for(int i=0; i< length; i++){
		
		printf("%d", numbers[i]);
	}
	printf("\n");
	return 0;
	
}
