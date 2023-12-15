#ifndef __VEC_H__
#define __VEC_H__

#ifndef __COMMON_H_
#include "Common.h"
#endif // !__COMMON_H_

////////////////////////////////////////////////////////////////////////////////////////////////

template<size_t N, typename T>
struct vec
{
	vec() { for (size_t i = N; i--; _value[i] = T()); };
			T& operator[](const size_t i)		{ return _value[i]; };
	const	T& operator[](const size_t i)const	{ return _value[i]; };
private:
	T _value[N];
};

////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
struct vec<2, T>
{
	vec() :x(T()), y(T()) { };
	vec(T X, T Y) :x(X), y(Y) { };
	template<class U>vec<2, T>(const vec<2, U>& v);

			T& operator[](const size_t i)		{ return _value[i]; };
	const	T& operator[](const size_t i)const	{ return _value[i]; };

	union 
	{
		struct { T x, y; };
		struct { T u, v; };
		T _value[2];
	};
};

////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
struct vec<3, T>
{
	vec() :x(T()), y(T()), z(T()) { };
	vec(T X, T Y, T Z) :x(X), y(Y), z(Z) { };
	template<class U>vec<3, T>(const vec<3, U>& v);

			T& operator[](const size_t i)		{ return _value[i]; };
	const	T& operator[](const size_t i)const	{ return _value[i]; };

	float		norm()		const { return std::sqrt(x * x + y * y + z * z); };
	vec<3, T>	normalize()	const { return *this / norm(); };

	union
	{
		struct { T x, y, z; };
		struct { T r, g, b; };
		T _value[3];
	};
};

////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
struct vec<4, T>
{
	vec() :x(T()), y(T()), z(T()), w(T()) { };
	vec(T X, T Y, T Z, T W) :x(X), y(Y), z(Z), w(W) { };
	template<class U>vec<4, T>(const vec<4, U>& v);

			T& operator[](const size_t i)		{ return _value[i]; };
	const	T& operator[](const size_t i)const	{ return _value[i]; };

	union
	{
		struct { T x, y, z, w; };
		struct { T r, g, b, a; };
		T _value[4];
	};
};

////////////////////////////////////////////////////////////////////////////////////////////////

template<size_t N, typename T>
vec<N, T> operator+ (const vec<N, T>& l, const vec<N, T>& r)
{
	vec<N, T> ret{};
	for (size_t i = N; i--; ret[i] = l[i] + r[i]);
	return ret;
}

template<size_t N, typename T>
vec<N, T> operator- (const vec<N, T>& l, const vec<N, T>& r)
{
	vec<N, T> ret{};
	for (size_t i = N; i--; ret[i] = l[i] - r[i]);
	return ret;
}

template<size_t N, typename T, typename U>
vec<N, T> operator* (const vec<N, T>& l, const U r)
{
	vec<N, T> ret{};
	for (size_t i = N; i--; ret[i] = l[i] * r);
	return ret;
}

template<size_t N, typename T, typename U>
vec<N, T> operator* (const U l, const vec<N, T>& r)
{
	vec<N, T> ret{};
	for (size_t i = N; i--; ret[i] = l * r[i]);
	return ret;
}

template<size_t N, typename T>
T operator* (const vec<N, T>& l, const vec<N, T>& r)
{
	T ret{};
	for (size_t i = N; i--; ret += l[i] * r[i]);
	return ret;
}

template<size_t N, typename T, typename U>
vec<N, T> operator/ (const vec<N, T>& l, const U r)
{
	vec<N, T> ret{};
	for (size_t i = N; i--; ret[i] = l[i] / r);
	return ret;
}

template<typename T>
vec<3, T> operator^ (const vec<3, T>& l, const vec<3, T>& r)
{
	return vec<3, T>(
		l.y * r.z - l.z * r.y,
		l.z * r.x - l.x * r.z,
		l.x * r.y - l.y * r.x);
}

template<size_t N, typename T>
std::ostream& operator<<(std::ostream& stream, const vec<N, T>& v)
{
	for (size_t i = 0; i < N; i++)
		stream << v[i] << '\t';
	return stream;
}

////////////////////////////////////////////////////////////////////////////////////////////////

using Vec2f = vec<2, float>;
using Vec2i = vec<2, int>;
using Vec3f = vec<3, float>;
using Vec3i = vec<3, int>;
using Vec4f = vec<4, float>;
using Vec4i = vec<4, int>;

#endif // !__VEC_H__
