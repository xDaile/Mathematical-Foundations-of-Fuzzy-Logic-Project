#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef enum
{
  TMIN,
  TPN,
  TDN,
  TLN,
  TH
} Normy;

char *Nor[200] = {
    "TMIN",
    "TSoucin",
    "TDrasticky",
    "TLukas",
    "THamacher"};
double TMin(double x, double y)
{
  if (x > y)
    return y;
  else
    return x;
}
double TP(double x, double y)
{
  return x * y;
}
double TD(double x, double y)
{
  if (x > 0.99 || y > 0.99)
    return TMin(x, y);
  else
    return 0.0;
  // if (x> 0.9) return y;
  // if(y>0.9) return x;
  // return 0;
}
double TL(double x, double y)
{
  double Pom = x + y - 1.0;
  if (Pom > 0.0)
    return Pom;
  else
    return 0.0;
}
double Hamacher(double x, double y)
{
  if (x == 0.0 && y == 0.0)
  {
    return 0.0;
  }
  else
    return (x * y) / ((100.0) + (1.0 - 100.0) * (x + y - x * y));
}
double Merge(int Norma, double x, double y)
{
  //printf("IN MERGE %f,Norma %d",TMin(x,y),Norma);
  switch (Norma)
  {
  case TMIN:

    return TMin(x, y);
    break;
  case TPN:
    return TP(x, y);
    break;
  case TDN:
    return TD(x, y);
    break;
  case TLN:
    return TL(x, y);
    break;
  case TH:
    return Hamacher(x, y);
    break;
  }
}
double Avg(int Normax, int Normay, double x, double y)
{
  return (Merge(Normax, x, y) + Merge(Normay, x, y)) / 2;
}
double tNorm(int Norma, double x, double y)
{

  return (Merge(Norma, x, y));
}
int main()
{
  double x = 0.0, y = 0.0, z = 0.0, firstRes = 0.0, firstBigL = 0.0, secondBigL = 0.0, firstBigR = 0.0, secondBigR = 0.0, leftSide = 0.0, secondRes = 0.0, rightSide = 0.0, diff = 0.0, inner1 = 0.0, inner2 = 0.0, avg1 = 0.0;
  int n = 0, j = 0;
  double inner3 = 0.0, inner4 = 0.0, avg2 = 0.0;

  for (x = 0.0; x <= 1.0; x += 0.1)
  {
    for (y = 0.0; y <= 1.0; y += 0.1)
    {
      for (z = 0.0; z <= 1.0; z += 0.1)
      {
        //////////////////////////
        for (n = 0; n <= 4; n++)
        {
          for (j = 0; j <= 4; j++)
          {
            //firstRes = Avg(n, j, x, y);
            inner1 = tNorm(n, x, y);
            inner2 = tNorm(j, x, y);

            avg1 = (inner1 + inner2) / 2;
            firstBigL = tNorm(n, avg1, z);
            secondBigL = tNorm(j, avg1, z);
            leftSide = firstBigL + secondBigL;

            inner3 = tNorm(n, x, z);
            inner4 = tNorm(j, x, z);
            avg2 = (inner3 + inner4) / 2;
            firstBigR = tNorm(n, avg2, y);
            secondBigR = tNorm(j, avg2, y);
            rightSide = firstBigR + secondBigR;

            /*firstBig = tNorm(n, firstRes, z);
            secondBig = tNorm(j, firstRes, z);
            leftSide = firstBig + secondBig;

            secondRes = Avg(n, j, x, z);
            firstBig = tNorm(n, secondRes, y);
            secondBig = tNorm(j, secondRes, y);

            rightSide = firstBig + secondBig;
            */
            //  printf(" secondRed=%f, firstBig=%f, secondBig=%f ,leftSide=%f ",secondRes, firstBig,secondBig, leftSide);

            //printf("Tnormax = %s a Tnormay = %s \n",Nor[n],Nor[j]);
            //printf("prvni vysledek je %f a druhy vysledek je %f second res: %f\n",firstBig,secondBig,secondRes );
            //printf("Lside= %.10f , Rside=%.10f\n",leftSide,rightSide);
            //printf(" VSTUPY :x= %f , z=%f,z=%f LEFT SIDE= %f, RIGHT SIDE= %f\n",x,y,z,leftSide, rightSide);
            //printf("vysledok pod: %d\n",(leftSide-rightSide>0.1 || leftSide-rightSide> -0.1));
            // leftSide=leftSide*100;
            // leftSide=floor(leftSide);
            // leftSide/=100;
            //
            // rightSide=rightSide*100;
            // rightSide=floor(rightSide);
            // rightSide/=100;

            // leftSide=floor(leftSide-leftSide/10000);
            // rightSide=floor(rightSide-rightSide/10000);

            //-----------------------
            diff = leftSide - rightSide;
            if (diff < 0)
              diff *= -1;
            if (diff > 0.1)
            {
              //   printf("inner1= %f, inner2=%f, avg1=%f, firstBigL=%f, secondBigL=%f, leftSide=%f, inner3=%f, inner4=%f, avg2=%f, firstBigR=%f, secondBigR=%f, rightSide=%f", inner1, inner2, avg1, firstBigL, secondBigL, leftSide, inner3, inner4, avg2, firstBigR, secondBigR, rightSide);

              printf(" %s a %s, rozdil je: %f, x=%f,y=%f,z=%f\n", Nor[n], Nor[j], diff, x, y, z);
              //  printf(" VSTUPY :x= %f , y=%f,z=%f LEFT SIDE= %.10f, RIGHT SIDE= %.10f, firstBigR=, secondBigR= \n", x, y, z, leftSide, rightSide);

              //printf("LEFT: firstRes=%f,  firstBig=%f, secondBig=%f ,leftSide=%f ", firstRes, firstBig, secondBig, leftSide);
              // printf("RIGHT: firstRes=%f,  firstBig=%f, secondBig=%f ,leftSide=%f\n", secondRes, firstBig, secondBig, rightSide);
            }

            // if(abs(leftSide-rightSide)>0.01){
            //     printf(" WRONG  a normy jsou %s a %s",Nor[n],Nor[j]);
            //     printf(" VSTUPY :x= %f , y=%f,z=%f LEFT SIDE= %.10f, RIGHT SIDE= %.10f\n",x,y,z,leftSide, rightSide);
            // }

            //printf("Lside= %f , Rside=%f\n",leftSide,rightSide);
          }
        } ///////////////////////
      }
    }
  }
  //printf("tnorm = %f", TL(0.8, 0.8));
  /*
  printf("LEFT: firstRes=%f,  firstBig=%f, secondBig=%f ,leftSide=%f\n", firstRes, firstBig, secondBig, leftSide);
  printf("RIGHT: firstRes=%f,  firstBig=%f, secondBig=%f ,leftSide=%f\n", secondRes, firstBig, secondBig, rightSide);
*/
  return 0;
}