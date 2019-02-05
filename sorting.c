#include<stdio.h>
struct stack
{
	int crr[10];
	int tos;
};
void bubble_sort(int *,int);
void sel_sort(int *,int);
void ins_sort(int *,int);
void quick_sort(int *,int);
void quick(int *,int,int,int*);
void push(struct stack *,int);
int pop(struct stack *);
void main()
{
	int arr[8];
	int ch;
	printf("Enter 8 Numbers in the array:");
	for(int i=0;i<=7;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Select from below options:\n");
	printf("1) Bubble Sort\n2) Selection Sort\n3) Insertion Sort\n4) Quick Sort\n");
	input:
	printf("Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: 
		bubble_sort(arr,8);
		break;
		case 2:
		sel_sort(arr,8);
		break;
		case 3:
		ins_sort(arr,8);
		break;
		case 4:
		quick_sort(arr,8);
		break;
		default:
		printf("Wrong choice!\n");
		goto input;
	}
		for(int i=0;i<=7;i++)
		{
			printf("\n%d",arr[i]);
		}
}
void bubble_sort(int arr[],int n)
{
	int i,j,temp;
	int swap;
	for(i=0;i<=n-2;i++)
	{
		swap=0;
		for(j=0;j<=n-2-i;j++)
	{
		if(arr[j]>arr[j+1])
		{
			swap=1;
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
	}
	if(swap==0)
	break;
	}
}
void sel_sort(int arr[],int n)
{
	int i,j,temp;
	int min;
	for(i=0;i<=n-2;i++)
	{
		min=i;
		for(j=i+1;j<=n-1;j++)
		{
			if(arr[min]>arr[j])
			{
				min=j;
			}
		}
		if(i!=min)
		{
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
		}
	}	
}
void ins_sort(int arr[],int n)
{
int i,j,temp;
int swap;
for(i=0;i<=n-2;i++)
{
	swap=0;
	for(j=i+1;j>=1;j--)
	{
		if(arr[j-1]>arr[j])
		{
			swap=1;
			temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
		}
		if(swap=0)
		break;
	}
}
}
void quick_sort(int arr[],int n)
{
	struct stack lower,upper;
	int beg,end,loc;
	lower.tos=upper.tos=-1;
	if(n>1)
	{
		push(&lower,0);
		push(&upper,n-1);
	}
	while(lower.tos!=-1)
	{
		beg=pop(&lower);
		end=pop(&upper);
		quick(arr,beg,end,&loc);
		if(beg<loc-1)
		{
			push(&lower,beg);
			push(&upper,loc-1);
		}
		if(end>loc+1)
		{
			push(&lower,loc+1);
			push(&upper,end);
		}
	}
}
void quick(int brr[],int beg,int end,int *p)
{
	int left=beg;
	int right=end;
	int loc=beg;
	int temp;
	while(1)
	{
		while(brr[loc]<=brr[right]&&loc!=right)
		{
			right--;
		}
		if(loc==right)
		{
			*p=loc;
			return;
		}
		if(brr[loc]>brr[right])
		{
			temp=brr[loc];
			brr[loc]=brr[right];
			brr[right]=temp;
			loc=right;
		}
	while(brr[loc]>=brr[left]&&loc!=left)
	{
		left++;
	}
	if(loc==left)
	{
		*p=loc;
		return;
	}
	if(brr[loc]<brr[left])
	{
		temp=brr[loc];
		brr[loc]=brr[left];
		brr[left]=temp;
		loc=left;
	}
	}
}
void push(struct stack *p,int x)
{
	if(p->tos==9)
	{
		printf("Stack overflow");
		return;
	}
	p->tos=p->tos+1;
	p->crr[p->tos]=x;
}
int pop(struct stack *p)
{
	int x;
	if(p->tos==-1)
	{
		printf("Stack overflow");
		return -1;
	}
	x=p->crr[p->tos];
	p->tos=p->tos-1;
	return x;
}

		
	

		
		
		