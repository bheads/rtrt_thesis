

#include <UnitTest++/UnitTest++.h>

#include <modules/vec4.h>
#include <modules/vec_func.h>
#include <modules/random.h>

#include <eigen3/Eigen/Dense>
typedef Eigen::Vector3f tvec;

#include <cmath>

#define ACC 0.00001

float length (vec4 &v);
vec4 normal (vec4 v);

SUITE (Vec4Tests)
{
	TEST (Construction)
	{
		vec4 a;
		CHECK_EQUAL (a.x, 0);
		CHECK_EQUAL (a.y, 0);
		CHECK_EQUAL (a.z, 0);
		CHECK_EQUAL (a.w, 0);
		vec4 b (1, 2, 3, 4);
		CHECK_EQUAL (b.x, 1);
		CHECK_EQUAL (b.y, 2);
		CHECK_EQUAL (b.z, 3);
		CHECK_EQUAL (b.w, 4);
		float data[4] = { 8, 9, 10, 11};
		vec4 c (data);
		CHECK_EQUAL (c.x, 8);
		CHECK_EQUAL (c.y, 9);
		CHECK_EQUAL (c.z, 10);
		CHECK_EQUAL (c.w, 11);
		vec4 d (33, false);
		CHECK_EQUAL (d.x, 33);
		CHECK_EQUAL (d.y, 33);
		CHECK_EQUAL (d.z, 33);
		CHECK_EQUAL (d.w, 0);
		vec4 e (45, true);
		CHECK_EQUAL (e.x, 45);
		CHECK_EQUAL (e.y, 45);
		CHECK_EQUAL (e.z, 45);
		CHECK_EQUAL (e.w, 45);
		vec4 f (e);
		CHECK_EQUAL (f.x, e.x);
		CHECK_EQUAL (f.y, e.y);
		CHECK_EQUAL (f.z, e.z);
		CHECK_EQUAL (f.w, e.w);
	}
	TEST (Assignment)
	{
		vec4 a (1, 2, 3, 4), b;
		CHECK_EQUAL (b.x, 0);
		CHECK_EQUAL (b.y, 0);
		CHECK_EQUAL (b.z, 0);
		CHECK_EQUAL (b.w, 0);
		b = a;
		CHECK_EQUAL (b.x, a.x);
		CHECK_EQUAL (b.y, a.y);
		CHECK_EQUAL (b.z, a.z);
		CHECK_EQUAL (b.w, a.w);
		b = 3.14;
		CHECK_CLOSE (b.x, 3.14, ACC);
		CHECK_CLOSE (b.y, 3.14, ACC);
		CHECK_CLOSE (b.z, 3.14, ACC);
		CHECK_CLOSE (b.w, 3.14, ACC);
	}
	TEST (Length)
	{
		vec4 a (5, 0, 0, 0), b (0, 10, 0, 0), c (0, 0, -19, 0), d (0, 0, 0, 2), e (0, 0, 0, 0);
		CHECK_CLOSE (length (a), a.length(), ACC);
		CHECK_CLOSE (length (b), b.length(), ACC);
		CHECK_CLOSE (length (c), c.length(), ACC);
		CHECK_CLOSE (length (d), d.length(), ACC);
		CHECK_CLOSE (length (e), e.length(), ACC);
		CHECK_CLOSE (5.0f, a.length(), ACC);
		CHECK_CLOSE (10.0f, b.length(), ACC);
		CHECK_CLOSE (19.0f, c.length(), ACC);
		CHECK_CLOSE (2.0f, d.w, ACC);
		CHECK_CLOSE (2.0f, d.length(), ACC);
		CHECK_CLOSE (0.0f, e.length(), ACC);
		tvec ta;
		vec tb;
		ta[0] = tb.x = Random::getf (-10000, 10000);
		ta[1] = tb.y = Random::getf (-10000, 10000);
		ta[2] = tb.z = Random::getf (-10000, 10000);
		CHECK_CLOSE (tb.length(), ta.norm(), ACC);
	}
	TEST (Length2)
	{
		vec4 a (4, 12, -23, 0), b (0, 10, -32, 12), c (41, 4, -19, 143.12), d (0, 0, -12, -1222.1), e (0.123, 23, 0, 1);
		CHECK_CLOSE (length (a), a.length(), ACC);
		CHECK_CLOSE (length (b), b.length(), ACC);
		CHECK_CLOSE (length (c), c.length(), ACC);
		CHECK_CLOSE (length (d), d.length(), ACC);
		CHECK_CLOSE (length (e), e.length(), ACC);
	}
	TEST (Normal)
	{
		vec4 a (1, 0, 0, 0), b (0, 1, 0, 0), c (0, 0, 1, 0), d (0, 0, 0, 1);
		CHECK_CLOSE (1.0f, a.normalize().length(), ACC);
		CHECK_CLOSE (1.0f, b.normalize().length(), ACC);
		CHECK_CLOSE (1.0f, c.normalize().length(), ACC);
		CHECK_CLOSE (1.0f, d.normalize().length(), ACC);
		vec4 aa (23, -1, 1234, -.23), bb (85, 0, 76, -32789), cc (064, 0.0234234, 0, -3), dd (23, 1, 64.2, 0);
		CHECK_CLOSE (1.0f, aa.normalize().length(), ACC);
		CHECK_CLOSE (1.0f, bb.normalize().length(), ACC);
		CHECK_CLOSE (1.0f, cc.normalize().length(), ACC);
		CHECK_CLOSE (1.0f, dd.normalize().length(), ACC);
		tvec ta;
		vec tb;
		ta[0] = tb.x = Random::getf (-10000, 10000);
		ta[1] = tb.y = Random::getf (-10000, 10000);
		ta[2] = tb.z = Random::getf (-10000, 10000);
		CHECK_CLOSE (ta.normalized().norm(), tb.fnormalize().length(), 0.001);
	}
	TEST (Normal2)
	{
		{
			vec4 a (123.4, -123.0, 0.231, 0), b = a.normalize(), c = normal (a);
			CHECK_CLOSE (b.x, c.x, ACC);
			CHECK_CLOSE (b.y, c.y, ACC);
			CHECK_CLOSE (b.z, c.z, ACC);
			CHECK_CLOSE (b.w, c.w, ACC);
		}
		vec4 a (M_PI, 0, M_PI_2, M_PI_4), b = a.normalize(), c = normal (a);
		CHECK_CLOSE (b.x, c.x, ACC);
		CHECK_CLOSE (b.y, c.y, ACC);
		CHECK_CLOSE (b.z, c.z, ACC);
		CHECK_CLOSE (b.w, c.w, ACC);
	}
	TEST (FastNormal)
	{
		vec4 a (1, 0, 0, 0), b (0, 1, 0, 0), c (0, 0, 1, 0), d (0, 0, 0, 1);
		CHECK_CLOSE (1.0f, a.fnormalize().length(), 0.001);
		CHECK_CLOSE (1.0f, b.fnormalize().length(), 0.001);
		CHECK_CLOSE (1.0f, c.fnormalize().length(), 0.001);
		CHECK_CLOSE (1.0f, d.fnormalize().length(), 0.001);
		vec4 aa (23, -1, 1234, -.23), bb (85, 0, 76, -32789), cc (064, 0.0234234, 0, -3), dd (23, 1, 64.2, 0);
		CHECK_CLOSE (1.0f, aa.fnormalize().length(), 0.001);
		CHECK_CLOSE (1.0f, bb.fnormalize().length(), 0.001);
		CHECK_CLOSE (1.0f, cc.fnormalize().length(), 0.001);
		CHECK_CLOSE (1.0f, dd.fnormalize().length(), 0.001);
		tvec ta;
		vec tb;
		ta[0] = tb.x = Random::getf (-10000, 10000);
		ta[1] = tb.y = Random::getf (-10000, 10000);
		ta[2] = tb.z = Random::getf (-10000, 10000);
		CHECK_CLOSE (ta.normalized().norm(), tb.fnormalize().length(), 0.001);
	}
	TEST (FastNormal2)
	{
		{
			vec4 a (123.4, -123.0, 0.231, 0), b = a.fnormalize(), c = normal (a);
			CHECK_CLOSE (b.x, c.x, 0.001);
			CHECK_CLOSE (b.y, c.y, 0.001);
			CHECK_CLOSE (b.z, c.z, 0.001);
			CHECK_CLOSE (b.w, c.w, 0.001);
		}
		vec4 a (M_PI, 0, M_PI_2, M_PI_4), b = a.fnormalize(), c = normal (a);
		CHECK_CLOSE (b.x, c.x, 0.001);
		CHECK_CLOSE (b.y, c.y, 0.001);
		CHECK_CLOSE (b.z, c.z, 0.001);
		CHECK_CLOSE (b.w, c.w, 0.001);
	}
}


float length (vec4 &v)
{
	float ret = v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
	return (sqrtf (ret));
}


vec4 normal (vec4 v)
{
	return v / length (v);
}

