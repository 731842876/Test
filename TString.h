#pragma once

#ifndef Common_String
#define Common_String

#include<iostream>
class String
{
private:
	char* data;
	int length;

public:
	String(const char* str = NULL) {

		if (str) {
			length = strlen(str);
			data = new char[length + 1];
			strcpy(data, str);
		}
		else
		{
			length = 0;
			data = new char[1];
			*data = '\0';
		}
	}


	/*String(const String& str) {
		length = str.size();
		data = new char[length + 1];
		strcpy(data, str);
	}*/



	~String() {
		delete[]data;
		length = 0;
	}

	//与调用形参匹配const String& str
	size_t size() const {
		return length;
	}


};

#endif // !Common_String

