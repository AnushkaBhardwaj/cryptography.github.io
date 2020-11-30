#include <stdio.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>

int Random()	//creating a random function to generate random prime numbers 
{
	int i,j,flag=0;
	int prime_nos[1000], count=0, random1;
	for(i=2;i<1500;i++)	//loop to check numbers between 2 to 1500
	{
		flag=0;
	    for(j=2;j<i;j++)
		{
	        if(i%j==0)	//checking if the number is prime or not
			{
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
    
    random1=prime_nos[rand()%(count+1)]; 	//storing the prime number using rand function
	return random1;
}
int main()
{
    int n,m;
    char s[100];
    int i;
    FILE *fp;	//declaring file pointer
    printf("Enter the text you want to encrypt: ");
    scanf("%[^\n]",s);
    fp=fopen("TextBeforeEncryption.txt","w"); 	//open file in write mode
    if(fp==NULL)
    {
        printf("file cannot open");
        exit(1);

    }
        for(i=0;i<strlen(s);i++)	//writes each character of the string in the text file
        fputc(s[i],fp); 		//write a single character in the file one at a time
        fclose(fp); 			//closes the file

 //for encryption   
    int j,l=strlen(s); 			//storing input string in l
    n=Random(); 			//first prime number
    m=Random();				//second prime number
    long int product=m*n,e=3; 		//gcd (e, phi(n)) should be 1	
    long int phi=(m-1)*(n-1); 		//Euler toitent
    long long c=1; 			//c is the cipher text
    printf("Encrypted Text"); 		//opens the text file storing the encrypted text
     fp = fopen("textAfterEncryption.txt", "w");  //loop for encrypting the text
    for(i=0;i<l;i++){
        c=1;
        for(j=0;j<e;j++){
            c=(s[i]-'a'+1)*c;	//incrementing index values
        }
        
        c=c%product;	   	 //cipher text
        printf("%lld ",c);	//prints the cipher text on the output screen
        fprintf(fp,"%lld ",c);	//prints the cipher text in the file
    }
    fclose(fp); //closes the file
    
{
   long long int num;
   FILE *fp;
   scanf("%[^\n]",s);
    

   if ((fp = fopen("textAfterEncryption.txt", "r")) == NULL){
       printf("Error! opening file");

       //Program exits if the file pointer returns NULL.
       exit(1);
   }
   printf("\n\nText After Encrytion:\n");
   
{
	num = fgetc(fp);
	if(fp){
	while(fscanf(fp,"%lld",&num)!=EOF)
	printf("%lld ", num);
	}	
}
   fclose(fp);	//closes the 'textAfterEncryption.txt' file
   printf("\n\nText after decryption: ");
   printf("\n%s\n", s);
   
int k=1;
int v;

fp = fopen("textAfterDecryption.txt", "r");
while(1)
{
	if (((int)k*phi+1)%e)
	break;
	else(k++);
}
long int d=((1+k*phi)/e);	//d is private key

v=((int)pow(c,d))%product;	//formula for decryption
}
fclose(fp);	//closes the 'textAfterDecryption.txt' file
return 0;
}
