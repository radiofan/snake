// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <cstdlib>
#include <Windows.h>
#include <iostream>//ввод вывод в консоль
#include <random>
#include <string>
#include <vector>
#include <cstdint>//фиксированный размер переменных
#include <fstream>//работа с файлами
#include "conio.h"//_getch()
#include <thread>//потоки
#include <stack>//стек
//#include <exception>

#ifndef UNICODE  
  typedef std::string String; 
#else
  typedef std::wstring String; 
#endif


// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы
