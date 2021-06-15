#include <unsupported/Eigen/MatrixFunctions>
#include <iostream>

using namespace Eigen;
using namespace std;


Vector3d inv_skew(Matrix3d A);
Matrix3d Calibration(Matrix3d A1, Matrix3d B1, Matrix3d A2, Matrix3d B2);
void test();
void testsvd();

int main()
{
    test();
    testsvd();
    cin.get();
}

void test() 
{
    Matrix3d A1, B1, A2, B2, R;

    cout << "Calibration_test" << endl;
    A1 << -0.989992, -0.141120, 0.000000,
           0.141120, -0.989992, 0.000000,
           0.000000, 0.000000, 1.000000;
    B1 << -0.989992, -0.138307, 0.028036,
           0.138307, -0.911449, 0.387470,
          -0.028036, 0.387470, 0.921456;
    A2 << 0.070737, 0, 0.997495,
            0, 1, 0,
        -0.997495, 0, 0.070737;
    B2 << 0.070737, 0.198172, 0.997612,
        -0.198172, 0.963323, -0.180936,
        -0.977612, -0.180936, 0.107415;
    R  = Calibration(A1, B1, A2, B2);
    cout << R<<endl;


    cout << endl;
    cout << endl;
}


Matrix3d Calibration(Matrix3d A1, Matrix3d B1, Matrix3d A2, Matrix3d B2)
{
    Matrix3d R , A, B;
    Vector3d alpha1, alpha2 ,alpha3;
    Vector3d  beta1,  beta2,  beta3;

    A1 = A1.log();
    A2 = A2.log();
    B1 = B1.log();
    B2 = B2.log();

    alpha1 = inv_skew(A1); // column
    alpha2 = inv_skew(A2);
    alpha3 = alpha1.cross(alpha2); // column

    beta1 = inv_skew(B1);
    beta2 = inv_skew(B2);
    beta3 = beta1.cross(beta2);

    A << alpha1, alpha2, alpha3;
    B << beta1, beta2, beta3;
    R = A * (B.inverse());

    return R;
}

Vector3d inv_skew(Matrix3d A)
{
    Vector3d n;
    n(0) = A(2, 1);
    n(1) = A(0, 2);
    n(2) = A(1, 0);
    return n;
}

void testsvd(void) {
    Matrix3f A;
    A(0, 0) = 1, A(0, 1) = 0, A(0, 2) = 1;
    A(1, 0) = 0, A(1, 1) = 1, A(1, 2) = 1;
    A(2, 0) = 0, A(2, 1) = 0, A(2, 2) = 0;
    JacobiSVD<Eigen::MatrixXf> svd(A, ComputeThinU | ComputeThinV);
    Matrix3f V = svd.matrixV(), U = svd.matrixU();
    Matrix3f  S = U.inverse() * A * V.transpose().inverse(); // S = U^-1 * A * VT * -1  

    cout << "SVD_test" << endl;
    std::cout << "A :\n" << A << std::endl;
    std::cout << "U :\n" << U << std::endl;
    std::cout << "S :\n" << S << std::endl;
    std::cout << "V :\n" << V << std::endl;
    std::cout << "U * S * VT :\n" << U * S * V.transpose() << std::endl;
   

}