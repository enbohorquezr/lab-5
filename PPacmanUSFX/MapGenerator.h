#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <fstream>

#include "GameObject.h"
#include "Texture.h"
#include "Moneda.h"
#include "Fantasma.h"
#include "Pacman.h"
#include "Fruta.h"
#include "Pared.h"
#include "Recursos.h"


using namespace std;

class MapGenerator
{
private:
	vector<GameObject*> vectorObjetosJuego;

	const string pathPacman = "Resources/pacOriginal.png";
	const string pathFantasma1 = "Resources/fan1.png";
	const string pathFantasma2 = "Resources/fantasma3.png";
	const string pathFantasma3 = "Resources/Inkey.bmp";
	const string pathFantasma4 = "Resources/Pinky.bmp";
	const string pathFruta = "Resources/fru.png";
	const string pathMoneda = "Resources/Monedas02M.png"; 
	const string pathSuperMoneda = "Resources/superjeringa.png";
	//recursos laberinto
	const string pathPared = "Resources/pared_recta.png";
	const string pathParedH = "Resources/pared_hori.png";
	const string pathParedC = "Resources/codo1.png";
	const string pathParedC2 = "Resources/codo2.png";
	const string pathParedC3 = "Resources/codo3.png";
	const string pathParedC4 = "Resources/codo4.png";
	const string pathParedC5 = "Resources/codo5.png";
	const string pathParedC6 = "Resources/codo6.png";
	const string pathRecursos = "Resources/pacmanM.png";
	//imagenes de apoyo
	const string pathRecursos1 = "Resources/SPRITE_PRUEBAPAC.png";
	const string pathRecursos2 = "Resources/berserker_layers_tool.png";
	const string pathRecursos3 = "Resources/medi_sprite.png";
	const string pathRecursos4 = "Resources/jeri_sprite.png";

	Texture* pacmanTexture;
	Texture* fantasma1Texture;
	Texture* fantasma2Texture;
	Texture* fantasma3Texture;
	Texture* fantasma4Texture;
	Texture* frutaTexture;
	Texture* monedaTexture;
	Texture* superMonedaTexture;
	Texture* paredTexture;
	Texture* paredHTexture;
	Texture* paredCTexture;
	Texture* paredC2Texture;
	Texture* paredC3Texture;
	Texture* paredC4Texture;
	Texture* paredC5Texture;
	Texture* paredC6Texture;
	Texture* recursosTexture;

	Texture* recursos1Texture;
	Texture* recursos2Texture;
	Texture* recursos3Texture;
	Texture* recursos4Texture;

	int anchoPantalla;
	int altoPantalla;
public:
	MapGenerator(int _anchoPantalla, int _altoPantalla);

	// carga el archivo con el mapa del nivel y todos los objetos
	bool load(string path);

	// carga los objetos generados por la clase MapGeneratos a un array de punteros a objetos GameObject*
	void populate(vector<GameObject*> &_vectorObjetosJuegoGM);
};

