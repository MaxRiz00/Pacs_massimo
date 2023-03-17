#include <cmath>
#include <iostream>
#include <functional>
#include <vector>
#include "basicZeroFun.hpp"


class CauchySolver{

private:

    size_t N; // number of steps

    double y0; // initial condition

    double T; // final time

    std::function<double(double ,double )> f; // function f

    double theta = 0.5;


public:

    // Constructor
    CauchySolver(size_t n_steps, double init_cond, double final_time,std::function<double(double,double)> force,double th):
        N(n_steps), y0(init_cond), T(final_time),f(force), theta(th) {};


    // solver

    std::pair<std::vector<double>, std::vector<double>> solver();


};