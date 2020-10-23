#include <stdio.h>
#include<time.h>
#include<string.h>
#include<math.h>

int random() {
	int i,j,flag=0;
	int prime_nos[1000], count=0, random1;
	for(i=2;i<1500;i++)
	{
		flag=0;
	    for(j=2;j<i;j++)
		{
	        if(i%j==0){
				flag=1;
				break;
				}
	    }
	    if(flag==0)
	    {
		prime_nos[count]=i;
		count++;
		}
	}
	random1=prime_nos[rand(time)%(count+1)];
	return random1;
}
int main()
{
    int n,m;
    char s[100];
    int i;
    FILE *fp;
    printf("Enter the text to be encrypted: ");
    scanf("%[^\n]",s);
    fp=fopen("TextBeforeEncryption.txt","w");
    if(fp==NULL)
    {
        printf("file cannot open");
        exit(1);
    }
        for(i=0;i<strlen(s);i++)
        fputc(s[i],fp);
        fclose(fp);
	
   
    int j,l=strlen(s);
    n=random();
    m=random();
    long int product=m*n,e=3;
    long int phi=(m-1)*(n-1);
    long long c=1;
    
	fp = fopen("textAfterEncryption.txt", "w");
    for(i=0;i<l;i++){
        c=1;
        for(j=0;j<e;j++){
            c=(s[i]-'a' + 1)*c;
        }
        
        c=c%product;
        printf("%lld ",c);
        fprintf(fp,"%11d",c);
    }
    fclose(fp);
return 0;
}
