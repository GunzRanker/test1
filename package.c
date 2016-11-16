#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<mysql/mysql.h>
#include<string.h>
#include"log.h"
#include"function.h"

void customer();
void business();
void administer();


MYSQL mysql;
MYSQL_RES *res;
MYSQL_ROW row;
int num=0;

int main()
{
          int select=0;
         while(select!=4)
         {
                system("clear");
                  printf("\t\t\t\t\t┌──────────────────────────────────────────────────────────────┐\n");
                  printf("\t\t\t\t\t│                   Travel ManageMent Program                  │\n");
                  printf("\t\t\t\t\t├─────────────┬───────────────┬───────────────┬────────────────┤\n");
                  printf("\t\t\t\t\t│1. 고     객 │ 2. 관  리  자 │ 3. 사  업  자 │ 4.프로그램종료 │\n");
                  printf("\t\t\t\t\t└─────────────┴───────────────┴───────────────┴────────────────┘\n");
                  printf("\t\t\t\t\tInput Operating Number :");
                  scanf("%d",&select);
                 login(select);
         }

          mysql_free_result(res);
          mysql_close(&mysql);

          return 0;
}

void customer()
{
                system("clear");
         printf("\n\n\t\t\t\t\t\tWelcom Customer\n");
         printf("\t\t\t\t\t\t Please Wait");
         sleep(3);

         while(num!=5)
         {
                system("clear");
                 printf("\t\t\t\t\t\t┌──────────────────────────────┐\n");
                 printf("\t\t\t\t\t\t│        View Of Customer      │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│1.여 행 패 키 지              │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│2.주  문  하  기              │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│3.주  문  취  소              │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│4.주  문  확  인              │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│5.종  료  하  기              │\n");
                 printf("\t\t\t\t\t\t└──────────────────────────────┘\n");
                 printf("\t\t\t\t\t\tInput Number :");
                 scanf("%d",&num);
                 functionC(num);
          }
}

void administer()
{
                system("clear");
         printf("\n\n\t\t\t\t\t\tWelcom Administrator\n");
         printf("\t\t\t\t\t\t Please Wait");
         sleep(3);

          while(num!=7)
          {
                system("clear");
                 printf("\t\t\t\t\t\t┌──────────────────────────────┐\n");
                 printf("\t\t\t\t\t\t│      View Of Administrator   │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│1.고  객  목  록              │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│2.고  객  등  록              │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│3.고  객  제  명              │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│4.패 키 지 목 록              │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│5.패 키 지 등 록              │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│6.패 키 지 제 거              │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│7.종  료  하  기              │\n");
                 printf("\t\t\t\t\t\t└──────────────────────────────┘\n");
                 printf("\t\t\t\t\t\tInput Number :");
                 scanf("%d",&num);

                  functionA(num);


          }
}

void business()
{
                system("clear");
         printf("\n\n\t\t\t\t\t\tWelcom Buyer\n");
         printf("\t\t\t\t\t\t Please Wait");
         sleep(3);
         while(num!=6)
          {
                system("clear");
                 printf("\t\t\t\t\t\t┌──────────────────────────────┐\n");
                 printf("\t\t\t\t\t\t│         View Of Buyer        │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│1.패키지별 구매현황           │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│2.일자별  판매 현황           │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│3.직   원   현   황           │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│4.직   원   추   가           │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│5.직   원   제   거           │\n");
                 printf("\t\t\t\t\t\t├──────────────────────────────┤\n");
                 printf("\t\t\t\t\t\t│6.종   료   하   기           │\n");
                 printf("\t\t\t\t\t\t└──────────────────────────────┘\n");
                 printf("\t\t\t\t\t\tInput Number :");
                 scanf("%d",&num);
                 functionB(num);
          }
}
