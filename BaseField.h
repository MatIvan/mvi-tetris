#ifndef BASEFIELD_H
#define BASEFIELD_H

#pragma once
#include <array>
#include "Elements.h"

#define FIELD_HIGHT 20
#define FIELD_WIDTH 10

class BaseField
{
public:
	BaseField();
	~BaseField();

	const int Hight() { return _h; }
	const int Width() { return _w; }
	bool isFilled(int x, int y) { return _field[x][y]; }

	// ������������, ��� ��� ����� ������ �� ������� �� �������
	// � �������� ������.
    // �������� �� ������� ������ � ������� ���������� �� ����
	// ������:
	//			-1 ������ � ������
	//			 0 ������ ������������, �� ��� ������ �����
	//			 ���  ���������� ����������� � ������������ �����.
	int Check(BaseFigure &figure);

private:
	static const int _h = 20;
	static const int _w = 10;
	bool _field[_w][_h] = { 0 };

	//�������� ������ � ����
	void push( BaseFigure & figure);

	//��������� ��� ����� �� ���� � ������� �����������
	//������ ���������� �����������
	int checkLines();
	void destroyLine(int line);
};


#endif //BASEFIELD_H