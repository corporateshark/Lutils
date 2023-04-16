﻿/**
 * \file lmathTests.cpp
 * \brief
 *
 * lmath tests
 *
 * \version 1.0.0
 * \date 15/03/2023
 * \author Sergey Kosarevsky, 2023
 * \author support@linderdaum.com   http://www.linderdaum.com   http://blog.linderdaum.com
 * https://github.com/corporateshark/lutils
 */

#include <gtest/gtest.h>
#include <lmath/Vector.h>

namespace ltests
{

GTEST_TEST(lmath, vec2_constructors)
{
	const float value = 32167.0f;
	vec2 v(value);

	ASSERT_TRUE(v.x == value);
	ASSERT_TRUE(v.y == value);

	v = vec2(1.0f, 2.0f);

	ASSERT_TRUE(v.x == 1.0f);
	ASSERT_TRUE(v.y == 2.0f);
}

GTEST_TEST(lmath, vec2_arithmetic)
{
	vec2 v = vec2(1.0f, 2.0f) + vec2(3.0f, 5.0f);

	ASSERT_TRUE(v.x == 4.0f);
	ASSERT_TRUE(v.y == 7.0f);

	v -= vec2(1.0f);

	ASSERT_TRUE(v.x == 3.0f);
	ASSERT_TRUE(v.y == 6.0f);

	v *= vec2(2.0f, 2.0f);

	ASSERT_TRUE(v.x == 6.0f);
	ASSERT_TRUE(v.y == 12.0f);

	v /= vec2(3.0f, 6.0f);

	ASSERT_TRUE(v.x == 2.0f);
	ASSERT_TRUE(v.y == 2.0f);

	const float f = dot(vec2(5.0f, 7.0f), vec2(3.0f, 9.0f));

	ASSERT_TRUE(f == (5.0f * 3.0f) + (7.0f * 9.0f));
}

GTEST_TEST(lmath, vec2_functions)
{
	ASSERT_TRUE(vec2(2.0f, 0.0f).length() == 2.0f);
	ASSERT_TRUE(vec2(0.0f, 2.0f).length() == 2.0f);
	ASSERT_TRUE(vec2(1.0f, 1.0f).sqrLength() == 2.0f);
	ASSERT_TRUE(vec2(3.0f, 5.0f).sum() == 8.0f);
	ASSERT_TRUE(vec2(3.0f, 5.0f).avg() == 4.0f);
	ASSERT_TRUE(vec2(3.0f, 5.0f).stdDev() == 1.0f);
	ASSERT_TRUE(vec2(2.0f, 0.0f).getNormalized().x == 1.0f);
	ASSERT_TRUE(vec2(0.0f, 2.0f).getNormalized().y == 1.0f);

	vec2 v1(3.0f, 5.0f);
	vec2 v2(2.0f, 6.0f);

	vec2 vmin = v1.getMinVector(v2);
	ASSERT_TRUE(vmin.x == 2.0f && vmin.y == 5.0f);

	vec2 vmax = v1.getMaxVector(v2);
	ASSERT_TRUE(vmax.x == 3.0f && vmax.y == 6.0f);

	v1 = vec2(10, -5);
	v2 = v1.getOrthogonalVector();
	ASSERT_TRUE(dot(v1, v2) == 0.0f);

	v2 = vec2(1.0f, 2.0f) * vec2(0.0f);
	ASSERT_TRUE(v2.isZeroVector(LMATH_EPSILON));

	v2 = vec2(-128, +128).saturate();
	ASSERT_TRUE(v2.x == 0.0f && v2.y == 1.0f);

	ASSERT_TRUE(vec2(-3.0f, 1.0f).abs().x == 3.0f);
	ASSERT_TRUE(vec2(1.0f, -3.0f).abs().y == 3.0f);

	v1 = vec2(1.0f, 2.0f);
	v2 = v1.yx();
	ASSERT_TRUE(v2.x == 2.0f && v2.y == 1.0f);
	ASSERT_TRUE(v1 == v2.yx());
}

} // namespace ltests