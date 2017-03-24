#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int i,j,k;
    char c[2560],c1[1000][10];
    long int in[1000];
    int bin[256][32];
    char m[256][16];
    
    
    FILE *coeff;
    FILE *data_exo,*data_ex;
    
    coeff = fopen("./coeff.txt","r");               //open the coefficient file here
    data_ex =fopen("./dataex.txt","r");
    data_exo = fopen("./dataout.txt", "r+");            //open the example data input here
    
    for(i=0;i<1000;i++)                        //this loop reads the 1000 example inputs. loop runs for 1000*6 because each hex number is 6char long (2 trailing spaces)
    {
        fscanf(data_ex,"%lx",&in[i]);                //fscanf(<filename>,<variable format>,<store in an array>
        
        in[i]=(in[i]*0x10000);
            if (in[i]>=0x80000000)
            {
               in[i] = in[i] | 0xFF00000000; 
               
            }
                    else {
                            in[i]=0x0000000000 + in[i];
                            
                         }
               
        
        printf("%010lX\n", in[i]);
        fprintf(data_exo, "%010lX \n",in[i]);
        
        
    }
    /*
    for(i=0;i<6000;i++)                        //this loop reads the 1000 example inputs. loop runs for 1000*6 because each hex number is 6char long (2 trailing spaces)
    {
        fscanf(data_exo,"%c",&in1[i]);
            if (in1[(6*i)] >= 0 && in1[(6*i)] <8)
                {
                    
                
                
                }
        
        
        
        in[i]=(in[i]*0x10000);
        
        fprintf(data_exo, "%08X \n",in[i]);
        fscanf(data_exo,"%x",&in[i]);
        
    }
    */
    
    
   
    fclose(coeff);
    fclose(data_ex);
    fclose(data_exo);
    
    return (0);
    //getchar();
}
