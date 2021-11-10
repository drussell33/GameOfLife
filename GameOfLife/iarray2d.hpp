#ifndef IARRAY2D
#define IARRAY2D

#include "row.hpp"

namespace data_structures
{
	template <class T>
	class Row;

	template <class T>
	class IArray2D
	{
	public:
		virtual ~IArray2D() = default;
		virtual T Select(const int& row, const int& column) const noexcept(false) = 0;
		virtual T& Select(const int& row, const int& column) noexcept(false) = 0;
		virtual Row<T> operator[](const int& row) const noexcept(false) = 0;
		virtual Row<T> operator[](const int& row) noexcept(false) = 0;
		virtual explicit operator bool() const noexcept = 0;
		virtual size_t Rows() const noexcept = 0;
		virtual size_t Columns() const noexcept = 0;
		virtual void Rows(const size_t& rows) noexcept(false) = 0;
		virtual void Columns(const size_t& columns) noexcept(false) = 0;
	};

}
#endif