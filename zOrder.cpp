#include "pch.h"
#include "zOrder.h"

zOrder::zOrder()
{
}


zOrder::~zOrder()
{
}

HRESULT zOrder::init()
{

	//_vRender.push_back(_player);
	//_vRender.push_back(_enemy);
	//_vRender.push_back(_boss);

	return S_OK;
}

void zOrder::release()
{
	
}

void zOrder::update()
{
	selectionSort();
}

void zOrder::render()
{
	//for (_viRender = _vRender.begin(); _viRender != _vRender.end(); _viRender++)
	//{
	//	(*_viRender)->render();
	//}
}

void zOrder::selectionSort()
{
	//int minIndex;
	//int i, j;

	//// ��ü�� ���� ����ũ�⸸ for�� ������ Ȯ�� ! ���ͳ����� �׻� null���� �����ؼ� -1 ����!!!!

	//for (i = 0; i < _vRender.size() - 1; i++)
	//{
	//	//���� ���밡�� .
	//	//for ���� �� �ϳ����ø��鼭 Ȯ���� min���� �״��
	//	minIndex = i;
	//	//for������ j = �� ���� ��� 0 ,1 �����ϱ����ؼ�  �������� �������� ��������
	//	for (j = i + 1; j < _vRender.size(); j++)
	//	{
	//		//j�� minindex
	//		if (_vRender[j]->getPosY() < _vRender[minIndex]->getPosY())
	//		{ //������ Y���� �����ͼ� ���Ͽ� ����.
	//			//�ٲ����� �갡 min�� ��
	//			minIndex = j;
	//		}
	//	}


	//	swap(&_vRender[i], &_vRender[minIndex]); //render

	//}
}

void zOrder::swap(gameNode** a, gameNode** b)
{
	//gameNode 
	/*gameNode* temp = *a;
	*a = *b;
	*b = temp;*/
}

