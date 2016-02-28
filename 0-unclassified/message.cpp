#include <stdio.h>
#define SPACE 21

void write(long long a){
	int i;
	for(i = SPACE; i >= 0; i--){
		if (a & (1<<i)){
			printf("%c", '#');
		} else {
			printf("%c", ' ');
		}
	}
	printf("\n");
}

int main(){
	int i;
	long long arr[7] = {2044305, 281169, 279633, 270481, 266513, 264721, 2032654};
	for (i = 0; i < 7; i++)
		write(arr[i]);
}