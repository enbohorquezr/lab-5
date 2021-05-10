#include "MapGenerator.h"

MapGenerator::MapGenerator(int _anchoPantalla, int _altoPantalla)
{
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;

	pacmanTexture = new Texture();
	pacmanTexture->loadFromImage(pathPacman);
	fantasma1Texture = new Texture();
	fantasma1Texture->loadFromImage(pathFantasma1);
	fantasma2Texture = new Texture();
	fantasma2Texture->loadFromImage(pathFantasma2);
	fantasma3Texture = new Texture();
	fantasma3Texture->loadFromImage(pathFantasma3);
	fantasma4Texture = new Texture();
	fantasma4Texture->loadFromImage(pathFantasma4);
	frutaTexture = new Texture();
	frutaTexture->loadFromImage(pathFruta);
	monedaTexture = new Texture();
	monedaTexture->loadFromImage(pathMoneda);
	superMonedaTexture = new Texture();
	superMonedaTexture->loadFromImage(pathSuperMoneda);
	paredTexture = new Texture();
	paredTexture->loadFromImage(pathPared);

	paredHTexture = new Texture();
	paredHTexture->loadFromImage(pathParedH);

	paredCTexture = new Texture();
	paredCTexture->loadFromImage(pathParedC);

	paredC2Texture = new Texture();
	paredC2Texture->loadFromImage(pathParedC2);

	paredC3Texture = new Texture();
	paredC3Texture->loadFromImage(pathParedC3);

	paredC4Texture = new Texture();
	paredC4Texture->loadFromImage(pathParedC4);

	paredC5Texture = new Texture();
	paredC5Texture->loadFromImage(pathParedC5);

	paredC6Texture = new Texture();
	paredC6Texture->loadFromImage(pathParedC6);

	recursosTexture = new Texture();
	recursosTexture->loadFromImage(pathRecursos);

	recursos1Texture = new Texture();
	recursos1Texture->loadFromImage(pathRecursos1);
	recursos2Texture = new Texture();
	recursos2Texture->loadFromImage(pathRecursos2);
	recursos3Texture = new Texture();
	recursos3Texture->loadFromImage(pathRecursos3);
	recursos4Texture = new Texture();
	recursos4Texture->loadFromImage(pathRecursos4);

}

bool MapGenerator::load(string path)
{
	// Crea un flujo a un archivo
	fstream file;

	// Abre el archivo y verifica si tuvo exito
	file.open(path.c_str(), ios::in);

	// Retorna false si falla la apertura del archivo
	if (file.is_open() == false)
		return false;

	string line;

	int x = 0;
	int y = 0;

	// Lee el archivo linea por linea
	while (getline(file, line)) {
		// Divide la linea leida y la guarda en un vector de caracteres
		vector<char> chars(line.begin(), line.end());

		for (unsigned int x = 0; x < chars.size(); x++) {
			GameObject* newObject = nullptr;

			// Se verifica que letra es la que se lee y en funcion a ello se crea un tipo de objeto
			switch (chars[x])
			{
				//recursos laberinto
			case 'z':
				newObject = new Pared(paredTexture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				break;
			case 'y':
				newObject = new Pared(paredHTexture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				break;
			case 'v':
				newObject = new Pared(paredCTexture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				break;
			case 'n':
				newObject = new Pared(paredC2Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				break;
			case 'm':
				newObject = new Pared(paredC3Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				break;
			case 'ñ':
				newObject = new Pared(paredC4Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				break;
			case 'h':
				newObject = new Pared(paredC5Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				break;
			case 'j':
				newObject = new Pared(paredC6Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				break;


			case '.':
				newObject = new Moneda(monedaTexture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				newObject->setParametrosAnimacion(4);
				break;
			case 'o':
				newObject = new Moneda(superMonedaTexture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				newObject->setParametrosAnimacion(6);
				break;
			case 'p':
				newObject = new Pacman(pacmanTexture, x *25 , y *25, 250, 250, anchoPantalla, altoPantalla, 5);
				newObject->setParametrosAnimacion(2);
				break;
			case 'b':
				newObject = new Fantasma(fantasma1Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 3);
				newObject->setParametrosAnimacion(4);
				break;
			case 'c':
				newObject = new Fantasma(fantasma2Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 3);
				newObject->setParametrosAnimacion(4);
				break;
			case 'i':
				newObject = new Fantasma(fantasma3Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 3);
				newObject->setParametrosAnimacion(4);
				break;
			case 'a':
				newObject = new Fantasma(fantasma4Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 3);
				newObject->setParametrosAnimacion(8);
				break;
			case 'q':
				newObject = new Recursos(recursosTexture, x*15  , y, 300, 168, anchoPantalla, altoPantalla);
				//newObject->setParametrosAnimacion(6);
				break;
				//imagenes de apoyo
			case '1':
				//newObject = new Recursos(recursos1Texture, x *25, y *25, 781, 721, anchoPantalla, altoPantalla);
				//newObject->setParametrosAnimacion(1);
				break;
			case '2':
				newObject = new Recursos(recursos2Texture, x *25 , y *25, 192, 192, anchoPantalla, altoPantalla);
				newObject->setParametrosAnimacion(6);
				break;
			case '3':
				newObject = new Recursos(recursos3Texture, x *17 , y *15, 78, 78, anchoPantalla, altoPantalla);
				//newObject->setParametrosAnimacion(6);
				break;
			case '4':
				newObject = new Recursos(recursos4Texture, x*15 , y*15, 104, 105, anchoPantalla, altoPantalla);
				//newObject->setParametrosAnimacion(6);
				break;


			case 'g':
				newObject = new Fruta(frutaTexture, x , y, 25, 25, anchoPantalla, altoPantalla);
				newObject->setParametrosAnimacion(4);
				break;
			}

			// If the object was created, add it to the vector
			if (newObject != nullptr)
				vectorObjetosJuego.push_back(newObject);
		}

		y++;
	}

	// Close the file
	file.close();

	return true;
}

void MapGenerator::populate(std::vector<GameObject*> &_vectorObjetosJuegoGM)
{
	for (unsigned int i = 0; i < vectorObjetosJuego.size(); i++) {
		_vectorObjetosJuegoGM.push_back(vectorObjetosJuego[i]);
	}
}