#ifndef	__ARRAY_H__
#define	__ARRAY_H__	1.5

#include <stdexcept>      // for: std::out_of_range


// A fixed size array container
// with index bounds checking
// and a forward iterator
template<typename T>
class	Array		// i.e. Array<T>
{

public:

	// To stay in style with e.g. vector<T>::size_type
	typedef	std::size_t  size_type;

private:

	size_type	 length;		// the array length
	T*			 values;		// the array contents

public:

	/// Create an empty array of given length (also default-constructor)
	explicit 	// (to prevent implicit typecasting e.g. Array<int> a = 7;)
	Array(size_type length=0) : length(length), values(new T[length]) {}
	// Also see: slides ArrayAdmin<T> support class

	/// Duplicate an array (copy-constructor)
	Array(const Array& a) {
		// copy the specs
		length = a.length;	values = new T[length];
		// copy the values
		T* dp = values;		T* sp = a.values;
		for (size_type i=0 ; i<length ; ++i, ++dp, ++sp)
			*dp = *sp;
	}

	~Array() { delete[] values; }

	int  size() const { return length; }

private:

	// Private to prevent the use of an '=' operator
	Array& operator=(const Array&) { return *this; }

	// The, internal, index bounds checker function
	size_type  checkedIndex(size_type index) const {
		if ((index < 0) || (length <= index))
			throw std::out_of_range();
		return index;
	}

public:

	// Element access:
	// 	     T&  for "left-hand-side"  (lhs) assignment
	// const T&  for "right-hand-side" (rhs) read-only usage in expressions

	// without index bounds checking
			T&  operator[](size_type index)			{ return values[index]; }	// LVAL
	const	T&  operator[](size_type index) const	{ return values[index]; }	// RVAL

	// with index bounds checking
			T&  at(size_type index)			{ return values[ checkedIndex(index) ]; }	// LVAL
	const	T&  at(size_type index) const	{ return values[ checkedIndex(index) ]; }	// RVAL



	// This bidirectional iterator
	// is a, public, nested, class
	class	iterator	// i.e. the Array<T>::iterator
	{
	private:
		T*	curptr;		// The 'current element pointer'

	public:
		// constructor and default constructor
		iterator(T* xp=0) : curptr(xp) {}

		// copy constructor (same as compiler generated default)
		iterator(const iterator& other) : curptr(other.curptr) {}

		// assignment operator (same as compiler generated default)
		iterator& operator=(const iterator& other) {
			curptr = other.curptr;
			return *this;
		}

		// infix:	xxx != yyy		(an inline helper function)
		friend  bool operator!=(const iterator& i, const iterator& j) {
			return i.curptr != j.curptr;
		}

		// infix:	xxx == yyy		(an inline helper function)
		friend  bool	operator==(const iterator& i, const iterator& j) {
			return i.curptr == j.curptr;
		}

		// prefix:	++xxx	(CHEAP)
		iterator& operator++() { ++curptr; return *this; }

		// postfix:	xxx++	(EXPENSIVE)
		iterator  operator++(int dummy) {
			iterator  temp(curptr);	// to save the old value
			++curptr;
			return temp; 			// returns a copy of the old value
		}

		// prefix:	--xxx	(CHEAP)
		iterator& operator--() { --curptr; return *this; }

		// postfix:	xxx--	(EXPENSIVE)
		iterator  operator--(int dummy) {
			iterator  temp(curptr);	// to save the old value
			--curptr;
			return temp; 			// returns a copy of the old value
		}

		// dereference:	*xxx
		// 	     T&  for "left-hand-side"  (lhs) expressions (assignment)
		// const T&  for "right-hand-side" (rhs) for read-only usage
				T& operator*()			{ return *curptr; }	// LVAL
		const	T& operator*() const	{ return *curptr; }	// RVAL

		// dereference:	xxx->member
		// 	     T*  for "left-hand-side"  (lhs) expressions (assignment)
		// const T*  for "right-hand-side" (rhs) for read-only usage
				T* operator->()			{ return curptr; }	// LVAL
		const	T* operator->() const	{ return curptr; }	// RVAL

	};  // iterator end


	// The container bounds
	iterator	begin() const {
		return iterator(values); // or iterator(&values[0])
	}
	iterator	end()   const {
		return iterator(&values[length]);	// address after last element
	}
	// BEWARE:	For two arrays: Array<T>  x, y;
	// 			the x.end() and y.end() values
	// 			will NOT be the same!

};


// vim:sw=4:ts=4:ai:aw:
#endif	/*ARRAY_H*/
