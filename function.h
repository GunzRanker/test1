#include<stdio.h>
#include<stdlib.h>
#include<mysql/mysql.h>
#include<errno.h>
#include<string.h>

MYSQL mysql;
MYSQL_RES *res;
MYSQL_ROW row;
my_ulonglong u;

void functionA(int num);
void functionB(int num);
void functionC(int num);
void initcustomer();
void initpackage();
void initorder();
void initemployee();
void result();


void functionA(int num)
{
          switch(num)
          {
                  case 1:
                          initcustomer();
                          if(mysql_query(&mysql,"select cid,cname,csex,cage,addr from customer2 order by cid"))
                          {
                                  fprintf(stderr,"%s\n",mysql_error(&mysql));
                                  exit(1);
                          }
                          printf("\n\n고객번호\t이름\t\t성별\t\t나이\t\t주소");
                          result();
                          break;
                  case 2:
                          {
                                  char Tquery[100]="insert into customer2(cname,csex,cage,addr,passwd) values(\'";
                                  char cname[10];
                                  char csex[5];
                                  char cage[5];
                                  char addr[20];
                                  char passwd[20];
                                  char space1[5]=",'";
                                  char space2[5]="','";
                                  char space3[5]="',";
                                  char space4[5]="')";

                                  printf("\n이름을 입력하세요:");
                                  scanf("%s",cname);
                                  printf("\n성별을 입력하세요(M,W):");
                                  scanf("%s",csex);
                                  printf("\n나이를 입력하세요:");
                                  scanf("%s",cage);
                                  printf("\n주소를 입력하세요:");
                                  scanf("%s",addr);
                                  printf("\n사용하실 비밀번호를 입력하세요:");
                                  scanf("%s",passwd);

                                  strcat(Tquery,cname);
                                  strcat(Tquery,space2);
                                  strcat(Tquery,csex);
                                  strcat(Tquery,space3);
                                  strcat(Tquery,cage);
                                  strcat(Tquery,space1);
                                  strcat(Tquery,addr);
                                  strcat(Tquery,space2);
                                  strcat(Tquery,passwd);
                                  strcat(Tquery,space4);

                                  initcustomer();
                                  if(mysql_real_query(&mysql,Tquery,strlen(Tquery)))
                                  {
                                          fprintf(stderr,"%s\n",mysql_error(&mysql));
                                          exit(1);
                                  }

                                  mysql_query(&mysql,"select cid,cname,csex,cage,addr from customer2 order by cid");
                                  printf("\n\n고객번호\t이름\t\t성별\t\t나이\t\t주소");
                                  result();
                                  break;
                          }
                  case 3:
                          {
                                  char Tquery[100]="delete from customer2 where cid=";
                                  char query1[5];

                                  printf("제거할 고객번호를 입력하세요:");
                                  scanf("%s",&query1);
                                  strcat(Tquery,query1);

                                  if(mysql_real_query(&mysql,Tquery,strlen(Tquery)))
                                  {
                                          fprintf(stderr,"%s\n",mysql_error(&mysql));
                                          exit(1);
                                  }

                                  initcustomer();
                                  mysql_query(&mysql,"select cid,cname,csex,cage,addr from customer2 order by cid");
                                  printf("\n\n고객번호\t이름\t\t성별\t\t나이\t\t주소");
                                 result();
                                 break;
                         }
                 case 4:
                         initpackage();

                         if(mysql_query(&mysql,"select pid,place,pdate,price from package2 order by pid"))
                         {
                                 fprintf(stderr,"%s\n",mysql_error(&mysql));
                                 exit(1);
                         }

                         printf("\n\n패키지번호\t패키지명\t\t일자\t\t\t가격");
                         result();
                         break;
                 case 5:
                         {
                                 initpackage();

                                 char Tquery[100]="insert into package2(place,pdate,price,eid) values('";
                                 char pid[2];
                                 char place[10];
                                 char pdate[30];
                                char price[10];
                                 char eid[2];
                                 char space1[8]="','";
                                 char space2[5]="',";
                                char space3[2]=")";
                                 char space4[2]=",";

                                 printf("\n등록할 패키지명을 입력하시오:");
                                 scanf("%s",place);
                                 printf("\n일정을 입력하시오(ex 14.07.01~14.07.12):");
                                 scanf("%s",pdate);
                                 printf("\n가격을 입력하세요:");
                                 scanf("%s",price);
                                 printf("\n전담직원을 입력하세요");
                                 scanf("%s",eid);
                                 strcat(Tquery,place);
                                 strcat(Tquery,space1);
                                 strcat(Tquery,pdate);
                                 strcat(Tquery,space2);
                                 strcat(Tquery,price);
                                 strcat(Tquery,space4);
                                 strcat(Tquery,eid);
                                 strcat(Tquery,space3);

                                 if(mysql_real_query(&mysql,Tquery,strlen(Tquery)))
                                 {
                                         fprintf(stderr,"%s\n",mysql_error(&mysql));
                                         exit(1);
                                }

                                 mysql_query(&mysql,"select * from package2 order by pid");
                                 result();
                                 break;
                         }
                 case 6:
                         {
                                 char Tquery[100]="delete from package2 where pid=";
                                 char query1[5];

                                 printf("제거할 패키지번호를 입력하세요:");
                                 scanf("%s",&query1);
                                 strcat(Tquery,query1);

                                 if(mysql_real_query(&mysql,Tquery,strlen(Tquery)))
                                 {
                                         fprintf(stderr,"%s\n",mysql_error(&mysql));
                                         exit(1);
                                 }

                                 initpackage();
                                 mysql_query(&mysql,"select * from package2 order by pid");
                                 result();
                                 break;
                         }
                 case 7:
                         printf("프로그램을 종료합니다\n");
                         break;
                 default :
                         printf("error!!\n");
                         break;
         }
}

