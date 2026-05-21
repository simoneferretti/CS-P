#pragma once
#include<Eigen/Dense>
#include<stdexcept>

std::pair<Eigen::VectorXd, Eigen::VectorXd> gradiente_coniugato(const Eigen::MatrixXd& A, Eigen::VectorXd& x0, const Eigen::VectorXd& b, const double& tol) {
    if (A.rows()!=A.cols()) {
        throw std::invalid_argument("A non è quadrata!");
    }

    if (A.rows()!=b.size() || x0.size() != b.size()) {
        throw std::invalid_argument("Dimensioni incompatibili");
    }
	size_t kmax = 3*x0.size(); 
	Eigen::VectorXd r0 = b-A*x0;
	Eigen::VectorXd p0 = r0;
	size_t k = 0;
	while (r0.norm()>tol && k < kmax) {
		double alfanum = (p0.transpose()*r0);
		double alfaden = (p0.transpose()*A*p0);
		double alfa = alfanum/alfaden;
		x0 += alfa*p0;
		r0 = b - A*x0;
		double betanum = p0.transpose()*A*r0;
		double betaden = p0.transpose()*A*p0;
		double beta = betanum/betaden;
		p0 = r0 - beta*p0;
		k++;
	}
	return std::pair<Eigen::VectorXd, Eigen::VectorXd> {x0, r0};
}

