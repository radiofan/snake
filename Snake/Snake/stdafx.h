// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <cstdlib>
#include <Windows.h>
#include <iostream>//���� ����� � �������
#include <random>
#include <string>
#include <vector>
#include <cstdint>//������������� ������ ����������
#include <fstream>//������ � �������
#include "conio.h"//_getch()
#include <thread>//������
#include <stack>//����
//#include <exception>

#ifndef UNICODE  
  typedef std::string String; 
#else
  typedef std::wstring String; 
#endif


// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������
