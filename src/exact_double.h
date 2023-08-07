#pragma once

#include "mini-mpq.h"

#include <algorithm>

namespace Rational
{
	struct exact_double
	{
		bool init;
		mpq_t val;
	};

	inline static void
	exact_double_new(exact_double& self)
	{
		self.init = true;
		mpq_init(self.val);
	}

	inline static void
	exact_double_new(exact_double& self, const exact_double& other)
	{
		self.init = true;
		mpq_init(self.val);
		mpq_set(self.val, other.val);
	}

	inline static void
	exact_double_new(exact_double& self, double val)
	{
		self.init = true;
		mpq_init(self.val);
		mpq_set_d(self.val, val);
	}

	inline static void
	destruct(exact_double& self)
	{
		self.init = false;
		mpq_clear(self.val);
	}

	inline static void
	exact_double_set(exact_double& self, double val)
	{
		mpq_set_d(self.val, val);
	}

	inline static void
	exact_double_set(exact_double& self, const exact_double& other)
	{
		mpq_set(self.val, other.val);
	}

	// relational operators
	inline static bool
	operator==(const exact_double& a, const exact_double& b)
	{
		return mpq_equal(a.val, b.val) != 0;
	}

	inline static bool
	operator==(const exact_double& a, const double& b)
	{
		exact_double _b;
		exact_double_new(_b, b);

		bool result = mpq_equal(a.val, _b.val) != 0;

		destruct(_b);

		return result;
	}

	inline static bool
	operator==(const double& b, const exact_double& a)
	{
		exact_double _b;
		exact_double_new(_b, b);

		bool result =  mpq_equal(a.val, _b.val) != 0;

		destruct(_b);

		return result;
	}

	inline static bool
	operator!=(const exact_double& a, const exact_double& b)
	{
		return !(mpq_equal(a.val, b.val) != 0);
	}

	inline static bool
	operator!=(const exact_double& a, const double& b)
	{
		exact_double _b;
		exact_double_new(_b, b);

		bool result = !(mpq_equal(a.val, _b.val) != 0);

		destruct(_b);

		return result;
	}

	inline static bool
	operator!=(const double& b, const exact_double& a)
	{
		exact_double _b;
		exact_double_new(_b, b);

		bool result = !(mpq_equal(a.val, _b.val) != 0);

		destruct(_b);

		return result;
	}

	inline static bool
	operator>=(const exact_double& a, const exact_double& b)
	{
		return !(mpq_cmp(a.val, b.val) < 0);
	}

	inline static bool
	operator>=(const exact_double& a, const double& b)
	{
		exact_double _b;
		exact_double_new(_b, b);

		bool result = !(mpq_cmp(a.val, _b.val) < 0);

		destruct(_b);

		return result;
	}

	inline static bool
	operator<=(const exact_double& a, const exact_double& b)
	{
		return !(mpq_cmp(b.val, a.val) < 0);
	}

	inline static bool
	operator<=(const exact_double& a, const double& b)
	{
		exact_double _b;
		exact_double_new(_b, b);

		bool result = !(mpq_cmp(_b.val, a.val) < 0);

		destruct(_b);

		return result;
	}

	inline static bool
	operator<(const exact_double& a, const exact_double& b)
	{
		return mpq_cmp(a.val, b.val) < 0;
	}

	inline static bool
	operator<(const exact_double& a, const double& b)
	{
		exact_double _b;
		exact_double_new(_b, b);

		bool result = mpq_cmp(a.val, _b.val) < 0;

		destruct(_b);

		return result;
	}

	inline static bool
	operator>(const exact_double& a, const exact_double& b)
	{
		return mpq_cmp(b.val, a.val) < 0;
	}

	inline static bool
	operator>(const exact_double& a, const double& b)
	{
		exact_double _b;
		exact_double_new(_b, b);

		bool result = mpq_cmp(_b.val, a.val) < 0;

		destruct(_b);

		return result;
	}

	//
	inline static void
	exact_double_add(const exact_double& a, const exact_double& b, exact_double& result)
	{
		mpq_add(result.val, a.val, b.val);
	}

	inline static void
	exact_double_sub(const exact_double& a, const exact_double& b, exact_double& result)
	{
		mpq_sub(result.val, a.val, b.val);
	}

	inline static void
	exact_double_mul(const exact_double& a, const exact_double& b, exact_double& result)
	{
		mpq_mul(result.val, a.val, b.val);
	}

	inline static void
	exact_double_div(const exact_double& a, const exact_double& b, exact_double& result)
	{
		mpq_div(result.val, a.val, b.val);
	}

	inline static void
	exact_double_neg(exact_double& a)
	{
		mpq_neg(a.val, a.val);
	}

	inline static int
	exact_double_sgn(const exact_double& a)
	{
		return mpq_sgn(a.val);
	}

} // namespace Rational
