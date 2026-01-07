//******** PRACTICA VISUALITZACIÓ GRÀFICA INTERACTIVA (Escola Enginyeria - UAB)
//******** Entorn bàsic VS2022 MULTIFINESTRA amb OpenGL 4.6, interfície MFC/GLFW i llibreries GLM
//******** Carme Julià, Débora Gil, Enric Martí Gòdia (Novembre 2025)
// trajectories.h : Definició de les trajectories per corbes Spline o Catmull-Rom i Matriu canvi de base.

#ifndef TRAJECT_H
#define TRAJECT_H

//------------ DEFINICIÓ DE CONSTANTS

// --------------- VGI. Nombre de frames de l'animació per a l'escena Paisatge
#define NFRAMES 25		// Numero de frames en Paisatge B-Spline o Catmull_Rom


const int S = 2;
const double hV = 10.0;

// Numero Pts control
const int npts = 9;

// Vector dels punts de control Tie (Trajectòria més suau, amb baixa torsió) - Origen davant cabina
const CPunt3D PtsH[] = { {256.0 + 16.0,256.0,41.0,1.0},{-256.0,256.0,1.0,1.0},{-256.0f,0.0f,41.0f,1.0},{-160.0,-70.0,86.0,1.0},
{-16.0,-100.0f,191.0,1.0},{256.0 - 32.0,64.0 - 32.0,86.0,1.0},{256.0 + 16.0,256.0,41.0,1.0},{-256.0,256.0,1.0,1.0},
{-256.0,0.0,41.0,1.0} };

// Vector dels punts de control Tie (Trajectòria menys suau, amb alta torsió) - Origen davant cabina
const CPunt3D PtsH2[] = { {256.0 + 16.0,256.0,41.0,1.0},{-256.0,256.0,1.0,1.0},{-256.0f,0.0f,41.0f,1.0},{-128.0 - 16.0,0.0,86.0,1.0},
{-16.0,64.0 + 32.0 + 32.0f,161.0,1.0},{256.0 - 32.0,64.0 - 32.0,86.0,1.0},{256.0 + 16.0,256.0,41.0,1.0},{-256.0,256.0,1.0,1.0},
{-256.0,0.0,41.0,1.0} };

const int Hhh = -50;

// Vector dels punts de control Tie (trajectoria escalada)
const CPunt3D PtsH3[] = { {S * (256.0 + 16.0),S * 256.0,S * (30.0 + Hhh)},{-256.0 * S,256.0 * S,S * (-10.0 + Hhh)},{-256.0 * S,0,S * (30.0 + Hhh)},{S * (-128.0 - 16.0),0,S * (75.0 + Hhh)},
{-16.0 * S,S * (64.0 + 32.0 + 32.0),S * (150.0 + Hhh)},{S * (256.0 - 32),S * (64.0 - 32.0),S * (75.0 + Hhh)},{S * (256.0 + 16.0),256.0 * S,S * (30 + Hhh)},{-256.0 * S,256.0 * S,S * (-10.0 + Hhh)},{-256.0 * S,0,S * (30.0 + Hhh)} };

//------------ FI DEFINICIÓ DE CONSTANTS

//------------------------------- MATRIUS CANVIS DE BASE PER ALINEAR EIXOS OBJECTE AMB EIXOS TRIEDRE FRENET ------------
void Base_Matrix(CPunt3D VT, CPunt3D VNP, CPunt3D VBN, GLfloat* pMatrix);
CPunt3D p3DxMatrix(CPunt3D p, GLfloat pMatrix[16]);
//------------------------------- FI MATRIUS CANVIS DE BASE PER ALINEAR EIXOS OBJECTE AMB EIXOS TRIEDRE FRENET ----------


#endif#pragma once
