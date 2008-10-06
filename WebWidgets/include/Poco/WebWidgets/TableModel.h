//
// TableModel.h
//
// $Id: //poco/Main/WebWidgets/include/Poco/WebWidgets/TableModel.h#4 $
//
// Library: WebWidgets
// Package: Views
// Module:  TableModel
//
// Definition of the TableModel class.
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef WebWidgets_TableModel_INCLUDED
#define WebWidgets_TableModel_INCLUDED


#include "Poco/WebWidgets/WebWidgets.h"
#include "Poco/RefCountedObject.h"
#include "Poco/AutoPtr.h"
#include "Poco/Any.h"


namespace Poco {
namespace WebWidgets {


class WebWidgets_API TableModel: public Poco::RefCountedObject
	/// TableModel defines the interface for data retrieval for a Table
{
public:
	typedef Poco::AutoPtr<TableModel> Ptr;

	TableModel(std::size_t colCnt);
		/// Creates the TableModel with the given number of columns.

	std::size_t getColumnCount() const;
		/// Returns the number of columns

	virtual const Poco::Any& getValue(std::size_t row, std::size_t col) const = 0;
		///Returns the value at pos(row, col) or an empty Any if no data is stored there

	virtual std::size_t getRowCount() const = 0;
		/// Returns the total number of rows

	virtual void setValue(const Poco::Any& val, std::size_t row, std::size_t col) = 0;
		/// Sets the value at pos(row, col)

	virtual void deleteRow(std::size_t row) = 0;
		/// Removes the row from the TableModel
		
	virtual void clear() = 0;
		/// Deletes all rows from the TableModel

	virtual TableModel::Ptr clone() const = 0;
		/// Creates a deep-copy of the table

protected:
	virtual ~TableModel();
		/// Destroys the TableModel.

private:
	std::size_t _colCnt;
};


//
// Inlines
//

inline std::size_t TableModel::getColumnCount() const
{
	return _colCnt;
}


} } // namespace Poco::WebWidgets


#endif // WebWidgets_TableModel_INCLUDED
