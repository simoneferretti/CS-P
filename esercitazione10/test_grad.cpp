#include <iostream>
#include <Eigen/Dense>
#include "gc.hpp"

int main() {
	using namespace Eigen;

	double tol;
	std::cout << "Inserire tolleranza: ";
	std::cin >> tol;

	if (tol <= 0) {
		std::cerr <<"La tolleranza non èuò essere negativa\n";
		return EXIT_FAILURE;
	}

	bool flag = true;

	MatrixXd A(3,3);

	A(0, 0) = 1; A(0, 1) = 0; A(0, 2) = 0;
	A(1, 0) = 0; A(1, 1) = 1; A(1, 2) = 0;
	A(2, 0) = 0; A(2, 1) = 0; A(2, 2) = 1;

	VectorXd x_esatta(3);
	x_esatta(0) = 1;
	x_esatta(1) = 2;
	x_esatta(2) = 3;
	VectorXd b(3);
	b = A*x_esatta;

	VectorXd x01(3);
	x01(0) = 0;
	x01(1) = 0;
	x01(2) = 0;

	std::pair<Eigen::VectorXd, Eigen::VectorXd> result = gradiente_coniugato(A,x01,b, tol);
	VectorXd x_result = result.first;
	VectorXd residuo = result.second;
	std::cout << "\nTest Identità'\n";
	std::cout << "Soluzione calcolata:\n" << x_result << "\n";

	if (residuo.norm() > tol) {
		flag = false;
	}

	/*Matrice di Hilbert*/

	MatrixXd H(3,3);

	H(0, 0) = 1.0;       H(0, 1) = 1.0 / 2.0; H(0, 2) = 1.0 / 3.0;
	H(1, 0) = 1.0 / 2.0; H(1, 1) = 1.0 / 3.0; H(1, 2) = 1.0 / 4.0;
	H(2, 0) = 1.0 / 3.0; H(2, 1) = 1.0 / 4.0; H(2, 2) = 1.0 / 5.0;

	VectorXd x_esatta2(3);
	x_esatta2(0) = 1;
	x_esatta2(1) = 2;
	x_esatta2(2) = 3;
	VectorXd b2(3);
	b2 = H*x_esatta2;

	VectorXd x02(3);
	x02(0) = 0;
	x02(1) = 0;
	x02(2) = 0;

	std::pair<Eigen::VectorXd, Eigen::VectorXd> result2 = gradiente_coniugato(H,x02,b2, tol);
	VectorXd x_result2 = result2.first;
	VectorXd residuo2 = result2.second;
	std::cout << "\nTest Hilbert\n";
	std::cout << "Soluzione calcolata:\n" << x_result2 << "\n";

	if (residuo2.norm() > tol) {
		flag = false;
	}

	if (flag) {
		return EXIT_SUCCESS;
	}
	else {return EXIT_FAILURE;}
}