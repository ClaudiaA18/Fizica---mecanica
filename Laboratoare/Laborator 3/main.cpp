#include <conio.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float xA;
    float x, y;
    float Fx, Fy;
    float M;
    float V = 0, H = 0, N = 0;
    int i, j, n, m;
    float eps = 0;


	printf("xA = ");
	scanf("%f", &xA);

    printf("\n");
    printf("Nr. forte = ");
    scanf(" %d", &n);
    
    printf("\n");
    printf("Nr. cupluri = ");
    scanf(" %d", &m);
    
    for (i = 1; i <= n; i++)
    {
        printf("%d)", i);
        printf(" F%dx", i);
        printf(", F%dy = ", i);
        scanf(" %f %f", &Fx, &Fy);
        
 		printf("%d)", i);
        printf(" x%d", i);
        printf(", y%d = ", i);
        scanf(" %f %f", &x, &y);
        
        H = H-Fx;
        V = V+(x-xA)*Fy-y*Fx;
        N = N+y*Fx-x*Fy;
        
        eps = eps + Fy;
    }
    
    for(j = 1; j<=m; j++)
    {
    	printf("%d)", j);
    	printf(" M%d = ", j);
    	scanf(" %f", &M);
    	
    	V = V+M;
    	N = N-M;
	}
	
	V = V / xA;
	N = N / xA;
	eps = eps + V + N;

    printf("\n");
    printf("H = %f;\n V = %f;\n N = %f;\n eps = %.9f;", H, V, N, eps);

    printf("\n");
	printf("   Press any key! \n");
    while (!kbhit()){};
    return 0;
}
