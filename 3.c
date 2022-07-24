#include<stdio.h>
int main()
{
	double num1,num2,value;
	char sign;
	printf("enter the first no:");
	scanf("%d",&num1);
	printf("enter another no");
	scanf("%d",&num2);
	value=num1+num2;
	sign='+';
	printf("%lf%c%lf=%lf\n",num1,sign,num2,value);
	value=num1-num2;
	sign='-';
	printf("%lf%c%lf=%lf\n",num1,sign,num2,value);
	value=num1*num2;
	sign='*';
	printf("%lf%c%lf=%lf",num1,sign,num2,value);
	value=num1/num2;
	sign='/';
	printf("%lf%c%lf=%lf",num1,sign,num2,value);
	return 0;
	
}
