#pragma once
#include "GameObject.h"
class Recursos :
    public GameObject
{
public:
    Recursos(Texture* _recursosTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);

};

