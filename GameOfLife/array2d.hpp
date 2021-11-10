#ifndef array_2d_HPP
#define array_2d_HPP


#include "array.hpp"
#include "iarray2d.hpp"

namespace data_structures
{
	template <class T>
	class Array2D final : public IArray2D<T>
	{
	public:
		Array2D();
		~Array2D() = default;
		explicit Array2D(const size_t& rows, const size_t& columns) noexcept(false);
		Array2D(const Array2D& copy) noexcept(false);
		Array2D& operator=(const Array2D& copy) noexcept(false);
		Array2D(Array2D&& copy) noexcept;
		Array2D& operator=(Array2D&& copy) noexcept;
		T Select(const int& row, const int& column) const override;
		T& Select(const int& row, const int& column) override;
		Row<T> operator[](const int& row_index) const noexcept(false) override;
		Row<T> operator[](const int& row_index) noexcept(false) override;
		explicit operator bool() const noexcept override;
		size_t Rows() const noexcept override;
		size_t Columns() const noexcept override;
		void Rows(const size_t& rows) noexcept(false) override;
		void Columns(const size_t& columns) noexcept(false) override;

		bool operator==(const Array2D<T>& rhs) const noexcept;
	private:
		Array<T> storage_;
		size_t rows_{ 0 };
		size_t columns_{ 0 };
	};


	template<class T>
	Array2D<T>::Array2D()
	{
	}


	template<class T>
	Array2D<T>::Array2D(const size_t& rows, const size_t& columns) noexcept(false)
		:storage_(rows* columns), rows_(rows), columns_(columns) //inline initializer
	{

	}

	template<class T>
	Array2D<T>::Array2D(const Array2D& copy) noexcept(false)
	{
		*this = copy;
	}

	template<class T>
	Array2D<T>& Array2D<T>::operator=(const Array2D& copy) noexcept(false)
	{
		if (this != &copy)
		{
			storage_ = copy.storage_; //calls Array's operator=
			rows_ = copy.rows_;
			columns_ = copy.columns_;
		}
		return *this;
	}

	template<class T>
	inline Array2D<T>::Array2D(Array2D&& copy) noexcept
	{
		*this = copy;
	}

	template<class T>
	Array2D<T>& Array2D<T>::operator=(Array2D&& copy) noexcept
	{
		if (this != &copy)
		{
			storage_ = std::move(copy.storage_);
			rows_ = copy.rows_;
			columns_ = copy.columns_;
		}
		return *this;
	}

	template<class T>
	T Array2D<T>::Select(const int& row, const int& column) const
	{
		//same code for the next one.
		const auto actual_index = ((row * columns_) + column);
		return storage_[actual_index];
	}

	template<class T>
	T& Array2D<T>::Select(const int& row, const int& column)
	{
		// Will this work for the other dimensions such as a 3 X 5

		const auto actual_index = ((row * columns_) + column);

		return storage_[actual_index];
	}

	template<class T>
	Row<T> Array2D<T>::operator[](const int& row_index) const noexcept(false)
	{
		if (!storage_)
			throw AdtException("WRONG!");
		return Row<T>(*this, row_index);
	}

	template<class T>
	Row<T> Array2D<T>::operator[](const int& row_index) noexcept(false)
	{
		if (!storage_)
			throw AdtException("WRONG!");
		return Row<T>(*this, row_index);
	}

	template<class T>
	Array2D<T>::operator bool() const noexcept
	{
		return columns_ > 0 && rows_ > 0;
	}

	template<class T>
	size_t Array2D<T>::Rows() const noexcept
	{
		return rows_;
	}

	template<class T>
	size_t Array2D<T>::Columns() const noexcept
	{
		return columns_;
	}

	template<class T>
	void Array2D<T>::Rows(const size_t& rows) noexcept(false)
	{
		Array<T> temp = Array<T>(columns_ * rows);

		auto const shorter_row = rows_ < rows ? rows_ : rows;

		for (size_t i = 0u; i < shorter_row * columns_; ++i)
		{
			temp[i] = storage_[i];
		}

		storage_ = temp;

		rows_ = rows;
	}

	template<class T>
	void Array2D<T>::Columns(const size_t& columns) noexcept(false)
	{
		Array<T> temp = Array<T>(rows_ * columns);

		auto const shorter_columns = columns_ < columns ? columns_ : columns;

		auto current_column = 0;
		auto rollback_index = 0;
		for (size_t i = 0u; i < columns * rows_; ++i)
		{
			if (current_column < shorter_columns)
			{
				temp[i] = storage_[i + rollback_index];
			}
			else
			{
				++rollback_index;
				temp[i] = storage_[i + rollback_index];
				current_column = 0;
			}
			++current_column;
		}

		storage_ = temp;

		columns_ = columns;
	}

	template<class T>
	bool Array2D<T>::operator==(const Array2D<T>& rhs) const noexcept
	{
		if (rows_ != rhs.rows_ || columns_ != rhs.columns_)
		{
			return false;
		}

		for (auto i = 0; i < rows_; ++i)
		{
			for (auto j = 0; j < columns_; ++j)
			{
				if (storage_[i][j] != rhs.storage_[i][j])
					return false;
			}
		}

		return true;
	}

}
#endif // array_2d_H