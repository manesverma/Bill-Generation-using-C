#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#define MAXCHAR 250
struct details
{
        char name[20];
        int price;
        char code;
        int qty;       

};



int main()
{
	int counter=1;
	int option, count;
	char c;
	char currentChar;
        int l2pos1=0; 
	int l2ocount=0; 
	int l2jcount=0;
	int p3pcount=0;
	int p3items[100]={-1};
	int p3pos=0;
	int l3ocount=0; 
	int l3jcount=0;
	int p2pos=0;
	int p2pcount=0;
	int n,i,x,y;
	int j,t1,k,l,m,f,f1,f2,f3;
	int a[100][100]={0};	
        FILE *bill,*bill1;
	while(counter!=0)
	{
		printf("\n\n\t\t\t\t1. Create a bill");
    	        printf("\n\n\t\t\t\t2. Prediction of Sales");
		printf("\n\n\t\t\t\t3. Exit\n\t");
                printf("\n\n\t\t\t\tEnter Your Option :--> ");
    		scanf("%d",&option);
		switch(option)
    		{
    			case 1:
    	
				bill = fopen("Billing.txt","a+");
			        struct details item[50];
		    		x=0;
				y=0;
				printf("The Items are as follows\n ");
				printf("\t\tItem\tItem code\n");
				printf("\t    Bread  \t 1\n");
				printf("\t    Butter \t 2\n");
				printf("\t    Milk   \t 3\n");
				printf("\t    Biscuit\t 4\n");
				printf("\t    Tea    \t 5\n");
                                printf("\t    Egg    \t 6\n");
                                printf("\t    Maggi  \t 7\n");
                                printf("\t    Ketchup\t 8\n");
				printf("\t    Sugar  \t 9\n\n");
				printf("Enter number of items:");
    				scanf("%d", &n);
    				for (i = 0; i < n; i++)
    				{       
        				printf("Item name: \t");
        				scanf("%s", &item[i].name);      
        				printf("Item code: \t");
        				scanf("%d", &item[i].code);    
        				printf("Quantity: \t");
        				scanf("%d", &item[i].qty);
        				printf("price: \t");
        				scanf("%d",  &item[i].price);      
    				}
    				printf("\n             *****BILL***** \n");
    				printf("---------------------------------------------------------------------------\n");
    				printf("S.N.|    NAME           |   CODE   |  QUANTITY |  @PRICE  |  TOTAL PRICE   \n");
    				printf("---------------------------------------------------------------------------\n");

    				float total=0,cust_amount,balance;
    				for (i = 0; i < n; i++){   
        				printf("%d     %-15s        %d        %-5d     %-5d         %-5d   \n", i + 1, item[i].name, item[i].code, item[i].qty, item[i].price, item[i].price*item[i].qty );        
        				total += item[i].price*item[i].qty;       
        			}
    				printf("TOTAL COST:                                                     %.2f \n", total);
				printf("\nENTER CUSTOMER AMOUNT:  \t\t\t\t\t");
				scanf("%f",&cust_amount);
    				balance = cust_amount-total;
    				printf("CUSTOMER BALANCE:                                               %.2f \n", balance);
    				printf("---------------------------------------------------------------------------------------\n");
    				for (i = 0; i < n; i++){
        				fprintf(bill,"%d",item[i].code);
					fprintf(bill," ");
        			}
    				fprintf(bill,".\n");
    				fclose(bill);
				break;

			case 2:
				x=0;
				y=0;
				if( bill1 = fopen("Billing.txt","r") )
					printf("\nlol\n");
				int temp;
				while((currentChar = (int)fgetc(bill1)) != EOF)
				{
					temp = (int)currentChar;
					//printf(",%d",temp);
					if(currentChar!= 32 && currentChar!= 46)
					{
						//printf("%c,,,%d",currentChar,currentChar);
						a[x][y]=(temp-48);
						//printf("%d ",a[x][y]);
						y++;
					}
					if(currentChar== 46 || currentChar == 10)
					{
						//printf("\nlollol");
						x++;
						y=0;
					}
					currentChar = fgetc(bill1);
				}
				int imax=0,jmax=0,jmax_temp=0;
				for(i=0;i<100;i++) {
					jmax_temp=0;
					if(a[i][0] == 0) {
						imax = i;
						break;
					}
					for(j=0;j<100;j++) {
						if(a[i][j] != 0)
							jmax_temp++;
						else
							break;
					}
					
					if(jmax_temp > jmax)
						jmax = jmax_temp;
				}
				//printf("\njmax :%d",jmax);
				for(i=0;i<imax;i++)
				{
					//printf("\n Enter items from purchase %d : ",i+1);
					for(j=0;j<jmax;j++)
					{
						printf("%d ",a[i][j]);
					}
					printf("\n");
				}
				int min,max;
				printf("\n Enter minimum acceptance level: ");
				scanf("%d",&min);
				printf("\nInitial Input:\n");
				printf("\nTrasaction\tItems\n");
				max = a[0][0];
				for(i=0;i<imax;i++)
				{
					printf("%d :",i+1);
					for(j=0;j<jmax;j++)
					{
						if(a[i][j] > max)
							max = a[i][j];
						printf("%d \t",a[i][j]);
					}
					printf("\n");
				}
				printf("\nAssume minimum support: %d     :%d ",min,max);
				int l1[100];
				for(i=0;i<max;i++)
				{
					t1=0;
					for(j=0;j<imax;j++)
					{
						for(k=0;k<jmax;k++)
						{
							if(a[j][k]==i+1)
							{
								t1++;
							}
						}
					}
					l1[i]=t1;
				}
				printf("\n\nGenerating C1 from data\n");
				for(i=0;i<max;i++)
				{
					printf("%d : %d\n",i+1,l1[i]);
				}
				int p2items[100];
				for(i=0;i<max;i++)
				{
					if(l1[i]>=min)
					{
						p2pcount++;
						p2items[p2pos]=i;
						p2pos++;
					}
				}
				printf("\nGenerating L1 From C1\n");
				for(i=0;i<p2pos;i++)
				{
					printf("%d\t %d\n",p2items[i]+1,l1[p2items[i]]);
				}
				int l2[100][3];
				int l2t1; 
				int l2t2;
				for(i=0;i<p2pcount;i++)
				{
					for(j=i+1;j<p2pcount;j++)
					{
						l2t1=p2items[i]+1;
						l2t2=p2items[j]+1;
						if(l2t1==l2t2)
						{
							continue;
						}
						l2[l2pos1][0]=l2t1;
						l2[l2pos1][1]=l2t2;
						l2jcount++;
						l2ocount=0; 
						for(k=0;k<5;k++)
						{
							f1=f2=0;
							for(l=0;l<5;l++)
							{
								if(l2t1==a[k][l])
								{
									f1=1;
								}
								if(l2t2==a[k][l])
								{
									f2=1;
								}
							}
							if(f1==1&&f2==1)
							{
								l2ocount++;
							}
						}
						l2[l2pos1][2]=l2ocount;
						l2pos1++;
					}
				}
				printf("\n\nGenerating L2\n");
				for(i=0;i<l2jcount;i++)
				{
					if(l2[i][2] >= min)
					{
						for(j=0;j<3;j++)
						{
							printf("%d\t",l2[i][j]);
						}
						printf("\n");
					}
				}

				for(i=0;i<max;i++)
				{
					if(l2[i][2]>=min)
					{
						f=0;
						for(j=0;j<max;j++)
						{
							if(p3items[j]==l2[i][0])
							{
								f=1;
							}
						}
						if(f!=1)
						{
							p3items[p3pos]=l2[i][0];
							p3pos++;
							p3pcount++;
						}
						f=0;
						for(j=0;j<max;j++)
						{
							if(p3items[j]==l2[i][1])
							{
								f=1;
							}
						}
						if(f!=1)
						{
							p3items[p3pos]=l2[i][1];
							p3pos++;
							p3pcount++;
						}
					}
				}
				int l3[100][4];
				int l3ocount=0; 
				int l3jcount=0; 
				printf("\n\nGenerating L3\n\n");
				for(i=0;i<p3pcount;i++)
				{
					for(j=i+1;j<p3pcount;j++)
					{
						for(x=j+1;x<p3pcount;x++)
						{
							l3[i][0]=p3items[i];
							l3[i][1]=p3items[j];
							l3[i][2]=p3items[x];
							//printf("%d   %d   %d\n",l3[i][0],l3[i][1],l3[i][2]);
							l3jcount++;
							l3ocount=0; 
							for(k=0;k<imax;k++)
							{
								f1=f2=f3=0;
								for(l=0;l<jmax;l++)
								{
									if(l3[i][0]==a[k][l])
									{
										f1=1;
									}
									if(l3[i][1]==a[k][l])
									{
										f2=1;
									}
									if(l3[i][2]==a[k][l])
									{
										f3=1;
									}
								}
								if(f1==1&&f2==1&&f3==1) 
								{
									l3ocount++;
								}
							}
							l3[i][3]=l3ocount;
							if(l3[i][3] >= min)
							    printf("%d   %d   %d   %d\n",l3[i][0],l3[i][1],l3[i][2],l3[i][3]);
						}
					}
				}

        			break;
    			case 3:
        			return 1;
        			break;
    			default:
        			printf("\n\t\tNo Action Detected");
        			printf("\n\t\tPress Any Key\n\n\n");
        			//getch();
        			system("pause");
    		}
     		printf("press 1 to continue and 0 to exit: ");
		scanf("%d",&counter);
	}
        return 1;
        //getch();
}
