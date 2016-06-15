#ifndef STUDENT_H
#define STUDENT_H

#include "stdafx.h"

const int STRING_MAX_SIZE = 80;

struct Student
{
	TCHAR name[STRING_MAX_SIZE];
	TCHAR birth[STRING_MAX_SIZE];
	TCHAR phone[STRING_MAX_SIZE];
	TCHAR email[STRING_MAX_SIZE];
	TCHAR adress[STRING_MAX_SIZE];
};

#endif // STUDENT_H