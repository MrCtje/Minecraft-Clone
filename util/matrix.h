#ifndef MATRIX_H
#define MATRIX_H
#include <math.h>
#include <string.h>

static const double PI = 3.1415;
namespace util {
typedef struct{
    float m[16];
}Matrix;

typedef struct{
    float Position[4];
    float Color[4];
}Vertex;

extern const Matrix IDENTITY_MATRIX;

float Cotangent(float angle);
float DegreesToRadians(float degrees);
float RadiansToDegrees(float radians);

Matrix MultiplyMatrices(const Matrix* m1, const Matrix* m2);
void RotateAboutX(Matrix *m, float angle);
void RotateAboutY(Matrix *m, float angle);
void RotateAboutZ(Matrix *m, float angle);
void ScaleMatrix(Matrix *m, float x, float y, float z);
void TranslateMatrix(Matrix *m, float x, float y, float z);
void Rotate(Matrix *m, float x, float y, float z);
Matrix CreateProjectionMatrix(float fov, float aspect_ratio, float near_plane, float far_plane);
}
#endif // MATRIX_H
