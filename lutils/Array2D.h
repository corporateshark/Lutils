/**
 * \file Array2D.h
 * \brief
 *
 * Access a 1D array (vector) as a 2D array
 *
 * \version 1.0.0
 * \date 04/03/2023
 * \author Sergey Kosarevsky, 2023
 * \author support@linderdaum.com   http://www.linderdaum.com   http://blog.linderdaum.com
 * https://github.com/corporateshark/lutils
 */


#pragma once

#include "Macros.h"

namespace ldr {

template <typename T> class Array2D
{
 public:
	typedef typename T::value_type value_type;

 public:
	Array2D() = delete;
	Array2D(size_t w, size_t h)
	: width_(w)
	, height_(h)
	, container_(w * h)
	{
	}
	Array2D(const Array2D<T>& other)
	: width_(other.width_)
	, height_(other.height_)
	, container_(other.container_)
	{
	}
	Array2D(Array2D<T>&& other)
	: width_(other.width_)
	, height_(other.height_)
	, container_(std::move(other.container_))
	{
	}
	LFORCEINLINE const value_type& operator()(size_t i, size_t j) const { return container_[j * width_ + i]; };
	LFORCEINLINE value_type& operator()(size_t i, size_t j) { return container_[j * width_ + i]; };
	LFORCEINLINE value_type at(size_t i, size_t j) const { return container_[j * width_ + i]; }; // a workaround for std::vector<bool>
	LFORCEINLINE void set(size_t i, size_t j, const value_type& val) { container_[j * width_ + i] = val; };
	LFORCEINLINE size_t getWidth() const { return width_; }
	LFORCEINLINE size_t getHeight() const { return height_; }

 private:
	size_t width_ = 0;
	size_t height_ = 0;
	T container_;
};

} // namespace ldr
