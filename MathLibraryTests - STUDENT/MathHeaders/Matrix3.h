#pragma once
#include "Vector3.h"
#include <string>
namespace MathClasses
{
    struct Matrix3
    {

        Matrix3(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9) {
            m1 = _m1;
            m2 = _m2;
            m3 = _m3;
            m4 = _m4;
            m5 = _m5;
            m6 = _m6;
            m7 = _m7;
            m8 = _m8;
            m9 = _m9;
        }

        Matrix3(float floatarray[]) {
            m1 = floatarray[0];
            m2 = floatarray[1];
            m3 = floatarray[2];
            m4 = floatarray[3];
            m5 = floatarray[4];
            m6 = floatarray[5];
            m7 = floatarray[6];
            m8 = floatarray[7];
            m9 = floatarray[8];
        }

        Matrix3() {
            m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m9 = 0.0f;
        }

        union {
            struct {
                float m1, m2, m3, m4, m5, m6, m7, m8, m9;
            };

            float v[9];
            float mm[3][3];

            Vector3 axis[3];
        };

        static Matrix3 MakeIdentity() {
            Matrix3 identity;
            identity.m1 = 1;
            identity.m2 = 0;
            identity.m3 = 0;
            identity.m4 = 0;
            identity.m5 = 1;
            identity.m6 = 0;
            identity.m7 = 0;
            identity.m8 = 0;
            identity.m9 = 1;
            return identity;
        }

        operator float* () { return v; }

        operator const float* () { return v; }

        Matrix3 Transposed() const {
            return Matrix3(m1, m4, m7, m2, m5, m8, m3, m6, m9);
        }

        std::string ToString() const {
            std::string str = std::to_string(v[0]);
            for (size_t i = 1; i < 9; i++) {
                str += ", " + std::to_string(v[i]);
            }
            return str;
        }

        float& operator [](int dim) {
            return v[dim];
        }

        const float& operator [](int dim) const {
            return v[dim];
        }

        Matrix3 operator *(Matrix3 rhs) const {
            Matrix3 result;

            for (size_t i = 0; i < 3; i++) {
                Vector3 row(mm[0][i], mm[1][i], mm[2][i]);

                for (size_t j = 0; j < 3; j++) {
                    result.mm[j][i] = row.Dot(rhs.axis[j]);
                }
            }
            return result;
        }

        Vector3 operator *(Vector3 rhs) const {
            return Vector3(
                Vector3(m1, m4, m7).Dot(rhs),
                Vector3(m2, m5, m8).Dot(rhs),
                Vector3(m3, m6, m9).Dot(rhs)
            );
        }

        bool operator ==(Matrix3 rhs) const {
            if (m1 == rhs.m1 && m2 == rhs.m2 && m3 == rhs.m3 && m4 == rhs.m4 && m5 == rhs.m5 && m6 == rhs.m6 && m7 == rhs.m7 && m8 == rhs.m8 && m9 == rhs.m9)
                return true;
            return false;
        }

        bool operator !=(Matrix3 rhs) const {
            if (m1 == rhs.m1 && m2 == rhs.m2 && m3 == rhs.m3 && m4 == rhs.m4 && m5 == rhs.m5 && m6 == rhs.m6 && m7 == rhs.m7 && m8 == rhs.m8 && m9 == rhs.m9)
                return false;
            return true;
        }
	};
}