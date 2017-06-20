#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

static void getData(char *datBuf);

char* room_data[12]={"$FLAG1011$","$FLAG1012$",
				"$FLAG1021$","$FLAG1022$",
				"$FLAG1031$","$FLAG1032$",
				"$FLAG1041$","$FLAG1042$",
				"$FLAG1051$","$FLAG1052$",
				"$FLAG1061$","$FLAG1062$"};

int main(int argc, char **argv)
{
	char data_buf[256];
	unsigned char cnt=0;
	FILE *fp_html;
	char html_buf[4096]="";
	char* store_buf[12];
	
	printf("%s\r\n\r\n","Content-Type: text/html\n\n");
	if((fp_html=fopen("index.html","r")) == NULL)
	{
		exit (1);
	}
	
	while(fgets(html_buf,4096,fp_html))
	{
		int i,j;
		getData(data_buf);
		cnt=0;
	
		
		if(strncmp(html_buf,"$FLAG1011$",10)==0)
			printf("--------------------------------------------");
		else
			printf("%s",html_buf);
	
		//--------------------------------------------------------------------//
		/*
		for(i = 0; i < 12; i++)
		{
			char tmp_buf[11]="";
			strcpy(tmp_buf,"$FLAG");
			tmp_buf[5]=data_buf[10*i+2];tmp_buf[6]=data_buf[10*i+3];
			tmp_buf[7]=data_buf[10*i+4];tmp_buf[8]=data_buf[10*i+5];
			tmp_buf[9]='$';

			store_buf[i]=tmp;
		}
		if(strncmp(store_buf[i],room_data[j],10)==0)
		//-------------------------------------------------------------------//
		*/
		/*
		for(i = 0; i < 12; i++)
		{
			char tmp_buf[11]="";
			strcpy(tmp_buf,"$FLAG");
			tmp_buf[5]=data_buf[10*i+2];tmp_buf[6]=data_buf[10*i+3];
			tmp_buf[7]=data_buf[10*i+4];tmp_buf[8]=data_buf[10*i+5];
			tmp_buf[9]='$';
			if(strncmp(tmp_buf,html_buf,9)==0)
			{
				if(data_buf[10*i+9])
					printf("%s","<img src=\"image/on.jpg\" width=\"126\" height=\"68\" id=\"1021\"/>");
					//printf("%s","light on");	
				else
					printf("%s","<img src=\"image/off.jpg\" width=\"126\" height=\"68\" id=\"1021\"/>");
					//printf("%s","light off");
				break;
			}else{
			//	printf("%s",html_buf);
			}
		}printf("%s",html_buf);
		*/
		
	}
	return 0;
}

static void getData(char *datBuf)
{
	int cnt;
	FILE *fp;
	if((fp=fopen("write.ini","r"))==NULL)
	{
		printf("<p>fopen Error!<a href=\"/cgi-bin/main.cgi\">Return/a>");
		exit (1);
	}
	//fseek(fp,-5,SEEK_END);
	//fgets(datBuf,5,fp);
	for(cnt=0;fscanf(fp,"%c",datBuf+cnt)!=EOF;cnt++);
	fclose(fp);
}


