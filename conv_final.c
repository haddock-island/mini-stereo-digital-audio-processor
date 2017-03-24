#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int i,j,k,p,z;
    char c[2560],c1[1000][10];
    long int in[10000], final[10000], out[10000] ;
    int bin[256][32];
    int m[256][32];
    
    
    FILE *coeff,*coeffbin;
    FILE *data_exo,*data_ex, *data_out, *data_in;
    
    coeff = fopen("./coeff.txt","r");               //open the coefficient file here
    //data_ex =fopen("./dataex.txt","r");             //open the example data input here
    data_in=fopen("./data2.txt","r+");
    data_out=fopen("./data2_out.txt","w+");    
    //data_exo = fopen("./dataout.txt", "r+");            //open the example data input here
    
    for(i=0;i<1000;i++)                        
    {
        fscanf(data_in,"%lx",&in[i]);                
        
        in[i]=(in[i]*0x10000);
            //printf("%X", in[i]);
            if (in[i] < 0x80000000)
            {
               in[i]=0x0000000000000000 + in[i];
               
 
            }
                    else {
                        in[i]=0xFFFFFFFF00000000 + in[i]; 
                        }
                     
        //fprintf(data_exo, "%016lX \n",in[i]);
        //h[i] = in[i];
        //fscanf(data_exo,"%x",&in[i]);
        
    }
    
    for(i=0;i<=255;i++)
    {
        
        for(j=0;j<=9;j++)
        {
            
            c1[i][j]=getc(coeff);
            
            //printf("c1[%d][%d] = %c",i,j,c1[i][j]);
            
        }
        //fprintf(data_exo,"\n")	;
    }
    
    for(i=0;i<=255;i++)
        {
        for(j=0;j<8;j++) 
            {
            switch(c1[i][j])
                {
                case '0':  bin[i][(j*4)+0]=0;
                    bin[i][(j*4)+1]=0;
                    bin[i][(j*4)+2]=0;
                    bin[i][(j*4)+3]=0;
                    break;
                case '1': bin[i][(j*4)+0]=0;
                    bin[i][(j*4)+1]=0;
                    bin[i][(j*4)+2]=0;
                    bin[i][(j*4)+3]=1;
                    break;
                case '2': bin[i][(j*4)+0]=0;
                    bin[i][(j*4)+1]=0;
                    bin[i][(j*4)+2]=1;
                    bin[i][(j*4)+3]=0;
                    break;
                case '3':bin[i][(j*4)+0]=0;
                    bin[i][(j*4)+1]=0;
                    bin[i][(j*4)+2]=1;
                    bin[i][(j*4)+3]=1;
                    break;
                case '4': bin[i][(j*4)+0]=0;
                    bin[i][(j*4)+1]=1;
                    bin[i][(j*4)+2]=0;
                    bin[i][(j*4)+3]=0;
                    break;
                case '5': bin[i][(j*4)+0]=0;
                    bin[i][(j*4)+1]=1;
                    bin[i][(j*4)+2]=0;
                    bin[i][(j*4)+3]=1;
                    break;
                case '6': bin[i][(j*4)+0]=0;
                    bin[i][(j*4)+1]=1;
                    bin[i][(j*4)+2]=1;
                    bin[i][(j*4)+3]=0;
                    break;
                case '7': bin[i][(j*4)+0]=0;
                    bin[i][(j*4)+1]=1;
                    bin[i][(j*4)+2]=1;
                    bin[i][(j*4)+3]=1;
                    break;
                case '8': bin[i][(j*4)+0]=1;
                    bin[i][(j*4)+1]=0;
                    bin[i][(j*4)+2]=0;
                    bin[i][(j*4)+3]=0;
                    break;
                case '9': bin[i][(j*4)+0]=1;
                    bin[i][(j*4)+1]=0;
                    bin[i][(j*4)+2]=0;
                    bin[i][(j*4)+3]=1;
                    break;
                case 'A': bin[i][(j*4)+0]=1;
                    bin[i][(j*4)+1]=0;
                    bin[i][(j*4)+2]=1;
                    bin[i][(j*4)+3]=0;
                    break;
                case 'B': bin[i][(j*4)+0]=1;
                    bin[i][(j*4)+1]=0;
                    bin[i][(j*4)+2]=1;
                    bin[i][(j*4)+3]=1;
                    break;
                case 'C': bin[i][(j*4)+0]=1;
                    bin[i][(j*4)+1]=1;
                    bin[i][(j*4)+2]=0;
                    bin[i][(j*4)+3]=0;
                    break;
                case 'D': bin[i][(j*4)+0]=1;
                    bin[i][(j*4)+1]=1;
                    bin[i][(j*4)+2]=0;
                    bin[i][(j*4)+3]=1;
                    break;
                case 'E': bin[i][(j*4)+0]=1;
                    bin[i][(j*4)+1]=1;
                    bin[i][(j*4)+2]=1;
                    bin[i][(j*4)+3]=0;
                    break;
                case 'F': bin[i][(j*4)+0]=1;
                    bin[i][(j*4)+1]=1;
                    bin[i][(j*4)+2]=1;
                    bin[i][(j*4)+3]=1;
                    break;
                case ' ':  printf(" ");
                }
              //fprintf(coeffbin, "%d", bin[i][j]);  
            }
            //fprintf(coeffbin,"\n");	
        }
    
    
    for (i=0; i<256; i++)
    {
        for (j=0; j<32; j++)
            {
            m[i][j] = bin[i][j];
            //printf("%d",m[i][j]);
            //printf("%d",bin[i][4*j+1]);
            //printf("%d",bin[i][4*j+2]);
            //printf("%d\t",bin[i][4*j+3]);
            //fprintf(coeffbin, "%d", bin[i][j]);
            }
            //printf("\n");
      }
      

for(i=0;i<1000;i++)
{
	//int m=0;
	//int l;
	//out[0]=0x0;
for(k=i;k>=0;k--)
{
	
for(j=0;j<16;j++)
{
	//printf("%d",bin[i][j-16]);
	//printf("%d",bin[0][j]);
	if(bin[i-k][j+16]==1)
	{

		if(bin[i-k][j]==0)
		{
		out[i]=out[i]+(in[k]>>(j+1));
			
		}
		else
		{
		out[i]=out[i]-((in[k])>>(j+1));
		//printf("%10lX\n",out[k]);
		}
			
		
	}
}
	if((i-k)==256)
	break;
//printf("%X\n",out[i]);
	//m++;
}	
	//m++;
	final[i] = out[i];
	long long int trunc = (0x000000FFFFFFFFFF & final[i]);
	fprintf (data_out,"%010llX\n", trunc);
	//printf("%010lX\n",out[i]);
         
}  
    
         
    //printf("\n"); 
    
    
    fclose(coeff);
    fclose(coeffbin);
    fclose(data_ex);
    fclose(data_exo);
    //getchar();
}


