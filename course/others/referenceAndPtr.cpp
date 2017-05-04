#include<cstdio>

int main(){

	int a = 10;
	int *aPtr = &a;
	int &aRef = a;

	//	printf("%d %d\n", *aPtr,aRef);
	printf("address a : %x add of ptr: %x value of ptr: %x vaule of ref: %d\n",
		   &a,&aPtr,aPtr,aRef );
	
	
	return 0;
}
