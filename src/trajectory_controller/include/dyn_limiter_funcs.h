#ifndef DYN_LIMITER_FUNCS_H
#define DYN_LIMITER_FUNCS_H

#include<math.h>
#include <iostream>
#include<vector>


int  cubic_eq_real_root (double a, double b, double c, double d, std::vector<double> &roots)
{
        if (a == 0.000)
        {
            throw(std::invalid_argument("The coefficient of the cube of x is 0. Please use the utility for a SECOND degree quadratic. No further action taken."));
            return 0;
        } //End if a == 0

        if (d == 0.000)
        {
//            throw(std::invalid_argument("One root is 0. Now divide through by x and use the utility for a SECOND degree quadratic to solve the resulting equation for the other two roots. No further action taken."));
            return 0;
        } //End if d == 0
//        std::cout<<"Eq info: "<<std::endl;
//        std::cout<< a <<", "<< b <<", "<< c <<", "<< d <<std::endl;
        b /= a;
        c /= a;
        d /= a;
        double disc, q, r, dum1, s, t, term1, r13;
        q = (3.0*c - (b*b))/9.0;
        r = -(27.0*d) + b*(9.0*c - 2.0*(b*b));
        r /= 54.0;
        disc = q*q*q + r*r;
        double root1 = 0; //The first root is always real.
        term1 = (b/3.0);
        if (disc > 1e-10) { // one root real, two are complex
//            std::cout<<"disc > 0, disc= "<< disc <<std::endl;
            s = r + sqrt(disc);
            s = ((s < 0) ? -pow(-s, (1.0/3.0)) : pow(s, (1.0/3.0)));
            t = r - sqrt(disc);
            t = ((t < 0) ? -pow(-t, (1.0/3.0)) : pow(t, (1.0/3.0)));
            double x1r= -term1 + s + t;
            term1 += (s + t)/2.0;
            double x3r = -term1,  x2r = -term1;
            term1 = sqrt(3.0)*(-t + s)/2;
            x2r = term1;
            double x3i = -term1;
            roots[0]= x1r;
            roots[1] = -100.0;
            roots[2]= -100.0;
            return 1;
        }
        // End if (disc > 0)
        // The remaining options are all real
        double x3i =0, x2r = 0;
        if (disc>=0.000 && disc< 1e-10){ // All roots real, at least two are equal.
//            std::cout<<"disc = 0 , disc= "<< disc <<std::endl;
            disc=0;
            r13 = ((r < 0) ? -pow(-r,(1.0/3.0)) : pow(r,(1.0/3.0)));
            double x1r= -term1 + 2.0*r13;
            double x3r = -(r13 + term1);
            x2r = -(r13 + term1);
            roots[0]= x1r;
            roots[1] = x2r;
            roots[2]= x3r;
            return 2;
        } // End if (disc == 0)
        // Only option left is that all roots are real and unequal (to get here, q < 0)
//        std::cout<<"disc < 0 , disc= "<< disc <<std::endl;
        q = -q;
        dum1 = q*q*q;
        dum1 = acos(r/sqrt(dum1));
        r13 = 2.0*sqrt(q);
        double x1r= -term1 + r13*cos(dum1/3.0);
        x2r = -term1 + r13*cos((dum1 + 2.0*M_PI)/3.0);
        double x3r = -term1 + r13*cos((dum1 + 4.0*M_PI)/3.0);
        roots[0]= x1r;
        roots[1] = x2r;
        roots[2]= x3r;
        return 3;
}  //End of cubicSolve



double compute_init_time(const double Ds, double &Tj, double &Ta, double &Tv, const double sm, const double vm, const double am, const double jm ){
    double Dthr1 = (am*vm)/jm + (vm*vm)/am ;
    double Dthr2 = 2*pow(am,3)/pow(jm,2);
    double Tjm= am/jm, Tam= vm/am - am/jm;
    if (Ds>= Dthr1){
        std::cout<<" init case 1 ... "<<std::endl;
        Tj= Tjm;
        Ta= Tam;
        Tv= (Ds-Dthr1)/vm;
    }
    else if(Ds>=Dthr2){
        std::cout<<" init case 3 ... "<<std::endl;
        Tj= Tjm;
        Ta= sqrt( (am*am/(4*jm)) + (Ds/am) ) - (3*am)/(2*jm);
        Tv= 0;
    }else {
        std::cout<<" init case 3 ... "<<std::endl;
        Tv=0;
        Ta=0;
        std::vector<double> rts;
        rts.resize(3);
        int sgn = (Ds>0)? 1:-1;
        int n_rts = cubic_eq_real_root (2*sgn*jm, 0.0, 0.0, -Ds, rts);
        Tj= rts[0];
    }
    return 4*Tj+2*Ta+Tv;
}








#endif // DYN_LIMITER_FUNCS_H
