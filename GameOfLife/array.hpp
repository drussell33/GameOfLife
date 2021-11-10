#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "adt_exception.hpp"

using std::exception;
namespace data_structures


{
	template <class T>
	class Array final
	{
	public:
		explicit Array() = default;
		~Array();
		explicit Array(const size_t& length, const int& start_index = 0) noexcept(false);
		explicit Array(const T* storage, const size_t& length, const int& start_index = 0) noexcept(false);

		Array(const Array& copy) noexcept(false); // copy ctor
		Array& operator=(const Array& rhs) noexcept(false); // assignment op
		Array(Array&& copy) noexcept; // move constructor 
		Array& operator=(Array&& rhs) noexcept; // move copy assignment op

		T& operator[](const int& index) noexcept(false); // 
		T operator[](const int& index) const noexcept(false);
		explicit operator bool() const noexcept; //put array in an if statement

		bool operator==(const Array<T>& rhs) noexcept; // compare element by element

		int StartIndex() const noexcept; //return start index
		size_t Length() const noexcept; // return length

		void StartIndex(const int& start_index) noexcept;
		void Length(const size_t& length) noexcept(false);

		Array& Merge(const Array<T>& array);


	private:
		T* storage_{ nullptr };
		size_t length_{ 0 };
		int start_index_{ 0 };

	};


	template<class T>
	Array<T>::~Array()
	{
		delete[] storage_;
	}

	template<class T>
	Array<T>::Array(const size_t& length, const int& start_index) noexcept(false)
		:length_(length), start_index_(start_index)
	{
		try
		{
			storage_ = new T[length];
		}
		catch (const std::bad_alloc& exception)
		{
			throw AdtException(exception.what());
		}
	}

	template<class T>
	Array<T>::Array(const T* storage, const size_t& length, const int& start_index) noexcept(false)
		:length_(length), start_index_(start_index)
	{
		try
		{
			storage_ = storage;
		}
		catch (const std::bad_alloc& exception)
		{
			throw AdtException(exception.what());
		}
	}

	template<class T>
	Array<T>::Array(const Array& copy) noexcept(false)
	{

		*this = copy; // this calls op=
	}

	template<class T>
	Array<T>& Array<T>::operator=(const Array& rhs) noexcept(false)
	{
		if (this != &rhs)
		{
			length_ = rhs.length_;
			start_index_ = rhs.start_index_;

			delete[] storage_;

			T* temp = new T[rhs.Length()];

			for (size_t i = 0u; i < rhs.Length(); ++i)
			{
				temp[i] = rhs.storage_[i];
			}

			storage_ = temp;
		}

		return *this;
	}

	template<class T>
	Array<T>::Array(Array&& copy) noexcept

	{
		*this = std::move(copy);
	}

	template<class T>
	Array<T>& Array<T>::operator=(Array&& rhs) noexcept
	{
		if (this != &rhs)
		{
			length_ = rhs.length_;
			start_index_ = rhs.start_index_;

			delete[] storage_;


			this->storage_ = rhs.storage_;


			rhs.storage_ = nullptr;
		}

		return *this;
	}

	template<class T>
	T& Array<T>::operator[](const int& index) noexcept(false)
	{
		if (index < 0 || index >= length_)          // THIS IS WHERE YOU CHANGED THINGS!!!!!!
		{
			throw AdtException("WRONG!");
		}

		return storage_[index];
	}

	template<class T>
	T Array<T>::operator[](const int& index) const noexcept(false)
	{
		if (index < 0 || index >= length_)
		{
			throw AdtException("WRONG!");
		}

		return storage_[index];
	}

	template<class T>
	Array<T>::operator bool() const noexcept
	{
		return length_ > 0 && storage_ != nullptr;
	}

	template<class T>
	bool Array<T>::operator==(const Array<T>& rhs) noexcept
	{

		if (length_ != rhs.length_ || start_index_ != rhs.start_index_)
		{
			return false;
		}

		for (auto i = 0; i < length_; ++i)
			if (storage_[i] != rhs.storage_[i])
				return false;

		return true;

	}

	template<class T>
	int Array<T>::StartIndex() const noexcept
	{
		return start_index_;
	}

	template<class T>
	size_t Array<T>::Length() const noexcept
	{
		return length_;
	}

	template<class T>
	void Array<T>::StartIndex(const int& start_index) noexcept
	{
		try
		{
			start_index_ = start_index;
		}
		catch (const std::bad_alloc& exception)
		{
			throw AdtException(exception.what());
		}
	}

	template<class T>
	void Array<T>::Length(const size_t& length) noexcept(false)
	{
		T* temp;

		try
		{
			temp = new T[length];
		}
		catch (const std::bad_alloc& exception)
		{
			throw AdtException(exception.what());
		}

		auto const shorter_length = length_ < length ? length_ : length;

		for (size_t i = 0u; i < shorter_length; ++i)
		{
			temp[i] = this->storage_[i];
		}

		length_ = length;

		delete[] storage_;

		storage_ = temp;

	}

	//template <class T>
	//Array<T>& Array<T>::Merge(const Array<T>& array)
	//{
	//	Array<T> result(this->Length() + array.Length(), 0);
	//	int place_holder = 0;

	//	for (auto i = 0u; i < result.Length(); ++i)
	//	{
	//		if(this->Length() > i)
	//		{
	//			result.storage_[place_holder++] = this->storage_[i];
	//		}

	//		if (array.Length() > i)
	//		{
	//			result.storage_[place_holder++] = array.storage_[i];
	//		}
	//	}
	//	return result;	
	//}


}

#endif
