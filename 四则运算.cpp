#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>
#include <string.h>

char getSignal();//�����ȡ��������� 
int Creat_Int(int r);//�����ȡ��������
void simple(int * m,int * n); //Լȥ���ӷ�ĸ������
int frac_intcompare(int fenzi,int fenmu,int a);//������������С�Ƚϵĺ��� 
int show(int a,int b,int r,FILE *fp);//����ת��Ϊ���ֵ������ 
void frac_fraccompare(int *fenzi1,int *fenzi2,int *fenmu1,int *fenmu2);//��a/c < b/d ����λ�� 	 
void print1(int r,FILE *fq,FILE *fa);//�������Ƿ����Ĵ�ӡ
void print2(int r,FILE *fq,FILE *fa);//�������������Ĵ�ӡ 
void print3(int r,FILE *fq,FILE *fa);//һ��һ�ֵĴ�ӡ 
void check(FILE *ans,FILE *stu,int r); //�Դ� 

int main()
{   
    FILE *fq;//��Ŀ���ĵ� 
	FILE *fa;//�𰸵��ĵ� 
    int x; 
    printf("ѡ����ţ�\n1.����Ŀ\n2.�Դ�\n");
	scanf("%d",&x);
    while(x!=1 && x!=2)//ѡ���� 
    {
    printf("�������빦�ܣ�\n");
    scanf("%d",&x);
    if(x!=1 && x!=2)
    continue;
    }
	switch(x)
	{
	case 1:
	{
	if((fq=fopen("Exercises.txt","w"))==NULL){ 
    printf("Cannot open this file!\n");
    exit(0);
	} 
	if((fa=fopen("Answers.txt","w"))==NULL){ 
    printf("Cannot open this file!\n");
    exit(0);
	} 
	srand(time(0));
	int m;
	int n,r;
	printf("��������Ŀ����\n");
	printf("Myapp.exe -n ");
	while(1){//�ò������������������򱨴�����������Ϣ��
		if(scanf("%d",&n)==1)break;
		else printf("����������1����������Ȼ��:");
		fflush(stdin);
	}
	
	printf("��������Ŀ����ֵ�ķ�Χ\n");
	printf("Myapp.exe -r ");
	while(1){//�ò������������������򱨴�����������Ϣ��
		if(scanf("%d",&r)==1)break;
		else printf("����������1����������Ȼ��:");
		fflush(stdin);
	}
	 
	
    //ѭ������
	for(int i=0;i<n;i++){		
      	m=rand()%3+1;//m=1or2or3
      	printf("%d.",i+1);
      	fprintf(fq,"%d.",i+1);
      	fprintf(fa,"%d.",i+1);
		switch(m){
			case 1:{
				print1(r,fq,fa);
				printf("\n");
				fprintf(fq,"\n");
				fprintf(fa,"\n");//9.25˼·��caseΪ1-3��������������������������������һ��һ�ֵ���� ��n�Ļ���forѭ�� 
				break;
			}
			case 2:{
				print2(r,fq,fa);
				printf("\n"); //��ӡ����2
				fprintf(fq,"\n");
				fprintf(fa,"\n");
				break;
			}
			case 3:{				
				print3(r,fq,fa);//��ӡ����3
				printf("\n");
				fprintf(fq,"\n"); 
				fprintf(fa,"\n");
				break;
			}
		}
	} 
	fclose(fq);
	fclose(fa);
	break;
}
//�Դ�
    case 2 :
	{FILE *ans;
	FILE *stu; 
	if((ans=fopen("Answers.txt","r"))==NULL){ 
    printf("Cannot open this file!\n");
    exit(EXIT_FAILURE);
	} 
	if((stu=fopen("Student.txt","r"))==NULL){ 
    printf("Cannot open this file!\n");
    exit(EXIT_FAILURE);
	}	
	int r;
	printf("һ���ж����⣺");
	scanf("%d",&r);
	check(ans,stu,r); 

	break;
	}
 
	 return 0;
} 
}
char getSignal(){//�����ȡ��������� 
	char signal[4]={'+','-','*','/'};
	//srand((unsigned)time(NULL));
	//srand(time(0));
	return signal[rand()%4];
}
int Creat_Int(int r){//�����ȡ��������

	//srand(time(0));
	//return (int)(r*rand()/(RAND_MAX+1.0));
    return rand()%r;
}

