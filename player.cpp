#include "pch.h"
#include "player.h"
#include <map>


HRESULT player::init()
{
    gameNode::init();

    _idle = new idle;
    _idle->init();

    _walk = new walk;
    _walk->init();

    _jump = new jump;
    _jump->init();

    _state = _idle;
    _state->init();




    return S_OK;
}

void player::release()
{
    gameNode::release();
    
}

void player::update()
{
    gameNode::update();
    _state->update();
}

void player::render()
{
    _state->render();
}

void player::setValue(state* state)
{
    state->setPlayerX(_state->getPlayerX());
    state->setPlayerY(_state->getPlayerY());
    state->setDir(_state->getDir());
    state->setPlayerHp(_state->getPlayerHp());
    state->setShadowX(_state->getShadowX());
    state->setShadowY(_state->getShadowY());
    _state = state;
}
