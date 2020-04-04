#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct
{
	char team[15];
	int score;
	float over;
	float runrate;
	char oppostionT[15];
	char ground[15];
}score;

score s;
FILE *f;

void display()
{
	system("cls");
	printf("\n\t\t\t\tMade By: Akash Saha   Registration No.:11702222\n");
	printf("\n-----------------------------------------------SCORE MANAGEMENT SYSTEM-------------------------------------------------");
	printf("\n\n\t\t\t\t\t\t1.Add Score");
	printf("\n\t\t\t\t\t\t2.Delete Score");
	printf("\n\t\t\t\t\t\t3.View Score");
	printf("\n\t\t\t\t\t\t4.Edit Score");
	printf("\n\t\t\t\t\t\t5.Search Score");
	printf("\n\t\t\t\t\t\t6.Exit");
}

void add()
{
	system("cls");
	f=fopen("s.txt","ab");
	printf("\nEnter the team name:");
	fflush(stdin);
	gets(s.team);
	printf("\nEnter score:");
	scanf("%d",&s.score);
	printf("\nEnter over:");
	scanf("%f",&s.over);
	printf("\nEnter runrate:");
	scanf("%f",&s.runrate);
	printf("\nEnter opposition team:");
	fflush(stdin);
	gets(s.oppostionT);
	printf("\nEnter ground name:");
	fflush(stdin);
	gets(s.ground);
	fwrite(&s,sizeof(s),1,f);
    fclose(f);
	getch();
}

void view()
{
	system("cls");
	f=fopen("s.txt","rb");
	printf("\n\tTM1   RUN    OVER    RR    TM2   GRD");
	printf("\n\t--------------------------------------");
	while(fread(&s,sizeof(s),1,f))
	{
		printf("\n\t%s | %d | %.2f | %.2f | %s | %s",s.team,s.score,s.over,s.runrate,s.oppostionT,s.ground);
		
	}
	getch();
	fclose(f);
}

void search()
{
	system("cls");
	int t;
	printf("\nEnter the choice to search:\n");
	printf("\n1.On the basis of Team Name");
	printf("\n2.On the basis of Ground");
	printf("\n3.On the basis Opposition Team Name\n");
	scanf("\n%d",&t);
	f=fopen("s.txt","rb");
    if(t==1)
    {
    	char a[30];
		       printf("Enter the team name to be search:");
	           scanf("%s",a);
               printf("\n\tTM1   RUN    OVER    RR    TM2   GRD");
               printf("\n\t--------------------------------------");
	           while(fread(&s,sizeof(s),1,f)==1)
	           {
		         if(strcmp(s.team,a)==0)
		         {	           
		            printf("\n\t%s   %d   %.2f   %.2f   %s   %s",s.team,s.score,s.over,s.runrate,s.oppostionT,s.ground);
		          }
	            }
	}
	else if(t==2)
	{
		char b[30];
		       printf("Enter the ground name to be search:");
	           scanf("%s",b);
	           printf("\n\tTM1   RUN    OVER    RR    TM2   GRD");
	           printf("\n\t--------------------------------------");
	           while(fread(&s,sizeof(s),1,f)==1)
	           {
		         if(strcmp(s.ground,b)==0)
		         {      	
		           printf("\n\t%s   %d   %.2f   %.2f   %s   %s",s.team,s.score,s.over,s.oppostionT,s.ground);
		          }
	            }
	}
	
	else if(t==3)
	{
		char c[30];
		       printf("Enter the oppostion team name to be search:");
	           scanf("%s",c);
	           printf("\n\tTM1   RUN    OVER    RR    TM2   GRD");
	           printf("\n\t--------------------------------------");
		           
	           while(fread(&s,sizeof(s),1,f)==1)
	           {
		         if(strcmp(s.oppostionT,c)==0)
		         {       	
	               printf("\n\t%s   %d   %.2f   %.2f   %s   %s",s.team,s.score,s.over,s.runrate,s.oppostionT,s.ground);
				  }
	            }  
	 }
	 else
	 {
	 	printf("\tWrong Input");
	 	getch();
	 	return search();
	 }
	fclose(f);
	getch();
}


void delete()
{
	system("cls");
	FILE *p1;
	char a[30];
	int x;
	f=fopen("s.txt","rb");
	p1=fopen("s1.txt","wb");
	printf("\nEnter the team name to be deleted:");
	scanf("%s",a);
	printf("\nEnter the run to which the team details to be deleted:");
	scanf("%d",&x);
	rewind(f);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(!(strcmp(s.team,a)==0 && x==s.score))
		{
			fwrite(&s,sizeof(s),1,p1);		
		}
	}
	fclose(f);
	fclose(p1);
	remove("s.txt");
	rename("s1.txt","s.txt");
	getch();	
}

void edit()
{
	system("cls");
	char x[15];
	long int y=sizeof(s);
	f=fopen("s.txt","rb+");
	printf("\nEnter the team name to edit:");
	scanf("%s",x);
	rewind(f);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.team,x)==0)
		{
			printf("\nEnter the new team name:");
	        fflush(stdin);
	        gets(s.team);
	        printf("\nEnter new score:");
	        scanf("%d",&s.score);
	        printf("\nEnter new over:");
	        scanf("%f",&s.over);
	        printf("\nEnter new runrate:");
	        scanf("%f",&s.runrate);
	        printf("\nEnter new opposition team:");
	        fflush(stdin);
	        gets(s.oppostionT);
	        printf("\nEnter new ground name:");
	        fflush(stdin);
	        gets(s.ground);
	        fseek(f,-y,1);
	        fwrite(&s,sizeof(s),1,f);
	        break;
		}		
	}
	fclose(f);
	getch();
}


void main()
{
	int i;
	while(1)
	{
		display();
		printf("\n\nEnter Choice As Your Wish:");
		scanf("%d",&i);
		if(i==1)
		{
		   add();
		   return main();
		}
		else if(i==2)
		{
		   delete();
		   return main();	
		}
		else if(i==3)
		{
			view();
		    return main();
		}
		else if(i==4)
		{
		    edit();
		    return main();	
		}
		else if(i==5)
		{
		    search();
		    return main();	
		}
		else if(i==6)
		{
		   exit(1);	
		}
		else
		{
			printf("\nWrong Choice....Please Enter Right Choice");
			getch();
			return main();
		}
	}
}

