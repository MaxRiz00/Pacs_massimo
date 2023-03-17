#include "CauchySolver.hpp"

std::pair<std::vector<double>, std::vector<double>> CauchySolver::solver(){

        double h=T/N;

        std::vector<double> u(N), t(N);
        u[0]=y0;
        t[0]=0;
        
        double x,tt,uu;


        for(size_t i=0; i<N; i++){

            tt=t[i];
            uu=u[i];

            auto foo =[this,&h,&tt,&uu](double x) {return x - h*(theta*f(tt+h,x)+
                               (1-theta)*f(tt ,uu))-uu;}; 

            x = std::get<0>(apsc::secant(foo, -1 , 1));

           u[i+1]=x;
           t[i+1]=t[i]+h;
        }

        return std::make_pair(t,u);

    }