void simple(int * m,int * n){ //Լȥ���ӷ�ĸ��Լ�� ��Ҫ��ָ������֣���Ϊ������void 
    int p;
    p=(*m+*n-abs(*m-*n))/2;//pΪm,n�е�Сֵ 
    for(int i=2;i<=p;i++){ 
    if(*m%i==0&&*n%i==0)
    {
      *m/=i;
      *n/=i;
      i=2;                    //��ʲô�ã��ִ�2��ʼ�����Բ������� 
    } 
    }
}
int frac_intcompare(int fenzi,int fenmu,int a){//�����������ıȽϺ��� 
	int d;
	int flag;
	d=fenmu*a;
	if((fenzi/d)>=1)flag=1;//������a/b���������� 
	else flag=0;
	return flag;
}
int show(int a,int b,int r,FILE *fp){//����ת��Ϊ���ֵ������ 
    int c;
    while(b==0){
    	b=Creat_Int(r); 
    	//b=rand()%r;
	}
    
	c=a/b;
	if(a==0) {
		printf("%d",a);
		fprintf(fp,"%d",a);
	}
	else if(a%b==0) {
		printf("%d",c);
		fprintf(fp,"%d",c);
	}
	else if(c==0) {
		simple(&a,&b); 
		printf("%d/%d",a,b);
		fprintf(fp,"%d/%d",a,b);
	}
	else {
	a=a-b*c;
	simple(&a,&b); 
    printf("%d'%d/%d",c,a,b);
    fprintf(fp,"%d'%d/%d",c,a,b);
	}
}

void frac_fraccompare(int *fenzi1,int *fenzi2,int *fenmu1,int *fenmu2){//��a/c < b/d ����λ�� 
	int m,n;
	int a,b;
	a=(*fenzi1) * (*fenmu2);
	b=(*fenmu1) * (*fenzi2);
	if(a<b){
		m=*fenzi1;
		*fenzi1=*fenzi2;
		*fenzi2=m;
		
		n=*fenmu1;
		*fenmu1=*fenmu2;
		*fenmu2=n;
	}
}
    	 
