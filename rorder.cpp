#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;


int n, c[100], m; 
int counter, caseNumber;
int ordersMemory[100][300000], sVisit[100][300000];


int checkOrders(int i, int s){

	if(i == n){
		return 0; 
	} 
	if(s == 0){
		return 1;
	}
	if(sVisit[i][s] == caseNumber){
		return ordersMemory[i][s]; 
	}
	sVisit[i][s] = caseNumber;
	ordersMemory[i][s] = checkOrders(i+1, s); 

	if(s - c[i] >= 0){
		ordersMemory[i][s] = ordersMemory[i][s] + checkOrders(i, s - c[i]);
	}
	if(ordersMemory[i][s] > 1000){
		ordersMemory[i][s] = 1000;
	}
	return ordersMemory[i][s];
}

void printOutput(int i, int s){
	if(s <= 0 || i == n){
		return;
	}
	
	if(checkOrders(i+1, s) ==  1){
		if(counter != 0){
			printf("%d ", i+1);
		}
		printOutput(i+1, s);
	}

	if(s - c[i] >= 0){
		if(checkOrders(i, s - c[i]) == 1){
			printf("%d ", i+1);
			printOutput(i, s - c[i]);
		}	
	}
	counter++;
}

int main(){

	scanf("%d\n", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}
	scanf("%d\n", &m);
	memset(sVisit, -1, sizeof(sVisit));
	for(int i = 0; i < m; i++){
		int s;
		scanf("%d", &s);
		int output = checkOrders(0, s);
		if(output == 0){
			printf("Impossible\n");
		}
		else if(output == 1){
			counter = 0;
			printOutput(0, s);
			printf("\n");
		}
		else
			printf("Ambiguous\n");
	}
}