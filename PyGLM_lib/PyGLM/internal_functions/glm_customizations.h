#pragma once

#include "../compiler_setup.h"

namespace glm {
	namespace custom {
		template<typename T>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR T dot(T x, T y)
		{
			return x * y;
		}

		template<length_t L, typename T, qualifier Q>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR T dot(vec<L, T, Q> const& x, vec<L, T, Q> const& y)
		{
			return detail::compute_dot<vec<L, T, Q>, T, detail::is_aligned<Q>::value>::call(x, y);
		}

		template<typename T, qualifier Q>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR T dot(qua<T, Q> const& x, qua<T, Q> const& y)
		{
			GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559 || GLM_CONFIG_UNRESTRICTED_FLOAT, "'dot' accepts only floating-point inputs");
			return detail::compute_dot<qua<T, Q>, T, detail::is_aligned<Q>::value>::call(x, y);
		}

		template<int C, int R, typename T, qualifier Q>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<C, R, T, Q>::col_type mat_mul
		(
			mat<C, R, T, Q> const& m,
			typename mat<C, R, T, Q>::row_type const& v
		)
		{
			return m * v;
		}

		template<int C, int R, typename T, qualifier Q>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<C, R, T, Q>::row_type mat_mul
		(
			typename mat<C, R, T, Q>::col_type const& v,
			mat<C, R, T, Q> const& m
		)
		{
			return v * m;
		}

		template<typename T, qualifier Q>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<3, 3, T, Q>::row_type mat_mul(typename mat<3, 3, T, Q>::col_type const& v, mat<3, 3, T, Q> const& m)
		{
			return typename mat<3, 3, T, Q>::row_type(
				glm::custom::dot(m[0], v),
				glm::custom::dot(m[1], v),
				glm::custom::dot(m[2], v));
		}

		template<typename T, qualifier Q>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 4, T, Q>::row_type mat_mul
		(
			typename mat<4, 4, T, Q>::col_type const& v,
			mat<4, 4, T, Q> const& m
		)
		{
			return typename mat<4, 4, T, Q>::row_type(
				glm::custom::dot(m[0], v),
				glm::custom::dot(m[1], v),
				glm::custom::dot(m[2], v),
				glm::custom::dot(m[3], v));
		}
	}
}
