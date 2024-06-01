#pragma once

#include <vector>
#include <string>
#include <stdarg.h>

class Info {
private:
	std::vector<std::pair<int, int>> values;

public:
	Info(int n, ...) {
        int result = 0;
        va_list f;         //��������� va_list
        va_start(f, n);    // ������������� ���������
        for (int i = 0; i < n; i+=2) {
            auto arg1 = va_arg(f, int);
            auto arg2 = va_arg(f, int);
            values.push_back(
                std::make_pair(arg1,arg2));  // �������� �������� �������� ��������� ���� int
        }
        va_end(f); // ��������� ��������� ����������
	}

    std::string getStr() {
        std::string str = "";
        for (auto v: values) {
            str += std::to_string(v.first) + " / " +
                std::to_string(v.second) + '\t';
        }
        return str;
    }
};