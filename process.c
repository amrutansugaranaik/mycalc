#include "mycalc.h"

char rpn[MAX_LIM],processed[MAX_LIM];
long double array[MAX_LIM];
long long num,dec;	//num=number, dec=after decimal point
void process()
{
	int var=0,idx=0,decimal=0;
	dec=0;
	num=0;
	int count=0;
	int flag=0;
	
	int len=strlen(display_string);
	for(int i=0;i<len;i++)
	{
		if(display_string[i]>='0' && display_string[i]<='9')
		{
			flag=1;
			if(decimal==0)
				num=num*10+display_string[i]-'0';
			else
				dec=dec*10+display_string[i]-'0',count++;
		}
		else if(display_string[i]=='.')
			decimal=1;
		else
		{
			if(flag==1)
			{
				//printf("Num = %lld\nDec = %lld\n",num,dec);
				array[var]=num;
				array[var]+=((float)dec/pow(10,count));
				processed[idx]='a'+var;
				var++;
				idx++;
				processed[idx]=display_string[i];
				idx++;
				flag=0;
				
				//printf("Hi %LF\n",array[var-1]);
				
			}
			else
			{
				processed[idx]=display_string[i];
				idx++;
			}
			num=0;
			dec=0;
			decimal=0;
			count=0;
		}
	}
	
	
	if(display_string[len-1]>='0' && display_string[len-1]<='9')
	{
		
		array[var]=num;
		array[var]+=((float)dec/pow(10,count));
		processed[idx]='a'+var;
		var++;
		idx++;
	}
	processed[idx]='\0';
	idx++;
	
	
	//printf("str = %s\n",processed);
	//for(int i=0;i<var;i++)
	//{
	//	printf("yo %LF\n",array[i]);
	//}
}
void getrpn()
{
	char stack[1000];
	int len=strlen(processed);
	int idx=0;
	int top=-1;
	for(int i=0;i<len;i++)
	{
		if(processed[i]=='(')
		{
			top++;
			stack[top]='(';
		}
		else if(processed[i]==')')
		{
			while(stack[top]!='(')
			{
				rpn[idx++]=stack[top];
				top--;
			}
			top--;
		}
		else if(isop(processed[i]))
		{
			if(top==-1)
			{
				top++;
				stack[top]=processed[i];
			}
			else if(get_precedence(processed[i])>get_precedence(stack[top]))
			{
				top++;
				stack[top]=processed[i];
			}
			else
			{
				while(get_precedence(stack[top])>get_precedence(processed[i]) && top!=-1)
				{
					rpn[idx++]=stack[top];
					top--;
				}
				top++;
				stack[top]=processed[i];
			}
		}
		else
			rpn[idx++]=processed[i];
	}
	while(top!=-1)
	{
		rpn[idx++]=stack[top];
		top--;
	}
	rpn[idx]='\0';
	//printf("Rpn = %s\n",rpn);
}
void solverpn()
{
	long double stack[MAX_LIM];
	int top=-1;
	int len=strlen(rpn);
	for(int i=0;i<len;i++)
	{
		if(rpn[i]>='a' && rpn[i]<='z')
		{
			top++;
			stack[top]=array[rpn[i]-'a'];
		}
		else
		{
			top--;
			stack[top]=solution(stack[top],stack[top+1],rpn[i]);
		}
	}
	char ans[MAX_LIM];
	sprintf(ans,"%LF",stack[0]);
	gtk_entry_set_text((GtkEntry *)disp,ans);
}
void solve()
{
	process();
	getrpn();
	solverpn();
}
