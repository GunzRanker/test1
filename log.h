#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<mysql/mysql.h>

extern MYSQL mysql;

void customer();
void administer();
void business();
void login(int select);

void login(int select)
{
          char id[10];
          char pa[10];
          switch(select)
          {
                  case 1:
                          mysql_init(&mysql);

                          if(!mysql_real_connect(&mysql,"localhost","db1326","1234","1326_db",0,NULL,0))
                          {
                                  fprintf(stderr,"%s\n",mysql_error(&mysql));
                                  exit(1);
                          }
                          if(mysql_query(&mysql,"use 1326_db"))
                          {
                                  fprintf(stderr,"%s\n",mysql_error(&mysql));
                                  exit(1);
                          }

                          customer();
                          break;

                  case 2:
                          mysql_init(&mysql);
                          printf("관리자님의 아이디와 비밀번호를 입력해주세요\n아이디:");
                          scanf("%s",id);
                         printf("\n비밀번호 : ");
                          scanf("%s",pa);

                          mysql_init(&mysql);

                         if(!mysql_real_connect(&mysql,"localhost",id,pa,"1326_db",0,NULL,0))
                         {
                                 fprintf(stderr,"%s\n",mysql_error(&mysql));
                                 exit(1);
                         }
                           printf("%s님 어서오세요\n",id);
                          if(mysql_query(&mysql,"use 1326_db"))
                          {
                                  fprintf(stderr,"%s\n",mysql_error(&mysql));
                                  exit(1);
                          }
                          administer();
                          break;
                  case 3:
                          mysql_init(&mysql);

                         if(!mysql_real_connect(&mysql,"localhost","db1326","1234","1326_db",0,NULL,0))
                         {
                                 fprintf(stderr,"%s\n",mysql_error(&mysql));
                                 exit(1);
                         }
                          printf("사업자님 어서오세요!!\n");
                          if(mysql_query(&mysql,"use 1326_db"))
                          {
                                  fprintf(stderr,"%s\n",mysql_error(&mysql));
                                  exit(1);
                          }
                          business();
                          break;
                  case 4:
                          printf("프로그램을 종료합니다\n");
                          break;
                 default :
                          printf("숫자를 제대로 입력하세요");
          }
  }