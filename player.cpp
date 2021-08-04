#include "pch.h"
#include "player.h"


HRESULT player::init()
{


    _idle = new idle;
    _idle->init();

    _walk = new walk;
    _walk->init();

    _jump = new jump;
    _jump->init();

    _state = _idle;
    //_state->init();

    _idle->setPlayer(this);
    _walk->setPlayer(this);
    _jump->setPlayer(this);


    

    return S_OK;
}

void player::release()
{

    
}

void player::update()
{
    //_state->setPlayer(this);
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

    state->setShadowX(_state->getShadowX());
    state->setShadowY(_state->getShadowY());
    
   
    state->setPlayerRc(_state->getPlayerRc());
   
    state->setDir(_state->getDir());
    state->setPlayerHp(_state->getPlayerHp());

    _state = state;

    
}
