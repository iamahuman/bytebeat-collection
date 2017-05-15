#include<math.h>

double s(double,double);double r(double,double);double d(double);double f(double);

char bytebeat(int t){return (d(f(t/4000.)/3) + 1) * 63;}
double f(double t){
  double sn=s(1./2,t-1); sn*=(sn*sn);
  return 3*s(1./4,1/s(1,t))+3*s(4,1/sn)/2+s(4,1/(sn*sn*sn*sn*sn))/4
       +2*s(55+18.3*r(1./2,t),t)+s(110+s(5,t)/4000,t)*s(1,t)+s(220+110*r(1,t)+55*r(3,t),t)/5
       +s(880+440*r(1./2,t)-220*r(1,t)+110*r(2,t)+s(5,t)/4000,t)
       *(2+s(1760+438*r(3./2,t)-1234*r(2,t)+423*r(5,t),t))/9
       +s(s(1,t)+s(1./2,t)+s(1./4,t)+s(1./8,t),t)*s(s(1,t)+s(1./2,t)+s(1./4,t)+s(1./8,t)+1,t)
       +r(264+11*r(1./20,t),t)*s(1./20,t);
}
double s(double f,double t){return d(sin(f*3.14159265*(t+999)));}
double r(double f,double t){return s(f,t)<0;}
double d(double a){return tanh(a+a*a/4);}

main(t){for(;;++t)putchar(bytebeat(t));}
