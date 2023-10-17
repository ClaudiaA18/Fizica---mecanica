//                             Centru parabola
//                utilizand Dev-C++5.11 - Console Application
//           Copyright © 2019 - prof. dr. ing. Andrei Craifaleanu



#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <graphics.h>

int main()
{
    float a, b, k, q;
    float xp, yp, x, y, xs, ys;
    float Sx, Sy;
    float Aa, xa, ya;       // aria, respectiv coordonatele centrului, calculate analitic
    float An = 0, xn, yn;   // aria, respectiv coordonatele centrului, calculate numeric
    int be = 600, he = 400; // dimensiunile ferestrei grafice, in pixeli
    int i,n;

//      Citirea datelor de intrare

    printf("Baza si inaltimea placii = ");
    scanf(" %f %f", &a, &b);
    printf("Nr. pasi =");
    scanf(" %d", &n);
    printf("Factor de scara =");
    scanf(" %f", &k);

//      Calcul analitic

 q = b*b/a;
 Aa = (2/3) * a * b;
 xa = (3/5) *a;
 ya = (3/8) *b;

//      Calcul numeric si desen

    initwindow(be, he);
    x = be/2;
    y = he/2;

    for (i = 0; i < n; i++)
    {
    	xp = i*a/n;
    	yp = sqrt(q * xp);
    	
		xs = (i+1) * a/n;
		yp = sqrt(q * xs);
		
		Aap = (1/2) * (xs - xp) * yp;
		Aas = (1/2) * (xs - xp) * ys;
		
		xnp = (2*xp + xs)/3;
		ynp = yp/3;
		
		xns = (2*xp + xs)/3;
		yns = (yp+ ys)/3;
		
		A = Aa + Aap + Aas;
		Soyz = Soyz + Aap * xnp + Aas * xns;
		Sozx = Sozx + Aap * ynp + Aas * yns;
		
        xp = 2;
        yp = 1;
        
        xep = x + k*xp;
        yep = y - k*yp;
       
	    xes = xp + k*xs;
        yes = yp - k*ys;
        

        line(x, y, xs, ys);
        line()
        
    }

    setcolor(YELLOW);
    setlinestyle(SOLID_LINE , 1, 4);
    circle(xs, ys, 4);

//      Afisarea rezultatelor

    printf("\n");
    printf("Analitic:  A = %6.3f, xC = %6.3f, yC = %6.3f \n", Aa, xa, ya);
    printf("Numeric :  A = %6.3f, xC = %6.3f, yC = %6.3f \n", An, xn, yn);

    printf("\n");
	printf("   Press any key! \n");
    while (!kbhit()){};
    return 0;
}
