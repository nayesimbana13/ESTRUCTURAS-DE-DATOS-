// metodosSobrecargados.h
// Declaraciones de funciones sobrecargadas con combinaciones de int, float y double

#pragma once

// Todas las permutaciones de (int, float, double)
double operar(int a, float b, double c);
double operar(int a, double b, float c);
double operar(float a, int b, double c);
double operar(float a, double b, int c);
double operar(double a, int b, float c);
double operar(double a, float b, int c);