void print1(int r,FILE *fq,FILE *fa){//�������Ƿ����Ĵ�ӡ 
   int a,b,c,d,f,g,h;
   char e; 

   a=Creat_Int(r);
   b=Creat_Int(r);
   c=Creat_Int(r);
   d=Creat_Int(r);
   
    while(b==0){
    	b=Creat_Int(r);
		//b=rand()%r; 
    	break;
	} 
	while(d==0){
    	d=Creat_Int(r);
		//d=rand()%r; 
    	break;
	}
   
   e=getSignal();

   simple(&a,&c);
   simple(&b,&d);
   
   frac_fraccompare(&a,&b,&c,&d);//��a/c < b/d ����λ�� 
   
//��ʾ��������ʽ
show(a,c,r,fq);//��������ʾ���� 
switch(e) 
{
     case '+': {
     	printf(" + ");
     	fprintf(fq," %c ",e);
		break;
	 }
     case '-': {
     	printf(" - ");
     	fprintf(fq," %c ",e);
		break;
	 }
     case '*': {
     	printf(" * ");
     	fprintf(fq," %c ",e);
		break;
	 }
     case '/':{
     	printf(" / ");
     	fprintf(fq," %c ",e);
		break;
	 }
}
show(b,d,r,fq);
printf(" = ");
fprintf(fq," = ");


switch(e) //�� 
{
	case '+': 
	 f=a*d+b*c;
     g=c*d;
     simple(&f,&g);
     show(f,g,r,fa);
     break;

	case '-':
	 f=a*d-b*c;
     g=c*d;
     simple(&f,&g);
     show(f,g,r,fa);
     break;
	  
     case '*': 
	  f=a*b;
      g=c*d;
      simple(&f,&g);
      show(f,g,r,fa); 
	  break;
	 
     case '/': 
	  f=a*d;
      g=b*c;
      simple(&f,&g);
      show(f,g,r,fa); 
	 break;
}	
}
void print2(int r,FILE *fq,FILE *fa){//�������������Ĵ�ӡ 
	int num1,num2;
	char signal;
	signal=getSignal();
	
	num1=Creat_Int(r);
	num2=Creat_Int(r);
	
	switch(signal){
		case '+':{
			printf("%d + %d = ",num1,num2);
			fprintf(fq,"%d + %d = ",num1,num2);
			break;
		}
		case '-':{
			if(num1<num2){
				int t;
				t=num1;
				num1=num2;
				num2=t;
			}
			printf("%d - %d = ",num1,num2);
			fprintf(fq,"%d - %d = ",num1,num2);
			break;
		}
		case '*':{
			printf("%d * %d = ",num1,num2);
			fprintf(fq,"%d * %d = ",num1,num2);
			break;
		}
		case '/':{
			while(num2==0){
				num2=Creat_Int(r);
			}
			if(num1>num2){
				int t;
				t=num1;
				num1=num2;
				num2=t;
			}
			printf("%d / %d = ",num1,num2);
			fprintf(fq,"%d / %d = ",num1,num2);
			break;
		}
		
	}
	
	//�����
	switch(signal) 
{
case '+':
	int c;
	c=num1+num2;
    printf("%d",c);
    fprintf(fa,"%d",c);
	break;
case '-':
    c=num1-num2; 
    printf("%d",c);
	fprintf(fa,"%d",c);   
	break;
case '*': 
    c=num1*num2;
	printf("%d",c);
	fprintf(fa,"%d",c);
	break;
case '/':
    c=num1/num2;
	show(num1,num2,r,fa);
    break;
}

}
void print3(int r,FILE *fq,FILE *fa){//һ��һ�ֵĴ�ӡ 

	int fenzi,fenmu,num1;
	char signal;
	fenzi=Creat_Int(r);
	fenmu=Creat_Int(r);
	num1=Creat_Int(r);

	signal=getSignal();
	
	while(fenmu==0){
				fenmu=Creat_Int(r);
			}
	if(fenzi>fenmu){
				int t;
				t=fenzi;
				fenzi=fenmu;
				fenmu=t;
			}
	simple(&fenzi,&fenmu);	

	switch(signal){
		case '+':{
		printf("%d %c ",num1,signal);
	    fprintf(fq,"%d %c ",num1,signal);
	    show(fenzi,fenmu,r,fq);
	    printf(" = ");
	    fprintf(fq," = ");
		break;
		}
		case '-':{
	    while(num1==0){
	    	num1=Creat_Int(r);
		}
		printf("%d %c ",num1,signal);
	    fprintf(fq,"%d %c ",num1,signal);
	    show(fenzi,fenmu,r,fq);
	    printf(" = ");
	    fprintf(fq," = ");
		break;
		}
		case '*':{
		printf("%d %c ",num1,signal);
	    fprintf(fq,"%d %c ",num1,signal);
	    show(fenzi,fenmu,r,fq);
	    printf(" = ");
	    fprintf(fq," = ");	
		break;
		}
		case '/':{
	    while(fenzi==0){
	    fenzi=Creat_Int(r);
		}
		printf("%d %c ",num1,signal);
	    fprintf(fq,"%d %c ",num1,signal);
	    show(fenzi,fenmu,r,fq);
	    printf(" = ");
	    fprintf(fq," = ");	
		break;
		}
	} 
			
	//�����
	switch(signal){
		int x;
	    case '+':{
	    	x=fenmu*num1+fenzi;
	    	simple(&x,&fenmu);
	    	show(x,fenmu,r,fa);
			break;
		}
		case '-':{        
			x=fenmu*num1-fenzi;
			simple(&x,&fenmu);
			show(x,fenmu,r,fa);
			break;
		} 
		case '*':{
			x=fenzi*num1;
			simple(&x,&fenmu);
			show(x,fenmu,r,fa);
			break;
		}
		case '/':{  
			x=fenmu*num1;
			simple(&fenzi,&x);
			show(x,fenzi,r,fa);
			break;
		}
	} 
		
}

void check(FILE *ans,FILE *stu,int n){
	char a[n+1];
	char s[n+1];
	int right[n+1];
	int wrong[n+1];
	char *p;
	char *q;
	int num=0;//ͳ�ƶԵĸ��� 
	
    for(int i=0,j=0,k=0;i<n;i++){
	p=fgets(a,n+1,ans);
	q=fgets(s,n+1,stu);
	if(strcmp(a,s)==0){
		right[j]=i+1;
		j++;
	    num++;	
	}
	else{
		wrong[k]=i+1;
		k++;
	}
	p++;
	q++;
	}
	printf("\nCorrect:%d(",num);
    fprintf(stu,"\nCorrect:%d(",num);
	for(int j=0;j<num;j++){
		fprintf(stu,"%d ",right[j]);
		printf("%d ",right[j]);
	}
	printf(")\n");
	fprintf(stu,")\n");
	
	printf("\nWrong:%d(",n-num);
	fprintf(stu,"\nWrong:%d(",n-num);
	for(int k=0;k<n-num;k++){
		printf("%d ",wrong[k]);
		fprintf(stu,"%d ",wrong[k]);
	}
	printf(")\n");
	fprintf(stu,")\n");
	//printf("���� %d ����\n",num);
	//printf("���� %d ����\n",n-num);
	
	fclose(ans);
	fclose(stu);
}