void functionB(int num)
{
         switch(num)
         {
                 case 1:
                         if(mysql_query(&mysql,"select orders.pid,place,sum(saleprice) profit from package2,orders2 where package2.pid=orders2.pid group by orders2.pid order by orders2.pid"))
                         {
                                 fprintf(stderr,"%s\n",mysql_error(&mysql));
                                 exit(1);
                         }

                         printf("고객번호\t패키지명\t\t판매총액");
                         result();
                         break;

                 case 2:
                         if(mysql_query(&mysql,"select substr(odate,3,8) as '날짜', sum(saleprice) from orders2 group by substr(odate,4,8)"))
                         {
                                 fprintf(stderr,"%s\n",mysql_error(&mysql));
                                 exit(1);
                         }

                         printf("판매일자\t\t판매총액");
                         result();
                         break;

                 case 3:
                         initemployee();
                         if(mysql_query(&mysql,"select eid,esex,ename,eage,rank,depart.dname from employee2,depart2 where depart2.did=employee2.did order by eid"))
                         {
                                 fprintf(stderr,"%s\n",mysql_error(&mysql));
                                 exit(1);
                         }

                         printf("\n\n직원번호\t성별\t\t이름\t\t나이\t\t직급\t\t부서명");
                         result();
                         break;

                 case 4:
                         {

                                 char Tquery[100]="insert into employee2(ename,esex,eage,rank,did) values(\'";
                                 char ename[10];
                                 char esex[3];
                                 char eage[5];
                                 char rank[8];
                                 char did[3];
                                 char space1[5]="','";
                                 char space2[5]="',";
                                 char space3[5]=",'";
                                 char space4[5]=")";

                                 printf("\n직원이름을 입력하세요:");
                                 scanf("%s",ename);
                                 printf("\n직원성별을 입력하세요(W,M):");
                                 scanf("%s",esex);
                                 printf("\n직원나이를 입력하세요:");
                                 scanf("%s",eage);
                                 printf("\n직원의직급을 입력하세요(사장,비서,부장,과장,대리):");
                                 scanf("%s",rank);
                                 printf("\n배정할부서번호를 입력하세요(OP=1,T/C=2,Guide=3,Counter=4,Programmer=5):");
                                 scanf("%s",did);
                                 strcat(Tquery,ename);
                                 strcat(Tquery,space1);
                                 strcat(Tquery,esex);
                                 strcat(Tquery,space2);
                                 strcat(Tquery,eage);
                                 strcat(Tquery,space3);
                                 strcat(Tquery,rank);
                                 strcat(Tquery,space2);
                                 strcat(Tquery,did);
                                 strcat(Tquery,space4);

                                 if(mysql_real_query(&mysql,Tquery,strlen(Tquery)))
                                 {
                                         fprintf(stderr,"%s\n",mysql_error(&mysql));
                                         exit(1);
                                 }
                                initemployee();
                                 mysql_query(&mysql,"select eid,esex,ename,eage,rank,depart2.dname from employee2,depart2 where depart2.did=employee2.did order by eid");
                                 printf("\n\n직원번호\t성별\t\t이름\t\t나이\t\t직급\t\t부서명");
                                 result();
                                 break;
                         }
                 case 5:
                         {
                                 char Tquery[100]="delete from employee2 where eid=";
                                 char query1[5];

                                 printf("제거할 직원번호를 입력하세요:");
                                 scanf("%s",query1);
                                 strcat(Tquery,query1);

                                 if(mysql_real_query(&mysql,Tquery,strlen(Tquery)))
                                 {
                                         fprintf(stderr,"%s\n",mysql_error(&mysql));
                                         exit(1);
                                 }

                                 initemployee();
                                 mysql_query(&mysql,"select eid,esex,ename,eage,rank,depart.dname from employee2,depart2 where depart2.did=employee2.did order by eid");
                                 printf("\n\n직원번호\t성별\t\t이름\t\t나이\t\t직급\t\t부서명");
                                 result();

                                 break;
                        }
                 case 6:
                         printf("프로그램을 종료합니다!\n");
                         break;
                 default :
                         printf("error!!");
                         break;
         }

 }

