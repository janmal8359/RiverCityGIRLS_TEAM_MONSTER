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

	//// 객체를 담은 벡터크기만 for을 돌려서 확인 ! 벡터끝에는 항상 null값이 존재해서 -1 해줌!!!!

	//for (i = 0; i < _vRender.size() - 1; i++)
	//{
	//	//내가 빡대가리 .
	//	//for 문에 서 하나씩올리면서 확인줌 min값은 그대상
	//	minIndex = i;
	//	//for문에서 j = 그 다음 대상 0 ,1 을비교하기위해서  이중포문 개념으로 접근하자
	//	for (j = i + 1; j < _vRender.size(); j++)
	//	{
	//		//j랑 minindex
	//		if (_vRender[j]->getPosY() < _vRender[minIndex]->getPosY())
	//		{ //렌더의 Y값을 가져와서 비교하여 스왑.
	//			//바꿨을때 얘가 min이 됨
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

