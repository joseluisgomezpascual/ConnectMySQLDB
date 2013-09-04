#include<stdio.h>
#include<mysql/mysql.h>

int main()
{
	MYSQL *con=mysql_init(NULL);
	MYSQL_ROW row;
	MYSQL_RES *res;
	char *server="localhost";
	char *user="root";
	char *password="root";
	char *db="prueba";
	
	if(!mysql_real_connect(con,server,user,password,db,0,NULL,0))
	{
		printf("Error: %s\n",mysql_error(con));
	}
	
	mysql_query(con,"select * from usuarios");
	res=mysql_use_result(con);
	if((row=mysql_fetch_row(res))!=NULL)
	{
		printf("%s %s \n",row[0],row[1]);
	}
	return 0;
}