void functionC(int num)
{
         switch(num)
         {
                 case 1:
                         {
                                 initpackage();
                                 if(mysql_query(&mysql,"select pid,place,pdate,price from package2 order by pid"))
                                 {
                                         fprintf(stderr,"%s\n",mysql_error(&mysql));
                                         exit(1);
                                 }
                                 printf("\n패키지번호\t장소\t\t\t일자\t\t\t가격");
                                result();
                                 break;
                         }
                 case 2:
                         {
                                 initorder();
                                 char Tquery[100]="insert into orders2(oid,odate,pid,cid) values(";
                                 char space1[2]=",";
                                 char space2[2]=")";
                                 char oid[3];
                                 char odate[10]=",now(),";
                                 char pid[3];
                                 char cid[3];

                                 mysql_query(&mysql,"select * from orders2 order by oid");
                                 res=mysql_store_result(&mysql);
                                 u=mysql_num_rows(res);
                                 sprintf(oid, "%lu",u+1);

                                 printf("주문을 시작합니다\n");
                                 printf("\n고객님의 번호를 입력하세요:");
                                 scanf("%s",cid);
                                 printf("\n주문하실 패키지번호를 입력하세요:");
                                 scanf("%s",pid);

                                 strcat(Tquery,oid);
                                 strcat(Tquery,odate);
                                 strcat(Tquery,pid);
                                 strcat(Tquery,space1);
                                strcat(Tquery,cid);
                                 strcat(Tquery,space2);

                                 if(mysql_real_query(&mysql,Tquery,strlen(Tquery)))
                                 {
                                         fprintf(stderr,"%s\n",mysql_error(&mysql));
                                         exit(1);
                                 }

                                 mysql_query(&mysql,"update orders2,package2 set saleprice=price where orders2.pid=package2.pid");
                                 mysql_query(&mysql,"update customer2,package2,orders2 set customer2.eid=package2.eid where orders2.cid=customer2.cid and package2.pid=orders2.pid");
                                 printf("주문번호\t\t주문일자\t\t패키지번호\t고객번호\t가격");
                                 mysql_query(&mysql,"select * from orders2 order by oid");
                                 result();
                                 break;
                         }
                 case 3:
                        {
                                 char Tquery[100]="delete from orders2 where cid=";
                                 char connect[10]=" and pid=";
                                 char cid[5];
                                 char pid[5];

                                 printf("고객님의 고객번호를 입력하세요:");
                                 scanf("%s",cid);
                                 printf("취소할 패키지번호를 입력하세요:");
                                 scanf("%s",pid);
                                 strcat(Tquery,cid);
                                 strcat(Tquery,connect);
                                 strcat(Tquery,pid);

                                 if(mysql_real_query(&mysql,Tquery,strlen(Tquery)))
                                 {
                                         fprintf(stderr,"%s\n",mysql_error(&mysql));
                                         exit(1);
                                 }
                                 initorder();
                                 printf("주문번호\t\t주문일자\t\t패키지번호\t고객번호\t가격");
                                 mysql_query(&mysql,"select * from orders2 order by oid");
                                 result();
                                 break;
                         }
                 case 4:
                         initorder();
                         if(mysql_query(&mysql,"select * from orders2 order by oid"))
                         {
                                fprintf(stderr,"%s\n",mysql_error(&mysql));
                                exit(1);
                         }
                         printf("\n주문번호\t\t주문일자\t\t패키지번호\t고객번호\t가격");
                         result();
                         break;
                 case 5:
                         printf("프로그램을 종료합니다!\n");
                         break;
                 default :
                         printf("error!!\n");
                         break;
         }
 }

void initcustomer()
{

         mysql_query(&mysql,"alter table customer2 auto_increment=1");
         mysql_query(&mysql,"set @count=0;");
         mysql_query(&mysql,"update customer2 set customer2.cid=@count:=@count+1");
}

void initpackage()
{

         mysql_query(&mysql,"alter table package2 auto_increment=1");
         mysql_query(&mysql,"set @count=0;");
         mysql_query(&mysql,"update package2 set package2.pid=@count:=@count+1");
}

void initorder()
{

         mysql_query(&mysql,"alter table orders2 auto_increment=1");
         mysql_query(&mysql,"set @count=0;");
         mysql_query(&mysql,"update orders2 set orders2.oid=@count:=@count+1");
}

void initemployee()
{

         mysql_query(&mysql,"alter table employee2 auto_increment=1");
         mysql_query(&mysql,"set @count=0;");
         mysql_query(&mysql,"update employee2 set employee2.eid=@count:=@count+1");
}

void result()
{
         int k,fields;
         res=mysql_store_result(&mysql);
         fields=mysql_num_fields(res);

         printf("\n--------------------------------------------------------------------------------------------------------\n");
         while(row=mysql_fetch_row(res))
         {
                 for(k=0;k<fields;k++)
                         printf("%s\t\t",row[k]);
                         printf("\n");
         }
         printf("\n--------------------------------------------------------------------------------------------------------\n");
}


