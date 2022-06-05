#ifndef INCLUDE_STRING_H
#define INCLUDE_STRING_H

#include "../include/Vector.hpp"

namespace mydatastructure {

class String {
public:
	String();												/* default ctor */
	String(const String &string);		/* copy ctor */
	String(String &&string);				/* move ctor */
	String(const char *string);
	~String();

	void Reset();
	std::size_t Length() const;
	char* AsCString() const;
	void  StringCopy(const &String);
	
	/* overload operator */
	void			operator const char*() const;
	char			operator[](int index) const;
	char&			operator[](int index);
	int				operator==(const String &string) const;
	int 			operator==(const char *string) const;
	String& 	operator=(const String &string) const;
	String& 	operator=(String &&string) noexcept;
	String& 	operator+=(const String &string);
	String& 	operator+=(const char *string);
	String		operator+(const String &string) const;
	String 		operator+(const char *string) const;

private:
	std::size_t _length;
	char *_string;
	
};	/* class String */

String::String() : _length(0), _string() {
	_string = new char[1];
	_string[0] = '\0';
}

String::String(const char *string)
	if (!string) {
		_length = 0;
		_string = new char[0];
	} else {
		_length = strlen(string);
		_string = new char[_length + 1];
	}

String::String(const String &string) {
	char *buffer = new char[string._length + 1];
}
	
}  /* namespace mydatastructure */


#endif
