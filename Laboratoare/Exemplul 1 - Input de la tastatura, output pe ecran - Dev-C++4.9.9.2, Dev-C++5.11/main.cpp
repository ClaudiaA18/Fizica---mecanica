
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>



int main()
{
          //  Declararea variabilelor
	
    float xM,yM,OA;
    float xL,xR,xinf;
    int k=1;
    float m=1;
    float V0=1;
    float alfa=1;
	float c=0.1;
    float g=9.81;
    float n=30;
    float epsilon=0.00001;
    float beta=c/m;

          //  punctul A
          
    xM=(V0*V0*sin(2*alfa))/(2*g);
    yM=(V0*V0*sin(alfa)*sin(alfa))/(2*g);
	     
		 // punctul B
	
	OA=2*xM;
    printf("%f %f %f\n",xM,yM,OA);
        
		//punctul C
	
    xM=(V0*V0*sin(alfa)*cos(alfa))/(g+beta*V0*sin(alfa));
    yM=(V0*sin(alfa))/beta-(g*log(1+(beta*V0*sin(alfa)/g)))/(beta*beta); 
	printf("%f %f ",xM,yM);
	
	    
		//punctul D
	
	xinf=(m*V0*cos(alfa))/c;
	xL=xM;
    xR=xinf;
    
    float xI, fxI;
    
    
    for(int i=1; i<=n;i++)
    {
    	xI =(xL+xR)/2;
    	float fxI=(tan(alfa)+g/(beta*V0*cos(alfa)))*xI+(g*log(1-(beta*xI)/(V0*cos(alfa))))/(beta*beta);
    	
    	if(fabs(fxI)<= epsilon)
    	{
    		OA = xI;
    		break;
		}
		
		if(fxI > epsilon)
		{
			xL=xI;
			
		}
		if(fxI < -epsilon)
		{
			xR=xI;	
		}
		
		k++; //nr de iteratii creste
	}

          //  Afisarea pe ecran a datelor de intrare 
          
    printf("%f\n",OA);
    printf("Solutia aproximativa a fost gasita dupa %d iteratii", k);
	printf("\n");

          //  Oprirea executiei programului pana la apasarea unei taste oarecare
	printf("   Press any key! \n");
	while(!_kbhit()){}
	return 0;
}
