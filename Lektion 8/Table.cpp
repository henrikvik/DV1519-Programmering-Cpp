#include "Table.h"

Table::Table()
{

}

Table::~Table()
{

}

string Table::toString() const
{
	return "I table!";
}

Table* Table::clone() const
{
	return new Table(*this);
}