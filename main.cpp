#include <iostream>
#include <fstream>
#include <string>
#include "CauchySolver.hpp"

double test_function(double t, double y){
    return -t*exp(-y);
}

int main() {

    size_t n_steps=100;
    double init_cond=0;
    double final_time=1.;


    CauchySolver P1(n_steps,init_cond,final_time,test_function);

    auto solution= P1.solver();

    for (auto & i: solution.second){
        std::cout<<i<<std::endl;
    }


    std::ofstream fw("result.txt",std::ofstream::out);

    //check if file was successfully opened for writing
    if (fw.is_open()) {

    //store array contents to text file

    fw<<"n\t"<<"t_n\t"<<"u_n\n";

    for (int i = 0; i < n_steps; i++) 
        fw <<i+1<<"\t"<<solution.first[i]<<"\t"<<solution.second[i]<<"\n";
    
    fw.close();
    }
    else std::cout << "Problem with opening file";






    return 0;
}

   
