#include <cmath>
#include <iostream>
#include <Eigen/Dense>
#include "tridiagonal.h"

/*******************************************************************************
 * Numerical Recipes' implementation of a method for solving tridiagonal
 * systems of linear equations.
 *
 *
 * @param a Lower offdiagonal.
 * @param b Diagonal.
 * @param c Upper offdiagonal.
 * @param r Right-hand side vector.
 ******************************************************************************/
void tridag(const Eigen::VectorXf& a, const Eigen::VectorXf& b,
            const Eigen::VectorXf& c, const Eigen::VectorXf& r,
            Eigen::VectorXf& u)
{
    int j;
    double bet;
    int n = a.size();
    Eigen::VectorXf gam(n);

    if (b[0] == 0.0) std::cout << "Error 1 in tridag" << std::endl;
    u[0] = r[0]/(bet=b[0]);

    for (j = 1; j < n; j++) {
        gam[j] = c[j-1]/bet;
        bet = b[j]-a[j]*gam[j];
        if (bet == 0.0) std::cout << "Error 2 in tridag" << std::endl;
        u[j] = (r[j]-a[j]*u[j-1])/bet;
    }

    for (j = (n-2); j >= 0; j--) u[j] -= gam[j+1]*u[j+1];
}
