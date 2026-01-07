//******** PRACTICA VISUALITZACI� GR�FICA INTERACTIVA (Escola Enginyeria - UAB)
//******** Entorn b�sic VS2022 MULTIFINESTRA amb OpenGL 4.6, interf�cie MFC i llibreries GLM
//******** Ferran Poveda, Marc Vivet, Carme Juli�, D�bora Gil, Enric Mart� G�dia (Setembre 2025)
// visualitzacio.h : Interface de visualitzacio.cpp
//

#ifndef GLVIS_H
#define GLVIS_H

/* ------------------------------------------------------------------------- */
/*                                Funcions                                   */
/* ------------------------------------------------------------------------- */

// Entorn VGI: Il.luminaci�
void Iluminacio(GLint sh_programID, char ilumin, bool ifix, bool ilu2sides, bool ll_amb, LLUM* lumin,
	char obj, bool frnt_fcs, int step);

// ----------- Entorn VGI: PROJECCIONS
// Entorn VGI: Projecci� Ortografica
glm::mat4 Projeccio_Orto(GLuint sh_programID, int x, int y, float w, float h, float escala, float escalaZoom = 1.0f, float farPlane = 100.0f);
// Entorn VGI: Projecci� Perspectiva
glm::mat4 Projeccio_Perspectiva(GLuint sh_programID, int minx, int miny, GLsizei w, GLsizei h, double zoom);

// ----------- Entorn VGI: C�MERES
// Entorn VGI: C�mera Ortogr�fica
glm::mat4 Vista_Ortografica(GLuint sh_programID, int prj, GLdouble Raux, 
						CColor col_fons, CColor col_object, char objecte, GLdouble mida, int step,
						bool frnt_fcs, bool oculta, bool testv, 
						char iluminacio, bool llum_amb, LLUM* lumin,
						bool ifix, bool il2sides, bool eix, CMask3D reixa, CPunt3D hreixa);
// Entorn VGI: C�mera Esf�rica
glm::mat4 Vista_Esferica(GLuint sh_programID, CEsfe3D opv,char VPol,bool pant,CPunt3D tr,CPunt3D trF,
						CColor col_fons,CColor col_object,char objecte,double mida,int step,
						bool frnt_fcs, bool oculta, bool testv, 
						char iluminacio, bool llum_amb, LLUM* lumin, 
						 bool ifix, bool il2sides, bool eix, CMask3D reixa, CPunt3D hreixa);
// Entorn VGI: C�mera Navega
glm::mat4 Vista_Navega(GLuint sh_programID,CPunt3D pv, GLdouble n[3],GLdouble v[3], bool pant,CPunt3D tr,CPunt3D trF,
						CColor col_fons,CColor col_object,char objecte,bool color, int step, 
						bool frnt_fcs, bool oculta, bool testv, 
						char iluminacio, bool llum_amb, LLUM* lumin, 
						bool ifix, bool il2sides,bool eix, CMask3D reixa, CPunt3D hreixa);
// Entorn VGI: C�mera Geode
glm::mat4 Vista_Geode(GLuint sh_programID, CEsfe3D opv, char VPol, bool pant, CPunt3D tr, CPunt3D trF,
						CColor col_fons, CColor col_object, char objecte, double mida, int step,
						bool frnt_fcs, bool oculta, bool testv,
						char iluminacio, bool llum_amb, LLUM* lumi, bool ifix, bool il2sides,
						bool eix, CMask3D reixa, CPunt3D hreixa);

// Entorn VGI: C�rrega TG
glm::mat4 instancia(bool TR, INSTANCIA tg, INSTANCIA tgF);

// Entorn VGI: Dibuix dels eixos de coordenades
GLuint deixos(void);
void draw_Eixos(GLuint vboId);

// Entorn VGI: GRID (gridXY, gridYZ, gridXZ, gridXYZ) -------------------------
void draw_Grid(CMask3D quadricula);
CVAO loadGridXY_VAO(int size, GLdouble h);
CVAO loadGridXZ_VAO(int size, GLdouble h);
CVAO loadGridYZ_VAO(int size, GLdouble h);
CVAO loadGridXYZ_VAO(int size);

// Entorn VGI: Esborrats de pantalla a fons variable (Fons), negre (Fons) o a blanc (FonsW)
void Fons(CColor int_fons);
void FonsN(void);
void FonsB(void);

// Entorn VGI: Carregar fitxer imatge de formats admesos per la llibreria DevIL/OpenIL 
//				com a textura
GLint loadIMA_SOIL(const char *filename);
unsigned int loadCubemap(std::vector<std::string> faces);
void SetTextureParameters(GLint num, GLint IDText, bool extensT, bool filterT, bool blendT, bool genMipmpT);
#endif