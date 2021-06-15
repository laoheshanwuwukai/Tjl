#pragma once
#include <unsupported/Eigen/MatrixFunctions>
using namespace Eigen;

class CalibrationMath
{
public:
	CalibrationMath();
	~CalibrationMath();

private:


	Matrix3d Calibration(Matrix3d A1, Matrix3d B1, Matrix3d A2, Matrix3d B2);
	Vector3d inv_skew(Matrix3d A);

};

CalibrationMath::CalibrationMath()
{
}

CalibrationMath::~CalibrationMath()
{
}