int get_precedence(char a)
{
	if(a=='/' || a=='*')
		return 2;
	if(a=='+' || a=='-')
		return 1;
	return 0;
}
int isop(char a)
{
	if(a=='+' || a=='-' || a=='*' || a=='/' )
		return 1;
	else
		return 0;
}
long double solution(long double a,long double b,char op)
{
	if(op=='*')
		return a*b;
	if(op=='/')
		return a/b;
	if(op=='+')
		return a+b;
	if(op=='-')
		return a-b;
		
	return 0;
}
