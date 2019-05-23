#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;
  double m = 7294.29;
  double q = 2.0;
  double dt = 0.1;
  double v_iniX=0;
  double v_iniY=1;
  double pos_iniX=1;
  double pos_iniY=0;
  double y1(double vel){
    return vel;
  }
  double y2(double t, double E){
    double y2a=(q*E/m);
    return y2a;
  }
  void matrizK_runge_kutta4( double t, double &u1, double &v1,double &u2,double &v2 ){

  	double matrizK[4][4];

  	matrizK[0][0] = y1(v1);
  	matrizK[0][3] = y2_1(t, u1, u2, v1, omega);

  	matrizK[1][0] = y1(v1+0.5*matrizK[0][3]*dt);
  	matrizK[1][3] = y2_1(t+0.5*dt,u1+0.5*matrizK[0][0]*dt, u2+0.5*matrizK[0][1]*dt, v1+0.5*matrizK[0][3]*dt, omega );

  	matrizK[2][0] = y1(v1+0.5*matrizK[1][3]*dt);
  	matrizK[2][3] = y2_1(t+0.5*dt, u1+0.5*matrizK[1][0]*dt, u2+0.5*matrizK[1][1]*dt, v1+0.5*matrizK[1][3]*dt, omega );

  	matrizK[3][0] = y1(v1+matrizK[2][3]*dt);
  	matrizK[3][3] = y2_1(t+dt, u1+matrizK[2][0]*dt, u2+matrizK[2][1]*dt, v1+matrizK[2][3]*dt, omega );


  	u1 += ( matrizK[0][0] + 2*(matrizK[1][0] + 2*matrizK[2][0]) + matrizK[3][0] )*(1/6.0)*dt;
  	u2 += ( matrizK[0][1] + 2*(matrizK[1][1] + 2*matrizK[2][1]) + matrizK[3][1] )*(1/6.0)*dt;
  	v1 += ( matrizK[0][3] + 2*(matrizK[1][3] + 2*matrizK[2][3]) + matrizK[3][3] )*(1/6.0)*dt;
  	v2 += ( matrizK[0][4] + 2*(matrizK[1][4] + 2*matrizK[2][4]) + matrizK[3][4] )*(1/6.0)*dt;
  }

  int main( ){
    //Se abre el archivo donde van a ser guardados los datos
    ofstream datos1;
    datos1.open("RungeKutta.dat");
    //Se crean condiciones iniciales para los tres cuerpos y omega
    double v1=0;
    double v2=1;
    double u1=1;
    double u2=0;
    for( double t = 0.0; t < 100; t += dt ){
      matrizK_runge_kutta4(t, u1, u2,v1,v2);
      datos1 << t << " " << u1 << " " << u2 << endl;
    }
    datos1.close();
    return 0;
  }
